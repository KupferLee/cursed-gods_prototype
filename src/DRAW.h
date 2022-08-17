#ifndef RAYLIBSTARTER_DRAW_H
#define RAYLIBSTARTER_DRAW_H
#include "raylib.h"
class DRAW
{
public:
    void DrawFrame(Vector2 destination, int x, int y , Texture2D texture, float TilecountX, float TilecountY)
    {
        Tilewidth = static_cast<float>(texture.width)/TilecountX;
        Tileheight =  static_cast<float>(texture.height)/TilecountY;
        source = Rectangle{x*Tilewidth, y*Tileheight,Tilewidth, Tileheight};
        dest = Rectangle{destination.x, destination.y, 50, 50};
        origin = Vector2{0, 0};
        //Vector2 origin = Vector2{Tilewidth/2, Tileheight/2};
        DrawTexturePro(texture, source, dest, origin, 0, WHITE);
    };
private:
    Rectangle source;
    Rectangle dest;
    Vector2 origin;
    float Tileheight;
    float Tilewidth;
};
#endif //RAYLIBSTARTER_DRAW_H
