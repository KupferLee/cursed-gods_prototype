//
// Created by Lee on 02.09.2022.
//

#include "ActorItemFlower.h"

ActorItemFlower::ActorItemFlower()
{
    this->animation = LoadTexture("assets/graphics/Actors/GlowFlower_Animation.png");

    this->position = {4914, 2943, (float)16, (float)32};

    // middle of hitbox should be middle of texture
    this->hitboxPosition = {position.x + this->position.width/2, position.y + this->position.height/2};
}

void ActorItemFlower::Update()
{
    UpdateAnimation(GetFrameTime(), 10, 0.22f);

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

void ActorItemFlower::Render()
{
    if (isActive == true)
    {
        RenderAnimation(position, 10, 1);

        if (showHitbox == true)
        {
            DrawCircle(hitboxPosition.x, hitboxPosition.y, 10, GREEN);
        }
    }

}

Vector2 ActorItemFlower::GetHitbox() { return hitboxPosition; };

void ActorItemFlower::SetActive(bool b) {this->isActive = b; }

bool ActorItemFlower::GetActive() { return this->isActive; }

// not used


void ActorItemFlower::Update(float) {}

void ActorItemFlower::HandleInput() {}