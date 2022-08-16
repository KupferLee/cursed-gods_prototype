//
// Created by Lee on 16.08.2022.
//

#include "Inventory.h"

Inventory::Inventory()
{
    this->texture = LoadTexture("assets/graphics/UI/Inventory_Base_Platzhalter.png");
}

void Inventory::Update(float, std::vector<Rectangle> &) {   }

void Inventory::Update()
{
    if (IsKeyPressed(KEY_I) && isOpen == false)
    {
        isOpen = true;
    }
    else if (IsKeyPressed(KEY_I) && isOpen == true)
    {
        isOpen = false;
    }
}

void Inventory::Render()
{
    if (isOpen == true)
    {
        DrawTexturePro(this->texture,
                       {0, 0, (float)this->texture.width, (float)this->texture.height},
                       {(float)GetScreenWidth()/2 - this->texture.width, (float)GetScreenHeight()/2 - this->texture.height, (float)this->texture.width*2, (float)this->texture.height*2},
                       {0, 0}, 0, WHITE);
    }

}

void Inventory::HandleInput() {     }