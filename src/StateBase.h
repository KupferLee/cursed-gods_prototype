//
// Created by Lee on 12.07.2022.
//

#ifndef RAYLIBSTARTER_STATEBASE_H
#define RAYLIBSTARTER_STATEBASE_H

#pragma once

#include "raylib.h"

class StateBase
{
protected:
    enum enumState { title, fight, level_1};
    enumState currentState = title;

    virtual int handleInput(); // asks for user input
    virtual void changeState(int i); // changes state to enum that is said

    //virtual int returnCurrentState(); // return int for enum for current state

    virtual void update();
};

#endif //RAYLIBSTARTER_STATEBASE_H
