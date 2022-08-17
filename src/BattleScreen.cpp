//
// Created by Lee on 17.08.2022.
//

#include "BattleScreen.h"

BattleScreen::BattleScreen()
{
    this->background = LoadTexture("assets/graphics/UI/BattleScreen_Background.png");
    // this->attackButton_1 = LoadTexture("");
    // textures get used in set slots
    this->SetSlots();

}

void BattleScreen::Update()
{
    // ask if key inputs or anything here
}

void BattleScreen::Render()
{
    // draw Background
    DrawTexturePro(this->background,
                   {0, 0, (float)this->background.width, (float)this->background.height},
                   {0, 0, (float)GetScreenWidth(), (float)GetScreenHeight()},
                   {0, 0}, 0, WHITE);

    // draw buttons in dedicated slots
    DrawTexturePro(this->attackButton_1,
                   {0.0, 0.0, (float)this->buttonDimensions.x, (float)this->buttonDimensions.y},
                   {buttonSlots[0].x, buttonSlots[0].y, (float)this->attackButton_1.width * this->scaleFactor, (float)this->attackButton_1.height * this->scaleFactor},
                   {0, 0}, 0, WHITE);

    DrawTexturePro(this->attackButton_2,
                   {0.0, 0.0, (float)this->buttonDimensions.x, (float)this->buttonDimensions.y},
                   {buttonSlots[1].x, buttonSlots[1].y, (float)this->attackButton_1.width * this->scaleFactor, (float)this->attackButton_1.height * this->scaleFactor},
                   {0, 0}, 0, WHITE);

    DrawTexturePro(this->attackButton_3,
                   {0.0, 0.0, (float)this->buttonDimensions.x, (float)this->buttonDimensions.y},
                   {buttonSlots[2].x, buttonSlots[2].y, (float)this->attackButton_1.width * this->scaleFactor, (float)this->attackButton_1.height * this->scaleFactor},
                   {0, 0}, 0, WHITE);

    DrawTexturePro(this->attackButton_4,
                   {0.0, 0.0, (float)this->buttonDimensions.x, (float)this->buttonDimensions.y},
                   {buttonSlots[3].x, buttonSlots[3].y, (float)this->attackButton_1.width * this->scaleFactor, (float)this->attackButton_1.height * this->scaleFactor},
                   {0, 0}, 0, WHITE);
}

void BattleScreen::SetSlots()
{
    // setting the button dimensions to have them in one accessible location
    this->buttonDimensions.x = this->attackButton_1.width;
    this->buttonDimensions.y = this->attackButton_1.height;

    // set slots right after each other
    // going width of texture to the right after setting new slot
    this->buttonSlots[0].x = GetScreenWidth()/2 - this->buttonDimensions.x;
    this->buttonSlots[0].y = GetScreenHeight()/2 - this->buttonDimensions.y;

    this->buttonSlots[1].x = this->buttonSlots[0].x + this->buttonDimensions.x;
    this->buttonSlots[1].y = this->buttonSlots[0].y + this->buttonDimensions.y;

    this->buttonSlots[2].x = this->buttonSlots[1].x + this->buttonDimensions.x;
    this->buttonSlots[2].y = this->buttonSlots[1].y + this->buttonDimensions.y;

    this->buttonSlots[3].x = this->buttonSlots[2].x + this->buttonDimensions.x;
    this->buttonSlots[3].y = this->buttonSlots[2].y + this->buttonDimensions.y;
}

void BattleScreen::Update(float, std::vector<Rectangle> &) { }

void BattleScreen::HandleInput() { }
