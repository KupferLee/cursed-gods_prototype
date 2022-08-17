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
    int scaleFactor = 2;
    bool isOpen = false;

    enum MenuState {None, Items, Options, Character, Loredrops };
    MenuState menuState = None;

    Texture2D textureInventoryBase;
    Texture2D textureOptionsBase;
    Texture2D textureCharacterspriteBase;
    Texture2D textureLoredropsBase;
    Texture2D textureRing;

    // GUI Item select
    Texture2D slotSelect;
    Vector2 slotPosition[4]; // to determine x and y value for the slots
    int currentSlot = 0;
    // Vector2 infoPosition;

    // inventory container
    item_ring* itemRing = new item_ring;
    item_sword* itemSword = new item_sword;
    Inventory_Template<item_base*, 4> inventoryContainer;

    int currentItem = 0;
    void itemAdd(item_base* item);


public:
    void Update() override;
    void Update(float, std::vector<Rectangle> &) override;
    void Render() override;
    void HandleInput() override;

    bool IsOpen();

    Inventory();
};


#endif //RAYLIBSTARTER_INVENTORY_H
