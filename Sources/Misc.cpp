#include "cheats.hpp"

namespace CTRPluginFramework
{

    void Collisions(MenuEntry *entry)
    {
        static bool btn = false;
        static bool active = false;
        static const u32 offset = Game::Collisions;

        if (entry->Hotkeys[0].IsDown() && !btn) //Controller::IsKeysDown(R + DPadRight)
        {
            if (!active)
            {
                Process::Write32(offset, 0);
                OSD::Notify("Collisions: " << Color::Green << "Off!");
                active = true;
                btn = true;
            }

            else if (active)
            {
                Process::Write32(offset, 0x3F8020C5);
                OSD::Notify("Collisions: " << Color::Red << "On!");
                active = false;
                btn = true;
            }
        }

        else if (!entry->Hotkeys[0].IsDown())
            btn = false;
    }


    //Model Modifier

    void Write_ModelSize(float size1, float size2, float size3)
    {
        if (*Game::ModelSize != 0)
        {
            Process::WriteFloat(*Game::ModelSize + 0xBC, size1);
            Process::WriteFloat(*Game::ModelSize + 0xC0, size2);
            Process::WriteFloat(*Game::ModelSize + 0xC4, size3);
        }
    }

    static void normalsize(void)
    {
        Write_ModelSize(1.f, 1.f, 1.f);
    }

    void invisi(MenuEntry *entry)
    {
        Write_ModelSize(0.f, 0.f, 0.f);
        if (!entry->WasJustActivated())
            OSD::Notify("Player Model: " << Color::Blue << "Invisible!");

            if (!entry->IsActivated())
                normalsize();
    }

    void tiny(MenuEntry *entry)
    {
        Write_ModelSize(0.25f, 0.25f, 0.25f);
        if (!entry->WasJustActivated())
            OSD::Notify("Player Model: " << Color::Blue << "Tiny!");

        if (!entry->IsActivated())
            normalsize();
    }

    void giant(MenuEntry *entry)
    {
        Write_ModelSize(3.f, 3.f, 3.f);
        if (!entry->WasJustActivated())
            OSD::Notify("Player Model: " << Color::Blue << "Giant!");

        if (!entry->IsActivated())
            normalsize();
    }

    void flat(MenuEntry *entry)
    {
        Write_ModelSize(0.125f, 1.f, 1.f);
        if (!entry->WasJustActivated())
            OSD::Notify("Player Model: " << Color::Blue << "Flat!");

        if (!entry->IsActivated())
            normalsize();
    }

    void paper(MenuEntry *entry)
    {
        Write_ModelSize(1.f, 0.125f, 1.f);
        if (!entry->WasJustActivated())
            OSD::Notify("Player Model: " << Color::Blue << "Paper!");

        if (!entry->IsActivated())
            normalsize();
    }

    void Fly(MenuEntry *entry)
    {
        u32* off = Game::Speed - 4;
        if (entry->Hotkeys[0].IsDown()) { //Controller::IsKeysDown(L + DPadRight)
            if (*off != 0) {
                Process::Write32(*off + 0x24, 0x44000000);
            }
        }

        if (entry->Hotkeys[1].IsDown()) { //Controller::IsKeysDown(L + DPadLeft)
            if (*off != 0) {
                Process::Write32(*off + 0x24, 0x42000000);
            }
        }

        if (entry->Hotkeys[2].IsDown()) { //Controller::IsKeysDown(R))
            if (*Game::Speed != 0) {
                Process::Write16(*Game::Speed + 0xD, 0x0134);
            }
        }

        if (entry->Hotkeys[3].IsDown()) { //Controller::IsKeysDown(B))
            if (*Game::Speed != 0) {
                Process::Write16(*Game::Speed + 0xD, 0x0001);
            }
        }
    }
}
