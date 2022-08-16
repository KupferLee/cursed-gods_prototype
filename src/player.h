#pragma once
#include "Actor.h"
#include "raymath.h"

enum class Animation
{
    Idle,
    RunRight,
    RunLeft,
    JumpRight,
    JumpLeft
};

class player : public Actor
{
public:
    void HandleInput() override;
    void Update(float, std::vector<Rectangle> &) override;
    void Update() override;
	void Render() override;
    void UpdatePlayer(float, std::vector<Rectangle> &);
    void RenderPlayer();
    void SetNextFrame();

private:
    //animation shit
    Texture2D Frames = LoadTexture("assets/graphics/Actors/katara_animations.png");
    float TilecountX = 8;
    float TilecountY = 4;
    float FrameDuration = 0.11;
    float Frametime = 0;
    Animation Animation;
    int frame;

    //states
    bool bIsWalking = false;
	bool bIsOnGround = true;
    bool bIsInAir = false;

    //constants
    const float fJumpAcc = -20/2.3f;
	const float fSideAcc = 2.5;
    const float fMaxSpeed = 7.5;
    const float fFriction = 0.6;
    const float fGravity = 1/ 3.f; //2te Ableitung der Jump kurve //floatcast important

    int iMaxJumpFrames = 6;
    int iJumpFrames = 0;
    Vector2 Momentum = {0 ,0};
	Vector2 vPosition = { 0, 450}; // Hardcoded weil test Texture ein Raylib Rec ist
};