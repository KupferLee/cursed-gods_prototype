//
// Created by Lee on 17.08.2022.
//

#include "Menus.h"

void Menus::Update()
{
    inventory->Update();
}

void Menus::Render()
{
    inventory->Render();
}

void Menus::Update(float, std::vector<Rectangle> &) { }

void Menus::HandleInput() { }
