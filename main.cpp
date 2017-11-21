//Using SDL, SDL_image, standard IO, and strings
#include "GameCore.h"
#include "system_includes.h"
#include "assets_includes.h"
#include <time.h>
#include <algorithm>
 
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
			//While application is running
			while( !quit ) {
				//Handle events on queue
				while(SDL_PollEvent( &event ) != 0) {
					if(event.type == SDL_QUIT) {
						quit = true;
                    }
				}
                core.update();
                //Clear screen
                SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND); 
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
				//Update screen
                core.render();
				SDL_RenderPresent( gRenderer );
			}
		}
	}

	//Free resources and close SDL
	Config::closeMedia();

	return 0;
}