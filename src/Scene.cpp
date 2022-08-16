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

Scene::Scene(const std::shared_ptr<player> &player, const std::shared_ptr<ProtectedTexture> &map, const std::shared_ptr<ProtectedTileset> &tileAtlas)
            : player_(player), map_(map), tileAtlas_(tileAtlas){
    this->rec_.x = 0.f;
    this->rec_.y = 0.f;
    this->rec_.width = 16.f;
    this->rec_.height = 16.f;

    this->vec_ = {0.f,0.f};

    this->counter_ = 0;

    for (int i = 0; i < this->tileAtlas_->getTileAtlas().size(); i++)
    {
        if (!(this->counter_% (this->tileAtlas_->getTilesX() * this->tileAtlas_->getTilesY()))
            || this->counter_ == 0)
        {
            this->vec_.y = 0;
            this->vec_.x = 0;
        }

        if (this->tileAtlas_->getTileAtlas().at(i) != 0) {
            this->recs_.push_back({static_cast<float> ((this->tileAtlas_->getTileAtlas().at(i) - 1)
                                                       % this->tileAtlas_->getColumns())
                                   * this->rec_.width,
                                   floor(static_cast<float> (this->tileAtlas_->getTileAtlas().at(i) - 1)
                                         / static_cast<float> (this->tileAtlas_->getColumns()))
                                   * this->rec_.width});
            this->vecs_.push_back(vec_);
        }
        this->vec_.x += this->rec_.width;
        if (this->vec_.x >= this->rec_.width * static_cast<float>(this->tileAtlas_->getTilesX())) {
            this->vec_.x = 0;
            this->vec_.y += this->rec_.height;
        }
        counter_++;
    }
    TraceLog(LOG_INFO, "Scene constructor called");
}

Scene::~Scene()
{
    TraceLog(LOG_INFO, "Scene destructor called");
}

void Scene::HandleInput() {
        return HandleInputScene();
}

void Scene::Update(float, std::vector<Rectangle> &) {

}

void Scene::Update() {
    return UpdateScene();
}

void Scene::Render() {
    return RenderScene();
}

void Scene::HandleInputScene(){}

void Scene::UpdateScene() {}

void Scene::RenderScene() {
    for (int i = 0; i < recs_.size(); ++i) {
        this->rec_.x = this->recs_.at(i).x;
        this->rec_.y = this->recs_.at(i).y;
        this->vec_.x = this->vecs_.at(i).x;
        this->vec_.y = this->vecs_.at(i).y;
        DrawTextureRec(this->map_->getTexture(), this->rec_, this->vec_, WHITE);
    }
}
