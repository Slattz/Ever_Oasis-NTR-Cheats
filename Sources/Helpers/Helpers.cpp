#include "cheats.hpp"

namespace CTRPluginFramework
{
    /* Convert EUR offsets to USA */
    u32     OffsetToUsa(u32 offset) {
        u16 off = offset >> 16;
        u32 x5D = offset >> 12;

        if (off >= 0x3000 && off < 0x4000)
            return offset;

        else if (off == 0x5D) {
            if (x5D >= 0x5DA && x5D <= 0x5DF) {
                return offset + 0x1010; }

            else if (x5D >= 0x5D0 && x5D <= 0x5D9) {
                return offset + 0x1000; }
        }

        else if (off >= 0x5E && off <= 0x61)
            return offset + 0x1010;

        return offset;
    }
}