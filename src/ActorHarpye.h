//
// Created by Lee on 18.08.2022.
//

#ifndef RAYLIBSTARTER_ACTORHARPYE_H
#define RAYLIBSTARTER_ACTORHARPYE_H

#include "Actor.h"
#include "player.h"

class ActorHarpye : public Actor{
public:
    ActorHarpye();

    void Update() override;
    void Update(float) override;
    void Render() override;
    void HandleInput()override;

protected:
    player Katara;

};


#endif //RAYLIBSTARTER_ACTORHARPYE_H
