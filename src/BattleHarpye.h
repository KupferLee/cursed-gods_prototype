//
// Created by Lee on 17.08.2022.
//

#ifndef RAYLIBSTARTER_BATTLEHARPYE_H
#define RAYLIBSTARTER_BATTLEHARPYE_H

#include "BattleActor.h"

class BattleHarpye final : public BattleActor {
public:
    BattleHarpye();
    attack moves[1] = {Scratch};

    void Render();

protected:
    Texture2D animation;

    // Atributes
    float LP = 50.f;
    float AP = 2.f;

    // Moves
    attack Scratch = {5, 1, 2, DamageType::Slash, true};
    // attach Screech bricht andere Attacke ab
};


#endif //RAYLIBSTARTER_BATTLEHARPYE_H
