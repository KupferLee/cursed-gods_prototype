#include "player.h"
#include <iostream>

void player::UpdatePlayer(float delta)
{
    if(IsKeyPressed(KEY_H) && !drawhitbox_) drawhitbox_ = true;
    else if(IsKeyPressed(KEY_H) && drawhitbox_) drawhitbox_ = false;

//Movement
    bIsWalking = false;
    if (bIsOnGround)Animation = Animation::Idle;
    Vector2 vNewPos = vPosition;

    if (IsKeyDown( KEY_A) || IsKeyDown( KEY_LEFT))
    {
        Momentum.x -= fSideAcc;
        bIsWalking = true;
        Animation = Animation::RunLeft;
    }
    if (IsKeyDown( KEY_D) || IsKeyDown( KEY_RIGHT))
    {
        Momentum.x += fSideAcc;
        bIsWalking = true;
        Animation= Animation::RunRight;
    }
    if (bIsWalking)
    {
        if(Momentum.x > fMaxSpeed)
        {
            Momentum.x = fMaxSpeed;
        }
        if(Momentum.x < -fMaxSpeed)
        {
            Momentum.x = -fMaxSpeed;
        }
    }
    else
    {
        Momentum.x *= fFriction;
    }

    if (doublejump)
    {
        if (((IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP)) && JumpCount==1))
        {
            Momentum = Vector2{0,0};
            Momentum = Vector2Add(Momentum,
                                  Vector2{0, fJumpAcc}); //Y-Achsenabschnitt ableitung 1 //floatcast important
            frame = 0;
            iJumpFrames++;
            JumpCount++;
        }
        if ((IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP)) && JumpCount==0)
        {
            Momentum = Vector2Add(Momentum,
                                  Vector2{0, fJumpAcc/2}); //Y-Achsenabschnitt ableitung 1 //floatcast important
            frame = 0;
            iJumpFrames++;
            JumpCount++;

        }

    }
    else {


        if ((IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_UP)) && !bIsInAir) {
            Momentum = Vector2Add(Momentum,
                                  Vector2{0, fJumpAcc / 2}); //Y-Achsenabschnitt ableitung 1 //floatcast important
            frame = 0;
            iJumpFrames++;
        }
    }
    if(IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_UP))
    {
        if(iJumpFrames < iMaxJumpFrames)
        {
            iJumpFrames++;
        }
        else if(iJumpFrames == iMaxJumpFrames)
        {
            Momentum = Vector2Add(Momentum, Vector2{0, fJumpAcc/2});
            iJumpFrames++;
        }
    }
    if(IsKeyReleased(KEY_SPACE) || IsKeyReleased(KEY_UP))
    {
        iJumpFrames = iMaxJumpFrames +1;
    }
	if (bIsInAir)
	{
		Momentum = Vector2Add(Momentum, Vector2{0, fGravity});
    }
    if (Momentum.y < 0)
    {
        if(Momentum.x <= 0)
        {
            Animation = Animation::JumpLeft;
        }
        else if(Momentum.x > 0)
        {
            Animation = Animation::JumpRight;
        }
    }
    else if(Momentum.y > fGravity)
    {
        frame = 2;
        if(Momentum.x < 0)
        {
            Animation = Animation::JumpLeft;
        }
        else if(Momentum.x >= 0)
        {
            Animation = Animation::JumpRight;
        }
    }
    if (bIsInAir)
    {
        if(Momentum.y > fMaxAirSpeed)
        {
            Momentum.y = fMaxAirSpeed;
        }
    }

    //PosUpdates;
    vNewPos = Vector2Add(vPosition, Momentum);
    KataraBox.x = vNewPos.x;
    KataraBox.y = vNewPos.y;
    HitBoxBody.x = vNewPos.x+3;
    HitBoxBody.y = vNewPos.y+2;
    HitBoxHead.x = vNewPos.x+7;
    HitBoxHead.y = vNewPos.y+1;
    HitBoxFeet.x = vNewPos.x+6;
    HitBoxFeet.y = vNewPos.y+29;




    //Wall Collision
    WallCollide = false;
    for (const auto& index : Walls)
    {
        if(CheckCollisionRecs(index, HitBoxBody))
        {
            WallCollide = true;
        }
         if (CheckCollisionRecs(index, HitBoxHead))
        {
            if (vNewPos.y < vPosition.y)
            {
                Momentum.y = 0;
            }
        }
    }
        bIsOnGround = false;
        bIsInAir = true;

    //Ground Collision;
    for (const auto& index : Ground)
    {
        if(CheckCollisionRecs(index, HitBoxFeet))
        {
            if(vNewPos.y >= vPosition.y)
            {
                vPosition.y = index.y - 32; //Kataras Größe Hardcoded;
                bIsInAir = false;
                bIsOnGround = true;
                JumpCount=0;
            }
        }
        else if (CheckCollisionRecs(index, HitBoxHead))
        {
            if (vNewPos.y < vPosition.y)
            {
                Momentum.y = 0;
            }
        }
     }

    //State results
    if(bIsOnGround)
    {
        iJumpFrames = 0;
        Momentum.y = 0;
    }
    else
    {
        vPosition.y = vNewPos.y;
    }

    if(WallCollide)
    {

    }
    else
    {
        vPosition.x = vNewPos.x;
    }

    Frametime += delta;
    if(Frametime >= FrameDuration)
    {
        Frametime -= FrameDuration;
        if (frame == 2 && Animation == Animation::JumpRight || Animation == Animation::JumpLeft){}
        else SetNextFrame();
    }
}

void player::RenderPlayer()
{
    if(drawhitbox_)
    {
        DrawRectangleRec(HitBoxBody, SKYBLUE);
        DrawRectangleRec(HitBoxHead, LIME);
        DrawRectangleRec(HitBoxFeet, RED);
    }

    DrawFrame(KataraBox, frame, static_cast<int>(Animation), Frames, TilecountX , TilecountY);
}

void player::Render() {
    RenderPlayer();
}

void player::Update(float a) {
    UpdatePlayer(a);
}

void player::HandleInput() {

}

void player::Update() {
}

void player::SetNextFrame() {
switch(Animation) {
    case(Animation::Idle):
        frame = frame + 1 % static_cast<int>(TilecountX);
        FrameDuration = 0.14;
        break;
    case(Animation::RunRight):
        frame = frame + 1 % static_cast<int>(TilecountX);
        FrameDuration = 0.11;
        break;
    case(Animation::RunLeft):
        frame = frame + 1 % static_cast<int>(TilecountX);
        FrameDuration = 0.11;
        break;
    case(Animation::JumpRight):
        frame = (frame + 1) % 3;
        FrameDuration = 0.22;
        break;
    case(Animation::JumpLeft):
        frame = (frame + 1) % 3;
        FrameDuration = 0.22;
        break;
    default: frame = 0;
        break;
}
}
void player::SetGround(std::vector<Rectangle> a)
{
    Ground = a;
}

Vector2 player::GetPosition() {
    return this->vPosition;
}

// vPosition.x + this->texture.width ging nicht
Vector2 player::GetMiddlePosition() { return {vPosition.x + 16, vPosition.y + 16}; }

Vector2 player::GetCurrentPosition()
{
    return this->Momentum;
}

void player::SetWalls(std::vector<Rectangle> a)
{
    Walls = a;
}
void player::SetPosition(Vector2 x)
{
    vPosition = x;
}

Vector2 player::GetInitialPosition()
{
    return InitialPosition;
}

float player::GetTextureHeight() {
    return static_cast<float>(Frames.width)/static_cast<float>(TilecountX);
}

float player::GetTextureWidth() {
    return static_cast<float>(Frames.height)/static_cast<float>(TilecountY);
}

void player::SetDoubleJump() {
    doublejump=true;

}
