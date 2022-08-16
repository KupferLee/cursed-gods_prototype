#include "player.h"
#include <iostream>

void player::UpdatePlayer(float delta, std::vector<Rectangle> &Ground)
{
    bIsWalking = false;
	Vector2 vNewPos = vPosition;
	//vNewPos.y += delta * fGravity;
	// vNewPos.y -= 2 * Gravity * static_cast<float>(IsKeyReleased(KEY_SPACE) || IsKeyReleased(KEY_UP))
    if (IsKeyDown( KEY_A) || IsKeyDown( KEY_LEFT))
    {
        Momentum.x -= fSideAcc;
        bIsWalking = true;
    }
    if (IsKeyDown( KEY_D) || IsKeyDown( KEY_RIGHT))
    {
        Momentum.x += fSideAcc;
        bIsWalking = true;
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
    vNewPos = Vector2Add(vPosition, Momentum);

    bIsInAir = true;

    for (const auto& index : Ground)
    {
        if(CheckCollisionRecs(index, Rectangle{vNewPos.x, vNewPos.y + 50, 25, 0}))
        {
            if(vNewPos.y >= vPosition.y)
            {bIsInAir = false; Momentum.y = 0; bIsOnGround = true; iJumpFrames = 0;}
        }
        else if (CheckCollisionRecs(index, Rectangle{vNewPos.x, vNewPos.y, 25, 0}))
        {
            if (vNewPos.y < vPosition.y)
            {Momentum.y = 0;}
        }
     }

    if(!bIsOnGround)
    {vPosition.y = vNewPos.y;}
    if(true)
    { vPosition.x = vNewPos.x;}
    bIsOnGround = false;
}

void player::RenderPlayer()
{
	DrawRectangleV(vPosition, {25, 50}, GREEN);
}

void player::Render() {
    RenderPlayer();
}

void player::Update(float a, std::vector<Rectangle> &b) {
    UpdatePlayer(a, b);
}

void player::HandleInput() {

}

void player::Update() {
}
