//
// Created by sbinz on 05.07.2022.
//

#ifndef RAYLIBSTARTER_GAMEOBJECT_H
#define RAYLIBSTARTER_GAMEOBJECT_H
#include <vector>
#include <raylib.h>


class GameObject {
public: virtual void HandleInput() = 0;
        virtual void Update(float, std::vector<Rectangle> &) = 0;
        virtual void Render() = 0;
};


#endif //RAYLIBSTARTER_GAMEOBJECT_H
