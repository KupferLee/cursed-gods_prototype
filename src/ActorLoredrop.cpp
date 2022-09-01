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
    this->loredropHorse = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Horse.png");
    this->loredropCanyonOversight = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Canyon_Oversight.png");
    this->loredropCheckpoint = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Checkpoint.png");
    this->loredropShack = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Hut.png");
    this->loredropAbillity =LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Boots.png");
    this->loredropFinal = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Towerentry.png");

    // position loredrop on screen
    this->position = {(float)(GetScreenWidth()/2 - this->loredropBase.width/2*this->scaleFactor), (float)(GetScreenHeight() - this->loredropBase.height*this->scaleFactor - this->offset), (float)this->loredropBase.width, (float)this->loredropBase.height};
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
        this->currentLoredrop = WhichLoredrop::horse;
    }
    else if (Vector2Distance(currentPosition, this->posDrop_Canyon_Oversight) < 50)
    {
        this->currentLoredrop = WhichLoredrop::canyonOversight;
    }
    else if (Vector2Distance(currentPosition, this->posDrop_Checkpoint) < 50)
    {
        this->currentLoredrop = WhichLoredrop::checkpoint;
        // activate checkpoint when loredrop gets triggered horse time
        // each checkpoint has a assigned id
    }
    else if (Vector2Distance(currentPosition, this->posDrop_Shack) < 50)
    {
        this->currentLoredrop = WhichLoredrop::shack;
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

    // InternUpdate();
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
        DrawCircle(this->posDrop_Shack.x, this->posDrop_Shack.y, 50, DARKBLUE);
        DrawCircle(this->posDrop_final.x, this->posDrop_final.y, 50, DARKBLUE);

    }

}

int ActorLoredrop::GetCurrentCheckpointID() { return this->whichCheckpointIsActive; }

void ActorLoredrop::InternRender()
{
    // position on the lower edge of screen, middle
    // specific for every loredrop weil texture
    switch (currentLoredrop)
    {
        case WhichLoredrop::base:
            DrawTextbox(this->loredropBase);
            break;

        case WhichLoredrop::horse:
            DrawTextbox(this->loredropHorse);
            break;

        case WhichLoredrop::canyonOversight:
            DrawTextbox(this->loredropCanyonOversight);
            break;

        case WhichLoredrop::checkpoint:
            DrawTextbox(this->loredropCheckpoint);
            break;

        case WhichLoredrop::shack:
            DrawTextbox(this->loredropShack);
            break;

        case WhichLoredrop::final:
            DrawTextbox(this->loredropFinal);
            break;
        case WhichLoredrop::abillity:
            DrawTextbox(this->loredropAbillity);
            break;

    }

}

void ActorLoredrop::DrawTextbox(Texture2D texture)
{
    DrawTexturePro(texture,
                   {0, 0, (float)texture.width, (float)texture.height},
                   {this->position.x, this->position.y, (float)texture.width*this->scaleFactor, (float)texture.height*this->scaleFactor},
                   {0, 0}, 0, WHITE);
}

// not used
void ActorLoredrop::Update() {}
void ActorLoredrop::Update(float) { }
void ActorLoredrop::HandleInput() { }
