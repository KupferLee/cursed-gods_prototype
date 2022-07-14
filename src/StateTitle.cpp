//
// Created by Lee on 12.07.2022.
//

#include "StateTitle.h"

void StateTitle::handleInput()
{
    // change to level 1
    if (IsKeyPressed(KEY_ENTER))
    {
        return new StateTitle();
    }
    else
    {
        return NULL;
    }
}

void StateTitle::update()
{
    ClearBackground(GRAY);
    DrawText("Title Screen", 10, 10, 20, DARKGRAY);
}
