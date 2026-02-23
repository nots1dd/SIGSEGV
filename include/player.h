#pragma once
#include <stdbool.h>
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
    bool isGrounded;
} Player;

Player initPlayer(void);
void displayPlayer(Player player);
void handleMovement(Player* player);
void handlePlayerCollisions(Player* player, Pillars* pillars);
void handleJump(Player* player);
void handlePlayerGravity(Player* player);
void updatePlayer(Player* player, Pillars* pillars);
