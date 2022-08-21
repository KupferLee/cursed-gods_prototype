//
// Created by Lee on 21.08.2022.
//

#ifndef RAYLIBSTARTER_ACTORITEMSWORD_H
#define RAYLIBSTARTER_ACTORITEMSWORD_H

#include "Actor.h"

class ActorItemSword : public Actor {
public:
    ActorItemSword();

    void Update() override;
    void Update(float) override;
    void Render() override;
    void HandleInput()override;

    Vector2 GetHitbox();
    void SetActive(bool b);
    bool GetActive();

protected:
    Texture2D textureOverworld;
    Vector2 hitboxPosition;
    bool showHitbox = false;
    bool isActive = true;

};


#endif //RAYLIBSTARTER_ACTORITEMSWORD_H
