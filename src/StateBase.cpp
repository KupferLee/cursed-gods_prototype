//
// Created by Lee on 12.07.2022.
//
#include "StateBase.h"

void StateBase::update()
{
    this->changeState(this->handleInput());
}