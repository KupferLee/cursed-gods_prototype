//
// Created by Lee on 02.09.2022.
//

#ifndef RAYLIBSTARTER_ACTORITEMFLOWER_H
#define RAYLIBSTARTER_ACTORITEMFLOWER_H

#include "Actor.h"

class ActorItemFlower : public Actor {
public:
    ActorItemFlower();

    void Update() override;
    void Update(float) override;
    void Render() override;
    void HandleInput()override;

    Vector2 GetHitbox();
    void SetActive(bool b);
    bool GetActive();


};


#endif //RAYLIBSTARTER_ACTORITEMFLOWER_H
