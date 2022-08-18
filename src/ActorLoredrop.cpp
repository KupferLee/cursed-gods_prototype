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
    if (IsKeyPressed(KEY_TAB) && this->currentLoredrop == WhichLoredrop::none)
    {
        this->currentLoredrop = WhichLoredrop::base;
    }
    else if (IsKeyPressed(KEY_TAB) && this->currentLoredrop == WhichLoredrop::base)
    {
        this->currentLoredrop = WhichLoredrop::first;
    }
    else if (IsKeyPressed(KEY_TAB) && this->currentLoredrop == WhichLoredrop::first)
    {
        this->currentLoredrop = WhichLoredrop::none;
    }
    // not used
    else if (IsKeyPressed(KEY_TAB) && this->currentLoredrop == WhichLoredrop::second)
    {
        this->currentLoredrop = WhichLoredrop::third;
    }
    else if (IsKeyPressed(KEY_TAB) && this->currentLoredrop == WhichLoredrop::third)
    {
        this->currentLoredrop = WhichLoredrop::none;
    }

    InternUpdate();

}

void ActorLoredrop::Render()
{
    InternRender();
}

void ActorLoredrop::InternUpdate()
{
    switch ((int)this->currentLoredrop)
    {
        case (int)WhichLoredrop::base:
            this->position = {(float)Katara.getPosition().x, (float)Katara.getPosition().y - 20, (float)this->loredropBase.width, (float)this->loredropBase.height};

            break;

        case (int)WhichLoredrop::first:
            this->position = {(float)Katara.getPosition().x, (float)Katara.getPosition().y - 20, (float)this->loredropOne.width, (float)this->loredropOne.height};
           break;

        case (int)WhichLoredrop::second:
            this->position = {(float)Katara.getPosition().x, (float)Katara.getPosition().y - 20, (float)this->loredropTwo.width, (float)this->loredropTwo.height};
            break;

        case (int)WhichLoredrop::third:
            this->position = {(float)Katara.getPosition().x, (float)Katara.getPosition().y - 20, (float)this->loredropThree.width, (float)this->loredropThree.height};
            break;
    }
}

void ActorLoredrop::InternRender()
{
    // position above kataras head
    // specific for every loredrop weil texture
    switch (currentLoredrop)
    {
        case WhichLoredrop::base:
            DrawTexturePro(this->loredropBase,
                           {0, 0, (float)this->loredropBase.width, (float)this->loredropBase.height},
                           {this->position.x, this->position.y, (float)this->loredropBase.width, (float)this->loredropBase.height},
                           {0, 0}, 0, WHITE);
            break;

        case WhichLoredrop::first:
            DrawTexturePro(this->loredropOne,
                           {0, 0, (float)this->loredropOne.width, (float)this->loredropOne.height},
                           {this->position.x, this->position.y, (float)this->loredropOne.width, (float)this->loredropOne.height},
                           {0, 0}, 0, WHITE);
            break;

        case WhichLoredrop::second:
            DrawTexturePro(this->loredropTwo,
                           {0, 0, (float)this->loredropTwo.width, (float)this->loredropTwo.height},
                           {this->position.x, this->position.y, (float)this->loredropTwo.width, (float)this->loredropTwo.height},
                           {0, 0}, 0, WHITE);
            break;

        case WhichLoredrop::third:
            DrawTexturePro(this->loredropThree,
                           {0, 0, (float)this->loredropThree.width, (float)this->loredropThree.height},
                           {this->position.x, this->position.y, (float)this->loredropThree.width, (float)this->loredropThree.height},
                           {0, 0}, 0, WHITE);
            break;

    }

}

// not used
void ActorLoredrop::Update(float) { }
void ActorLoredrop::HandleInput() { }
