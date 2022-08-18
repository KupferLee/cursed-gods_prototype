//
// Created by Lee on 18.08.2022.
//

#ifndef RAYLIBSTARTER_ACTORLOREDROP_H
#define RAYLIBSTARTER_ACTORLOREDROP_H

#include "Actor.h"
#include "player.h"

class ActorLoredrop : public Actor {
public:
    ActorLoredrop();

    void Update() override;
    void Update(float) override;
    void Render() override;

    void HandleInput()override;

protected:
    player Katara;

};


#endif //RAYLIBSTARTER_ACTORLOREDROP_H
