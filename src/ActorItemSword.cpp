//
// Created by Lee on 21.08.2022.
//

#include "ActorItemSword.h"

ActorItemSword::ActorItemSword()
{
    this->textureOverworld = LoadTexture("assets/graphics/Actors/Item_Sword.png");

    this->position = {7166, 3243, (float)this->textureOverworld.width, (float)this->textureOverworld.height};
    // middle of hitbox should be middle of texture
    this->hitboxPosition = {position.x + this->textureOverworld.width/2, position.y + this->textureOverworld.height/2};
}

void ActorItemSword::Update()
{
    if (IsKeyPressed(KEY_H) && showHitbox == false)
    {
        showHitbox = true;
    }
    else if (IsKeyPressed(KEY_H) && showHitbox == true)
    {
        showHitbox = false;
    }
}

void ActorItemSword::Render()
{
    if(isActive == true)
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

Vector2 ActorItemSword::GetHitbox() { return hitboxPosition; };

void ActorItemSword::SetActive(bool b) {this->isActive = b; }

bool ActorItemSword::GetActive() { return this->isActive; }

// not used


void ActorItemSword::Update(float) {}

void ActorItemSword::HandleInput() {}