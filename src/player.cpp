#include "player.h"
#include <iostream>

void player::UpdatePlayer(float delta, std::vector<Rectangle> &Ground)
{
	Vector2 vNewPos = vPosition;
	vNewPos.x -= delta * iSpeed * static_cast<float>(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT));
	vNewPos.x += delta * iSpeed * static_cast<float>(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT));
	vNewPos.y += delta * iGravity;
	// vNewPos.y -= 2 * Gravity * static_cast<float>(IsKeyReleased(KEY_SPACE) || IsKeyReleased(KEY_UP))
	if ((IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_UP)) && bCanJump)
	{
		bIsJumping = true;
        bCanJump = false;
	}
	if (bIsJumping && iJumpHeight >= iTimeInAir)
	{
		vNewPos.y -= delta * iGravity * 2;
		iTimeInAir++;
	}
	if (IsKeyReleased(KEY_SPACE) || IsKeyReleased(KEY_UP))
	{
		iTimeInAir = iJumpHeight + 1;
	}
    bIsFalling = true;
    for (const auto& index : Ground)
    {
        if(CheckCollisionRecs(index, Rectangle{vNewPos.x, vNewPos.y + 50, 25, 0}))
        {
            if(vNewPos.y >= vPosition.y)
            {bCanJump = true; bIsJumping = false; iTimeInAir = 0; bIsOnGround = true; bIsFalling = false;}
        }
        else if (CheckCollisionRecs(index, Rectangle{vNewPos.x, vNewPos.y, 25, 0}))
        {
            if (vNewPos.y < vPosition.y)
            {iTimeInAir = iJumpHeight + 1;}
        }
     }
    if(bIsFalling == true)
    {bCanJump = false;}
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
