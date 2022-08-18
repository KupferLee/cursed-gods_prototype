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

    void UpdateLore(Vector2 position);

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


private:
    void InternUpdate();
    void InternRender();

};


#endif //RAYLIBSTARTER_ACTORLOREDROP_H
