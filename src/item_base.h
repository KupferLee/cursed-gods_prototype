//
// Created by Lee on 16.08.2022.
//

/*
 * All item classes will be children of this class.
 */

#ifndef RAYLIBSTARTER_ITEM_BASE_H
#define RAYLIBSTARTER_ITEM_BASE_H

#include "string"
#include "raylib.h"


class item_base {
protected:
    std::string name;
    std::string description;

public:
    Texture2D texture;
    // things all items will have
};


#endif //RAYLIBSTARTER_ITEM_BASE_H
