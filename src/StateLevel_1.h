//
// Created by Lee on 12.07.2022.
//

#ifndef RAYLIBSTARTER_STATELEVEL_1_H
#define RAYLIBSTARTER_STATELEVEL_1_H

#include "StateBase.h"

class StateLevel_1 : public StateBase {

protected:
    int handleInput() override;
    void changeState(int i) override;
};


#endif //RAYLIBSTARTER_STATELEVEL_1_H
