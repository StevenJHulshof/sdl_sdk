//Using SDL, SDL_image, standard IO, and strings
#include <time.h>
#include <iostream>
#include <string>
#include "GameCore.h"
#include "Config.h"
#include "Input.h"
#include "time_user.h"

int main(int argc, char* args[])
{
    srand(time(NULL));
   	//Start up SDL and create window
	if(!Config::init())
		printf( "Failed to initialize!\n" );
	else {
		//Load media
		if(!Config::loadMedia())
			printf( "Failed to load media!\n" );
		else {

            SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );
            gTextures[TEXTURE_LOADING_SCREEN].render(0, 0, NULL, 0, NULL, SDL_FLIP_NONE, 1.0);
            SDL_RenderPresent( gRenderer );
            // Gamecore
            GameCore core;
			//Main loop flag
			bool quit = false;
            SDL_Event event;
            ShowCursor(false);
			//While application is running
            uint64_t frameTime = 1;
			while( !quit ) {
                while(SDL_PollEvent( &event ) != 0) {

				}
                uint64_t startTime = getTimeMicroSec();
                // Handle events on queue
                quit = Input::onKeyPressed(VK_ESCAPE);
                core.update();
                // Clear screen
                SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
				// Update screen
                core.render();

                SDL_Color textColor = { 0, 255, 0 };
                gTextTexture.loadFromRenderedText("FPS: " + std::to_string((int)(1000000 / frameTime)), textColor);
                gTextTexture.render(0, 0, NULL, 0, NULL, SDL_FLIP_NONE, 1);
				SDL_RenderPresent( gRenderer );
                frameTime = getTimeMicroSec() - startTime;
			}
		}
	}

	//Free resources and close SDL
	Config::closeMedia();

	return 0;
}
