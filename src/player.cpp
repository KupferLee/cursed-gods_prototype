#include "player.h"

void player::Update()
{
	Vector2 vNewPos = vPosition;
	vNewPos.x -= iSpeed * static_cast<float>(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT));
	vNewPos.x += iSpeed * static_cast<float>(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT));
	vNewPos.y += iGravity;
	// vNewPos.y -= 2 * Gravity * static_cast<float>(IsKeyReleased(KEY_SPACE) || IsKeyReleased(KEY_UP))
	if (IsKeyDown(KEY_SPACE) || IsKeyDown(KEY_UP) && bIsOnGround)
	{
		bIsJumping = true;
		bIsOnGround = false;
	}
	if (bIsJumping && iJumpHeight >= iTimeInAir)
	{
		vNewPos.y -= iGravity * 2;
		iTimeInAir++;
	}
	else
	{
		bIsJumping = false;
	}
	if (IsKeyReleased(KEY_SPACE) || IsKeyReleased(KEY_UP))
	{
		iTimeInAir = iJumpHeight + 1;
	}


	if (bIsOnGround)
	{
		vPosition.x = vNewPos.x; //Vorlage Collision
		
		iTimeInAir = 0;
		bIsOnGround = false;
	}
	else
	{
		vPosition = vNewPos;
	}
}

void player::Render()
{
	DrawRectangleV(vPosition, {25, 50}, GREEN);
}

void player::CheckCollision(Rectangle rec)
{
	if (CheckCollisionRecs(rec, Rectangle{ vPosition.x, vPosition.y, 25, 50 }))
	{
		bIsOnGround = true;
	}
}
