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

    virtual void RenderAnimation(Rectangle position, int maxFramesInX, int maxFramesInY);
    virtual void UpdateAnimation(float delta, int framesInRow, float frameDuration);

protected:
    Rectangle position;
    Texture2D animation;

    float frameTime = 0.f;
    int frame = 0;

};

#endif //RAYLIBSTARTER_BATTLEACTOR_H
