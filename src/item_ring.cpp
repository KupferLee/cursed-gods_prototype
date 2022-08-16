//
// Created by Lee on 16.08.2022.
//

#include "item_ring.h"

item_ring::item_ring()
{
    this->name = "HP Ring";
    this->description = "An ancient ring that adds a few HP to your max HP.";
    this->addHP = 10;
    this->texture = LoadTexture("assets/graphics/UI/Slot_Ring.png");
}