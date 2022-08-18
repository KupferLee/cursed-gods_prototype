//
// Created by Lee on 18.08.2022.
//

#include "ActorLoredrop.h"
#include "iostream"


ActorLoredrop::ActorLoredrop()
{
    this->positionTest = {1000, 730};
    this->posDrop_1 = {730, 700 };
    this->posDrop_2 = {2410, 860};
    this->posDrop_3 = {2695, 3307};
    this->posDrop_4 = {2000, 3275};
    this->posDrop_final = {8960, 1245};

    this->loredropBase = LoadTexture("assets/graphics/Actors/Loredrop_Template.png");
    this->loredropOne = LoadTexture("assets/graphics/Actors/Loredrop_1.png");
    this->loredropTwo = LoadTexture("assets/graphics/Actors/Loredrop_2.png");
    this->loredropThree = LoadTexture("assets/graphics/Actors/Loredrop_3.png");
    this->loredropFour = LoadTexture("assets/graphics/Actors/Loredrop_4.png");
    this->loredropFinal = LoadTexture("assets/graphics/Actors/Loredrop_5.png");
}

void ActorLoredrop::UpdateLore(Vector2 currentPosition)
{
    if (IsKeyPressed(KEY_H) && isHitboxVisible == false)
    {
        this->isHitboxVisible = true;
    }
    else if (IsKeyPressed(KEY_H) && isHitboxVisible == true)
    {
        this->isHitboxVisible = false;
    }

    // to get mid of katara
    currentPosition.x += 16;
    currentPosition.y += 16;

    // show loredrop on/off
    if (Vector2Distance(currentPosition, this->posDrop_1) < 50)
    {
        this->currentLoredrop = WhichLoredrop::first;
    }
    else if (Vector2Distance(currentPosition, this->posDrop_2) < 50)
    {
        this->currentLoredrop = WhichLoredrop::second;
    }
    else if (Vector2Distance(currentPosition, this->posDrop_3) < 50)
    {
        this->currentLoredrop = WhichLoredrop::third;
    }
    else if (Vector2Distance(currentPosition, this->posDrop_4) < 50)
    {
        this->currentLoredrop = WhichLoredrop::fourth;
    }
    else if (Vector2Distance(currentPosition, this->posDrop_final) < 50)
    {
        this->currentLoredrop = WhichLoredrop::final;
    }
    else
    {
        this->currentLoredrop = WhichLoredrop::none;
    }

    InternUpdate();

}

void ActorLoredrop::Render()
{
    InternRender();
}

void ActorLoredrop::Draw()
{
    if (this->isHitboxVisible == true)
    {
        DrawRectangle(this->posDrop_1.x, this->posDrop_1.y, 50, 50, RED);
        DrawRectangle(this->posDrop_2.x, this->posDrop_2.y, 50, 50, RED);
        DrawRectangle(this->posDrop_3.x, this->posDrop_3.y, 50, 50, RED);
        DrawRectangle(this->posDrop_4.x, this->posDrop_4.y, 50, 50, RED);
        DrawRectangle(this->posDrop_final.x, this->posDrop_final.y, 50, 50, RED);
    }

}

void ActorLoredrop::InternUpdate()
{
    switch ((int)this->currentLoredrop)
    {
        case (int)WhichLoredrop::base:
            this->position = {(float)(GetScreenWidth()/2 - this->loredropBase.width/2*this->scaleFactor), (float)(GetScreenHeight() - this->loredropBase.height*this->scaleFactor - this->offset), (float)this->loredropBase.width, (float)this->loredropBase.height};
            break;

        case (int)WhichLoredrop::first:
            this->position = {(float)(GetScreenWidth()/2 - this->loredropOne.width/2*this->scaleFactor), (float)(GetScreenHeight() - this->loredropOne.height*this->scaleFactor - this->offset), (float)this->loredropOne.width, (float)this->loredropOne.height};
            break;

        case (int)WhichLoredrop::second:
            this->position = {(float)(GetScreenWidth()/2 - this->loredropTwo.width/2*this->scaleFactor), (float)(GetScreenHeight() - this->loredropTwo.height*this->scaleFactor - this->offset), (float)this->loredropTwo.width, (float)this->loredropTwo.height};
            break;

        case (int)WhichLoredrop::third:
            this->position = {(float)(GetScreenWidth()/2 - this->loredropThree.width/2*this->scaleFactor), (float)(GetScreenHeight() - this->loredropThree.height*this->scaleFactor - this->offset), (float)this->loredropThree.width, (float)this->loredropThree.height};
            break;

        case (int)WhichLoredrop::fourth:
            this->position = {(float)(GetScreenWidth()/2 - this->loredropFour.width/2*this->scaleFactor), (float)(GetScreenHeight() - this->loredropFour.height*this->scaleFactor - this->offset), (float)this->loredropFour.width, (float)this->loredropFour.height};
            break;

        case (int)WhichLoredrop::final:
            this->position = {(float)(GetScreenWidth()/2 - this->loredropFinal.width/2*this->scaleFactor), (float)(GetScreenHeight() - this->loredropFinal.height*this->scaleFactor - this->offset), (float)this->loredropFinal.width, (float)this->loredropFinal.height};
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
                           {this->position.x, this->position.y, (float)this->loredropBase.width*this->scaleFactor, (float)this->loredropBase.height*this->scaleFactor},
                           {0, 0}, 0, WHITE);
            break;

        case WhichLoredrop::first:
            DrawTexturePro(this->loredropOne,
                           {0, 0, (float)this->loredropOne.width, (float)this->loredropOne.height},
                           {this->position.x, this->position.y, (float)this->loredropOne.width*this->scaleFactor, (float)this->loredropOne.height*this->scaleFactor},
                           {0, 0}, 0, WHITE);
            break;

        case WhichLoredrop::second:
            DrawTexturePro(this->loredropTwo,
                           {0, 0, (float)this->loredropTwo.width, (float)this->loredropTwo.height},
                           {this->position.x, this->position.y, (float)this->loredropTwo.width*this->scaleFactor, (float)this->loredropTwo.height*this->scaleFactor},
                           {0, 0}, 0, WHITE);
            break;

        case WhichLoredrop::third:
            DrawTexturePro(this->loredropThree,
                           {0, 0, (float)this->loredropThree.width, (float)this->loredropThree.height},
                           {this->position.x, this->position.y, (float)this->loredropThree.width*this->scaleFactor, (float)this->loredropThree.height*this->scaleFactor},
                           {0, 0}, 0, WHITE);
            break;

        case WhichLoredrop::fourth:
            DrawTexturePro(this->loredropFour,
                           {0, 0, (float)this->loredropFour.width, (float)this->loredropFour.height},
                           {this->position.x, this->position.y, (float)this->loredropFour.width*this->scaleFactor, (float)this->loredropFour.height*this->scaleFactor},
                           {0, 0}, 0, WHITE);
            break;

        case WhichLoredrop::final:
            DrawTexturePro(this->loredropFinal,
                           {0, 0, (float)this->loredropFinal.width, (float)this->loredropFinal.height},
                           {this->position.x, this->position.y, (float)this->loredropFinal.width*this->scaleFactor, (float)this->loredropFinal.height*this->scaleFactor},
                           {0, 0}, 0, WHITE);
            break;

    }

}

// not used
void ActorLoredrop::Update() {}
void ActorLoredrop::Update(float) { }
void ActorLoredrop::HandleInput() { }
