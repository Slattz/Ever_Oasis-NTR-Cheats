#include "cheats.hpp"

namespace CTRPluginFramework
{
    void oneHitKill(MenuEntry *entry)
    {
        u16 enemyMaxHP = 0;
    
        // Iterate through 6 known slots, check if Max HP is > 1 and if so
        // set Max and Current HP to 1 for one-hit kill
        for (int i = 0; i < 6; i++)
        {
            Process::Read16(Game::EnemyHealth + (i * 0x28), enemyMaxHP);
            if (enemyMaxHP > 0x1)
            {
                Process::Write16(Game::EnemyHealth + (i * 0x28), 1);
                Process::Write16((Game::EnemyHealth + 2) + (i * 0x28), 1);
            }
        }
    }

    void oneHitDestructible(MenuEntry *entry)
    {
        u16 destructableHP = 0;

        // Iterate through 29 known slots, check if current HP is > 1 and if so
        // set Current HP to 1 for one-hit destroy
        for (int i = 0; i < 29; i++)
        {
            Process::Read16(Game::DestructHealth + (i * 0x38), destructableHP);
            if (destructableHP > 1)
                Process::Write16(Game::DestructHealth + (i * 0x38), 1);
        }
    }
}
