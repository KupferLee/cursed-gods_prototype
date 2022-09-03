//
// Created by Lee on 16.08.2022.
//

#include "Inventory.h"


Inventory::Inventory()
{
    this->textureItempageBase = LoadTexture("assets/graphics/UI/Inventory/Itemslots_Base.png");
    this->textureOptionsBase = LoadTexture("assets/graphics/UI/Inventory/Options_Base.png");
    this->textureCharacterspriteBase = LoadTexture("assets/graphics/UI/Inventory/Charactersprite_Base_Platzhalter.png");
    this->itemSelect = LoadTexture("assets/graphics/UI/Inventory/Slot_Select.png");
    this->iconBook = LoadTexture("assets/graphics/UI/Inventory/Icon.png");
    this->optionsSelect = LoadTexture("assets/graphics/UI/Inventory/Options_Select.png");

    this->iToOpen = LoadTexture("assets/graphics/UI/Buttons/I_To_Open.png");

    // load empty item slot to get width and height for set slots
    this->textureItem = LoadTexture("assets/graphics/UI/Inventory/Slot_Item.png");

    this->SetSlots();

}

void Inventory::PickUpSword() { itemAdd(itemSword); }

void Inventory::PickUpRing() { itemAdd(itemRing); }

void Inventory::PickUpFlower() { itemAdd(itemFlower); }

void Inventory::Update()
{
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
            if (IsKeyPressed(KEY_S) && currentSlot < currentItem-1)
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

            if (IsKeyPressed(KEY_S) && currentOption < 1)
            {
                currentOption = 1;
            }
            else if (IsKeyPressed(KEY_W) && currentOption > 0)
            {
                currentOption = 0;
            }

            if(IsKeyPressed(KEY_E))
            {
                menuState = Items;
            }
            else if (IsKeyPressed(KEY_I))
            {
                menuState = Closed;
                isOpen = false;
            }

            if (IsKeyPressed(KEY_ENTER))
            {
                if(currentOption == 0)
                {
                    menuState = Closed;
                    isOpen = false;
                    isTitle = true;
                }
                else if (currentOption == 1)
                {
                    menuState = Closed;
                    isOpen = false;
                    isExit = true;
                }
            }

            // do other stuff here
            break;

            // do other stuff here
            break;

    }

    if (IsKeyPressed(KEY_ESCAPE))
    {
        menuState = Closed;
        isOpen = false;
    }
}

void Inventory::Render()
{
    // draw icon no matter what state
    DrawTexturePro(this->iconBook,
                   {(float)this->isOpen*this->iconBook.width/2, 0, (float)this->iconBook.width/2, (float)this->iconBook.width/2},
                   {10, 10, (float)this->iconBook.width/2 * scaleFactor, (float)this->iconBook.height*scaleFactor},
                   {0, 0}, 0, WHITE);

    if (isButtonI == true)
    {
        DrawButtonPromt();
    }

    // draw Inventory
    switch (menuState)
    {
        case Items: // draw inventory
            DrawPage(this->textureItempageBase);


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
            if (currentItem > 0)
            {
                DrawTexturePro(this->itemSelect,
                               {0, 0, (float)this->itemSelect.width, (float)this->itemSelect.height},
                               {itemsSlotPosition[currentSlot].x, itemsSlotPosition[currentSlot].y, (float)this->itemSelect.width * this->scaleFactor, (float)this->itemSelect.height * this->scaleFactor},
                               {0, 0}, 0, WHITE);
            }



            break;

        case Options: // draw options
            DrawPage(this->textureOptionsBase);

            DrawTexturePro(this->optionsSelect,
                           {0, 0, (float)this->optionsSelect.width, (float)this->optionsSelect.height},
                           {this->optionSelectPosition[currentOption]},
                           {0, 0}, 0, WHITE);
            break;

        case Character: // draw charactersprite
            DrawPage(textureCharacterspriteBase);
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

    this->optionSelectPosition[0] = {(float)inventoryPosition.x + 750, (float)inventoryPosition.y + 432, (float)this->optionsSelect.width * scaleFactor, (float)this->optionsSelect.height * scaleFactor};
    this->optionSelectPosition[1] = {(float)optionSelectPosition[0].x, (float)optionSelectPosition[0].y + optionsSelect.height*scaleFactor - 8, (float)this->optionsSelect.width * scaleFactor, (float)this->optionsSelect.height * scaleFactor};
}

void Inventory::DrawPage(Texture2D texture)
{
    DrawTexturePro(texture,
                   {0, 0, (float)texture.width, (float)texture.height},
                   {(float)inventoryPosition.x, (float)inventoryPosition.y, (float)texture.width * this->scaleFactor, (float)texture.height * this->scaleFactor},
                   {0, 0}, 0, WHITE);
}

void Inventory::UpdateButtonPromt(Vector2 playerPosition)
{
    if (Vector2Distance(playerPosition, {1078, 1200}) < 20 && menuState == Closed)
    {
        isButtonI = true;
    }
    else
    {
        isButtonI = false;
    }
}

void Inventory::DrawButtonPromt()
{
    DrawTexturePro(iToOpen,
                   {0, 0, (float)iToOpen.width, (float)iToOpen.height},
                   {(float)10 + iconBook.width*scaleFactor/2, (float)40, (float)this->iToOpen.width * scaleFactor, (float)this->iToOpen.height*scaleFactor},
                   {0, 0}, 0, WHITE);
}

int Inventory::GetCurrentState() { return menuState; }

bool Inventory::ShouldWindowClose() { return isExit; }

bool Inventory::ShouldGoTitle() { return isTitle; }

void Inventory::SetReturnTitle(bool title) { isTitle = title; }

void Inventory::HandleInput() { }

void Inventory::Update(float) { }