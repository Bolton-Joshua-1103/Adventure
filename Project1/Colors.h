#pragma once
#include <Windows.h>
// Text collors  https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c

   //Name            FG  BG
   //Black           30  40
   //Red             31  41
   //Green           32  42
   //Yellow          33  43
   //Blue            34  44
   //Magenta         35  45
   //Cyan            36  46
   //White           37  47
   //Bright Black    90  100
   //Bright Red      91  101
   //Bright Green    92  102
   //Bright Yellow   93  103
   //Bright Blue     94  104
   //Bright Magenta  95  105
   //Bright Cyan     96  106
   //Bright White    97  107

#define ColorResetMacro  "\033[0m"
#define BrightRedMacro "\x1B[91m"
#define BrightBlueMacro "\x1B[94m"
#define BrightGreenMacro "\x1B[92m"
#define BrightBlackMacro "\x1B[90m"
#define BrightMagentaMacro "\x1B[95m"
#define BrightYelloMacro "\x1B[93m"

///
#define BGBrightBlueMacro "\x1B[104m"
#define BGBrightYellowMacro "\x1B[103m"
#define BGBrightGreenMacro "\x1B[102m"
#define BGDarkGreenMacro "\x1B[42m"
