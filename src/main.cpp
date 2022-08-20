﻿#include <cstdlib>
#include <vector>
#include <memory>

#include "raylib.h"

#include "config.h"

#include "player.h"
#include "Scene.h"
#include "ProtectedTexture.h"
#include "ProtectedTileset.h"
#include "Inventory.h"
#include "BattleScreen.h"
#include "ActorHarpye.h"
#include "ActorLoredrop.h"

int main() {
    // Raylib initialization
    // Project name, screen size, fullscreen mode etc. can be specified in the config.h.in file
    InitWindow(Game::ScreenWidth, Game::ScreenHeight, Game::PROJECT_NAME);
    SetTargetFPS(60);
    InitAudioDevice();
    SetMasterVolume(0.1f);


#ifdef GAME_START_FULLSCREEN
    ToggleFullscreen();
#endif

    // Your own initialization code here
    // ...
    // ...
    Inventory inventory;
    ActorHarpye enemyHarpy;
    ActorLoredrop loredrop;
    BattleScreen fightScreen;

    Texture2D background = LoadTexture("assets/graphics/Backgrounds/Background1.png");

    const char* titleTexture = "assets/graphics/UI/title_screen.png";
    std::shared_ptr<ProtectedTexture> titleTex = std::make_shared<ProtectedTexture>(titleTexture);
    Music titlemusic = LoadMusicStream("assets/audio/tracks/TitleTestMusic.wav");

    const char* gameoverTexture = "assets/graphics/UI/game_over_screen.png";
    std::shared_ptr<ProtectedTexture> gameoverTex = std::make_shared<ProtectedTexture>(gameoverTexture);
    Music gameovermusic = LoadMusicStream("assets/audio/tracks/gameover.wav");

    const char* mapTexture = "assets/graphics/Map/Test-LevelGit.png"; //columns = 14
    const char* mapDescription = "assets/graphics/Map/THIS.json";
    std::shared_ptr<ProtectedTexture> mapTex = std::make_shared<ProtectedTexture>(mapTexture);
    std::shared_ptr<ProtectedTileset> description = std::make_shared<ProtectedTileset>(mapDescription);
    Music levelmusic = LoadMusicStream("assets/audio/tracks/TraumDerHellenen.wav");

    Texture2D button_start = LoadTexture("assets/graphics/UI/Buttons/start_button.png");


    // enum for changing gamestates
    // default for title
    enum GameState {state_title, state_level1, state_fight, state_gameover};
    GameState gameState = state_title;



    std::shared_ptr <player> katara = std::make_shared<player>();
    std::unique_ptr<Scene> TestScene = std::make_unique<Scene>(katara,
                    mapTex,
                    description,
                    levelmusic,
                    Camera2D({Game::ScreenWidth/2,Game::ScreenHeight/2}));

    std::unique_ptr<Scene> TestTitle = std::make_unique<Scene>(titleTex,
                                                          titlemusic);

    std::unique_ptr<Scene> TestGameover = std::make_unique<Scene>(gameoverTex,
                                                               gameovermusic);
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
                TestScene->Update();
                inventory.Update();
                enemyHarpy.Update();
                loredrop.UpdateLore(katara->GetPosition());

                // State Wechsel
                // if in options und press enter
                if (IsKeyPressed(KEY_ENTER) && inventory.GetCurrentState() == 2)
                {
                    gameState = state_title;
                }
                // if inventory not open then change to fight on key
                else if (IsKeyPressed(KEY_F) && inventory.IsOpen() == false)
                {
                    gameState = state_fight;
                }

                else if (TestScene->getGameOver())
                {
                    gameState = state_gameover;
                }
                break;

            case (state_fight):
                if (IsKeyPressed(KEY_F))
                {
                    gameState = state_level1;
                }
                break;

            case(state_gameover):
                if(IsKeyPressed(KEY_ENTER))
                {
                    gameState = state_title;
                }
                break;

            default:
                break;
        }

        BeginDrawing();


            // You can draw on the screen between BeginDrawing() and EndDrawing()
            // ...
            // ...

        //Music leveltheme = LoadMusicStream();

        //UnloadMusicStream(leveltheme);

        //PlayMusicStream(leveltheme);

        //StopMusicStream(leveltheme);

        switch(gameState)
            {
                case (state_title):
                    ClearBackground(WHITE);
                    TestTitle->Update();
                    TestTitle->Render();

                    // draw a button that should later be added to the scene
                    DrawTexturePro(button_start,
                                   {0, 0, (float)button_start.width, (float)button_start.height},
                                   {(float)GetScreenWidth()/2 - (button_start.width * 5)/2, (float)GetScreenHeight() - 260, (float)button_start.width * 5, (float)button_start.height * 5},
                                   {0, 0}, 0, WHITE);
                    break;

                case (state_level1): // playing screen
                    ClearBackground(WHITE);
                    DrawText("Level 1", 10, 10, 30, LIGHTGRAY);
                    DrawText("Press F to start fight.", 10, 40, 30, LIGHTGRAY);

                    //draw Background
                    DrawTexturePro(background,
                                   {0, 0, (float)background.width, (float)background.height},
                                   {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
                                   {0, 0}, 0, WHITE);

                    //begin of camera
                    BeginMode2D(TestScene->getCamera());

                    TestScene->Render();
                    loredrop.Draw();

                    // enemies
                    enemyHarpy.RenderHarpye({3510, 3015});
                    enemyHarpy.RenderHarpye({3800, 3025});
                    enemyHarpy.RenderHarpye({3990, 3015});
                    enemyHarpy.RenderHarpye({4380, 3005});

                    EndMode2D();
                    // end of camera

                    // inventory
                    loredrop.Render();
                    inventory.Render();

                    break;

                case (state_fight):
                    ClearBackground(WHITE);
                    DrawText("Fight", 10, 10, 30, LIGHTGRAY);
                    DrawText("Press F to return to Level 1.", 10, 40, 30, LIGHTGRAY);

                    fightScreen.Update();
                    fightScreen.Render();
                    break;

                case (state_gameover):
                    ClearBackground(WHITE);
                    TestGameover->Update();
                    TestGameover->Render();
                    // DrawText("Title", 10, 10, 30, LIGHTGRAY);
                    // DrawText("Press Enter to start Level 1.", 10, 40, 30, LIGHTGRAY);
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
    CloseAudioDevice();
    return EXIT_SUCCESS;
}
