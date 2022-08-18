#pragma once
#include "Actor.h"
#include "raymath.h"
#include "DRAW.h"
#include "config.h"

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
    player(){};
    void HandleInput() override;
    void Update(float) override;
    void Update() override;
	void Render() override;
    void UpdatePlayer(float);
    void RenderPlayer();
    void SetNextFrame();
    void SetGround(std::vector<Rectangle> a);
    void SetWalls(std::vector<Rectangle> a);
    Vector2 getPosition();
    float getTextureWidth();
    float getTextureHeight();

private:
    //animation shit
    Texture2D Frames = LoadTexture("assets/graphics/Actors/katara_animations.png");
    float TilecountX = 8;
    float TilecountY = 9;
    float FrameDuration = 0.11;
    float Frametime = 0;
    Animation Animation;
    int frame;

    //states
    bool bIsWalking = false;
	bool bIsOnGround = true;
    bool bIsInAir = false;
    bool WallCollide = false;

    //constants
    const float fJumpAcc = -20/2.3f;
	const float fSideAcc = 2.5;
    const float fMaxSpeed = 7.5;
    const float fMaxAirSpeed = 22.2;
    const float fFriction = 0.6;
    const float fGravity = 1/ 3.f; //2te Ableitung der Jump kurve //floatcast important

    std::vector<Rectangle> Ground;
    std::vector<Rectangle> Walls;
    int iMaxJumpFrames = 6;
    int iJumpFrames = 0;
    Vector2 Momentum = {0 ,0};
	Vector2 vPosition = { 400,400}; // Hardcoded weil test Texture ein Raylib Rec ist
};