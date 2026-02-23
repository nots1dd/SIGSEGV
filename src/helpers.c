#include "helpers.h"
#include "pillar.h"
#include <stdio.h>

bool isColliding(float x1, float y1, int w1, int h1, float x2, float y2, int w2, int h2) {
    return (x1 < x2 + w2 &&
            x1 + w1 > x2 &&
            y1 < y2 + h2 &&
            y1 + h1 > y2);
}

void pushBackPillar(Pillars *pillars, float width, float height, float x, float y) {
    if (pillars->count >= pillars->capacity) {
        if (pillars->capacity == 0) {
            pillars->capacity = 1;
        }
        pillars->capacity *= 2;
        
        pillars->items = realloc(pillars->items, pillars->capacity * sizeof(Pillar));
        if (pillars->items == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(1);
        }
    }

    pillars->items[pillars->count++] = initPillar(width, height, x, y);
}