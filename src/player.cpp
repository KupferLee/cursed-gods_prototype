#include "player.h"

void player::Update()
{
	Vector2 vNewPos = vPosition;
	vNewPos.x -= iSpeed * static_cast<float>(IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT));
	vNewPos.x += iSpeed * static_cast<float>(IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT));
	vNewPos.y += iGravity;
	if (IsKeyDown(KEY_SPACE) && !bIsInAir)
	{
		bIsInAir = true;
	}
	if (bIsInAir && iJumpHeight >= iTimeInAir)
	{
		vNewPos.y -= iGravity * 2;
		iTimeInAir++;
	}
	if (IsKeyReleased(KEY_SPACE))
	{
		iTimeInAir = iJumpHeight + 1;
	}


	if (vNewPos.y >= 500 - 50)
	{
		vPosition.x = vNewPos.x; //Vorlage Collision
		bIsInAir = false;
		iTimeInAir = 0;
	}
	/* else if (vNewPos.y <= 500 - 50 && bIsInAir == true)
	{
		vPosition.x = vNewPos.x;
		vNewPos.y = vPosition.y + 1;
		vPosition.y = vNewPos.y;
	}
	*/
	else
	{
		vPosition = vNewPos;
	}
}

void player::Render()
{
	DrawRectangleV(vPosition, {25, 50}, GREEN);
}
