//
// Created by Lee on 17.08.2022.
//

#include "BattleRat.h"

BattleRat::BattleRat()
{
    this->animation = LoadTexture("assets/graphics/Actors/Rat_Animations.png");
    this->healthBar = LoadTexture("assets/graphics/Actors/health_bar.png");
}
