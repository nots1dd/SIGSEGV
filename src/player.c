#include "player.h"
#include "globals.h"
#include "raylib.h"

#define PLAYER_SIZE 100 // Temporary player size, can be changed later

void displayPlayer(void) {
    DrawRectangle(GetScreenWidth() / 2, GetScreenHeight() /2, PLAYER_SIZE, PLAYER_SIZE, RED);
}

void updatePlayer(void) {
    displayPlayer();
}

void initPlayer(void) {
    // Initialize player properties here if needed
}
