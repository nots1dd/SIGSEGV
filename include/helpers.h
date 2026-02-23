#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include "pillar.h"

bool isColliding(float x1, float y1, int w1, int h1, float x2, float y2, int w2, int h2);

typedef struct {
    Pillar *items;
    size_t count;
    size_t capacity;
} Pillars;

extern void pushBackPillar(Pillars* pillars, float width, float height, float x, float y);