//
// Created by Lee on 16.08.2022.
//

#include "Inventory.h"

Inventory::Inventory()
{
    this->textureInventoryBase = LoadTexture("assets/graphics/UI/Inventory_Base_Platzhalter.png");
    this->textureOptionsBase = LoadTexture("assets/graphics/UI/Options_Base_Platzhalter.png");
    this->textureCharacterspriteBase = LoadTexture("assets/graphics/UI/Charactersprite_Base_Platzhalter.png");
    this->textureLoredropsBase = LoadTexture("assets/graphics/UI/Loredrops_Base_Platzhalter.png");
    this->slotSelect = LoadTexture("assets/graphics/UI/Slot_Select.png");

    this->textureRing = LoadTexture("assets/graphics/UI/Slot_Ring.png");

    // assign x and y position for every slot
    // currently putting -90 is a quick and dirty solution only for the Platzhalter
    this->slotPosition[0].x = GetScreenWidth()/2 - this->textureRing.width * scaleFactor - 80;
    this->slotPosition[0].y = GetScreenHeight()/2 - this->textureRing.height * this->scaleFactor - 90;

    this->slotPosition[1].x = this->slotPosition[0].x;
    this->slotPosition[1].y = this->slotPosition[0].y + this->textureRing.height * this->scaleFactor;

    this->slotPosition[2].x = this->slotPosition[0].x;
    this->slotPosition[2].y = this->slotPosition[1].y + this->textureRing.height * this->scaleFactor;

    this->slotPosition[3].x = this->slotPosition[0].x;
    this->slotPosition[3].y = this->slotPosition[2].y + this->textureRing.height * this->scaleFactor;
}

void Inventory::Update()
{
    // add items for debug
    if(IsKeyPressed(KEY_K))
    {
        itemAdd(itemRing);
    }
    if(IsKeyPressed(KEY_J))
    {
        itemAdd(itemSword);
    }


    switch (menuState)
    {
        case Closed:
            // open inventory
            if (IsKeyPressed(KEY_I))
            {
                menuState = Items;
                isOpen = true;
            }
            break;

        case Items:
            // switch menu state
            if(IsKeyPressed(KEY_E))
            {
                menuState = Character;
            }
            else if (IsKeyPressed(KEY_Q))
            {
                menuState = Options;
            }
            else if (IsKeyPressed(KEY_I))
            {
                menuState = Closed;
                isOpen = false;
            }

            // navigate items
            if (IsKeyPressed(KEY_S) && currentSlot < 3)
            {
                currentSlot++;
            }
            else if (IsKeyPressed(KEY_W) && currentSlot > 0)
            {
                currentSlot--;
            }
            break;

        case Character:
            // switch menu state
            if (IsKeyPressed(KEY_Q))
            {
                menuState = Items;
            }
            else if (IsKeyPressed(KEY_E))
            {
                menuState = Loredrops;
            }
            else if (IsKeyPressed(KEY_I))
            {
                menuState = Closed;
                isOpen = false;
            }

            // do other stuff here
            break;

        case Options:

            if(IsKeyPressed(KEY_E))
            {
                menuState = Items;
            }
            else if (IsKeyPressed(KEY_I))
            {
                menuState = Closed;
                isOpen = false;
            }

            // do other stuff here
            break;

        case Loredrops:
            if (IsKeyPressed(KEY_Q))
            {
                menuState = Character;
            }
            else if (IsKeyPressed(KEY_I))
            {
                menuState = Closed;
            }

            // do other stuff here
            break;

    }
}

void Inventory::Render()
{
    // draw Inventory
    switch (menuState)
    {
        case Items: // draw inventory
            DrawTexturePro(this->textureInventoryBase,
                           {0, 0, (float)this->textureInventoryBase.width, (float)this->textureInventoryBase.height},
                           {(float)GetScreenWidth()/2 - this->textureInventoryBase.width, (float)GetScreenHeight() / 2 - this->textureInventoryBase.height, (float)this->textureInventoryBase.width * this->scaleFactor, (float)this->textureInventoryBase.height * this->scaleFactor},
                           {0, 0}, 0, WHITE);

            // draw items
            for (int i = 0; i < 4; i++)
            {
                if (this->currentItem > i)
                {
                    // draw itemslot
                    DrawTexturePro(this->inventoryContainer.getItem(i)->GetTexture(),
                                   {0, 0, (float)this->inventoryContainer.getItem(i)->GetTexture().width, (float)this->inventoryContainer.getItem(i)->GetTexture().height},
                                   {slotPosition[i].x, slotPosition[i].y, (float)this->inventoryContainer.getItem(i)->GetTexture().width*this->scaleFactor, (float)this->inventoryContainer.getItem(i)->GetTexture().height*this->scaleFactor},
                                   {0, 0}, 0, WHITE);

                    // draw infos if there is a item in the slot selected
                    if (this->inventoryContainer.getItem(currentSlot) != NULL)
                    {
                        DrawTexturePro(this->inventoryContainer.getItem(currentSlot)->GetTexture(),
                                       {0, 0, (float)this->inventoryContainer.getItem(i)->GetTexture().width, (float)this->inventoryContainer.getItem(i)->GetTexture().height},
                                       {(float)GetScreenWidth()/2 + 60, (float)GetScreenHeight()/2, (float)this->inventoryContainer.getItem(i)->GetTexture().width*this->scaleFactor, (float)this->inventoryContainer.getItem(i)->GetTexture().height*this->scaleFactor},
                                       {0, 0}, 0, WHITE);
                    }

                }

            }

            // draw select
            DrawTexturePro(this->slotSelect,
                           {0, 0, (float)this->slotSelect.width, (float)this->slotSelect.height},
                           {slotPosition[currentSlot].x, slotPosition[currentSlot].y, (float)this->slotSelect.width*this->scaleFactor, (float)this->slotSelect.height*this->scaleFactor},
                           {0, 0}, 0, WHITE);


            break;

        case Options: // draw options
            DrawTexturePro(this->textureOptionsBase,
                           {0, 0, (float)this->textureOptionsBase.width, (float)this->textureOptionsBase.height},
                           {(float)GetScreenWidth()/2 - this->textureOptionsBase.width, (float)GetScreenHeight() / 2 - this->textureOptionsBase.height, (float)this->textureOptionsBase.width * this->scaleFactor, (float)this->textureOptionsBase.height * this->scaleFactor},
                           {0, 0}, 0, WHITE);
            break;

        case Character: // draw charactersprite
            DrawTexturePro(this->textureCharacterspriteBase,
                           {0, 0, (float)this->textureCharacterspriteBase.width, (float)this->textureCharacterspriteBase.height},
                           {(float)GetScreenWidth()/2 - this->textureCharacterspriteBase.width, (float)GetScreenHeight() / 2 - this->textureCharacterspriteBase.height, (float)this->textureCharacterspriteBase.width * this->scaleFactor, (float)this->textureCharacterspriteBase.height * this->scaleFactor},
                           {0, 0}, 0, WHITE);
            break;

        case Loredrops:
            DrawTexturePro(this->textureLoredropsBase,
                           {0, 0, (float)this->textureLoredropsBase.width, (float)this->textureLoredropsBase.height},
                           {(float)GetScreenWidth()/2 - this->textureLoredropsBase.width, (float)GetScreenHeight() / 2 - this->textureLoredropsBase.height, (float)this->textureLoredropsBase.width * this->scaleFactor, (float)this->textureLoredropsBase.height * this->scaleFactor},
                           {0, 0}, 0, WHITE);
            break;

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

bool Inventory::IsOpen() { return isOpen; }

int Inventory::GetCurrentState() { return menuState; }

void Inventory::HandleInput() { }

void Inventory::Update(float) { }