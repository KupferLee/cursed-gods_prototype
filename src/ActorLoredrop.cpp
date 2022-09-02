//
// Created by Lee on 18.08.2022.
//

#include "ActorLoredrop.h"
#include "iostream"


ActorLoredrop::ActorLoredrop()
{
    this->loredropBase = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Template.png");
    this->loredropHorse = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Horse.png");
    this->loredropCanyonOversight = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Canyon_Oversight.png");
    this->loredropCheckpoint = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Checkpoint.png");
    this->loredropShack = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Hut.png");
    this->loredropAbillity = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_HermesBoots.png");
    this->loredropFinal = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Towerentry.png");

    this->loredropEntrance = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Entrance.png");
    this->loredropRing = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Ring.png");
    this->loredropExit = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_ExitCave.png");
    this->loredropHarpy = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Harpy.png");
    this->loredropFlower = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Flower.png");
    this->loredropSword = LoadTexture("assets/graphics/UI/Textboxes/Loredrop_Sword.png");
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

    else if (Vector2Distance(currentPosition, this->posDrop_Entrance) < 100)
    {
        this->currentLoredrop = WhichLoredrop::entrance;
    }
    else if (Vector2Distance(currentPosition, this->posDrop_Ring) < 25)
    {
        this->currentLoredrop = WhichLoredrop::ring;
    }
    else if (Vector2Distance(currentPosition, this->posDrop_Exit) < 100)
    {
        this->currentLoredrop = WhichLoredrop::exit;
    }
    else if (Vector2Distance(currentPosition, this->posDrop_Harpye) < 300)
    {
        this->currentLoredrop = WhichLoredrop::harpy;
    }
    else if (Vector2Distance(currentPosition, this->posDrop_Flower) < 25)
    {
        this->currentLoredrop = WhichLoredrop::flower;
    }
    else if (Vector2Distance(currentPosition, this->posDrop_Sword) < 25)
    {
        this->currentLoredrop = WhichLoredrop::sword;
    }

    else
    {
        this->currentLoredrop = WhichLoredrop::none;
    }
}

void ActorLoredrop::Render()
{
    InternRender();
}

void ActorLoredrop::DrawHitbox()
{
    if (this->isHitboxVisible == true)
    {

        DrawCircle(this->posDrop_Horse.x, this->posDrop_Horse.y, 50, DARKBLUE);
        DrawCircle(this->posDrop_Canyon_Oversight.x, this->posDrop_Canyon_Oversight.y, 50, DARKBLUE);
        DrawCircle(this->posDrop_Checkpoint.x, this->posDrop_Checkpoint.y, 50, DARKBLUE);
        DrawCircle(this->posDrop_Shack.x, this->posDrop_Shack.y, 50, DARKBLUE);
        DrawCircle(this->posDrop_final.x, this->posDrop_final.y, 50, DARKBLUE);

        DrawCircle(this->posDrop_Entrance.x, this->posDrop_Entrance.y, 100, DARKBLUE);
        DrawCircle(this->posDrop_Ring.x, this->posDrop_Ring.y, 25, DARKBLUE);
        DrawCircle(this->posDrop_Exit.x, this->posDrop_Exit.y, 100, DARKBLUE);
        DrawCircle(this->posDrop_Harpye.x, this->posDrop_Harpye.y, 300, DARKBLUE);
        DrawCircle(this->posDrop_Flower.x, this->posDrop_Flower.y, 25, DARKBLUE);
        DrawCircle(this->posDrop_Sword.x, this->posDrop_Sword.y, 25, DARKBLUE);

    }

}

int ActorLoredrop::GetCurrentCheckpointID() { return this->whichCheckpointIsActive; }

void ActorLoredrop::InternRender()
{
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


        case WhichLoredrop::entrance:
            DrawTextbox(this->loredropEntrance);
            break;

        case WhichLoredrop::ring:
            DrawTextbox(this->loredropRing);
            break;

        case WhichLoredrop::exit:
            DrawTextbox(this->loredropExit);
            break;

        case WhichLoredrop::harpy:
            DrawTextbox(this->loredropHarpy);
            break;

        case WhichLoredrop::flower:
            DrawTextbox(this->loredropFlower);
            break;

        case WhichLoredrop::sword:
            DrawTextbox(this->loredropSword);
            break;
    }

}

void ActorLoredrop::DrawTextbox(Texture2D texture)
{
    // position on the lower edge of screen, middle
    // in relation to current texture
    DrawTexturePro(texture,
                   {0, 0, (float)texture.width, (float)texture.height},
                   {(float)(GetScreenWidth()/2 - this->loredropBase.width/2*this->scaleFactor), (float)(GetScreenHeight() - this->loredropBase.height*this->scaleFactor - this->offset), (float)texture.width*this->scaleFactor, (float)texture.height*this->scaleFactor},
                   {0, 0}, 0, WHITE);
}

// not used bc it doesnt work
void ActorLoredrop::LoredropCollision(Vector2 playerPos, Vector2 lorePos, WhichLoredrop loredrop)
{
    if (Vector2Distance(playerPos, lorePos) < 50)
    {
        this->currentLoredrop = loredrop;
    }
}

// not used
void ActorLoredrop::Update() {}
void ActorLoredrop::Update(float) { }
void ActorLoredrop::HandleInput() { }
