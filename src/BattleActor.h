//
// Created by Lee on 17.08.2022.
//

#ifndef RAYLIBSTARTER_BATTLEACTOR_H
#define RAYLIBSTARTER_BATTLEACTOR_H

#include "raylib.h"
#include "Actor.h"
#include "DRAW.h"

enum class DamageType
{
    Pierce,
    Slash
};

struct attack
{
    int damage;
    int maxTargets;
    int actionPoints;
    DamageType damagetype;
    bool state; //true active false passive
};

class BattleActor : public DRAW {
public:
    // virtual void GetCurrentAttack();
    // virtual void Attack(attack currentAttack);

protected:
    Rectangle position;

};

#endif //RAYLIBSTARTER_BATTLEACTOR_H
