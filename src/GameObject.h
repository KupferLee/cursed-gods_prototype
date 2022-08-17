//
// Created by sbinz on 05.07.2022.
//

#ifndef RAYLIBSTARTER_GAMEOBJECT_H
#define RAYLIBSTARTER_GAMEOBJECT_H
#include <vector>
#include <raylib.h>


class GameObject {

public: virtual void HandleInput() = 0;
        virtual void Update(float, std::vector<Rectangle> &) = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
        void DrawFrame(Vector2 destination, int x, int y , Texture2D texture, float TilecountX, float TilecountY)
        {
            float Tilewidth = static_cast<float>(texture.width)/TilecountX;
            float Tileheight =  static_cast<float>(texture.height)/TilecountY;
            Rectangle source = Rectangle{x*Tilewidth, y*Tileheight,Tilewidth, Tileheight};
            Rectangle dest = Rectangle{destination.x, destination.y, 50, 50};
            Vector2 origin = Vector2{0, 0};
            //Vector2 origin = Vector2{Tilewidth/2, Tileheight/2};
            DrawTexturePro(texture, source, dest, origin, 0, WHITE);
        };
};



#endif //RAYLIBSTARTER_GAMEOBJECT_H
