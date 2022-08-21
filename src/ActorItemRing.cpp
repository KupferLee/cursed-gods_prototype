//
// Created by Lee on 21.08.2022.
//

#include "ActorItemRing.h"

ActorItemRing::ActorItemRing()
{
    this->textureOverworld = LoadTexture("assets/graphics/Actors/Item_Ring.png");

    this->position = {7832, 3168, (float)this->textureOverworld.width, (float)this->textureOverworld.height};
}

void ActorItemRing::Update() {}

void ActorItemRing::Render()
{
    DrawTexturePro(this->textureOverworld,
                   {0, 0, (float)this->textureOverworld.width, (float)this->textureOverworld.height},
                   position, {0, 0}, 0, WHITE);
}


// not used


void ActorItemRing::Update(float) {}

void ActorItemRing::HandleInput() {}