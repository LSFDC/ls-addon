#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files

#define _WIN32_WINNT   0x501              //WM_MOUSEWHEEL 상수를 사용하기 위해 define하였음. winuser.h에 보면 #if (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)
#define _WIN32_WINDOWS 0x501              //이렇게 WM_MOUSEWHEEL사용을 제한하고 있다. 혹은 WM_MOUSEWHEEL은 0x020A이므로 바로 사용해도 상관없음.

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE


#define FONT_SIZE_12  0.60f

#include <Windows.h>
#include <iostream>

#include <string>

#include "DiscordSDK/include/discord_rpc.h"
#include "DiscordSDK/include/discord_register.h"
