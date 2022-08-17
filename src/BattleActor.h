//
// Created by Lee on 17.08.2022.
//

#ifndef RAYLIBSTARTER_BATTLEACTOR_H
#define RAYLIBSTARTER_BATTLEACTOR_H

#include "raylib.h"

struct attack
{
    int damage;
    int maxTargets;
    int actionPoints;
};

class BattleActor {
public:
    virtual void GetCurrentAttack();
    virtual void Attack(attack currentAttack);

protected:


};

#endif //RAYLIBSTARTER_BATTLEACTOR_H
