#pragma once

typedef struct Player {
    int x;
    int y;
    int width;
    int height;
    float speed;
} Player;

Player initPlayer(void);
void displayPlayer(Player player);
void movePlayer(Player* player);
void updatePlayer(Player* player);
