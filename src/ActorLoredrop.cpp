//
// Created by Lee on 18.08.2022.
//

#include "ActorLoredrop.h"

ActorLoredrop::ActorLoredrop()
{
    this->animation = LoadTexture("assets/graphics/UI/Slot_Sword.png");
}

void ActorLoredrop::Update()
{
    // position above kataras head
    this->position = {(float)Katara.getPosition().x, (float)Katara.getPosition().y - 20, (float)this->animation.width/5, (float)this->animation.height};

    UpdateAnimation(GetFrameTime(), 1, 0.22f);
}

void ActorLoredrop::Render()
{
    RenderAnimation({this->position.x, this->position.y, (float)this->animation.width, (float)this->animation.height}, 1, 1);
}

// not used
void ActorLoredrop::Update(float) { }
void ActorLoredrop::HandleInput() { }
