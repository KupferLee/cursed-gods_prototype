//
// Created by Lee on 17.08.2022.
//

#ifndef RAYLIBSTARTER_BATTLESCREEN_H
#define RAYLIBSTARTER_BATTLESCREEN_H

#include "GameObject.h"

class BattleScreen : public GameObject {
protected:
    // GUI
    Texture2D background;
    Texture2D attackButton_1;
    Texture2D attackButton_2;
    Texture2D attackButton_3;
    Texture2D attackButton_4;
    Texture2D attackSelection;

    Vector2 buttonSlots[4];
    Vector2 buttonDimensions;
    int currentSlot = 0;
    int scaleFactor = 3;

    void SetSlots();

public:
    BattleScreen();

    void Update() override;
    void Update(float, std::vector<Rectangle> &) override;
    void Render() override;
    void HandleInput() override;
};


#endif //RAYLIBSTARTER_BATTLESCREEN_H
