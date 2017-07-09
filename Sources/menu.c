#include "cheats.h"
#include "notes.h"

#define ENTRY_COUNT 300

typedef struct s_menu
{
    int         count;
    int         status;
    u32         f[ENTRY_COUNT];
    u32         s[ENTRY_COUNT];
    int         a[ENTRY_COUNT];
    const char  *t[ENTRY_COUNT];
    const char  *n[ENTRY_COUNT];
    void        (*fp[ENTRY_COUNT])();
}             t_menu;


typedef void    (*FuncPointer)(void);
extern t_menu menu;



void    new_super_unselectable_entry(char *str, FuncPointer function)
{
    int index;

    index = menu.count;
    if (index >= 300)
        return;
    new_unselectable_entry(str);
    menu.f[index] |= BIT(0) | BIT(1);
    menu.fp[index] = function;
}

char	*builder_name = "Slattz, Scotline & AnalogMan";

void with_note_common(const char *name, const char *note, void (*cheatfunction)(void), int type)
{
    int     index;

    if (type == 0)
        index = new_entry((char *)name, cheatfunction);
    else if (type == 1)
        index = new_radio_entry((char *)name, cheatfunction);
    else if (type == 2)
        index = new_spoiler((char *)name);
    else return;
    set_note(note, index);
}

inline void new_entry_with_note(const char *name, const char *note, void (*cheatfunction)(void))
{
    with_note_common(name, note, cheatfunction, 0);
}

inline void new_radio_entry_with_note(const char *name, const char *note, void (*cheatfunction)(void))
{
    with_note_common(name, note, cheatfunction, 1);
}

inline void new_spoiler_with_note(const char *name, const char *note)
{
    with_note_common(name, note, NULL, 2);
}

//TODO: Controllable Time Modifier

/*
char    time_level_buffer[40] = "Current Hour: XX";
char    Ptime_level_buffer[40] = "Pending Time Change: XX";
int     g_increase_menu_index1 = 0;
int     g_decrease_menu_index1 = 0;
int     g_increase_menu_index2 = 0;
int     g_decrease_menu_index2 = 0;
*/

static inline void  smenu(void)
{
	new_spoiler("Important Info");
	new_unselectable_entry("-Press (Y) on an entry to");
    new_unselectable_entry(" view the corresponding note.");
	new_line();
	new_unselectable_entry("-Some cheats require you to");
	new_unselectable_entry(" reload the area before they");
	new_unselectable_entry(" take effect.");
	new_unselectable_entry(" Leaving and returning will work.");
	exit_spoiler();
	new_separator();
	new_entry_with_note("Faster Speed", speednote, Speed);
	new_entry_with_note("Toggle Collisions", collisionsnote, Collisions);
	new_entry_with_note("Max Dewadems", moneynote, maxMoney);
	new_entry_with_note("Fly", flynote, Fly);
	
	new_spoiler("Battle Cheats");
	{
		new_entry_with_note("Infinite HP", infhealthnote, infHealth);
		new_entry_with_note("Infinite SP", infspnote, infSP);
		new_entry_with_note("One Hit Kill Enemies", OHKillnote, oneHitKill);
		new_entry_with_note("One Hit Kill Destructibles", OHKillDnote, oneHitDestructible);
	}
	exit_spoiler();
	
	new_spoiler("Item Codes");
		new_spoiler("Inventory");
			new_entry_with_note("All Materials", matenote, allMaterials);
			new_entry_with_note("All Garden Seeds", seednote, allSeeds);
			new_entry_with_note("All Slabs", slabsnote, allSlabs);
			new_entry_with_note("All Healing Items", healitemnote, allHealingItems);
		exit_spoiler();
		new_spoiler("Chest");
			new_entry_with_note("All Weapons", weaponnote, allWeapons);
			new_entry_with_note("All Turbans", turbannote, allTurbans);
			new_entry_with_note("All Accessories", accessorynote, allAccessory);
			new_entry_with_note("All Clothes", clothnote, allClothes);
		exit_spoiler();
		new_entry_with_note("All Stores Stocked x999", shopstocknote, ShopStocker);
		new_entry_with_note("Max Stores Quest EXP Gauge", shopgaugenote, QuestGauge);
	exit_spoiler();
	
	new_spoiler("Stat Codes");
		new_entry_with_note("Max Player Level", levelnote, maxLVL);
		new_entry("Max Player HP", maxHP);
		new_entry("Max Attack", maxAttack);
		new_entry("Max Defense", maxDefense);
		new_entry("Max Magic Defense", maxMagicDef);
		new_entry("Max Luck", maxLuck);
	exit_spoiler();
	
    new_spoiler("Time Modifier");
	//TODO: Controllable Time Modifier

/*
        new_unselectable_entry(time_level_buffer);
		new_unselectable_entry(Ptime_level_buffer);
		g_increase_menu_index1 = new_entry("Hour + 1", increase_time);
		g_decrease_menu_index1 = new_entry("Hour - 1", decrease_time);
		new_radio_entry_with_note("Change Time To Day", timedaynote, time_day);
		new_radio_entry_with_note("Change Time To Night", timenightnote, time_night);
*/
	new_entry_with_note("Time Changer", timenote, changeTime);
    exit_spoiler();
	
    new_spoiler_with_note("Model Mods", modelnote);
        new_radio_entry_with_note("Invisible Character", invisinote, invisi);
        new_radio_entry_with_note("Tiny Character", tinynote, tiny);
        new_radio_entry_with_note("Giant Character", giantnote, giant);
		new_radio_entry_with_note("Flat Character", papernote, paper1);
        new_radio_entry_with_note("Paper Character", papernote, paper2);
    exit_spoiler();
	
	new_spoiler("Expiremental");
	new_unselectable_entry("These cheats may cause issues");
	new_unselectable_entry("with certain aspects of the");
	new_unselectable_entry("game. Take caution and make a");
	new_unselectable_entry("save backup just in case.");
	new_separator();
	new_entry_with_note("Max Oasis Size", oasisnote, OasisLVL);
	exit_spoiler();



}

void    my_menus(void)
{
    u32 tid;
    
    set_hid_address(0x10002000); //This is in order to unlock the advanced HID capabilities such as Touchscreen and the stick (No N3DS hid for the moment)
    tid = get_tid_low();
	/*
	EUR: 00040000001A4900
	USA: 00040000001A4800
	JPN:
	*/
	
    if (tid == 0x1a4900)
    {
		assign_region(EUR);
		new_unselectable_entry("E-Oasis NTR Cheats EUR v1.2.1");
    }
	
	else if (tid == 0x1A4800)
    {
		assign_region(USA);
		new_unselectable_entry("E-Oasis NTR Cheats USA v1.2.1");
    }
	
	else if (tid == 0x1a0000)
    {
		//assign_region(JAP);
		new_unselectable_entry("E-Oasis NTR Cheats JPN v1.2.1");
		new_unselectable_entry("JPN is currently unsupported!");
		new_unselectable_entry("It will be in the future!");
		return;
    }
	
	
	else
	{
		new_unselectable_entry("You're Using An Incorrect TitleID!");			
		new_unselectable_entry("This plugin only supports the");
		new_unselectable_entry("Following TitleIDs:");
		new_unselectable_entry("00040000001A4900 (EUR)");
		new_unselectable_entry("00040000001ab800 (USA)");
		new_unselectable_entry("00040000001a0000 (JAP)");
		
        return;
    }
    smenu();
}