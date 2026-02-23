#include "pillar.h"
#include "raylib.h"

Pillar initPillar(float width, float height, float x, float y) {
    Pillar pillar;
    pillar.width = width;
    pillar.height = height;
    pillar.x = x;
    pillar.y = y;
    return pillar;
}

void displayPillar(Pillar *pillar) {
    DrawRectangle(pillar->x, pillar->y, pillar->width, pillar->height, GRAY);
}