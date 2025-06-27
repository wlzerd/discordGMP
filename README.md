# Discord Game Integration Guide

This guide provides an overview of Discord's Embedded SDK and explains how to integrate it into a game project.

## Overview

Discord's Embedded SDK allows games to incorporate features such as Rich Presence, voice chat, and overlay capabilities directly into the game client. By integrating the SDK, developers can connect players and communities through Discord while keeping them engaged inside the game.

## Prerequisites

- A Discord developer account
- Access to your game's source code
- A compiler toolchain compatible with your target platforms

## Setup Instructions

1. **Download the SDK**
   - Visit the [Discord Embedded App SDK](https://discord.com/developers/docs/game-sdk/sdk-starter-guide) page and download the latest release for your operating system.

2. **Install Dependencies**
   - Windows users will need Visual Studio 2015 or later.
   - macOS users should have Xcode installed.
   - Linux users must install `gcc` or `clang` along with `cmake`.

3. **Create a Discord Application**
   - Go to the [Discord Developer Portal](https://discord.com/developers/applications) and create a new application.
   - Under the **OAuth2** settings, copy the **Client ID** and **Client Secret**. You will use these as your API keys.

4. **Extract the SDK**
   - Unzip the downloaded SDK into your project's directory (for example, `libs/discord`).

5. **Link the SDK in Your Build System**
   - Add the SDK's include directory to your compiler's include path and link the appropriate library files. The libraries are located inside the SDK's `lib` folder for each platform.

6. **Initialize the SDK in Code**
   - Basic initialization typically looks like this (in C/C++):

```c
#include "discord.h"

int main()
{
    DiscordEventHandlers handlers;
    memset(&handlers, 0, sizeof(handlers));
    Discord_Initialize("<your-client-id>", &handlers, 1, NULL);
    // ... your game loop ...
    Discord_Shutdown();
    return 0;
}
```

7. **Run the Game**
   - Build and run your game. If everything is configured correctly, you should see your game appear in Discord's Rich Presence.

## Documentation Links

- [Discord Game SDK Documentation](https://discord.com/developers/docs/game-sdk/sdk-starter-guide)
- [Discord Developer Portal](https://discord.com/developers/applications)

For more details, refer to the official documentation and examples provided in the SDK package.

