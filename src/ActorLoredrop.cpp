//
// Created by Lee on 18.08.2022.
//

#include "ActorLoredrop.h"

ActorLoredrop::ActorLoredrop()
{
    this->loredropBase = LoadTexture("assets/graphics/Actors/Loredrop_Template.png");
    this->loredropOne = LoadTexture("assets/graphics/Actors/Loredrop_Empty.png");
    this->loredropTwo = LoadTexture("assets/graphics/Actors/Loredrop_Empty.png");
    this->loredropThree = LoadTexture("assets/graphics/Actors/Loredrop_Empty.png");
}

void ActorLoredrop::Update()
{
    // show loredrop on/off
    if (IsKeyPressed(KEY_TAB) && this->current == 0)
    {
        this->current = 1;
    }
    else if (IsKeyPressed(KEY_TAB) && this->current == 1)
    {
        this->current = 2;
    }
    else if (IsKeyPressed(KEY_TAB) && this->current == 2)
    {
        this->current = 0;
    }

    InternUpdate();

}

void ActorLoredrop::Render()
{
    InternRender();
}

void ActorLoredrop::InternUpdate()
{
    switch (this->current)
    {
        case 1:
            this->position = {(float)Katara.getPosition().x, (float)Katara.getPosition().y - 20, (float)this->loredropBase.width, (float)this->loredropBase.height};
            UpdateAnimation(GetFrameTime(), 5, 0.7f);

            break;

        case 2:
            this->position = {(float)Katara.getPosition().x, (float)Katara.getPosition().y - 20, (float)this->loredropOne.width, (float)this->loredropOne.height};
            UpdateAnimation(GetFrameTime(), 1, 0.7f);
            break;

        case 3:
            this->position = {(float)Katara.getPosition().x, (float)Katara.getPosition().y - 20, (float)this->loredropTwo.width, (float)this->loredropTwo.height};
            UpdateAnimation(GetFrameTime(), 1, 0.7f);
            break;

        case 4:
            this->position = {(float)Katara.getPosition().x, (float)Katara.getPosition().y - 20, (float)this->loredropThree.width, (float)this->loredropThree.height};
            UpdateAnimation(GetFrameTime(), 1, 0.7f);
            break;
    }
}

void ActorLoredrop::InternRender()
{
    // position above kataras head
    // specific for every loredrop


    switch (current)
    {
        case 1:
            RenderAnimation({this->position.x, this->position.y, (float)this->loredropBase.width / 5, (float)this->loredropBase.height}, 5, 1);
            break;

        case 2:
            RenderAnimation({this->position.x, this->position.y, (float)this->loredropOne.width, (float)this->loredropOne.height}, 1, 1);
            break;

        case 3:
            RenderAnimation({this->position.x, this->position.y, (float)this->loredropTwo.width, (float)this->loredropTwo.height}, 1, 1);
            break;

        case 4:
            RenderAnimation({this->position.x, this->position.y, (float)this->loredropThree.width, (float)this->loredropThree.height}, 1, 1);
            break;

    }

}

// not used
void ActorLoredrop::Update(float) { }
void ActorLoredrop::HandleInput() { }
