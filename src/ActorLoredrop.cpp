//
// Created by Lee on 18.08.2022.
//

#include "ActorLoredrop.h"
#include "iostream"


ActorLoredrop::ActorLoredrop()
{
    this->posDrop_Horse = {780, 750 };
    this->posDrop_Canyon_Oversight = {2400, 910};
    this->posDrop_Checkpoint = {2725, 3357};
    this->posDrop_Shack = {2050, 3325};
    this->posDrop_abillity = {8360,3180};
    this->posDrop_final = {8970, 1295}; //8970, 1295

    this->loredropBase = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Template.png");
    this->loredropOne = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Horse.png");
    this->loredropTwo = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Canyon_Oversight.png");
    this->loredropCheckpoint = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Checkpoint.png");
    this->loredropShack = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Hut.png");
    this->loredropAbillity =LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Boots.png");
    this->loredropFinal = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Towerentry.png");
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
    if (Vector2Distance(currentPosition, this->posDrop_Horse) < 50)
    {
        this->currentLoredrop = WhichLoredrop::first;
    }
    else if (Vector2Distance(currentPosition, this->posDrop_Canyon_Oversight) < 50)
    {
        this->currentLoredrop = WhichLoredrop::second;
    }
    else if (Vector2Distance(currentPosition, this->posDrop_Checkpoint) < 50)
    {
        this->currentLoredrop = WhichLoredrop::third;
        // activate checkpoint when loredrop gets triggered first time
        // each checkpoint has a assigned id
    }
    else if (Vector2Distance(currentPosition, this->posDrop_Shack) < 50)
    {
        this->currentLoredrop = WhichLoredrop::fourth;
    }
    else if (Vector2Distance(currentPosition, this->posDrop_final) < 50)
    {
        this->currentLoredrop = WhichLoredrop::final;
    }
    else if (Vector2Distance(currentPosition, this->posDrop_abillity) < 50)
    {
        this->currentLoredrop = WhichLoredrop::abillity;
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

        DrawCircle(this->posDrop_Horse.x, this->posDrop_Horse.y, 50, DARKBLUE);
        DrawCircle(this->posDrop_Canyon_Oversight.x, this->posDrop_Canyon_Oversight.y, 50, DARKBLUE);
        DrawCircle(this->posDrop_Checkpoint.x, this->posDrop_Checkpoint.y, 50, DARKBLUE);
        DrawText("1", posDrop_Checkpoint.x, posDrop_Checkpoint.y, 50, WHITE);
        DrawCircle(this->posDrop_Shack.x, this->posDrop_Shack.y, 50, DARKBLUE);
        DrawCircle(this->posDrop_final.x, this->posDrop_final.y, 50, DARKBLUE);

    }

}

int ActorLoredrop::GetCurrentCheckpointID() { return this->whichCheckpointIsActive; }

// Lee: forgot what this is fore and what it does oops
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
            this->position = {(float)(GetScreenWidth()/2 - this->loredropCheckpoint.width / 2 * this->scaleFactor), (float)(GetScreenHeight() - this->loredropCheckpoint.height * this->scaleFactor - this->offset), (float)this->loredropCheckpoint.width, (float)this->loredropCheckpoint.height};
            break;

        case (int)WhichLoredrop::fourth:
            this->position = {(float)(GetScreenWidth()/2 - this->loredropShack.width / 2 * this->scaleFactor), (float)(GetScreenHeight() - this->loredropShack.height * this->scaleFactor - this->offset), (float)this->loredropShack.width, (float)this->loredropShack.height};
            break;
        case (int)WhichLoredrop::abillity:
            this->position = {(float)(GetScreenWidth()/2 - this->loredropAbillity.width/2*this->scaleFactor), (float)(GetScreenHeight() - this->loredropAbillity.height*this->scaleFactor - this->offset), (float)this->loredropAbillity.width, (float)this->loredropAbillity.height};
            break;

        case (int)WhichLoredrop::final:
            this->position = {(float)(GetScreenWidth()/2 - this->loredropFinal.width/2*this->scaleFactor), (float)(GetScreenHeight() - this->loredropFinal.height*this->scaleFactor - this->offset), (float)this->loredropFinal.width, (float)this->loredropFinal.height};
            break;
    }
}

void ActorLoredrop::InternRender()
{
    // position on the lower edge of screen, middle
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
            DrawTexturePro(this->loredropCheckpoint,
                           {0, 0, (float)this->loredropCheckpoint.width, (float)this->loredropCheckpoint.height},
                           {this->position.x, this->position.y, (float)this->loredropCheckpoint.width * this->scaleFactor, (float)this->loredropCheckpoint.height * this->scaleFactor},
                           {0, 0}, 0, WHITE);
            break;

        case WhichLoredrop::fourth:
            DrawTexturePro(this->loredropShack,
                           {0, 0, (float)this->loredropShack.width, (float)this->loredropShack.height},
                           {this->position.x, this->position.y, (float)this->loredropShack.width * this->scaleFactor, (float)this->loredropShack.height * this->scaleFactor},
                           {0, 0}, 0, WHITE);
            break;

        case WhichLoredrop::final:
            DrawTexturePro(this->loredropFinal,
                           {0, 0, (float)this->loredropFinal.width, (float)this->loredropFinal.height},
                           {this->position.x, this->position.y, (float)this->loredropFinal.width*this->scaleFactor, (float)this->loredropFinal.height*this->scaleFactor},
                           {0, 0}, 0, WHITE);
            break;
        case WhichLoredrop::abillity:
            DrawTexturePro(this->loredropAbillity,
                           {0, 0, (float)this->loredropAbillity.width, (float)this->loredropAbillity.height},
                           {this->position.x, this->position.y, (float)this->loredropAbillity.width*this->scaleFactor, (float)this->loredropAbillity.height*this->scaleFactor},
                           {0, 0}, 0, WHITE);
            break;

    }

}

// not used
void ActorLoredrop::Update() {}
void ActorLoredrop::Update(float) { }
void ActorLoredrop::HandleInput() { }
