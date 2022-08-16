//
// Created by Lee on 16.08.2022.
//

#ifndef RAYLIBSTARTER_INVENTORYTEMPLATE_H
#define RAYLIBSTARTER_INVENTORYTEMPLATE_H

#include <iostream>

template <typename T, int size>
class Inventory_Template
{
public:
    T items_container[size] {};

    void setItem(T item, int slot)
    {
        if (slot < size)
        {
            // this gives error "Segmentation fault"
            items_container[slot] = item;
            std::cout << "DEBUG: Item Set " << slot << std::endl;
        }
        else
        {
            std::cout << "ERROR: Items array full" << std::endl;
        }
    }

    T getItem(int slot)
    {
        return items_container[slot];
    }
};
#endif //RAYLIBSTARTER_INVENTORYTEMPLATE_H
