#include "cheats.hpp"

namespace CTRPluginFramework
{

    void    PSpeed(MenuEntry *entry) //Probably actually friction
    {
        static bool btn = false;
        static bool active = false;
        static const u32 fast = 0x3F000000; //0.5f
        static const u32 orig = 0x3F800000; //1.0f
    
        if (entry->Hotkeys[0].IsDown() && !btn) //Controller::IsKeysDown(R + DPadLeft)
        {
            if (!active)
            {
                if (*Game::Speed != 0)
                {
                    Process::Write32(*Game::Speed + 0xB0, fast); //Change it in realtime
                    Process::Patch(Game::SpeedASM1, fast); //Can change place without speed resetting
                    Process::Patch(Game::SpeedASM2, fast); //Can roll without speed resetting
                }
                OSD::Notify("Speed: " << Color::Green << "Fast!");
                active = true;
                btn = true;
            }
    
            else if (active)
            {
                if (*Game::Speed != 0x0)
                {
                    Process::Write32(*Game::Speed + 0xB0, orig);
                    Process::Patch(Game::SpeedASM1, orig);
                    Process::Patch(Game::SpeedASM2, orig);
                }

                OSD::Notify("Speed: " << Color::Red << "Normal!");
                active = false;
                btn = true;
            }
        }

        else if (!entry->Hotkeys[0].IsDown())
            btn = false;
    }

    void infHealth(MenuEntry *entry)
    {
        //u16 maxHP;
        //u16 rainbowProt;

        // Load Rainbow Protection amount if any
        //rainbowProt = READU16(Game::rainbowprot);

        //maxHP = READU16(Game::maxhp);

        Process::Write16(Game::Health, 999);
        //WRITEU16(0x32967DFC, maxHP + rainbowProt);
    }

    void infSP(MenuEntry *entry)
    {
        Process::Write16(Game::SP, 999);
    }

    void infMoney(MenuEntry *entry)
    {
        Process::Write32(Game::Money, 0x000F423F);
    }

    /* Inventory Items */

    void maxMaterials(MenuEntry *entry)
    {
        u8 slotcheck = 0;
        OSD::Notify("x99 of your Materials!");
        for (int i = 0; i < 217; i++) {
            Process::Read8(Game::Materials + (i * 8), slotcheck);
            if (slotcheck != 0)
                Process::Write8(Game::Materials + (i * 8), 99);
        }
        entry->Disable();
    }

    void maxSlabs(MenuEntry *entry)
    {
        u8 sslotcheck = 0;
        OSD::Notify("x50 of your Slabs!");
        for (int i = 0; i < 18; i++) {
            Process::Read8(Game::Slabs + (i * 8), sslotcheck);
            if (sslotcheck != 0)
                Process::Write8(Game::Slabs + (i * 8), 50);
        }
        entry->Disable();
    }

    void allSeeds(MenuEntry *entry)
    {
        OSD::Notify("x50 of All Seeds!");
        for (int i = 0; i < 51; i++) {
            Process::Write8(Game::Seeds + (i * 8), 50);
        }
        entry->Disable();
    }

    void allHealingItems(MenuEntry *entry)
    {
        OSD::Notify("x99 of All Healing Items!");
        for (int i = 0; i < 12; i++) {
            Process::Write8(Game::HealItems + (i * 8), 99);
        }
        entry->Disable();
    }

    /* Chest Items */

    void maxWeapons(MenuEntry *entry)
    {
        u8 wslotcheck = 0;
        OSD::Notify("x50 of your Weapons!");
        for (int i = 0; i < 128; i++) {
            Process::Read8(Game::Weapons + (i * 8), wslotcheck);
            if (wslotcheck != 0)
                Process::Write8(Game::Weapons + (i * 8), 50);
        }
        entry->Disable();
    }

    void allAccessory(MenuEntry *entry)
    {
        OSD::Notify("x50 of All Accessories!");
        for (int i = 0; i < 50; i++) {
            Process::Write8(Game::Accessories + (i * 8), 50);
        }
        entry->Disable();
    }

    void allTurbans(MenuEntry *entry)
    {
        OSD::Notify("x50 of All Turbans!");
        for (int i = 0; i < 8; i++) {
            Process::Write8(Game::Turbans + (i * 8), 50);
        }
        entry->Disable();
    }

    void allClothes(MenuEntry *entry)
    {
        OSD::Notify("x50 of All Clothing!");
        for (int i = 0; i < 81; i++) {
            Process::Write8(Game::Clothing + (i * 8), 50);
        }
        entry->Disable();
    }

    /* Stats */

    void maxLVL(MenuEntry *entry)
    {
        Process::Write8(Game::Level, 0x1E);
        OSD::Notify("Maxed Level Stat!");
        entry->Disable();
    }

    void maxHP(MenuEntry *entry)
    {
        Process::Write16(Game::MaxHP, 999);
        OSD::Notify("Maxed HP Stat!");
        entry->Disable();
    }

    void maxAttack(MenuEntry *entry)
    {
        Process::Write8(Game::Attack, 99);
        OSD::Notify("Maxed Attack Stat!");
        entry->Disable();
    }

    void maxDefense(MenuEntry *entry)
    {
        Process::Write8(Game::Defense, 99);
        OSD::Notify("Maxed Defense Stat!");
        entry->Disable();
    }

    void maxMagicDef(MenuEntry *entry)
    {
        Process::Write8(Game::Magicdef, 99);
        OSD::Notify("Maxed Magic Defense Stat!");
        entry->Disable();
    }

    void maxLuck(MenuEntry *entry)
    {
        Process::Write8(Game::Luck, 99);
        OSD::Notify("Maxed Luck Stat!");
        entry->Disable();
    }
}
