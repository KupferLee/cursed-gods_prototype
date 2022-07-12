//
// Created by Lee on 12.07.2022.
//

#include "StateTitle.h"

int StateTitle::handleInput()
{
    // change to level 1
    if (IsKeyPressed(KEY_ENTER))
    {
        return this->level_1;
    }
}
void StateTitle::changeState(int i)
{
    if (i == this->level_1)
    {

    }
}

