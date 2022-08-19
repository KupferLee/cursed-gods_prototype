//
// Created by Lee on 18.08.2022.
//

#ifndef RAYLIBSTARTER_ACTORLOREDROP_H
#define RAYLIBSTARTER_ACTORLOREDROP_H

#include "Actor.h"
#include "player.h"

enum class WhichLoredrop
{
    base,
    first,
    second,
    third,
    fourth,
    final,
    none
};

class ActorLoredrop : public Actor {
public:
    ActorLoredrop();

    void Draw();

    void UpdateLore(Vector2 position);
    // every checkpoint has an ID that gets updated when we reach it
    int GetCurrentCheckpointID();

    void Update() override;
    void Update(float) override;
    void Render() override;

    void HandleInput()override;

    Vector2 positionTest;

protected:
    WhichLoredrop currentLoredrop = WhichLoredrop::none;

    player* Katara = new player;

    int scaleFactor = 4;
    int offset = 20;
    Texture2D loredropBase;
    Texture2D loredropOne;
    Texture2D loredropTwo;
    Texture2D loredropThree;
    Texture2D loredropFour;
    Texture2D loredropFinal;

    // positions
    Vector2 posDrop_1;
    Vector2 posDrop_2;
    Vector2 posDrop_3;
    Vector2 posDrop_4;
    Vector2 posDrop_final;

    bool isHitboxVisible = false;
    int whichCheckpointIsActive = 0;


private:
    void InternUpdate();
    void InternRender();

};


#endif //RAYLIBSTARTER_ACTORLOREDROP_H
