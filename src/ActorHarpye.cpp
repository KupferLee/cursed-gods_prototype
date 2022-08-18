//
// Created by Lee on 18.08.2022.
//

#include "ActorHarpye.h"

ActorHarpye::ActorHarpye()
{
    this->animation = LoadTexture("assets/graphics/Actors/Harpye_Animations.png");

}

void ActorHarpye::Update()
{
    this->position = {(float)Katara.getPosition().x, (float)Katara.getPosition().y, (float)this->animation.width/5, (float)this->animation.height};
    UpdateAnimation(GetFrameTime(), 5, 0.22f);
}

void ActorHarpye::Render()
{
    RenderAnimation(this->position, 5, 1);
}

void ActorHarpye::Update(float) {}

void ActorHarpye::HandleInput() {}
