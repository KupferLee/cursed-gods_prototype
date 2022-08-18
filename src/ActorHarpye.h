//
// Created by Lee on 18.08.2022.
//

#ifndef RAYLIBSTARTER_ACTORHARPYE_H
#define RAYLIBSTARTER_ACTORHARPYE_H

#include "Actor.h"
#include "player.h"

class ActorHarpye : public Actor {
public:
    ActorHarpye();

    // use this render
    void RenderHarpye (Vector2 position);

    void Update() override;
    void Update(float) override;
    void Render() override;

    void HandleInput()override;


};


#endif //RAYLIBSTARTER_ACTORHARPYE_H
