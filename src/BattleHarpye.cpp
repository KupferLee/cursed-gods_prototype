//
// Created by Lee on 17.08.2022.
//

#include "BattleHarpye.h"

BattleHarpye::BattleHarpye()
{
    this->animation = LoadTexture("assets/graphics/Actors/Battle_Harpye.png");
    this->position = {0, 0, 32 * scaleFactor, 32 * scaleFactor};
}

void BattleHarpye::Update(float delta)
{
    this->frameTime += delta;

    if(this->frameTime >= frameDuration)
    {
        this->frame = (this->frame + 1) % 5;
        this->frameTime = 0;
    }
}

void BattleHarpye::Render()
{
    DrawFrame(this->position, frame, 0, this->animation, 5, 1);
}

