#pragma once
#include <raylib.h>

class player
{
public:
	void Update();
	void Render();
private:
	bool bIsInAir = false;
	bool bIsOnGround = false;
	bool bIsMoving = false;
	int iSpeed = 10;
	int iGravity = 10;
	int iTimeInAir = 0;
	int iJumpHeight = 20;
	Vector2 vPosition = { 0, 450};// Hrdcoded weil test TExture ein Raylib kreis ist
};