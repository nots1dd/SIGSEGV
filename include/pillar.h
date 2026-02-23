#pragma once

typedef struct Pillar {
    int width;
    int height;
    float x;
    float y;
} Pillar;

extern Pillar initPillar(float width, float height, float x, float y);
extern void displayPillar(Pillar* pillar);

