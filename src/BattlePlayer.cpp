//
// Created by Lee on 17.08.2022.
//

#include "BattlePlayer.h"


BattlePlayer::BattlePlayer()
{
    this->animation = LoadTexture("assets/graphics/Actors/katara_animations.png");
    this->healthBar = LoadTexture("assets/graphics/Actors/health_bar.png");
}
