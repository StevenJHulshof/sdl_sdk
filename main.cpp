//Using SDL, SDL_image, standard IO, and strings
#include "GameCore.h"
#include "system_includes.h"
#include "assets_includes.h"
#include <time.h>
#include <time_user.h>
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
            ShowCursor(false);
			//While application is running
            uint64_t frameTime = 1;
			while( !quit ) {
                uint64_t startTime = getTimeMilliSec();
//				Handle events on queue
				while(SDL_PollEvent( &event ) != 0) {
                    switch( event.key.keysym.sym )
                    {
                        case SDLK_ESCAPE: 
                        std::cout << "FPS: " << (int)(1000 / frameTime) << std::endl;
                        quit = true; 
                        break;
                        
                        default:
                        break;
                    }
					if(event.type == SDL_QUIT) {
						quit = true;
                    }
				}
                core.update();
                // Clear screen
                SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND); 
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );
				// Update screen
                core.render();
				SDL_RenderPresent( gRenderer );
                frameTime = getTimeMilliSec() - startTime;
			}
		}
	}

	//Free resources and close SDL
	Config::closeMedia();

	return 0;
}