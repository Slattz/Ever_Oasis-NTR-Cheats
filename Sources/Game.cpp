#include "Game.hpp"
#include "Offsets.hpp"
#include "Helpers.hpp"
#include "cheats.hpp"

namespace CTRPluginFramework
{
    // Initialize properties
    void    Game::Initialize(void) {
        Speed = reinterpret_cast<u32 *>(AutoRegion(OffsetToUsa(SPEED_ADDR), SPEED_ADDR)());
        SpeedASM1 = AutoRegion(SPEED_ASMADDR + 0x5C0, SPEED_ASMADDR)();
        SpeedASM2 = AutoRegion(SPEEDROLL_ASMADDR + 0x7C, SPEEDROLL_ASMADDR)();
        Health = AutoRegion(OffsetToUsa(HEALTH_ADDR), HEALTH_ADDR)();
        SP = AutoRegion(OffsetToUsa(SP_ADDR), SP_ADDR)();
        Money = AutoRegion(OffsetToUsa(MONEY_ADDR), MONEY_ADDR)();
        ModelSize = reinterpret_cast<u32 *>(AutoRegion(OffsetToUsa(MODELSIZE_ADDR), MODELSIZE_ADDR)());
        RainbowProt = AutoRegion(OffsetToUsa(RAINBOWPROT_ADDR), RAINBOWPROT_ADDR)();
        Collisions = AutoRegion(OffsetToUsa(COLLISIONS_ADDR), COLLISIONS_ADDR)();
        EnemyHealth = AutoRegion(OffsetToUsa(ENEMYHEALTH_ADDR), ENEMYHEALTH_ADDR)();
        DestructHealth = AutoRegion(OffsetToUsa(DESTRUCTHEALTH_ADDR), DESTRUCTHEALTH_ADDR)();
        Time = reinterpret_cast<u32 *>(AutoRegion(OffsetToUsa(TIME_ADDR), TIME_ADDR)());
        Oasislvl = AutoRegion(OffsetToUsa(OASISLVL_ADDR), OASISLVL_ADDR)();
        ShopStock = AutoRegion(OffsetToUsa(SHOPSTOCK_ADDR), SHOPSTOCK_ADDR)();
        ShopGuage = AutoRegion(OffsetToUsa(SHOPGUAGE_ADDR), SHOPGUAGE_ADDR)();
        Materials = AutoRegion(OffsetToUsa(MATERIALS_ADDR), MATERIALS_ADDR)();
        Seeds = AutoRegion(OffsetToUsa(SEEDS_ADDR), SEEDS_ADDR)();
        Slabs = AutoRegion(OffsetToUsa(SLABS_ADDR), SLABS_ADDR)();
        HealItems = AutoRegion(OffsetToUsa(HEALITEMS_ADDR), HEALITEMS_ADDR)();
        Weapons = AutoRegion(OffsetToUsa(WEAPONS_ADDR), WEAPONS_ADDR)();
        Accessories = AutoRegion(OffsetToUsa(ACCESSORIES_ADDR), ACCESSORIES_ADDR)();
        Turbans = AutoRegion(OffsetToUsa(TURBANS_ADDR), TURBANS_ADDR)();
        Clothing = AutoRegion(OffsetToUsa(CLOTHING_ADDR), CLOTHING_ADDR)();
        PendingExp = AutoRegion(OffsetToUsa(PENDINGEXP_ADDR), PENDINGEXP_ADDR)();
        CompareExp = AutoRegion(OffsetToUsa(COMPAREEXP_ADDR), COMPAREEXP_ADDR)();
        Level = AutoRegion(OffsetToUsa(LEVEL_ADDR), LEVEL_ADDR)();
        MaxHP = AutoRegion(OffsetToUsa(MAXHP_ADDR), MAXHP_ADDR)();
        Attack = AutoRegion(OffsetToUsa(ATTACK_ADDR), ATTACK_ADDR)();
        Defense = AutoRegion(OffsetToUsa(DEFENSE_ADDR), DEFENSE_ADDR)();
        Magicdef = AutoRegion(OffsetToUsa(MAGICDEF_ADDR), MAGICDEF_ADDR)();
        Luck = AutoRegion(OffsetToUsa(LUCK_ADDR), LUCK_ADDR)();
        Loadscreen = AutoRegion(OffsetToUsa(LOADSCREEN_ADDR), LOADSCREEN_ADDR)();
    }

    u32      *Game::Speed = nullptr;          
    u32      Game::SpeedASM1 = 0;          
    u32      Game::SpeedASM2 = 0;          
    u32      Game::Health = 0;         
    u32      Game::SP = 0;             
    u32      Game::Money = 0;          
    u32      *Game::ModelSize = nullptr;      
    u32      Game::RainbowProt = 0;    
    u32      Game::Collisions = 0;     
    u32      Game::EnemyHealth = 0;    
    u32      Game::DestructHealth = 0; 
    u32      *Game::Time = nullptr;           
    u32      Game::Oasislvl = 0;       
    u32      Game::ShopStock = 0;      
    u32      Game::ShopGuage = 0;      
    u32      Game::Materials = 0;      
    u32      Game::Seeds = 0;          
    u32      Game::Slabs = 0;          
    u32      Game::HealItems = 0;      
    u32      Game::Weapons = 0;        
    u32      Game::Accessories = 0;    
    u32      Game::Turbans = 0;        
    u32      Game::Clothing = 0;       
    u32      Game::PendingExp = 0;     
    u32      Game::CompareExp = 0;     
    u32      Game::Level = 0;          
    u32      Game::MaxHP = 0;          
    u32      Game::Attack = 0;         
    u32      Game::Defense = 0;        
    u32      Game::Magicdef = 0;       
    u32      Game::Luck = 0;           
    u32      Game::Loadscreen = 0;     
}
