#pragma once
#include "pillar.h"

typedef struct Player {
    float x;
    float y;
    float lastX;
    float lastY;
    int width;
    int height;
    float acceleration;
    float friction;
    float velocityX;
    float velocityY;
    float maxSpeed;
    float jumpStrength;
} Player;

Player initPlayer(void);
void displayPlayer(Player player);
void handleInput(Player* player);
void handleMovement(Player* player, Pillar* pillar);
void handleJump(Player* player);
void handleGravity(Player* player);
void updatePlayer(Player* player, Pillar* pillar);
