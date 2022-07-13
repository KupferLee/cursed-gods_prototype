//
// Created by Lee on 12.07.2022.
//

#include "StateTitle.h"

void StateTitle::handleInput()
{
    // change to level 1
    if (IsKeyPressed(KEY_ENTER))
    {
        return new StateTitle;
    }
    else
    {
        return NULL;
    }
}
/*
void StateTitle::changeState(int i)
{
    // change state
    if (i == this->level_1)
    {

    }
}

 */
