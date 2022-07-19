/*
*   Created by Schr4mMb00 on 19.07.2022.
*
*   Title: ProtectedTexture
*   Required: const char* filename --> for Initialization
*   Return: you can get readingaccess to:  -> texture [getTexture()] returns a Texture2D
*                                          -> width [getTextureWidth()] returns a int
*                                          -> height [getTextureHeight()] returns a int
*   Function: assertion handling of texture file and provide save data for game
*/

#include "ProtectedTexture.h"

//explicit constructor to load Texture and getting width and height of texture
//default- and copy-constructor are deleted
//destructor unloads Texture from vram
ProtectedTexture::ProtectedTexture(const char *filename) {
    this->texture_ = LoadTexture(filename);
    TraceLog(LOG_INFO, "ProtectedTexture constructor called");
}

Texture2D ProtectedTexture::getTexture() {
    return this->texture_;
}

int ProtectedTexture::getTextureWidth() {
    return this->texture_.width;
}

int ProtectedTexture::getTextureHeight() {
    return this->texture_.height;
}

ProtectedTexture::~ProtectedTexture() {
    TraceLog(LOG_INFO, "ProtectedTexture destructor called");
    UnloadTexture(this->texture_);
}

