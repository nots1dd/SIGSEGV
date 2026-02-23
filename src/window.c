#include "window.h"
#include "globals.h"
#include "player.h"
#include "pillar.h"

#define STARTING_PILLAR_WIDTH 850.0f
#define STARTING_PILLAR_HEIGHT 850.0f
#define STARTING_PILLAR_X -200.0f
#define STARTING_PILLAR_Y 500.0f

void initWindow(void) {
    int monitor = GetCurrentMonitor();
    int width   = GetMonitorWidth(monitor);
    int height  = GetMonitorHeight(monitor);

    InitWindow(width, height, "SIGSEGV");
}

void displayWindow(void) {
    Player player = initPlayer();
    Pillar pillar = initPillar(STARTING_PILLAR_WIDTH, STARTING_PILLAR_HEIGHT, STARTING_PILLAR_X, STARTING_PILLAR_Y); // Initial pillar where the player would start on
    Camera2D camera = {0};
    int monitor = GetCurrentMonitor();
    int screenWidth = GetMonitorWidth(monitor);
    int screenHeight = GetMonitorHeight(monitor);
    camera.target = (Vector2){player.x, player.y};
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 0.7f;
    while (!WindowShouldClose()) {
        deltaTime = GetFrameTime();
        camera.target = (Vector2){player.x + player.width/2.0f, player.y + player.height/2.0f};
        
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode2D(camera);
        updatePlayer(&player, &pillar);
        displayPillar(&pillar);
        EndMode2D();
        EndDrawing();
    }
}
