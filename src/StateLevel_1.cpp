//
// Created by Lee on 12.07.2022.
//

#include "StateLevel_1.h"

int StateLevel_1::handleInput()
{
    // change to title
    if (IsKeyPressed(KEY_ENTER))
    {
        return this->title;
    }
    else if (IsKeyPressed(KEY_SPACE))
    {
        return this->fight;
    }
}
void StateLevel_1::changeState(int i)
{
    if (i == this->fight)
    {
        // set shared pointer to fight
    }
    else if (i == this->title)
    {
        // set shared pointer to title
    }
}