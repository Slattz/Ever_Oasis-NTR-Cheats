#include "cheats.hpp"

namespace CTRPluginFramework
{
    /* Time Modifier */

    static bool isDay(void)
    {
        u8 currentTime = 0;

        Process::Read8(*Game::Time + 0x31F, currentTime);
        if ((currentTime >= 6) && (currentTime < 18))
            return true;
        else
            return false;
    }

    void changeTime(MenuEntry *entry)
    {
        static u16 changedTime;
        static bool timePending = false;
        u8 loadingScreen = 0;

        if (Controller::IsKeysDown(R + DPadUp) && !timePending)
        {
            if (isDay())
                changedTime = 6 + (15 * 0x100);
            else
                changedTime = 5 + (45 * 0x100);
            timePending = true;
        }

        if (Controller::IsKeysDown(R + DPadDown) && !timePending)
        {
            if (isDay())
                changedTime = 17 + (45 * 0x100);
            else
                changedTime = 18 + (15 * 0x100);
            timePending = true;
        }

        if (Controller::IsKeysDown(R + DPadLeft) && timePending)
            timePending = false;

        if (timePending)
        {
            Process::Write16(0x328106C7, changedTime);
            Process::Read8(Game::Loadscreen, loadingScreen);
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
} // namespace CTRPluginFramework
