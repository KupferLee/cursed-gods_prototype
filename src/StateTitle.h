//
// Created by Lee on 12.07.2022.
//

#ifndef RAYLIBSTARTER_STATETITLE_H
#define RAYLIBSTARTER_STATETITLE_H

#include "StateBase.h"
#include "StateLevel_1.h"
#include <memory>

class StateTitle : public StateBase {

protected:
    std::shared_ptr <StateBase> state;

    int handleInput() override;
    void changeState(int i) override;

};


#endif //RAYLIBSTARTER_STATETITLE_H
