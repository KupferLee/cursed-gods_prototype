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
    // WhichLoredrop currentLoredrop = WhichLoredrop::none;

    player Katara;
    bool isVisible = false;

    // Texture2D loredropBox[4];

};


#endif //RAYLIBSTARTER_ACTORLOREDROP_H
