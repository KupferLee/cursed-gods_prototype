//
// Created by Lee on 17.08.2022.
//

#include "item_sword.h"

item_sword::item_sword()
{
    this->name = "Soldier's Xisiphos";
    this->description = "A simple sword.";
    this->addAD = 10;
    this->texture_item = LoadTexture("assets/graphics/UI/Slot_Sword.png");
    this->texture_infos = LoadTexture("assets/graphics/UI/Info_Sword.png");
}
