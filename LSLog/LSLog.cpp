// LSLog.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

BOOL APIENTRY DllMain(HMODULE hModule,
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);

		LPSTR cmdLine = GetCommandLineA();

		if (!strstr(cmdLine, "YOUR_SERVER_ID")) return FALSE; //validate serverID | put your serverID

		if (!GetModuleHandleA("lostsaga.exe")) return FALSE; //validate App Name


		if (GetFileAttributes("KRNprotectBypass.dll") == INVALID_FILE_ATTRIBUTES && GetFileAttributes("DiscordRPC.dll") == INVALID_FILE_ATTRIBUTES) return FALSE; //validate .dll

		LoadLibrary("KRNprotectBypass.dll");
		LoadLibrary("DiscordRPC.dll");

		break;
	}

    return TRUE;
}

