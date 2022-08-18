//
// Created by sbinz on 05.07.2022.
//

#ifndef RAYLIBSTARTER_ACTOR_H
#define RAYLIBSTARTER_ACTOR_H
#include "GameObject.h"
#include "DRAW.h"


class Actor : public GameObject, public DRAW {
public:
    virtual void RenderAnimation(Rectangle position, int maxFramesInX, int maxFramesInY);
    virtual void UpdateAnimation(float delta, int framesInRow, float frameDuration);

protected:
    Rectangle position;
    Texture2D animation;

    float frameTime = 0.f;
    int frame = 0;
};


#endif //RAYLIBSTARTER_ACTOR_H
