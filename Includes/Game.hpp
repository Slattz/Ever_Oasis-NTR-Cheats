#ifndef GAME_HPP
#define GAME_HPP

#include "types.h"

namespace CTRPluginFramework
{
    struct Position
    {
        u32     x;
        u32     y;
    };

    class Game
    {
    public:

        // Initialize properties
        static void     Initialize(void);

        // Properties

        /* Player */
        static u32      *Speed;             //Player Speed
        static u32      SpeedASM1;           //Player Speed (Normal) ASM Float Addr
        static u32      SpeedASM2;           //Player Speed (After Roll) ASM Float Addr
        static u32      Health;             //Player Health
        static u32      SP;                 //Player SP
        static u32      Money;              //Player Money
        static u32      *ModelSize;         //Pointer for Player model size
        static u32      RainbowProt;        //Player Rainbow Protction Addr

        static u32      Collisions;         //World Collisions
        static u32      EnemyHealth;        //Enemy Health
        static u32      DestructHealth;     //Destructables Health
        static u32      *Time;              //Address for Worlds time
        static u32      Oasislvl;           //Oasis Level
        static u32      ShopStock;          //
        static u32      ShopGuage;          //

        /* Inventory Items */
        static u32      Materials;          //
        static u32      Seeds;              //
        static u32      Slabs;              //
        static u32      HealItems;          //

        /* Chest Items */
        static u32      Weapons;            //
        static u32      Accessories;        //
        static u32      Turbans;            //
        static u32      Clothing;           //

        /* Stats */
        static u32      PendingExp;         //
        static u32      CompareExp;         //
        static u32      Level;              //Player Level Address
        static u32      MaxHP;              //Player Max HP Address
        static u32      Attack;             //Player Attack Address
        static u32      Defense;            //Player Defense Address
        static u32      Magicdef;           //Player Magic Defense Address
        static u32      Luck;               //Player Luck Address

        static u32      Loadscreen;         //
    };
}

#endif
