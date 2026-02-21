#include "player.h"
#include "globals.h"
#include "raylib.h"

void displayPlayer(Player player) {
    DrawRectangle(player.x, player.y, player.width, player.height, RED);
}

void updatePlayer(Player* player) {
    displayPlayer(*player);
}

Player initPlayer(void) {
    Player player;
    player.x = 100;
    player.y = 100;
    player.width = 50;
    player.height = 50;
    player.speed = 200.0f;
    return player;
}