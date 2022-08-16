//
// Created by Lee on 16.08.2022.
//

#ifndef RAYLIBSTARTER_INVENTORY_H
#define RAYLIBSTARTER_INVENTORY_H

#include "GameObject.h"


class Inventory : public GameObject {
protected:
    Texture2D texture;

    bool isOpen = false;

public:
    void Update() override;
    void Update(float, std::vector<Rectangle> &) override;
    void Render() override;
    void HandleInput() override;

    Inventory();
};


#endif //RAYLIBSTARTER_INVENTORY_H
