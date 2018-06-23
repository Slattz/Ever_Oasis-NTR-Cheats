#ifndef CHEATS_HPP
#define CHEATS_HPP

#include "CTRPluginFramework.hpp"
#include "Game.hpp"
#include "Helpers.hpp"
#include "Unicode.h"

#define MAJOR_VERSION       2
#define MINOR_VERSION       0
#define REVISION_VERSION    0
#define STRINGIFY(x)        #x
#define TOSTRING(x)         STRINGIFY(x)
#define STRING_VERSION      "[" TOSTRING(MAJOR_VERSION) "." TOSTRING(MINOR_VERSION) "." TOSTRING(REVISION_VERSION) "]"

namespace CTRPluginFramework
{
    using StringVector = std::vector<std::string>;

    /*
    ** Helpers
    ********************/
    u32     OffsetToUsa(u32 offset);

    /*
    ** Player
    ********************/
    void    PSpeed(MenuEntry *entry);
    void    infHealth(MenuEntry *entry);
    void    infSP(MenuEntry *entry);
    void    maxLVL(MenuEntry *entry);
    void    maxMoney(MenuEntry *entry);

    //Inventory
    void    maxMaterials(MenuEntry *entry);
    void    maxSlabs(MenuEntry *entry);
    void    allSeeds(MenuEntry *entry);
    void    allHealingItems(MenuEntry *entry);

    //Chest
    void    maxWeapons(MenuEntry *entry);
    void    allAccessory(MenuEntry *entry);
    void    allTurbans(MenuEntry *entry);
    void    allClothes(MenuEntry *entry);

    //Stats
    void    maxLVL(MenuEntry *entry);
    void    maxHP(MenuEntry *entry);
    void    maxAttack(MenuEntry *entry);
    void    maxDefense(MenuEntry *entry);
    void    maxMagicDef(MenuEntry *entry);
    void    maxLuck(MenuEntry *entry);
  
    /*
    ** Oasis.cpp
    ********************/
    void    OasisLVL(MenuEntry *entry);
    void    ShopStocker(MenuEntry *entry);
    void    ShopBouncer(MenuEntry *entry);
    void    QuestGauge(MenuEntry *entry);

    /*
    ** NPC.cpp
    ********************/
    void    oneHitKill(MenuEntry *entry);
    void    oneHitDestructible(MenuEntry *entry);

    /*
    ** Misc.cpp
    ********************/

    //Model
    void    invisi(MenuEntry *entry);
    void    tiny(MenuEntry *entry);
    void    giant(MenuEntry *entry);
    void    flat(MenuEntry *entry);
    void    paper(MenuEntry *entry);

    //Misc
    void    Collisions(MenuEntry *entry);
    void    Fly(MenuEntry *entry);

    /*
    ** Time.cpp
    ********************/
    void    changeTime(MenuEntry *entry);
}
#endif
