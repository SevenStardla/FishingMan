#include "core/GameManager.h"

int main()
    {
        InitWindow(800, 600, "피싱범을 찾아라! - Prototype");
        SetTargetFPS(60);

        GameManager game;
        game.Init();

        while (!WindowShouldClose())
            {
                game.Update();

                BeginDrawing();
                ClearBackground(BLACK);

                game.Render();

                EndDrawing();
            }
        CloseWindow();
        return 0;
    }