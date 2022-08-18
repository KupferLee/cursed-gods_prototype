//
// Created by Lee on 18.08.2022.
//

#include "ActorHarpye.h"

ActorHarpye::ActorHarpye()
{
    this->animation = LoadTexture("assets/graphics/Actors/Harpye_Animations.png");
    this->position = {(float)GetScreenWidth()/2, (float)GetScreenHeight()/2, (float)this->animation.width/5, (float)this->animation.height};
}

void ActorHarpye::Update()
{
    UpdateAnimation(GetFrameTime(), 5, 0.22f);
}

void ActorHarpye::Render()
{
    RenderAnimation(this->position, 5, 1);
}

void ActorHarpye::Update(float) {}

void ActorHarpye::HandleInput() {}
