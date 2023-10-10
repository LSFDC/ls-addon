// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "string"
#include "DiscordSDK/include/discord_register.h"
#include "DiscordSDK/include/discord_rpc.h"
#include "chrono"
#include <thread>

static const char* APPLICATION_ID = ""; //https://discord.com/developers/applications


void InitDiscordRPC() {
	DiscordEventHandlers handlers;
	memset(&handlers, 0, sizeof(handlers));
	Discord_Initialize(APPLICATION_ID, &handlers, 1, NULL);

	// Get the start time
	auto start = std::chrono::high_resolution_clock::now();

	// Update the state every second
	while (true) {
		DiscordRichPresence discordPresence;
		memset(&discordPresence, 0, sizeof(discordPresence));

		// Calculate the time elapsed
		auto now = std::chrono::high_resolution_clock::now();

		auto elapsed = std::chrono::duration_cast<std::chrono::minutes>(now - start);
		int minutes = elapsed.count();

		if (minutes == 0) {
			discordPresence.state = "Just started playing";
		}
		else if (minutes > 1440) {
			int days = minutes / 1440;
			minutes = minutes % 1440;
			discordPresence.state = ("Playing for " + std::to_string(days) + " days " + std::to_string(minutes / 60) + " hours " + std::to_string(minutes % 60) + " minutes").c_str();
		}
		else {
			discordPresence.state = (minutes == 60 || minutes > 60 ? ("Playing for " + std::to_string(minutes / 60) + " hours " + std::to_string(minutes % 60) + " minutes").c_str() : ("Playing for " + std::to_string(minutes) + " minutes").c_str());
		}

		discordPresence.details = "";
		discordPresence.startTimestamp = NULL;
		discordPresence.endTimestamp = NULL;
		discordPresence.largeImageKey = "rpc_logo";
		discordPresence.largeImageText = "";
		discordPresence.smallImageKey = "rpc_logo";
		discordPresence.smallImageText = "Private Server";
		

		Discord_UpdatePresence(&discordPresence);

		std::this_thread::sleep_for(std::chrono::seconds(1));

	}
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)InitDiscordRPC, NULL, NULL, NULL);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

