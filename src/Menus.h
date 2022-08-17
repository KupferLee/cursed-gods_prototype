//
// Created by Lee on 17.08.2022.
//

#ifndef RAYLIBSTARTER_MENUS_H
#define RAYLIBSTARTER_MENUS_H

#include "GameObject.h"
#include "Inventory.h"

class Menus : public GameObject {
public:
    void HandleInput() override;
    void Update(float, std::vector<Rectangle> &) override;
    void Update() override;
    void Render() override;

protected:
    Inventory* inventory = new Inventory;

};


#endif //RAYLIBSTARTER_MENUS_H
