//
// Created by Lee on 18.08.2022.
//

#include "ActorLoredrop.h"

ActorLoredrop::ActorLoredrop()
{
    this->animation = LoadTexture("assets/graphics/Actors/Loredrop_Template.png");
}

void ActorLoredrop::Update()
{
    // show loredrop on/off
    if (IsKeyPressed(KEY_TAB) && this->isVisible == false)
    {
        this->isVisible = true;
    }
    else if (IsKeyPressed(KEY_TAB) && this->isVisible == true)
    {
        this->isVisible = false;
    }

    // position above kataras head
    this->position = {(float)Katara.getPosition().x, (float)Katara.getPosition().y - 20, (float)this->animation.width/5, (float)this->animation.height};

    UpdateAnimation(GetFrameTime(), 5, 0.7f);
}

void ActorLoredrop::Render()
{
    if (this->isVisible == true)
    {
        RenderAnimation({this->position.x, this->position.y, (float)this->animation.width/5, (float)this->animation.height}, 5, 1);
    }

}

// not used
void ActorLoredrop::Update(float) { }
void ActorLoredrop::HandleInput() { }
