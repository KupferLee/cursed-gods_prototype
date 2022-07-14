//
// Created by Lee on 12.07.2022.
//

#ifndef RAYLIBSTARTER_STATEBASE_H
#define RAYLIBSTARTER_STATEBASE_H

#pragma once

#include "raylib.h"
#include "StateTitle.h"
#include "StateLevel_1.h"
#include <memory>

class StateBase
{
public:
    virtual ~StateBase() {};

    enum enumState { title, fight, level_1};
    enumState currentState = title;

    virtual void handleInput();
    virtual void update();

    StateTitle stateTitle;
    StateLevel_1 stateLevel1;

private:
    StateBase* state_;

};

#endif //RAYLIBSTARTER_STATEBASE_H
