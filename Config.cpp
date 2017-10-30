#include "Texture.h"
#include "Config.h"

/** The SDL window. */
SDL_Window* gWindow = NULL;
/** The windows renderer. */
SDL_Renderer* gRenderer = NULL;
/** Globally used font. */
TTF_Font *gFont = NULL;

Texture gTextTexture;

bool Config::init() {
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);  
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool Config::loadMedia() {
	//Loading success flag
	bool success = true;

    for(int i = 0; i < TEXTURES_TOTAL; i++) {
        if(!gTextures[i].loadFromFile("../textures/" + gTextureStringNames[i] + ".png")) 
            success = false;
	}
    //Open the font
//    gFont = TTF_OpenFont("../true_type_fonts/Courier Prime Italic.ttf", 16);
//    if(gFont == NULL) {
//        printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
//        success = false;
//    }   
	return success;
}

void Config::closeMedia() {
    
    for(int i; i < TEXTURES_TOTAL; i++)
        gTextures[i].free();
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
