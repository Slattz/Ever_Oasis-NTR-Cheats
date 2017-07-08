#include "cheats.h"

u32		g_speed;
u32		g_collisions;
u32		g_health;
u32		g_sp;
u32		g_enemyhealth;
u32		g_destructhealth;
u32		g_rainbowprot;
u32		g_model;
u32		g_time;
u32		g_stats;
u32		g_money;
u32		g_oasislvl;
u32		g_shopstock;
u32		g_shopgauge;
u32		g_materials;
u32		g_seeds;
u32		g_slabs;
u32		g_healitems;
u32		g_weapons;
u32		g_accessory;
u32		g_turbans;
u32		g_clothes;
u32		g_rainbowprot;
u32		g_level;
u32		g_maxhp;
u32		g_attack;
u32		g_defense;
u32		g_magicdef;
u32		g_luck;
u32		g_loadscreen;

void    assign_region(u32 region)
{
	g_speed = SPEED_ADDR;
	g_collisions = COLLISIONS_ADDR;
	g_health = HEALTH_ADDR;
	g_sp = SP_ADDR;
	g_enemyhealth = ENEMYHEALTH_ADDR;
	g_destructhealth = DESTRUCTHEALTH_ADDR;
	g_model = APPEAR_ADDR;
	g_time = TIME_ADDR;
	g_money = MONEY_ADDR;
	g_oasislvl = OASISLVL_ADDR;
	g_shopstock = SHOPSTOCK_ADDR;
	g_shopgauge = SHOPGUAGE_ADDR;
	g_materials = MATERIALS_ADDR;
	g_seeds = SEEDS_ADDR;
	g_slabs = SLABS_ADDR;
	g_healitems = HEALITEMS_ADDR;
	g_weapons = WEAPONS_ADDR;
	g_accessory = ACCESSORIES_ADDR;
	g_turbans = TURBANS_ADDR;
	g_clothes = CLOTHING_ADDR;
	g_rainbowprot = RAINBOWPROT_ADDR;
	g_level = LEVEL_ADDR;
	g_maxhp = MAXHP_ADDR;
	g_attack = ATTACK_ADDR;
	g_defense = DEFENSE_ADDR;
	g_magicdef = MAGICDEF_ADDR;
	g_luck = LUCK_ADDR;
	g_loadscreen = LOADSCREEN_ADDR;
	
    switch (region)
    {
		case USA:
		g_speed += 0x1000;
		g_collisions += 0x1010;
		g_health += 0x1010;
		g_sp += 0x1010;
		g_enemyhealth += 0x1010;
		g_destructhealth += 0x1010;
		g_model += 0x1000;
		g_time += 0x1010;
		g_level += 0x1010;
		g_money = MONEY_ADDR;
		g_oasislvl = OASISLVL_ADDR;
		g_shopstock += 0x1010;
		g_shopgauge += 0x1010;
		g_materials += 0x1010;
		g_seeds += 0x1010;
		g_slabs += 0x1010;
		g_healitems += 0x1010;
		g_weapons += 0x1010;
		g_accessory += 0x1010;
		g_turbans += 0x1010;
		g_clothes += 0x1010;
		g_rainbowprot += 0x1004;
		g_level += 0x1010;
		g_maxhp += 0x1010;
		g_attack += 0x1010;
		g_defense += 0x1010;
		g_magicdef += 0x1010;
		g_luck += 0x1010;
		g_loadscreen += 0x1000;
		break;
		
		case JAP:
		//Future proofing for when JPN game is released.
		g_speed -= JAP_DIFFERENCE;
		g_collisions -= JAP_DIFFERENCE;
		g_health -= JAP_DIFFERENCE;
		g_sp -= JAP_DIFFERENCE;
		g_enemyhealth -= JAP_DIFFERENCE;
		g_destructhealth -= JAP_DIFFERENCE;
		g_model -= JAP_DIFFERENCE;
		g_time -= JAP_DIFFERENCE;
		g_level -= JAP_DIFFERENCE;
		g_money -= JAP_DIFFERENCE;
		g_oasislvl -= JAP_DIFFERENCE;
		g_materials -= JAP_DIFFERENCE;
		g_shopstock -= JAP_DIFFERENCE;
		g_shopgauge -= JAP_DIFFERENCE;
		g_seeds -= JAP_DIFFERENCE;
		g_slabs -= JAP_DIFFERENCE;
		g_healitems -= JAP_DIFFERENCE;
		g_weapons -= JAP_DIFFERENCE;
		g_materials -= JAP_DIFFERENCE;
		g_accessory -= JAP_DIFFERENCE;
		g_turbans -= JAP_DIFFERENCE;
		g_clothes -= JAP_DIFFERENCE;
		g_rainbowprot -= JAP_DIFFERENCE;
		g_level -= JAP_DIFFERENCE;
		g_maxhp -= JAP_DIFFERENCE;
		g_attack -= JAP_DIFFERENCE;
		g_defense -= JAP_DIFFERENCE;
		g_magicdef -= JAP_DIFFERENCE;
		g_luck -= JAP_DIFFERENCE;
		g_loadscreen -= JAP_DIFFERENCE;
		break;
    }
}

void	Speed(void)
{
	u32 speed_p;
	u32 fast = 0x3F000000;
	u32 orig = 0x3F800000;
	
	static bool btn = false;
	static bool toggle = false;

	if (is_pressed(BUTTON_R + BUTTON_DL) && !btn)
	{
		toggle = !toggle;
		btn = true;
	} 
	else if (!is_pressed(BUTTON_R + BUTTON_DL)) 
	{
		btn = false;
	}

	if (toggle) 
	{
		// cheat on
		speed_p = READU32(g_speed);
		if (speed_p != 0x0)
		{
			WRITEU32(speed_p + 0xB0, fast);
		}
	}

	else
	{
		// cheat off
		speed_p = READU32(g_speed);
		if (speed_p != 0x0)
		{
			WRITEU32(speed_p + 0xB0, orig);
		}
	}
}

void	Collisions(void)
{
	static bool btn = false;
	static bool toggle = false;

	if (is_pressed(BUTTON_R + BUTTON_DR) && !btn) 
	{
		toggle = !toggle;
		btn = true;
	} 
	else if (!is_pressed(BUTTON_R + BUTTON_DR))
	{
		btn = false;
	}

	if (toggle) 
	{
		// cheat on
		WRITEU32(g_collisions, 0x0);
	}
	else
	{
		// cheat off
		WRITEU32(g_collisions, 0x3F8020C5);
	}
}

void	infHealth(void)
{
    //u16 maxHP;
    //u16 rainbowProt;
	
	// Load Rainbow Protection amount if any
	//rainbowProt = READU16(g_rainbowprot);

	//maxHP = READU16(g_maxhp);
	
	WRITEU16(g_health, 999);
	//WRITEU16(0x32967DFC, maxHP + rainbowProt);
	
}

void	infSP(void)
{
	WRITEU16(g_sp, 999);
}

void    oneHitKill(void)
{
    u16 enemyMaxHP = 0; 

    // Iterate through 6 known slots, check if Max HP is > 1 and if so
    // set Max and Current HP to 1 for one-hit kill
    for (int i = 0; i < 6; i++) 
	{
        enemyMaxHP = READU16(g_enemyhealth + (i * 0x28));
		
        if (enemyMaxHP > 0x1) 
		{
            WRITEU16((g_enemyhealth + 0x2) + (i * 0x28), 0x1);
            WRITEU16(g_enemyhealth + (i * 0x28), 0x1);
        }
    }
}

void    oneHitDestructible(void)
{
    u16 destructableHP = 0;

    // Iterate through 29 known slots, check if current HP is > 1 and if so
    // set Current HP to 1 for one-hit destroy
    for (int i = 0; i < 29; i++)
	{
            destructableHP = READU16(g_destructhealth + (i * 0x38));
            if (destructableHP > 1)
            WRITEU16(g_destructhealth + (i * 0x38), 0x1);
    }
}

void	maxMoney(void)
{
	WRITEU32(g_money, 0x000F423F);
}

void	OasisLVL(void)
{
	if (READU8(g_oasislvl) <= 0x14) {
	WRITEU8(g_oasislvl, 0x14); }
}

void	ShopStocker(void)
{
	u16 diffs[] = 
	{
		0x0,
		0x1D0,
		0x2B8,
		0x89C,
		0x910,
		0xC3C,
		0xCB0,
	};

	for (int i = 0; i < 7; i++) 
	{
    WRITEU16(g_shopstock + diffs[i], 999);
    WRITEU16(g_shopstock + diffs[i] + 2, 999);
	}
}

void	QuestGauge(void)
{
	u16 diffs[] = 
	{
		0x0,
		0x1D0,
		0x2B8,
		0x89C,
		0x910,
		0xC3C,
		0xCB0,
	};

	for (int i = 0; i < 7; i++) 
	{
    WRITEU16(g_shopgauge + diffs[i], 0xFFFF);
	}
}

void	allMaterials(void)
{
    for (int i = 0; i < 217; i++) 
	{
        WRITEU8(g_materials + (i * 8), 0x63);
    }
}

void	allSeeds(void)
{
    for (int i = 0; i < 51; i++) 
	{
        WRITEU8(g_seeds + (i * 8), 0x32);
    }
}

void	allSlabs(void)
{
    for (int i = 0; i < 18; i++) 
	{
        WRITEU8(g_slabs + (i * 8), 0x1);
    }
}

void	allHealingItems(void)
{
    for (int i = 0; i < 12; i++) 
	{
        WRITEU8(g_healitems + (i * 8), 0x63);
    }
}

void	allWeapons(void)
{
    for (int i = 0; i < 128; i++) 
	{
        WRITEU8(g_weapons + (i * 8), 0x32);
    }
}

void	allAccessory(void)
{
    for (int i = 0; i < 50; i++) 
	{
        WRITEU8(g_accessory + (i * 8), 0x32);
    }
}

void	allTurbans(void)
{
    for (int i = 0; i < 8; i++) 
	{
        WRITEU8(g_turbans + (i * 8), 0x32);
    }
}

void	allClothes(void)
{
    for (int i = 0; i < 81; i++) 
	{
        WRITEU8(g_clothes + (i * 8), 0x32);
    }
}

//Stats

void	maxLVL(void)
{
	WRITEU8(g_level, 0x1E);
}

void	maxHP(void)
{
	WRITEU16(g_maxhp, 999);
}

void	maxAttack(void)
{
	WRITEU8(g_attack, 99);
}

void	maxDefense(void)
{
	WRITEU8(g_defense, 99);
}

void	maxMagicDef(void)
{
	WRITEU8(g_magicdef, 99);
}

void	maxLuck(void)
{
	WRITEU8(g_luck, 99);
}

//Model Modifier

void	model_general(u32 size1, u32 size2, u32 size3)
{
	u32 point;
	static bool btn = false;
	static bool toggle = false;

	if (is_pressed(BUTTON_L + BUTTON_DR) && !btn) 
	{
		toggle = !toggle;
		btn = true;
	} 
	
	else if (!is_pressed(BUTTON_L + BUTTON_DR))
	{
		btn = false;
	}

if (toggle) 
{
	//cheat on
    point = READU32(g_model);
	if (point != 0x0)
	{
		WRITEU32(point + 0xBC, size1);
		WRITEU32(point + 0xC0, size2);
		WRITEU32(point + 0xC4, size3);
	}
} 
else 
{
    // cheat off
	point = READU32(g_model);
	if (point != 0x0)
	{
		WRITEU32(point + 0xBC, 0x3F800000);
		WRITEU32(point + 0xC0, 0x3F800000);
		WRITEU32(point + 0xC4, 0x3F800000);
	}
}}

void	invisi(void)
{
	model_general(0x0, 0x0, 0x0);
}

void	tiny(void)
{
	u32 fl = 0x3E800000;
	model_general(fl, fl, fl);
}

void	giant(void)
{
	u32 fl = 0x40400000;
	model_general(fl, fl, fl);
}

void	paper1(void)
{
	u32 fl = 0x3E000000;
	u32 norm = 0x3F800000;
	model_general(fl, norm, norm);
}

void	paper2(void)
{
	u32 fl = 0x3E000000;
	u32 norm = 0x3F800000;
	model_general(norm, fl, norm);
}



//Time Modifier

bool    isDay(void)
{
	u32		time_p;
    u8 currentTime;
	
	time_p = READU32(g_time);
    currentTime = READU8(time_p + 0x31F);
    if ((currentTime) >= 6 && (currentTime < 18))
        return true;
    else
        return false;
}

void    changeTime(void)
{
    static u16 changedTime;
    static bool timePending = false;
    u8 loadingScreen = 0;

    if (is_pressed(BUTTON_R + BUTTON_DU) && !timePending)
	{
        if (isDay())
            changedTime = 6 + (15*0x100);
        else
            changedTime = 5 + (45*0x100);
        timePending = true;
    }

    if (is_pressed(BUTTON_R + BUTTON_DD) && !timePending)
	{
        if (isDay())
            changedTime = 17 + (45*0x100);
        else
            changedTime = 18 + (15*0x100);
        timePending = true;
    }

    if (is_pressed(BUTTON_R + BUTTON_DL) && timePending)
        timePending = false;

    if (timePending) 
	{
        WRITEU16(0x328106C7, changedTime);
        loadingScreen = READU8(g_loadscreen);
		if (loadingScreen == 0x5) 
		{
            timePending = false;
            return;
        }
    }

}

//TODO: Controllable Time Modifier
/*
void    set_current_time(u16 value)
{
	u32		time_p;
	
	time_p = READU32(g_time);
	
    WRITEU16(time_p + 0x31F, value);
}

u16      get_current_time(void)
{
    u16     current_time;
	u32		time_p;

    time_p = READU32(g_time);
	current_time = READU16(time_p + 0x31F);
    return (current_time);
}

void    update_time_entry(void)
{
    u16 current_time;

    current_time = get_current_time();
	pending_time = get_pending_time();
    xsprintf(time_level_buffer, "Current Hour: %d", current_time);
    xsprintf(Ptime_level_buffer, "Pending Time Change: %d", pending_time);
}

void    time_day(void)
{
    set_current_time(0x000C);
    update_time_entry();
}

void    time_night(void)
{
    set_current_time(0x0017);
    update_time_entry();
}

void    increase_time(void)
{
    u16  current_time;

    current_time = get_current_time();
    if (current_time < 0x0017)
        current_time++;
    else
        current_time = 0;
    set_current_time(current_time);
    update_time_entry();
    disableCheat(g_increase_menu_index1);
	disableCheat(g_increase_menu_index2);
}

void    decrease_time(void)
{
    u16  current_time;

    current_time = get_current_time();
    if (current_time > 0)
        current_time--;
    else
        current_time = 0x0018;
    set_current_time(current_time);
    update_time_entry();
    disableCheat(g_decrease_menu_index1);
    disableCheat(g_decrease_menu_index2);
}
*/

void	Fly(void)
{
	u32	point;
	
	if (is_pressed(BUTTON_L + BUTTON_DR))
	{
		point = READU32(g_speed - 0x4);
		if (point != 0)
		{
			WRITEU32(point + 0x24, 0x44000000);
		}
	}
	
	if (is_pressed(BUTTON_L + BUTTON_DL))
	{
		point = READU32(g_speed - 0x4);
		if (point != 0)
		{
			WRITEU32(point + 0x24, 0x42000000);
		}
	}
	
	if (is_pressed(BUTTON_R))
	{
		point = READU32(g_speed);
		if (point != 0)
		{
			WRITEU16(point + 0xD, 0x0134);
		}
	}
	
	if (is_pressed(BUTTON_B))
	{
		point = READU32(g_speed);
		if (point != 0)
		{
			WRITEU16(point + 0xD, 0x0001);
		}
	}
}