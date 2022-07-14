//
// Created by Lee on 12.07.2022.
//

#ifndef RAYLIBSTARTER_STATETITLE_H
#define RAYLIBSTARTER_STATETITLE_H

#include "StateBase.h"


class StateTitle : public StateBase {

protected:
    // std::shared_ptr <StateBase> state_;

    void handleInput() override;
    void update() override;

};


#endif //RAYLIBSTARTER_STATETITLE_H
