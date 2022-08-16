//
// Created by Lee on 16.08.2022.
//

#include "Inventory.h"

Inventory::Inventory()
{
    this->texture = LoadTexture("assets/graphics/UI/Inventory_Base_Platzhalter.png");
    this->textureRing = LoadTexture("assets/graphics/UI/Slot_Ring.png");

    // assign x and y position for every slot
    this->slotPosition[0].x = GetScreenWidth()/2 - this->textureRing.width * scaleFactor;
    this->slotPosition[0].y = GetScreenHeight()/2 - this->textureRing.height * this->scaleFactor;

    this->slotPosition[1].x = this->slotPosition[0].x;
    this->slotPosition[1].y = this->slotPosition[0].y + this->textureRing.height * this->scaleFactor;

    this->slotPosition[2].x = this->slotPosition[0].x;
    this->slotPosition[2].y = this->slotPosition[1].y + this->textureRing.height * this->scaleFactor;

    this->slotPosition[3].x = this->slotPosition[0].x;
    this->slotPosition[3].y = this->slotPosition[2].y + this->textureRing.height * this->scaleFactor;
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
    // draw Inventory
    if (isOpen == true)
    {
        DrawTexturePro(this->texture,
                       {0, 0, (float)this->texture.width, (float)this->texture.height},
                       {(float)GetScreenWidth()/2 - this->texture.width, (float)GetScreenHeight()/2 - this->texture.height, (float)this->texture.width*this->scaleFactor, (float)this->texture.height*this->scaleFactor},
                       {0, 0}, 0, WHITE);
    }

    // draw items
    for (int i = 0; i < 4; i++)
    {
        if (this->currentItem > i)
        {
            DrawTexturePro(this->textureRing,
                           {0, 0, (float)this->textureRing.width, (float)this->textureRing.height},
                           {slotPosition[i].x, slotPosition[i].y, (float)this->textureRing.width*this->scaleFactor, (float)this->textureRing.height*this->scaleFactor},
                           {0, 0}, 0, WHITE);
        }
        // this->slotOffset = this->slotOffset + textureRing.height;

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