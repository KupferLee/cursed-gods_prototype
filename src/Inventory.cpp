//
// Created by Lee on 16.08.2022.
//

#include "Inventory.h"

Inventory::Inventory()
{
    this->texture = LoadTexture("assets/graphics/UI/Inventory_Base_Platzhalter.png");
}

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

    if(IsKeyPressed(KEY_K))
    {
        itemAdd(itemRing);
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

// add any item to the inventory that is an array
// then go one slot further in the array
void Inventory::itemAdd(item_base *item)
{
    if (this->currentItem < 4)
    {
        inventoryContainer.setItem(item, this->currentItem);

        this->currentItem++;
    }
    else
    {
        std::cout << "DEBUG: Inventory full." << std::endl;
    }
}

void Inventory::HandleInput() { }

void Inventory::Update(float, std::vector<Rectangle> &) { }