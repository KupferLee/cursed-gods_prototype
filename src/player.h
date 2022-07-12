#pragma once
#include "Actor.h"

class player : public Actor
{
public:
    void HandleInput() override;
    void Update(float, std::vector<Rectangle> &) override;
	void Render() override;
    void UpdatePlayer(float, std::vector<Rectangle> &);
    void RenderPlayer();
private:
	bool bIsJumping = false;
	bool bIsOnGround = true;
    bool bCanJump = true;
    bool bIsFalling = false;
	int iSpeed = 300;
	int iGravity = 300;
	int iTimeInAir = 0;
	int iJumpHeight = 30;
	Vector2 vPosition = { 0, 450};// Hardcoded weil test Texture ein Raylib Kreis ist
};