//
// Created by Lee on 18.08.2022.
//

#ifndef RAYLIBSTARTER_ACTORLOREDROP_H
#define RAYLIBSTARTER_ACTORLOREDROP_H

#include "Actor.h"
#include "player.h"

enum class WhichLoredrop
{
    base,
    first,
    second,
    third,
    none
};

class ActorLoredrop : public Actor {
public:
    ActorLoredrop();

    void Update() override;
    void Update(float) override;
    void Render() override;

    void HandleInput()override;

protected:
    //enum WhichLoredrop;
    WhichLoredrop currentLoredrop = WhichLoredrop::none;

    int current = 0;
    player Katara;

    Texture2D loredropBase;
    Texture2D loredropOne;
    Texture2D loredropTwo;
    Texture2D loredropThree;

private:
    void InternUpdate();
    void InternRender();

};


#endif //RAYLIBSTARTER_ACTORLOREDROP_H
