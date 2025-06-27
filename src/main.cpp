#include <iostream>
#include <memory>
#include <cstdint>
#include "discord.h"

int main() {
    // TODO: replace with your actual Discord application Client ID
    const long long clientId = 0;

    discord::Core* core{};
    auto result = discord::Core::Create(clientId, DiscordCreateFlags_Default, &core);
    if (result != discord::Result::Ok) {
        std::cerr << "Discord init failed: " << static_cast<int>(result) << std::endl;
        return -1;
    }

    std::unique_ptr<discord::Core> discordCore{core};
    std::cout << "Discord SDK initialized" << std::endl;

    // Run one round of callbacks for demonstration purposes
    discordCore->RunCallbacks();

    return 0;
}
