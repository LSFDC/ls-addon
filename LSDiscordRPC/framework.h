#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files

#define _WIN32_WINNT   0x501              //WM_MOUSEWHEEL ����� ����ϱ� ���� define�Ͽ���. winuser.h�� ���� #if (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)
#define _WIN32_WINDOWS 0x501              //�̷��� WM_MOUSEWHEEL����� �����ϰ� �ִ�. Ȥ�� WM_MOUSEWHEEL�� 0x020A�̹Ƿ� �ٷ� ����ص� �������.

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE


#define FONT_SIZE_12  0.60f

#include <Windows.h>
#include <iostream>

#include <string>

#include "DiscordSDK/include/discord_rpc.h"
#include "DiscordSDK/include/discord_register.h"
