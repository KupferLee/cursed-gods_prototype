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
            : player_(player), map_(map), tileAtlas_(tileAtlas), theme_(theme), cam_(cam) {

    if(player_ != nullptr){
        player_->SetGround(tileAtlas_->getHitboxesGround());
        player_->SetWalls(tileAtlas_->getHitboxes());
        cam_.target = player_->getPosition();
        cam_.zoom = 1.f;
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
    float delta = GetFrameTime();
    if(player_ != nullptr) {
        player_->Update(delta);
        cam_.target = player_->getPosition();
    }

}

void Scene::RenderScene() {
    PlayMusicStream(theme_);
    if(map_->getTextureWidth() > Game::ScreenWidth) {
        DrawTexturePro(this->map_->getTexture(),
                       {0, 0, static_cast<float>(Game::ScreenWidth), static_cast<float>(Game::ScreenHeight)},
                       {0, 0, static_cast<float>(Game::ScreenWidth), static_cast<float>(Game::ScreenHeight)}, {}, {},
                       WHITE);
    }
    else
    {
        DrawTexturePro(this->map_->getTexture(),
                       {0, 0, static_cast<float>(map_->getTextureWidth()), static_cast<float>(map_->getTextureHeight())},
                       {0, 0, static_cast<float>(Game::ScreenWidth), static_cast<float>(Game::ScreenHeight)}, {}, {},
                       WHITE);
    }
    if(tileAtlas_ != nullptr){
        for (int i = 0; i < tileAtlas_->getHitboxesGround().size(); ++i){
            DrawRectangle(tileAtlas_->getHitboxesGround().at(i).x,
                          tileAtlas_->getHitboxesGround().at(i).y,
                          tileAtlas_->getHitboxesGround().at(i).width,
                          tileAtlas_->getHitboxesGround().at(i).height,
                          RED);
            }
        for (int i = 0; i < tileAtlas_->getHitboxes().size(); ++i){
            DrawRectangle(tileAtlas_->getHitboxes().at(i).x,
                          tileAtlas_->getHitboxes().at(i).y,
                          tileAtlas_->getHitboxes().at(i).width,
                          tileAtlas_->getHitboxes().at(i).height,
                          ORANGE);
            }
        for (int i = 0; i < tileAtlas_->getTriggerboxesStalagtit().size(); ++i){
            DrawRectangle(tileAtlas_->getTriggerboxesStalagtit().at(i).x,
                          tileAtlas_->getTriggerboxesStalagtit().at(i).y,
                          tileAtlas_->getTriggerboxesStalagtit().at(i).width,
                          tileAtlas_->getTriggerboxesStalagtit().at(i).height,
                          GREEN);
            }
        for (int i = 0; i < tileAtlas_->getTriggerboxesStalagmit().size(); ++i){
            DrawRectangle(tileAtlas_->getTriggerboxesStalagmit().at(i).x,
                          tileAtlas_->getTriggerboxesStalagmit().at(i).y,
                          tileAtlas_->getTriggerboxesStalagmit().at(i).width,
                          tileAtlas_->getTriggerboxesStalagmit().at(i).height,
                          BLUE);
            }
        for (int i = 0; i < tileAtlas_->getTriggerboxesBreakable().size(); ++i){
            DrawRectangle(tileAtlas_->getTriggerboxesBreakable().at(i).x,
                          tileAtlas_->getTriggerboxesBreakable().at(i).y,
                          tileAtlas_->getTriggerboxesBreakable().at(i).width,
                          tileAtlas_->getTriggerboxesBreakable().at(i).height,
                          PINK);
            }
        }
    if(player_ != nullptr){
    player_->Render();
    }
}

Camera2D Scene::getCamera() {
    return cam_;
}
