#include "player.h"
#include <iostream>

void player::UpdatePlayer(float delta)
{
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

    if ((IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_UP)) && !bIsInAir)
	{
        Momentum = Vector2Add(Momentum, Vector2{0, fJumpAcc/2}); //Y-Achsenabschnitt ableitung 1 //floatcast important
        frame = 0;
        iJumpFrames++;
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
    vNewPos = Vector2Add(vPosition, Momentum);

    //Wall Collision
    WallCollide = false;
    for (const auto& index : Walls)
    {
        if(CheckCollisionRecs(index, Rectangle{vNewPos.x, vNewPos.y, 32, 29})) //Kataras Größe Hardcoded und 2 Pixel Weniger, da die Hitboxen sometimes Slightly Off sind
        {
            WallCollide = true;
        }
    }

    bIsInAir = true;
    bIsOnGround = false;

    //Ground Collision;
    for (const auto& index : Ground)
    {
        if(CheckCollisionRecs(index, Rectangle{vNewPos.x, vNewPos.y + 31, 32, 1})) //Kataras Größe Hardcoded
        {
            if(vNewPos.y >= vPosition.y)
            {
                vPosition.y = index.y - 32; //Kataras Größe Hardcoded;
                bIsInAir = false;
                bIsOnGround = true;
            }
        }
        else if (CheckCollisionRecs(index, Rectangle{vNewPos.x, vNewPos.y, 32, 1})) //Kataras Größe Hardcoded
        {
            if (vNewPos.y < vPosition.y)
            {
                Momentum.y = 0;
            }
        }
     }

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
	DrawRectangleV(vPosition, {32, 32}, SKYBLUE); //Kataras Größe Hardcoded
    DrawFrame(Rectangle{vPosition.x, vPosition.y, 32,32}, frame, static_cast<int>(Animation), Frames, TilecountX , TilecountY);
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

Vector2 player::getPosition() {
    return this->vPosition;
}

void player::SetWalls(std::vector<Rectangle> a)
{
    Walls = a;
}

float player::getTextureHeight() {
    return static_cast<float>(Frames.width)/static_cast<float>(TilecountX);
}

float player::getTextureWidth() {
    return static_cast<float>(Frames.height)/static_cast<float>(TilecountY);
}
