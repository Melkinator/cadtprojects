#include "raylib.h"

static void update(void) {
    BeginDrawing();
    ClearBackground(WHITE);
        DrawRectangle(200, 200, 200, 200, GRAY);
        DrawText("i dont like this", 240, 240, 12, WHITE);
    DrawFPS(10, 10);
    EndDrawing();
}

int main() {
    int height = 800;
    int width = 600;

    SetConfigFlags(FLAG_WINDOW_RESIZABLE|FLAG_VSYNC_HINT);
    InitWindow(width, height, "test");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        update();
        if (IsWindowResized()&&!IsWindowFullscreen()) {
            width = GetScreenWidth();
            height = GetScreenHeight();
        }
    }
    CloseWindow();
}
