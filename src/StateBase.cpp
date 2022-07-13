//
// Created by Lee on 12.07.2022.
//
#include "StateBase.h"

void StateBase::update()
{

    // this->changeState(this->handleInput());
}

void StateBase::handleInput()
{
    // ???????????
    StateBase* state = state_->handleInput();
    if (state != NULL)
    {
        delete state_;
        state_ = state;
    }
}