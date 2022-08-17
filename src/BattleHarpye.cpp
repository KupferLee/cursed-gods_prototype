//
// Created by Lee on 17.08.2022.
//

#include "BattleHarpye.h"

BattleHarpye::BattleHarpye()
{
    this->animation = LoadTexture("assets/graphics/Actors/Battle_Harpye.png");
    this->position = {0, 0};
}

void BattleHarpye::Render()
{
    DrawFrame(position, 0, 0, this->animation, 5, 1);
}

