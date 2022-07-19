#pragma once
#include "raylib.h"

class ProtectedTexture final {
private:
    Texture2D texture_;

public:
    ProtectedTexture()=delete;
    explicit ProtectedTexture(const char *filename);
    ProtectedTexture(const ProtectedTexture &other) = delete;
    ProtectedTexture &operator = (const ProtectedTexture &) = delete;
    Texture2D getTexture();
    int getTextureWidth();
    int getTextureHeight();
    ~ProtectedTexture();
};
