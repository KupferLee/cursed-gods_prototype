//
// Created by Lee on 16.08.2022.
//

#include "Inventory.h"

Inventory::Inventory()
{
    this->textureItempageBase = LoadTexture("assets/graphics/UI/Inventory/Itemslots_Base.png");
    this->textureOptionsBase = LoadTexture("assets/graphics/UI/Inventory/Options_Base.png");
    this->textureCharacterspriteBase = LoadTexture("assets/graphics/UI/Inventory/Charactersprite_Base_Platzhalter.png");
    this->textureLoredropsBase = LoadTexture("assets/graphics/UI/Inventory/Loredrops_Base_Platzhalter.png");
    this->itemSelect = LoadTexture("assets/graphics/UI/Inventory/Slot_Select.png");
    this->iconBook = LoadTexture("assets/graphics/UI/Inventory/Icon.png");

    // load empty item slot to get width and height for set slots
    this->textureItem = LoadTexture("assets/graphics/UI/Inventory/Slot_Item.png");

    this->SetSlots();

}

void Inventory::PickUpSword() { itemAdd(itemSword); }

void Inventory::PickUpRing() { itemAdd(itemRing); }

void Inventory::Update()
{
    /*
    // add items for debug
    if(IsKeyPressed(KEY_K))
    {
        itemAdd(itemRing);
    }
    if(IsKeyPressed(KEY_J))
    {
        itemAdd(itemSword);
    }
     */


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
                isOpen = false;
            }

            // do other stuff here
            break;

    }
}

void Inventory::Render()
{
    // draw icon no matter what state
    DrawTexturePro(this->iconBook,
                   {(float)this->isOpen*this->iconBook.width/2, 0, (float)this->iconBook.width/2, (float)this->iconBook.width/2},
                   {10, 10, (float)this->iconBook.width/2 * scaleFactor, (float)this->iconBook.height*scaleFactor},
                   {0, 0}, 0, WHITE);

    // draw Inventory
    switch (menuState)
    {
        case Items: // draw inventory
            DrawTexturePro(this->textureItempageBase,
                           {0, 0, (float)this->textureItempageBase.width, (float)this->textureItempageBase.height},
                           {(float)this->inventoryPosition.x, (float)this->inventoryPosition.y, (float)this->textureItempageBase.width * this->scaleFactor, (float)this->textureItempageBase.height * this->scaleFactor},
                           {0, 0}, 0, WHITE);

            // draw items
            for (int i = 0; i < 4; i++)
            {
                if (this->currentItem > i)
                {
                    // draw itemslot
                    DrawTexturePro(this->inventoryContainer.getItem(i)->GetTexture(),
                                   {0, 0, (float)this->inventoryContainer.getItem(i)->GetTexture().width, (float)this->inventoryContainer.getItem(i)->GetTexture().height},
                                   {itemsSlotPosition[i].x, itemsSlotPosition[i].y, (float)this->inventoryContainer.getItem(i)->GetTexture().width * this->scaleFactor, (float)this->inventoryContainer.getItem(i)->GetTexture().height * this->scaleFactor},
                                   {0, 0}, 0, WHITE);

                    // draw texture_infos if there is a item in the slot selected
                    if (this->inventoryContainer.getItem(currentSlot) != NULL)
                    {
                        DrawTexturePro(this->inventoryContainer.getItem(currentSlot)->GetInfos(),
                                       {0, 0, (float)this->inventoryContainer.getItem(i)->GetInfos().width, (float)this->inventoryContainer.getItem(i)->GetInfos().height},
                                       {this->infoPosition.x, this->infoPosition.y, (float)this->inventoryContainer.getItem(i)->GetInfos().width*this->scaleFactor, (float)this->inventoryContainer.getItem(i)->GetInfos().height*this->scaleFactor},
                                       {0, 0}, 0, WHITE);
                    }

                }

            }

            // draw select
            DrawTexturePro(this->itemSelect,
                           {0, 0, (float)this->itemSelect.width, (float)this->itemSelect.height},
                           {itemsSlotPosition[currentSlot].x, itemsSlotPosition[currentSlot].y, (float)this->itemSelect.width * this->scaleFactor, (float)this->itemSelect.height * this->scaleFactor},
                           {0, 0}, 0, WHITE);


            break;

        case Options: // draw options
            DrawTexturePro(this->textureOptionsBase,
                           {0, 0, (float)this->textureOptionsBase.width, (float)this->textureOptionsBase.height},
                           {(float)this->inventoryPosition.x, (float)this->inventoryPosition.y, (float)this->textureOptionsBase.width * this->scaleFactor, (float)this->textureOptionsBase.height * this->scaleFactor},
                           {0, 0}, 0, WHITE);
            break;

        case Character: // draw charactersprite
            DrawTexturePro(this->textureCharacterspriteBase,
                           {0, 0, (float)this->textureCharacterspriteBase.width, (float)this->textureCharacterspriteBase.height},
                           {(float)this->inventoryPosition.x, (float)this->inventoryPosition.y, (float)this->textureCharacterspriteBase.width * this->scaleFactor, (float)this->textureCharacterspriteBase.height * this->scaleFactor},
                           {0, 0}, 0, WHITE);
            break;

        case Loredrops:
            DrawTexturePro(this->textureLoredropsBase,
                           {0, 0, (float)this->textureLoredropsBase.width, (float)this->textureLoredropsBase.height},
                           {(float)this->inventoryPosition.x, (float)this->inventoryPosition.y, (float)this->textureLoredropsBase.width * this->scaleFactor, (float)this->textureLoredropsBase.height * this->scaleFactor},
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

void Inventory::SetSlots()
{
    // assign position for Info draw
    this->infoPosition = {(float)GetScreenWidth()/2 + 60, (float)GetScreenHeight()/2 - 325};
    this->inventoryPosition = {(float)GetScreenWidth()/2 - (this->textureItempageBase.width * scaleFactor / 2), (float)GetScreenHeight() / 2 - (this->textureItempageBase.height * scaleFactor / 2)};

    // assign x and y position for every slot
    // currently putting -90 is a quick and dirty solution only for the Platzhalter
    this->itemsSlotPosition[0].x = GetScreenWidth() / 2 - this->textureItem.width * scaleFactor - 127;
    this->itemsSlotPosition[0].y = GetScreenHeight() / 2 - this->textureItem.height * this->scaleFactor - 143;

    this->itemsSlotPosition[1].x = this->itemsSlotPosition[0].x;
    this->itemsSlotPosition[1].y = this->itemsSlotPosition[0].y + this->textureItem.height * this->scaleFactor;

    this->itemsSlotPosition[2].x = this->itemsSlotPosition[0].x;
    this->itemsSlotPosition[2].y = this->itemsSlotPosition[1].y + this->textureItem.height * this->scaleFactor;

    this->itemsSlotPosition[3].x = this->itemsSlotPosition[0].x;
    this->itemsSlotPosition[3].y = this->itemsSlotPosition[2].y + this->textureItem.height * this->scaleFactor;
}

int Inventory::GetCurrentState() { return menuState; }

void Inventory::HandleInput() { }

void Inventory::Update(float) { }