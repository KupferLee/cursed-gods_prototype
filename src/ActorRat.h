//
// Created by Lee on 21.08.2022.
//

#ifndef RAYLIBSTARTER_ACTORRAT_H
#define RAYLIBSTARTER_ACTORRAT_H

#include "Actor.h"

class ActorRat : public Actor {
public:
    ActorRat();

    // use this render
    void RenderRat (Vector2 position);

    void Update() override;
    void Update(float) override;
    void Render() override;

    void HandleInput()override;

};


#endif //RAYLIBSTARTER_ACTORRAT_H
