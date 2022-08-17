#include <cstdlib>
#include <vector>
#include <memory>

#include "raylib.h"

#include "config.h"

#include "player.h"
#include "Scene.h"
#include "ProtectedTexture.h"
#include "ProtectedTileset.h"
#include "Inventory.h"

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
    Inventory inventory;

    const char* mapTexture = "assets/graphics/Map/Test-LevelGit.png"; //columns = 14
    const char* mapDescription = "assets/graphics/Map/THIS.json";
    std::shared_ptr<ProtectedTexture> mapTex = std::make_shared<ProtectedTexture>(mapTexture);
    std::shared_ptr<ProtectedTileset> description = std::make_shared<ProtectedTileset>(mapDescription);



    // enum for changing gamestates
    // default for title
    enum GameState {state_title, state_level1, state_fight};
    GameState gameState = state_title;

    std::shared_ptr<Scene> TestScene = std::make_shared<Scene>((std::make_shared<player>()),
                    mapTex,
                    description);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Updates that are made by frame are coded here
        // ...
        // ...
        switch (gameState)
        {
            case (state_title):
                if (IsKeyPressed(KEY_ENTER))
                {
                    gameState = state_level1;
                }
                break;

            case (state_level1):
                inventory.Update();

                // State Wechsel
                if (IsKeyPressed(KEY_ENTER))
                {
                    gameState = state_title;
                }
                if (IsKeyPressed(KEY_F))
                {
                    gameState = state_fight;
                }
                break;

            case (state_fight):
                if (IsKeyPressed(KEY_F))
                {
                    gameState = state_level1;
                }
                break;
            default:
                break;
        }

        BeginDrawing();
            // You can draw on the screen between BeginDrawing() and EndDrawing()
            // ...
            // ...

            switch(gameState)
            {
                case (state_title):
                    ClearBackground(WHITE);
                    DrawText("Title", 10, 10, 30, LIGHTGRAY);
                    DrawText("Press Enter to start Level 1.", 10, 40, 30, LIGHTGRAY);
                    break;

                case (state_level1):
                    // playing screen
                    ClearBackground(WHITE);
                    TestScene->Update();
                    TestScene->Render();
                    DrawText("Level 1", 10, 10, 30, LIGHTGRAY);
                    DrawText("Press F to start fight.", 10, 40, 30, LIGHTGRAY);


                    // inventory
                    inventory.Render();
                    break;

                case (state_fight):
                    ClearBackground(WHITE);
                    DrawText("Fight", 10, 10, 30, LIGHTGRAY);
                    DrawText("Press F to return to Level 1.", 10, 40, 30, LIGHTGRAY);
                    break;

                default:
                    break;

            }


        EndDrawing();
    } // Main game loop end

    // De-initialization here
    // ...
    // ...

    // Close window and OpenGL context
    CloseWindow();

    return EXIT_SUCCESS;
}
