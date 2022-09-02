//
// Created by Lee on 16.08.2022.
//

#include "item_ring.h"

item_ring::item_ring()
{
    this->addHP = 10;
    this->texture_item = LoadTexture("assets/graphics/UI/Inventory/Slot_Ring.png");
    this->texture_infos = LoadTexture("assets/graphics/UI/Inventory/Info_Ring.png");
}