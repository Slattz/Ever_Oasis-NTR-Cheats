#ifndef CHEATS_H
#define CHEATS_H

#include "../Includes/plugin.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define     ADD32(addr, value)         			*(u32 *)addr += value
#define     SUB32(addr, value)         			*(u32 *)addr -= value
#define     ADD64(addr, value)                  *(vs64 *)addr += value
#define     SUB64(addr, value)                  *(vs64 *)addr -= value
#define		ADD16(addr, value)					*(u16 *)addr += value
#define		SUB16(addr, value)					*(u16 *)addr -= value
#define     ADDTOFLOAT(addr, add_value)         *(float *)addr += (float)add_value
#define     SUBTOFLOAT(addr, sub_value)         *(float *)addr -= (float)sub_value

/*
 EUR Addresses
*/

#define		SPEED_ADDR				0x5D9FAC
#define		COLLISIONS_ADDR			0x5DB46C
#define		HEALTH_ADDR				0x5E8930
#define		SP_ADDR					0x5E8948
#define		ENEMYHEALTH_ADDR		0x610E0C
#define		DESTRUCTHEALTH_ADDR		0x611BD4
#define		RAINBOWPROT_ADDR		0x5DAFAC
#define		APPEAR_ADDR				0x5D9FA8
#define		TIME_ADDR				0x5DA9A0
#define		MONEY_ADDR				0x326995A0
#define		OASISLVL_ADDR			0x3002A040
#define		SHOPSTOCK_ADDR			0x5E8D56
#define		SHOPGUAGE_ADDR			0x5E8D30

//Inventory
#define		MATERIALS_ADDR			0x615EF0
#define		SEEDS_ADDR				0x616E48
#define		SLABS_ADDR				0x616FE0
#define		HEALITEMS_ADDR			0x617070

//Chest
#define		WEAPONS_ADDR			0x6165A8
#define		ACCESSORIES_ADDR		0x615C60
#define		TURBANS_ADDR			0x615C00
#define		CLOTHING_ADDR			0x6159C0

//Stats
#define		PENDINGEXP_ADDR			0x5E8924
#define		COMPAREEXP_ADDR			0x5E8928
#define		LEVEL_ADDR				0x5E895C
#define		MAXHP_ADDR				0x5E8932
#define		ATTACK_ADDR				0x5F0140
#define		DEFENSE_ADDR			0x5F0142
#define		MAGICDEF_ADDR			0x5F0144
#define		LUCK_ADDR				0x5F0146

#define		LOADSCREEN_ADDR			0x5D7364



//#define		USA_DIFFERENCE			0x0 - No common difference atm
#define		JAP_DIFFERENCE			0x0


enum
{
    EUR = 0,
    USA,
    JAP
};

/*
Globals
*/

//TODO: Controllable Time Modifier

/*
extern char    time_level_buffer[40];
extern char    Ptime_level_buffer[40];
extern int     g_increase_menu_index1;
extern int     g_decrease_menu_index1;
extern int     g_increase_menu_index2;
extern int     g_decrease_menu_index2;
*/
 
/*
Cheats
*/

void    disable_entry(int identifier);
void    assign_region(u32 region);

void	Speed(void);
void	Collisions(void);
void	infHealth(void);
void	infSP(void);
void    oneHitKill(void);
void    oneHitDestructible(void);
void	maxLVL(void);
void	maxMoney(void);
void	OasisLVL(void);
void	ShopStocker(void);
void	QuestGauge(void);
void	Fly(void);

//Inventory
void	allMaterials(void);
void	allSeeds(void);
void	allSlabs(void);
void	allHealingItems(void);

//Chest
void	allWeapons(void);
void	allAccessory(void);
void	allTurbans(void);
void	allClothes(void);

//Stats
void	maxLVL(void);
void	maxHP(void);
void	maxAttack(void);
void	maxDefense(void);
void	maxMagicDef(void);
void	maxLuck(void);

//Model
void	invisi(void);
void	tiny(void);
void	giant(void);
void	paper1(void);
void	paper2(void);

//Time
void    changeTime(void);

//TODO: Controllable Time Modifier

/*
void    time_day(void);
void    time_night(void);
void    increase_time(void);
void    decrease_time(void);
*/

#endif
