//
// Created by Lee on 17.08.2022.
//

#ifndef RAYLIBSTARTER_BATTLERAT_H
#define RAYLIBSTARTER_BATTLERAT_H

#include "BattleActor.h"

class BattleRat final : public BattleActor {
public:
    BattleRat();
    attack moves[2] {Scratch, Bite};

protected:
    Texture2D Animations;

    // Attributes
    float LP = 100.f;
    float AP = 5.f;

    // Moves
    attack Scratch = {3, 1, 2, DamageType::Slash, true};
    attack Bite = {5, 1, 3, DamageType::Slash, true};
};


#endif //RAYLIBSTARTER_BATTLERAT_H
