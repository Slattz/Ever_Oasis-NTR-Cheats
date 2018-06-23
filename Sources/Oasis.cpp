#include "cheats.hpp"

static const u16 shopdiffs[] = {
    0x0,
    0x1D0,
    0x2B8,
    0x89C,
    0x910,
    0xC3C,
    0xCB0,
};

namespace CTRPluginFramework
{
    void OasisLVL(MenuEntry *entry) {
        u8 lvl = 0;
        Process::Read8(Game::Oasislvl, lvl);
        if (lvl <= 20) {
            Process::Write8(Game::Oasislvl, 20);
        }
        OSD::Notify("Maxed Oasis Level!");
        entry->Disable();
    }

    void ShopStocker(MenuEntry *entry)
    {
        for (int i = 0; i < 7; i++) {
            Process::Write16(Game::ShopStock + shopdiffs[i], 999); //Item 1
            Process::Write16(Game::ShopStock + shopdiffs[i] + 2, 999); //Item 2
            Process::Write16(Game::ShopStock + shopdiffs[i] + 4, 999); //Item 3
        }
        OSD::Notify("Shops Stock: " << Color::Blue << "Filled!");
        entry->Disable();
    }

    void ShopBouncer(MenuEntry *entry)
    {
        for (int i = 0; i < 7; i++) {
            Process::Write16(Game::ShopStock + shopdiffs[i], 0);
            Process::Write16(Game::ShopStock + shopdiffs[i] + 2, 0);
            Process::Write16(Game::ShopStock + shopdiffs[i] + 4, 0);
        }
        OSD::Notify("Shops Stock: " << Color::Blue << "Emptied!");
        entry->Disable();
    }

    void QuestGauge(MenuEntry *entry)
    {
        for (int i = 0; i < 7; i++) {
            Process::Write16(Game::ShopGuage + shopdiffs[i], 0xFFFF);
        }
        OSD::Notify("Quest Guage " << Color::Blue << "Filled!");
        entry->Disable();
    }
}
