#pragma once

typedef struct Player {
    float x;
    float y;
    int width;
    int height;
    float speed;
} Player;

Player initPlayer(void);
void displayPlayer(Player player);
void handleMovement(Player* player);
void handleGravity(Player* player);
void updatePlayer(Player* player);
