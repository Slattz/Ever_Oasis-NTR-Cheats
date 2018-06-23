#include "CTRPluginFramework.hpp"
#include "cheats.hpp"

// Will exit the plugin
void    abort(void);
bool    g_isGame = false;

namespace CTRPluginFramework
{
    // This function is called before main
    void    PatchProcess(FwkSettings &settings) { 

    }

    extern Region               g_region;
    static const std::string    unsupportedVersion = "The version of Ever Oasis you have installed is unsupported.\nThis plugin only supports v1.1!\nNo Ever Oasis menu entries will appear.";
    static const std::string    unsupportedGame = "Error:\nThis game isn't Ever Oasis!\nNo Ever Oasis menu entries will appear.";
    static const std::string    gameName = "Ever Oasis";
    static const std::string    credits =
        "Plugin Version: " STRING_VERSION  "\n"
        "Plugin Developers:\n"
        "Slattz\n"
        "Scotline\n"
        "AnalogMan\n"
        "\n\nThanks to Nanquitas for CTRPF!";

    static bool    IsGame(void) {
        u32         tid = Process::GetTitleID();
        u16         ver = Process::GetVersion();

        // Get current game's region
        switch (tid) {
            case 0x001A4900: //EUR
                if (ver != 1040)
                    goto unsupported;
                g_region = EUR;
                break;

            case 0x001A4800: //USA
                if (ver != 1040)
                    goto unsupported;
                g_region = USA;
                break;

            default:
                (MessageBox(unsupportedGame))();
                return false;
        }

        return true;

    unsupported:
        (MessageBox(unsupportedVersion))();
        return false;
    }

    MenuEntry *EntryWithHotkey(MenuEntry *entry, const Hotkey &hotkey)
    {
        if (entry != nullptr)
        {
            entry->Hotkeys += hotkey;
            entry->SetArg(new std::string(entry->Name()));
            entry->Name() += " " + hotkey.ToString();
            entry->Hotkeys.OnHotkeyChangeCallback([](MenuEntry *entry, int index)
            {
                std::string *name = reinterpret_cast<std::string *>(entry->GetArg());

                entry->Name() = *name + " " + entry->Hotkeys[0].ToString();
            });
        }

        return (entry);
    }

    MenuEntry *EntryWithHotkey(MenuEntry *entry, const std::vector<Hotkey> &hotkeys)
    {
        if (entry != nullptr)
        {
            for (const Hotkey &hotkey : hotkeys)
                entry->Hotkeys += hotkey;
        }

        return (entry);
    }

    void    InitMenu(PluginMenu &menu) {
        menu += EntryWithHotkey(new MenuEntry("Toggle Collisions", Collisions, "Toggles collisions, allowing walking through walls.\nPress the hotkey to toggle between fast and normal."),
            {Hotkey(Key::R | Key::DPadRight, "Change toggle button")}),
        menu += EntryWithHotkey(new MenuEntry("Fly", Fly, "Press L + D-Pad Right to go very high into the sky.\nPress L + D-Pad Left to go into the sky.\nPress R once in the sky to maintain the height.\nPress B to cancel any height.\nNOTE: Speed is affected after pressing R."),
        {
            Hotkey(Key::L | Key::DPadRight, "Change buttons for going high in sky"), Hotkey(Key::L | Key::DPadLeft, "Change buttons for going in sky"), 
            Hotkey(Key::R, "Change button for maintain height"), Hotkey(Key::B, "Change button for cancel height")
        });

        MenuFolder *playerfolder = new MenuFolder("Player Codes");
        {
            *playerfolder += EntryWithHotkey(new MenuEntry("Faster Speed", PSpeed, "Makes your player faster.\nPress the hotkey to toggle between fast and normal."),
                                {Hotkey(Key::R | Key::DPadLeft, "Change toggle button")}),
            *playerfolder += new MenuFolder("Battle Cheats", std::vector<MenuEntry *>(
            {
                new MenuEntry("Infinite HP", infHealth, "Gives the player infinite health, making them invincible."),
                new MenuEntry("Infinite SP", infSP, "Gives the player infinite SP."),
                new MenuEntry("One Hit Kill Enemies", oneHitKill, "Makes enemies a one hit kill."),
                new MenuEntry("One Hit Kill Destructibles", oneHitDestructible, "Makes destructables, such as cacti, a one hit kill.")
            }));
            MenuFolder *itemfolder = new MenuFolder("Item Cheats");
            {
                *itemfolder += new MenuFolder("Inventory", std::vector<MenuEntry *>(
                {
                    new MenuEntry("Max Materials", maxMaterials, "Gives you x99 of each Material if you have at least 1"),
                    new MenuEntry("Max Slabs", maxSlabs, "Gives you x50 of each Slab if you have at least 1"),
                    new MenuEntry("All Garden Seeds", allSeeds, "Gives you x50 of every Seed"),
                    new MenuEntry("All Healing Items", allHealingItems, "Gives you x99 of every Healing Item")
                }));
                *itemfolder += new MenuFolder("Chest", std::vector<MenuEntry *>(
                {
                    new MenuEntry("All Weapons", maxWeapons, "Gives you x50 of each Weapon if you have at least 1"),
                    new MenuEntry("All Turbans", allTurbans, "Gives you every Turban"),
                    new MenuEntry("All Accessories", allAccessory, "Gives you every Accessory"),
                    new MenuEntry("All Clothes", allClothes, "Gives you all Clothes"),
                }));
            }
            *playerfolder += itemfolder;
            *playerfolder += new MenuFolder("Stat Codes", std::vector<MenuEntry *>(
            {
                new MenuEntry("Max Player Level", maxLVL, "Makes your player the max level (30)."),
                new MenuEntry("Max Player HP", maxHP, "Gives your player max HP stat."),
                new MenuEntry("Max Attack", maxAttack, "Gives your player max Attack stat."),
                new MenuEntry("Max Defense", maxDefense, "Gives your player max Defense stat."),
                new MenuEntry("Max Magic Defense", maxMagicDef, "Gives your player max Magic Defense stat."),
                new MenuEntry("Max Luck", maxLuck, "Gives your player max Luck stat."),
            }));
        }
        menu += playerfolder;
        menu += new MenuFolder("Oasis Cheats", std::vector<MenuEntry *>(
        {
            new MenuEntry(1, "All Stores Stocked x999", ShopStocker, "Stocks each shop with x999 of their item."),
            new MenuEntry(1, "All Stores Stocked x0", ShopBouncer, "Stocks each shop with x0 of their item."),
            new MenuEntry("Max Stores Quest EXP Gauge", QuestGauge, "Fill's the Quest Guage for each shop. After using this code, you will need to restock once to trigger the upgrade quest."),
        }));
        MenuFolder *miscfolder = new MenuFolder("Misc Cheats");
        {
            *miscfolder += new MenuFolder("Time Modifier", std::vector<MenuEntry *>(
            {
                new MenuEntry("Time Changer", changeTime, "R+Up = dawn. R+Down = dusk.\nR+Left cancel pending time change.\nReload the area to trigger the time change."),
            }));
            *miscfolder += new MenuFolder("Player Model Mods", std::vector<MenuEntry *>(
            {
                new MenuEntry(2, "Invisible Character", invisi, "Makes the player appear invsible.\nNOTE:\nEnemies will still detect you."),
                new MenuEntry(2, "Tiny Character", tiny, "Makes the player appear tiny."),
                new MenuEntry(2, "Giant Character", giant, "Makes the player appear giant."),
                new MenuEntry(2, "Flat Character", flat, "Achievement Unlocked: Pancaked!"),
                new MenuEntry(2, "Paper Character", paper, "Paper Mario meets Ever Oasis."),
            }));
            *miscfolder += new MenuFolder("Experimental", std::vector<MenuEntry *>(
            {
                new MenuEntry("Note about Experimental Cheats", "These may cause issues with certain aspects of the game.\nTake caution and make a save backup before use."),
                new MenuEntry("Max Oasis Size", OasisLVL, "Makes your oasis the biggest size (sets it to level 20)."),
            }));
        }
        menu += miscfolder;
    }

    int     main(void) {
        g_isGame = IsGame();

        PluginMenu  *menu = new PluginMenu(gameName, MAJOR_VERSION, MINOR_VERSION, REVISION_VERSION, credits);

        if (g_isGame) {
            // Initialize game's addresses based on region
            Game::Initialize();

            // Init our menu entries & folders
            InitMenu(*menu);
        }

        // Menu loop executed 1 per game frame
        menu->SynchronizeWithFrame(true); //Needed for EO, otherwise game freezes

        // Launch menu and mainloop
        menu->Run();

        // Release resources used by menu
        delete menu;

        // Exit plugin
        return (0);
    }
}
