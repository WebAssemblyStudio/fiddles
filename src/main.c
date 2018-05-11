#define WASM_EXPORT __attribute__((visibility("default")))

#include "sleepy_discord/sleepy_discord.h"

class myClientClass : public SleepyDiscord::DiscordClient {
public:
	using SleepyDiscord::DiscordClient::DiscordClient;
	void onMessage(SleepyDiscord::Message message) {
		if (message.startsWith("whcg hello"))
			sendMessage(message.channelID, "Hello " + message.author.username);
	}
};

WASM_EXPORT
int main() {
	myClientClass client("PLACE YOUR TOKEN HERE", USER_CONTROLED_THREADS);
	client.run();
  return 0;
}
