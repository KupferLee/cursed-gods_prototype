//
// Created by Lee on 02.09.2022.
//

#ifndef RAYLIBSTARTER_ACTORHERMESBOOTS_H
#define RAYLIBSTARTER_ACTORHERMESBOOTS_H

#include "Actor.h"

class ActorHermesBoots : public Actor {
public:
    ActorHermesBoots();
    void Update() override;
    void Update(float) override;
    void Render() override;
    void HandleInput()override;

    Vector2 GetHitbox();
    void SetActive(bool b);
    bool GetActive();

};


#endif //RAYLIBSTARTER_ACTORHERMESBOOTS_H
