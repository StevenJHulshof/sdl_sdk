#include "sdl_includes.h"
#include "texture_types.h"
#include "config_types.h"
#include "Texture.h"

Texture::Texture()
{
    // Initialize
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

Texture::~Texture()
{
    // Deallocate
    free();
}

bool Texture::loadFromFile(std::string path)
{
    // Get rid of preexisting texture
    free();

    // The final texture
    SDL_Texture* newTexture = NULL;

    // Load image at specified path
    mSurface = IMG_Load(path.c_str());
    if(mSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    } else {
        // Color key image
        SDL_SetColorKey(mSurface, SDL_TRUE, SDL_MapRGB(mSurface->format, 0, 0xFF, 0xFF));

        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, mSurface);
        if(newTexture == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        } else {
            // Get image dimensions
            mWidth = mSurface->w;
            mHeight = mSurface->h;
        }
    }

    // Return success
    mTexture = newTexture;
    return mTexture != NULL;
}

bool Texture::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
    // Get rid of preexisting texture
    free();
    // Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
    if(textSurface == NULL)
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    else {
        // Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if(mTexture == NULL)
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        else {
            // Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }
        // Get rid of old surface
        SDL_FreeSurface(textSurface);
    }
    // Return success
    return mTexture != NULL;
}

void Texture::free()
{
    // Free texture if it exists
    if(mTexture != NULL) {
        SDL_DestroyTexture(mTexture);
        SDL_FreeSurface(mSurface);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip, float zoom)
{
    if(x > 0 - (int) (mWidth * zoom) && x < SCREEN_WIDTH &&
       y > 0 - (int) (mHeight * zoom) && y < SCREEN_HEIGHT)
    {
        // Set rendering space and render to screen
        SDL_Rect renderQuad = { x, y, (int) (mWidth * zoom), (int) (mHeight * zoom)};
        // Set clip rendering dimensions
        if(clip != NULL) {
            renderQuad.w = clip->w * zoom;
            renderQuad.h = clip->h * zoom;
        }
        // Render to screen
        SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, angle, center, flip);
    }
}

int Texture::getWidth()
{
    return mWidth;
}

int Texture::getHeight()
{
    return mHeight;
}

Uint32 Texture::getPixelColor(int x, int y) {
    lockSurface();
    Uint32 *pixels = (Uint32 *)mSurface->pixels;
    unlockSurface();
    return pixels[(y * mSurface->w) + x];
}

bool Texture::lockSurface() {

    bool success = true;

    if(SDL_MUSTLOCK(mSurface)) {
        if(SDL_LockSurface(mSurface) != 0) {
            printf("Surface can't be locked!\n");
            success = false;
        }
    }

    return success;
}

bool Texture::unlockSurface()
{

    bool success = true;

    if(SDL_MUSTLOCK(mSurface)) {
        SDL_UnlockSurface(mSurface);
    }

    return success;
}

SDL_PixelFormat* Texture::getPixelFormat()
{
    return mSurface->format;
}

/** Create texture buffer. */
Texture gTextures[TEXTURES_TOTAL];
Texture gTextTexture;