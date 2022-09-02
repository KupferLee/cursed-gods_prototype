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
    horse,
    canyonOversight,
    checkpoint,
    shack,
    abillity,
    final,
    entrance,
    ring,
    exit,
    none
};

class ActorLoredrop : public Actor {
public:
    ActorLoredrop();

    void DrawHitbox();

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
    Texture2D loredropHorse;
    Texture2D loredropCanyonOversight;
    Texture2D loredropCheckpoint;
    Texture2D loredropShack;
    Texture2D loredropAbillity;
    Texture2D loredropFinal;

    Texture2D loredropEntrance;
    Texture2D loredropRing;
    Texture2D loredropExit;

    // ingame positions of Loredrops
    Vector2 posDrop_Horse = {780, 750};
    Vector2 posDrop_Canyon_Oversight = {2400, 910};
    Vector2 posDrop_Checkpoint  = {2725, 3357};
    Vector2 posDrop_Shack = {2050, 3325};
    Vector2 posDrop_abillity = {8360,3180};
    Vector2 posDrop_final = {8970, 1295};

    Vector2 posDrop_Entrance = {1689, 1118};
    Vector2 posDrop_Ring = {1084, 1211};
    Vector2 posDrop_Exit = {2809, 1641};

    bool isHitboxVisible = false;
    int whichCheckpointIsActive = 0;


private:
    void InternUpdate();
    void LoredropCollision(Vector2 playerPos, Vector2 lorePos, WhichLoredrop loredrop);
    void InternRender();
    void DrawTextbox(Texture2D texture);

};


#endif //RAYLIBSTARTER_ACTORLOREDROP_H
