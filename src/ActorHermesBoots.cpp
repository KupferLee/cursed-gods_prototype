//
// Created by Lee on 02.09.2022.
//

#include "ActorHermesBoots.h"

ActorHermesBoots::ActorHermesBoots()
{
    this->textureOverworld = LoadTexture("assets/graphics/Actors/Item_Boots.png");

    this->position = {8361, 3202, (float)this->textureOverworld.width, (float)this->textureOverworld.height};

    // middle of hitbox should be middle of texture
    this->hitboxPosition = {position.x + this->textureOverworld.width/2, position.y + this->textureOverworld.height/2};
}

void ActorHermesBoots::Update()
{
    if (IsKeyPressed(KEY_H) && showHitbox == false)
    {
        showHitbox = true;
    }
    else if (IsKeyPressed(KEY_H) && showHitbox == true)
    {
        showHitbox = false;
    }

    if (showHitbox == true)
    {
        DrawCircle(position.x, position.y, 10, GREEN);
    }
}

void ActorHermesBoots::Render()
{
    if (isActive == true)
    {
        DrawTexturePro(this->textureOverworld,
                       {0, 0, (float)this->textureOverworld.width, (float)this->textureOverworld.height},
                       position, {0, 0}, 0, WHITE);

        if (showHitbox == true)
        {
            DrawCircle(hitboxPosition.x, hitboxPosition.y, 10, GREEN);
        }
    }

}


Vector2 ActorHermesBoots::GetHitbox() { return hitboxPosition; };

void ActorHermesBoots::SetActive(bool b) {this->isActive = b; }

bool ActorHermesBoots::GetActive() { return this->isActive; }

// not used


void ActorHermesBoots::Update(float) {}

void ActorHermesBoots::HandleInput() {}