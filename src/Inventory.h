//
// Created by Lee on 16.08.2022.
//

#ifndef RAYLIBSTARTER_INVENTORY_H
#define RAYLIBSTARTER_INVENTORY_H

#include "GameObject.h"
#include "InventoryTemplate.h"
#include "item_base.h"
#include "item_ring.h"


class Inventory : public GameObject {
protected:
    Texture2D texture;

    bool isOpen = false;

    // inventory container
    item_ring* itemRing = new item_ring;
    Inventory_Template<item_base*, 4> inventoryContainer;

    int currentItem;
    void itemAdd(item_base* item);


public:
    void Update() override;
    void Update(float, std::vector<Rectangle> &) override;
    void Render() override;
    void HandleInput() override;

    Inventory();
};


#endif //RAYLIBSTARTER_INVENTORY_H
