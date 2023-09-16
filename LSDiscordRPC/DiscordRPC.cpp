#include "DiscordRPC.h"

std::time_t CurrentTime = std::time(0);

const char* APP_ID;

void Init(const char* APPLICATION_ID)
{
	APP_ID = APPLICATION_ID;
}

void UpdateState(const char* szState, const char* szDetil)
{
	DiscordEventHandlers handlers;
	memset(&handlers, 0, sizeof(handlers));
	Discord_Initialize(APP_ID, &handlers, 1, NULL);
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));

	discordPresence.state = szDetil;
	discordPresence.details = szDetil;
	discordPresence.startTimestamp = CurrentTime;
	discordPresence.endTimestamp = NULL;
	discordPresence.largeImageKey = "yourimages";
	discordPresence.largeImageText = "Lost Saga";
	discordPresence.smallImageKey = "yourimages";
	discordPresence.smallImageText = "Private Server";
	discordPresence.partySize = 1;
	discordPresence.partyMax = 5;

	Discord_UpdatePresence(&discordPresence);
}
