//
// Created by Lee on 16.08.2022.
//

#ifndef RAYLIBSTARTER_INVENTORY_H
#define RAYLIBSTARTER_INVENTORY_H

#include "GameObject.h"
#include "InventoryTemplate.h"
#include "item_base.h"
#include "item_ring.h"
#include "item_sword.h"


class Inventory : public GameObject {
protected:
    int scaleFactor = 3;
    bool isOpen = false;

    enum MenuState {Closed, Items, Options, Character, Loredrops };
    MenuState menuState = Closed;

    Texture2D textureItempageBase;
    Texture2D textureOptionsBase;
    Texture2D textureCharacterspriteBase;
    Texture2D textureLoredropsBase;
    Texture2D textureItem;
    Texture2D iconBook;

    // GUI Item select
    Texture2D itemSelect;
    Vector2 itemsSlotPosition[4]; // to determine x and y value for the slots
    int currentSlot = 0;

    void SetSlots();
    Vector2 infoPosition;
    Vector2 inventoryPosition;

    // inventory container
    item_ring* itemRing = new item_ring;
    item_sword* itemSword = new item_sword;
    Inventory_Template<item_base*, 4> inventoryContainer;

    int currentItem = 0;
    void itemAdd(item_base* item);


public:
    void Update() override;
    void Update(float) override;
    void Render() override;
    void HandleInput() override;

    int GetCurrentState();
    bool IsOpen();

    void PickUpSword();
    void PickUpRing();

    Inventory();
};


#endif //RAYLIBSTARTER_INVENTORY_H
