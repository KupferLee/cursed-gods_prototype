//
// Created by Lee on 21.08.2022.
//

#ifndef RAYLIBSTARTER_ACTORITEMRING_H
#define RAYLIBSTARTER_ACTORITEMRING_H

#include "Actor.h"

class ActorItemRing : public Actor {
public:
    ActorItemRing();

    void Update() override;
    void Update(float) override;
    void Render() override;

    void HandleInput()override;

protected:
    Texture2D textureOverworld;
};


#endif //RAYLIBSTARTER_ACTORITEMRING_H
