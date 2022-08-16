//
// Created by Lee on 16.08.2022.
//

#include "Inventory.h"

Inventory::Inventory()
{
    this->texture = LoadTexture("assets/graphics/UI/Inventory_Platzhalter.png");
}

void Inventory::Update(float, std::vector<Rectangle> &) {   }

void Inventory::Update() {  }

void Inventory::Render()
{
    DrawTexturePro(this->texture,
                   {0, 0, (float)this->texture.width, (float)this->texture.height},
                   {(float)GetScreenWidth()/2 - this->texture.width/2*this->texture.width, (float)GetScreenHeight() / 2 - this->texture.height, (float)this->texture.width, (float)this->texture.height},
                   {0, 0}, 0, WHITE);
}

void Inventory::HandleInput() {     }