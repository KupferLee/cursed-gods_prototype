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
    Texture2D texture;

public:
    Texture2D GetTexture() { return texture; }
    std::string GetName() { return name; }
    std::string GetDescription() {return description; }
    // things all items will have
};


#endif //RAYLIBSTARTER_ITEM_BASE_H
