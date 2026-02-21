#include "player.h"
#include "globals.h"
#include "raylib.h"

void displayPlayer(Player player) {
    DrawRectangle((int)player.x, (int)player.y, player.width, player.height, RED);
}

void handleInput(Player* player) {
    if (IsKeyDown(KEY_D)) {
        player->velocityX += player->acceleration * deltaTime;
    }
    if (IsKeyDown(KEY_A)) {
        player->velocityX -= player->acceleration * deltaTime;
    }
}

void handleMovement(Player* player) {
    // Apply velocity to position
    player->x += player->velocityX * deltaTime;
    player->y += player->velocityY * deltaTime;

    // Clamp velocity to max speed
    if (player->velocityX > player->maxSpeed) {
        player->velocityX = player->maxSpeed;
    } else if (player->velocityX < -player->maxSpeed) {
        player->velocityX = -player->maxSpeed;
    }
}

void handleGravity(Player* player) {
    player->y += gravity * deltaTime;
}

void updatePlayer(Player* player) {
    handleInput(player);
    handleMovement(player);
    handleGravity(player);
    displayPlayer(*player);
}

Player initPlayer(void) {
    Player player;
    player.x = 100.0f;
    player.y = 100.0f;
    player.width = 100;
    player.height = 100;
    player.velocityX = 0.0f;
    player.velocityY = 0.0f;
    player.acceleration = 10.0f;
    player.maxSpeed = 500.0f;
    return player;
}