//
// Created by Lee on 21.08.2022.
//

#include "ActorRat.h"

ActorRat::ActorRat()
{
    this->animation = LoadTexture("assets/graphics/Actors/Rat_Animations.png");
}

void ActorRat::Update()
{
    UpdateAnimation(GetFrameTime(), 6, 0.22f);
}

void ActorRat::RenderRat(Vector2 position)
{
    RenderAnimation({position.x, position.y, 48, 32}, 11, 2);
}

// unused
void ActorRat::Update(float) {}

void ActorRat::Render() {}

void ActorRat::HandleInput() {}