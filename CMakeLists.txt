cmake_minimum_required(VERSION 3.10)
project(discord_game_example)
set(CMAKE_CXX_STANDARD 11)

add_library(discord_game_sdk SHARED IMPORTED)
set_target_properties(discord_game_sdk PROPERTIES
    IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/discord_game_sdk/lib/x86_64/discord_game_sdk.so
)

file(GLOB DISCORD_CPP_SOURCES ${CMAKE_SOURCE_DIR}/discord_game_sdk/cpp/*.cpp)

add_executable(example
    src/main.cpp
    ${DISCORD_CPP_SOURCES}
)

target_include_directories(example PRIVATE ${CMAKE_SOURCE_DIR}/discord_game_sdk/cpp)

target_link_libraries(example PRIVATE discord_game_sdk dl pthread)

# Ensure runtime can locate the SDK library
set_target_properties(example PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    BUILD_RPATH ${CMAKE_SOURCE_DIR}/discord_game_sdk/lib/x86_64
    INSTALL_RPATH ${CMAKE_SOURCE_DIR}/discord_game_sdk/lib/x86_64
)
