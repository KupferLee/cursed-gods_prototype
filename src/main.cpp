#include <cstdlib>
#include <vector>

#include "raylib.h"

#include "config.h"

#include "player.h"

int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);

#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here
    // ...
    // ...
    player Test;

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Updates that are made by frame are coded here
        // ...
        // ...
        Test.Update();

        BeginDrawing();
            // You can draw on the screen between BeginDrawing() and EndDrawing()
            // ...
            // ...
            ClearBackground(WHITE);
            DrawText("TestScene", 10, 10, 30, LIGHTGRAY);
            std::vector<Rectangle> Ground;
            Ground.push_back(Rectangle{ 0, 500, static_cast<float>(GetScreenWidth()), 40 });
            Ground.push_back(Rectangle{ 230, 400, 150, 20 });
            Ground.push_back(Rectangle{ 420, 300, 150, 20 });
            for (const auto& index : Ground)
            {
                DrawRectangleRec(index, LIGHTGRAY);
                Test.CheckCollision(index);
            }
            Test.Render();

        EndDrawing();
    } // Main game loop end

    // De-initialization here
    // ...
    // ...

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
