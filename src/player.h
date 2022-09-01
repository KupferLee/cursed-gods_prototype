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

    //Base-functions
    player(){};
    void HandleInput() override;
    void Update(float) override;
    void Update() override;
	void Render() override;
    void UpdatePlayer(float);
    void RenderPlayer();

    //Setter-functions
    void SetNextFrame();
    void SetGround(std::vector<Rectangle> a);
    void SetWalls(std::vector<Rectangle> a);
    void SetPosition(Vector2 x);
    void SetDoubleJump();

    //Getter-functions
    Vector2 GetPosition();
    Vector2 GetMiddlePosition();
    Vector2 GetInitialPosition();
    Vector2 GetCurrentPosition();
    float GetTextureWidth();
    float GetTextureHeight();

private:

    //KataraBoxes
    Rectangle KataraBox =  {0,0,32,32};
    Rectangle HitBoxHead = {0,0,18, 3};
    Rectangle HitBoxBody = {0,0, 26, 28};
    Rectangle HitBoxFeet = {0,0, 20, 3};

    //Animation Stuff
    Texture2D Frames = LoadTexture("assets/graphics/Actors/katara_animations.png");
    float TilecountX = 8;
    float TilecountY = 9;
    float FrameDuration = 0.11;
    float Frametime = 0;
    Animation Animation;
    int frame;

    //State-Bools
    bool bIsWalking = false;
	bool bIsOnGround = true;
    bool bIsInAir = false;
    bool WallCollide = false;
    bool drawhitbox_ = false;
    bool doublejump = false;

    //constants
    const float fJumpAcc = -7.7f;
	const float fSideAcc = 0.5; //2.5
    const float fMaxSpeed = 4.f;
    const float fMaxAirSpeed = 22.2;
    const float fFriction = 0.6;
    const float fGravity = 1/ 3.f; //2te Ableitung der Jump kurve

    //Restlicher Stuff
    std::vector<Rectangle> Ground;
    std::vector<Rectangle> Walls;
    int JumpCount = 0;
    int iMaxJumpFrames = 6;
    int iJumpFrames = 0;
    Vector2 InitialPosition = {730, 700};
    Vector2 Momentum = {0 ,0};
	Vector2 vPosition = InitialPosition;
    Vector2 vScreenPosition = {Game::ScreenWidth/2, Game::ScreenHeight/2};
};