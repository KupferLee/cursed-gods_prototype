//
// Created by Lee on 21.08.2022.
//

#include "ActorItemSword.h"

ActorItemSword::ActorItemSword()
{
    this->textureOverworld = LoadTexture("assets/graphics/Actors/Item_Sword.png");

    this->position = {1078, 1200, (float)this->textureOverworld.width, (float)this->textureOverworld.height};
}

void ActorItemSword::Update() {}

void ActorItemSword::Render()
{
    DrawTexturePro(this->textureOverworld,
                   {0, 0, (float)this->textureOverworld.width, (float)this->textureOverworld.height},
                   position, {0, 0}, 0, WHITE);
}


// not used


void ActorItemSword::Update(float) {}

void ActorItemSword::HandleInput() {}