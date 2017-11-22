#pragma once

#include <string>
#include <stdio.h>
#include "sdl_includes.h"
#include "texture_types.h"

//Texture wrapper class
class Texture {
public:
    //Initializes variables
    Texture();
    //Deallocates memory
    ~Texture();
    //Loads image at specified path
    bool loadFromFile( std::string path );
    //Creates image from font string
    bool loadFromRenderedText( std::string textureText, SDL_Color textColor );
    //Deallocates texture
    void free();
    //Renders texture at given point
    void render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip, float zoom);
    Uint32 getPixelColor(int x, int y);
    SDL_PixelFormat *getPixelFormat();
    //Gets image dimensions
    int getWidth();
    int getHeight();


private:
    bool lockSurface();
    bool unlockSurface();
    //The actual hardware texture
    SDL_Texture* mTexture;
    SDL_Surface* mSurface;
    //Image dimensions
    int mWidth;
    int mHeight;
};

extern Texture gTextures[TEXTURES_TOTAL];
extern Texture gTextTexture;