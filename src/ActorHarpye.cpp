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
    //this->position = {(float)Katara.getPosition().x, (float)Katara.getPosition().y, (float)this->animation.width/5, (float)this->animation.height};
    UpdateAnimation(GetFrameTime(), 5, 0.22f);
}



void ActorHarpye::RenderHarpye(Vector2 position)
{
    RenderAnimation({position.x, position.y, 64, 64}, 5, 1);
}

// not used
void ActorHarpye::Render() { }
void ActorHarpye::Update(float) {}
void ActorHarpye::HandleInput() {}

