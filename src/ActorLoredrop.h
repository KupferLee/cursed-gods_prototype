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
    checkpoint_1,
    shack,
    abillity,
    final,
    entrance,
    ring,
    exit,
    harpy,
    flower,
    sword,
    checkpoint_2,
    fight,
    statue,
    answer_statue,
    none
};

class ActorLoredrop : public Actor {
public:
    ActorLoredrop();

    void DrawHitbox();

    void UpdateLore(Vector2 position, bool isFightActive);
    // every checkpoint_1 has an ID that gets updated when we reach it
    int GetCurrentCheckpointID();

    void Update() override;
    void Update(float) override;
    void Render() override;

    void HandleInput()override;

protected:
    WhichLoredrop currentLoredrop = WhichLoredrop::none;

    int scaleFactor = 4;
    int offset = 20;
    Texture2D loredropBase;
    Texture2D loredropHorse;
    Texture2D loredropCanyonOversight;
    Texture2D loredropCheckpoint_1;
    Texture2D loredropShack;
    Texture2D loredropAbillity;
    Texture2D loredropFinal;

    Texture2D loredropEntrance;
    Texture2D loredropRing;
    Texture2D loredropExit;
    Texture2D loredropHarpy;
    Texture2D loredropFlower;
    Texture2D loredropSword;
    Texture2D loredropCheckpoint_2;
    Texture2D loredropFight;
    Texture2D loredropStatue;
    Texture2D statueZeus;

    Texture2D eToInteract;

    // ingame positions of Loredrops
    Vector2 posDrop_Horse = {780, 750};
    Vector2 posDrop_Canyon_Oversight = {2400, 910};
    Vector2 posDrop_Checkpoint_1  = {2725, 3357};
    Vector2 posDrop_Shack = {2050, 3325};
    Vector2 posDrop_Abillity = {8360, 3180};
    Vector2 posDrop_Final = {8970, 1295};

    Vector2 posDrop_Entrance = {1689, 1118};
    Vector2 posDrop_Ring = {1084, 1211};
    Vector2 posDrop_Exit = {2809, 1641};
    Vector2 posDrop_Harpye = {3679, 3264};
    Vector2 posDrop_Flower = {4914, 2943};
    Vector2 posDrop_Sword = {7166, 3243};
    Vector2 posDrop_Checkpoint_2 = {7841, 2967};
    Vector2 posDrop_Fight = {5145, 1750};
    Vector2 posDrop_Statue = {8067, 1272};

    bool isHitboxVisible = false;
    bool isStatueInfoActive = true;
    int whichCheckpointIsActive = 0;


private:
    void InternUpdate();
    void LoredropCollision(Vector2 playerPos, Vector2 lorePos, WhichLoredrop loredrop);
    void InternRender();
    void DrawTextbox(Texture2D texture);

};


#endif //RAYLIBSTARTER_ACTORLOREDROP_H
