#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "raylib.h"

bool fullscreen = 0;
int width = 800;
int height = 600;
int fps = 60;
int speed = 5;

int rectangleX[5];

int main(int argc, char *argv[]) {
    if (getenv("FULLSCREEN") != NULL && strcmp(getenv("FULLSCREEN"), "1") == 0) fullscreen = true;
    if (getenv("WIDTH") != NULL) width = atoi(getenv("WIDTH"));
    if (getenv("HEIGHT") != NULL) height = atoi(getenv("HEIGHT"));
    if (getenv("FPS") != NULL) fps = atoi(getenv("FPS"));
    if (getenv("SPEED") != NULL) speed = atoi(getenv("SPEED"));

    //printf("FULLSCREEN: %i, WIDTH: %i, HEIGHT: %i, FPS: %i, SPEED: %i\n", fullscreen, width, height, fps, speed);
    speed = speed - 1;

    for (int i = 0; i < 5; i++) {
        rectangleX[i] = i * (width / 4);
    }

    InitWindow(width, height, "raylib screen tearing test");
    if (fullscreen == 1) ToggleFullscreen();

    SetTargetFPS(fps);
    while (!WindowShouldClose()) {
        for (int i = 0; i < 5; i++) {
            rectangleX[i]++;
            if (rectangleX[i] >= width + width / 8) rectangleX[i] = - (width / 8);
            if (rectangleX[i] <= - width / 4) rectangleX[i] = width;
        }

        BeginDrawing();
            DrawFPS(0, 0);
            ClearBackground(WHITE);
            for (int i = 0; i < 5; i++) {
                DrawRectangle(rectangleX[i], 0, width / 8, height, BLACK);

                rectangleX[i] = rectangleX[i] + speed;
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}