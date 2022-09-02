/*
*   Created by Schr4mMb00 on 22.07.2022.
*
*   Title: Scene
*   Required: const ref to shared_ptr for Map, Tileatlas, Player and Enemies
*   Return: you can get readingaccess to:  ->
*                                          ->
*                                          ->
*   Function: drawing Screen-Scene, building up Leveldata, Checkcollisions and Levellogic
*/

#include "Scene.h"
#include "config.h"
#include <iostream>

Scene::Scene(const std::shared_ptr<player> &player,
             const std::shared_ptr<ProtectedTexture> &map,
             const std::shared_ptr<ProtectedTileset> &tileAtlas,
             const Music &theme,
             const Camera2D &cam)
            : player_(player), map_(map), tileAtlas_(tileAtlas), theme_(theme), cam_(cam), drawhitbox_(false), gameover_(false) {

    if(player_ != nullptr){
        player_->SetGround(tileAtlas_->getHitboxesGround());
        player_->SetWalls(tileAtlas_->getHitboxes());
        cam_.target = player_->GetPosition();
        cam_.zoom = 2.f;
    }

    TraceLog(LOG_INFO, "Scene constructor called");
}

Scene::Scene(const std::shared_ptr<ProtectedTexture> &map, const Music &theme)
        : player_(nullptr), map_(map), tileAtlas_(nullptr), theme_(theme), cam_({0,0}) {
    cam_.target = {0,0};
    cam_.zoom = 1.f;
    TraceLog(LOG_INFO, "Scene constructor called");
}

void Scene::Render() {
    return RenderScene();
}

void Scene::HandleInputScene() {}

Scene::~Scene()
{
    UnloadMusicStream(theme_);
    TraceLog(LOG_INFO, "Scene destructor called");
}

void Scene::HandleInput() {
        return HandleInputScene();
}

void Scene::Update(float) {

}

void Scene::Update() {
    return UpdateScene();
}


void Scene::UpdateScene()
{

    UpdateMusicStream(theme_);
    if(IsKeyPressed(KEY_H) && !drawhitbox_) drawhitbox_ = true;
    else if(IsKeyPressed(KEY_H) && drawhitbox_) drawhitbox_ = false;
    float delta = GetFrameTime();
    if(player_ != nullptr) {
        player_->Update(delta);
        cam_.target = player_->GetPosition();
        IndexCounter = 0;
        for(auto &index : spawnpoints)
        {
            if (Vector2Distance(player_->GetPosition(), index) < 50)
            {
                whichCheckpointIsActive = IndexCounter;
            }
            IndexCounter++;
        }
        gameover_ = false;
        for(int i = 0; i < tileAtlas_->getTriggerboxesStalagmit().size(); ++i) {
            if (CheckCollisionRecs({player_->GetPosition().x, player_->GetPosition().y, 32, 32},
                                   tileAtlas_->getTriggerboxesStalagmit().at(i))) {
                player_->SetPosition(spawnpoints[whichCheckpointIsActive]);
                gameover_ = true;
            }
        }
        if (Vector2Distance(player_->GetPosition(),{8360,3180})<50)
        {
        player_->SetDoubleJump();
        }
        // teleport to fight
        if(IsKeyPressed(KEY_P)) player_->SetPosition({4845, 1650});
    }
}

void Scene::RenderScene() {
    PlayMusicStream(theme_);
    if(player_ != nullptr) {
        DrawTexturePro(this->map_->getTexture(),
                       {(player_->GetPosition().x - Game::ScreenWidth / 2),
                        (player_->GetPosition().y - Game::ScreenHeight / 2),
                        (static_cast<float>(Game::ScreenWidth)/2) * cam_.zoom,
                        (static_cast<float>(Game::ScreenHeight)/2) * cam_.zoom},
                       {player_->GetPosition().x - Game::ScreenWidth / 2,
                        player_->GetPosition().y - Game::ScreenHeight / 2,
                        (static_cast<float>(Game::ScreenWidth) / 2) *cam_.zoom,
                        (static_cast<float>(Game::ScreenHeight) / 2) *cam_.zoom},
                        {},
                        {},
                       WHITE);
    }
    else{
        DrawTexturePro(this->map_->getTexture(),
                       {0,0,static_cast<float>(this->map_->getTexture().width),static_cast<float>(this->map_->getTexture().height)},
                       {0,0,Game::ScreenWidth,Game::ScreenHeight},{},0,WHITE);
    }
    if(drawhitbox_) {
        if (tileAtlas_ != nullptr) {
            for (int i = 0; i < tileAtlas_->getTriggerboxesStalagtit().size(); ++i) {
                DrawRectangle(tileAtlas_->getTriggerboxesStalagtit().at(i).x,
                              tileAtlas_->getTriggerboxesStalagtit().at(i).y,
                              tileAtlas_->getTriggerboxesStalagtit().at(i).width,
                              tileAtlas_->getTriggerboxesStalagtit().at(i).height,
                              GREEN);
            for (int i = 0; i < tileAtlas_->getHitboxes().size(); ++i) {
                DrawRectangle(tileAtlas_->getHitboxes().at(i).x,
                              tileAtlas_->getHitboxes().at(i).y,
                              tileAtlas_->getHitboxes().at(i).width,
                              tileAtlas_->getHitboxes().at(i).height,
                              ORANGE);
            }
            }
            for (int i = 0; i < tileAtlas_->getTriggerboxesStalagmit().size(); ++i) {
                DrawRectangle(tileAtlas_->getTriggerboxesStalagmit().at(i).x,
                              tileAtlas_->getTriggerboxesStalagmit().at(i).y,
                              tileAtlas_->getTriggerboxesStalagmit().at(i).width,
                              tileAtlas_->getTriggerboxesStalagmit().at(i).height,
                              BLUE);
            }
            for (int i = 0; i < tileAtlas_->getHitboxesGround().size(); ++i) {
                DrawRectangle(tileAtlas_->getHitboxesGround().at(i).x,
                              tileAtlas_->getHitboxesGround().at(i).y,
                              tileAtlas_->getHitboxesGround().at(i).width,
                              tileAtlas_->getHitboxesGround().at(i).height,
                              RED);

            }
        }
        for(auto &index : spawnpoints)
        {
            DrawCircleV({index.x,index.y}, 50, BLUE);
        }
        }
    if(player_ != nullptr){
    player_->Render();
    }
}

Camera2D Scene::getCamera() {
    return cam_;
}

int Scene::getGameOver() {
    return gameover_;
}
