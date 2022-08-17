#ifndef RAYLIBSTARTER_DRAW_H
#define RAYLIBSTARTER_DRAW_H
#include "raylib.h"
class DRAW
{
public:
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
#endif //RAYLIBSTARTER_DRAW_H
