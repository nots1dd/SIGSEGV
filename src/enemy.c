#include "enemy.h"
#include "raylib.h"
#include "helpers.h"
#include "pillar.h"
#include <stdio.h>

Enemy initEnemy(float x, float y, float speed, int width, int height, int type, int id) {
    Enemy enemy;
    enemy.x = x;
    enemy.y = y;
    enemy.speed = speed;
    enemy.width = width;
    enemy.height = height;
    enemy.type = type;
    enemy.id = id;
    return enemy;
}

void initEnemies(Enemies* enemies) {
    enemies->count = 0;
    enemies->capacity = 10;
    enemies->items = malloc(sizeof(Enemy) * enemies->capacity);
}

void addEnemy(Enemies* enemies, Enemy enemy) {
    if (enemies->count >= enemies->capacity) {
        enemies->capacity *= 2;
        enemies->items = realloc(enemies->items, sizeof(Enemy) * enemies->capacity);
    }
    enemies->items[enemies->count++] = enemy;
}

void generateEnemies(Enemies* enemies, Pillars* pillars) {
    for (size_t i = 0; i < pillars->count; i++) {
        float randomChance = (float)GetRandomValue(0, 100) / 100.0f;
        
        // If the random chance is greater than 0.25, skip spawning an enemy
        if (randomChance > 0.25f) {
            continue;
        }

        float x = (float)GetRandomValue(
            (int)pillars->items[i].x,
            (int)(pillars->items[i].x + pillars->items[i].width - 50)
        );

        float y = pillars->items[i].y - 50;

        int type = GetRandomValue(0, 1);

        float speed = (type == 0) ? 100.0f : 150.0f;

        Enemy newEnemy = initEnemy(x, y, speed, 50, 50, type, i);
        addEnemy(enemies, newEnemy);
    }
}

void displayEnemies(Enemies* enemies) {
    for (size_t i = 0; i < enemies->count; i++) {
        Enemy* e = &enemies->items[i];
        Color color = (e->type == 0) ? BLUE : GREEN;
        DrawRectangle((int)e->x, (int)e->y, e->width, e->height, color);
    }
}

void freeEnemy(Enemies *enemies, int id) {
    for (size_t i = 0; i < enemies->count; i++) {
        if (enemies->items[i].id == id) {
            // Swap the enemy to be removed with the last enemy
            enemies->items[i] = enemies->items[enemies->count - 1];
            enemies->count--;
            enemies->items = realloc(enemies->items, sizeof(Enemy) * enemies->count);
            
            // If realloc fails, handle memory allocation failure
            if (enemies->items == NULL && enemies->count > 0) {
                fprintf(stderr, "Memory allocation failed!\n");
                exit(1);
            }
            break;
        }
    }
}