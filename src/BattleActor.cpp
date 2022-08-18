//
// Created by Lee on 17.08.2022.
//

#include "BattleActor.h"

void BattleActor::UpdateAnimation(float delta,  int framesInRow, float frameDuration)
{
    this->frameTime += delta;

    if(this->frameTime >= frameDuration)
    {
        this->frame = (this->frame + 1) % framesInRow;
        this->frameTime = 0;
    }
}

void BattleActor::RenderAnimation(Rectangle position, int maxFramesInX, int maxFramesInY)
{
    DrawFrame(position, this->frame, 0, this->animation, maxFramesInX, maxFramesInY);
}