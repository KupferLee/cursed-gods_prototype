//
// Created by Lee on 21.08.2022.
//

#include "ActorItemRing.h"

ActorItemRing::ActorItemRing()
{
    this->textureOverworld = LoadTexture("assets/graphics/Actors/Item_Ring.png");

    this->position = {7832, 3168, (float)this->textureOverworld.width, (float)this->textureOverworld.height};

    // middle of hitbox should be middle of texture
    this->hitboxPosition = {position.x + this->textureOverworld.width/2, position.y + this->textureOverworld.height/2};
}

void ActorItemRing::Update()
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

void ActorItemRing::Render()
{
    DrawTexturePro(this->textureOverworld,
                   {0, 0, (float)this->textureOverworld.width, (float)this->textureOverworld.height},
                   position, {0, 0}, 0, WHITE);

    if (showHitbox == true)
    {
        DrawCircle(hitboxPosition.x, hitboxPosition.y, 10, GREEN);
    }
}


Vector2 ActorItemRing::GetHitbox() { return hitboxPosition; };

// not used


void ActorItemRing::Update(float) {}

void ActorItemRing::HandleInput() {}