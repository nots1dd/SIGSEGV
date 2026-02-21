#pragma once

void initPlayer(void);
void displayPlayer(void);
void updatePlayer(void);

typedef struct Player {
    int x;
    int y;
    int width;
    int height;
    float speed;
} Player;
