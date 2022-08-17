//
// Created by Lee on 17.08.2022.
//

#ifndef RAYLIBSTARTER_BATTLEPLAYER_H
#define RAYLIBSTARTER_BATTLEPLAYER_H

#include "BattleActor.h"


class BattlePlayer final : public BattleActor {
public:
    BattlePlayer();
    attack moves[4] {Slash, Arrow,ArrowRain};

private:
    Texture2D Animations;

    //Attributes
    float LP = 200.f;
    float AP = 5.f;

    //Moves
    attack Slash = {15,1,2, DamageType::Slash,true};
    attack Arrow = {15,1,2, DamageType::Pierce, true};
    attack ArrowRain = {15, 3, 5, DamageType::Pierce, true};



};


#endif //RAYLIBSTARTER_BATTLEPLAYER_H
