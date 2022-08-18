//
// Created by Lee on 18.08.2022.
//

#include "Actor.h"

void Actor::UpdateAnimation(float delta,  int framesInRow, float frameDuration)
{
    this->frameTime += delta;

    if(this->frameTime >= frameDuration)
    {
        this->frame = (this->frame + 1) % framesInRow;
        this->frameTime = 0;
    }
}

void Actor::RenderAnimation(Rectangle position, int maxFramesInX, int maxFramesInY)
{
    // draw actor
    DrawFrame(position, this->frame, 0, this->animation, maxFramesInX, maxFramesInY);

}