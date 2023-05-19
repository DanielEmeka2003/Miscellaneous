//using sdl2 and c++ standard IO
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "LoadingText.hpp"

using namespace std;

LoadingText spriteSheet;
LoadingText backgroundTexture;

bool loadMedia()
{
    bool success = true;
    if (!spriteSheet.loadImage("C:/Users/MIKE EMEKA/Documents/C++/Game/new.png"))
    {
        cout << "Failed to load FrontTexture\n"; 
        success = false;
    }
    return success;
}


int main( [[maybe_unused]] int argc,  [[maybe_unused]]char* argv[]){
    if (!init())
    {
        cout << "Failed to initialize!\n";
    }
    else
    {
        if (!loadMedia())
        {
            cout << "Failed to load image!\n";
        }
        else
        {
            
            //Event handler
            SDL_Event e; 
            //quit flag
            bool quit = false;
            SDL_Rect any{0, 0, 50, 75};
            SDL_Rect down{0, 0, 50, 75};
            SDL_Rect up{0, 225, 50, 75};
            SDL_Rect qleft{0, 75, 50, 75};
            SDL_Rect qright{0, 150, 50, 75};    
            int x{0}, y{445};
            int amount{10};

            //main loop: a loop that runs while the application is active       
            while(!quit){
                Uint32 ticks = SDL_GetTicks64();
                Uint32 seconds = ticks/100;
                int sprite = seconds % 4;

                SDL_Rect downSprite = {sprite * 50, 0, 50, 75};
                SDL_Rect upSprite = {sprite * 50, 225, 50, 75};
                SDL_Rect leftSprite = {sprite * 50, 75, 50, 75};
                SDL_Rect rightSprite = {sprite * 50, 150, 50, 75};
                
                //Handles event on a queue; keeps track of recent event data and stores it in the SDL_event union 
                while(SDL_PollEvent(&e) != 0){
                    
                    
                    //executes true when an event type equals the explicit quit window, which it will then set the quit flag to true 
                    if(e.type == SDL_QUIT){ quit = true; }
                    else if (e.type == SDL_KEYDOWN)
                    {
                       switch (e.key.keysym.sym)
                       {
                       case SDLK_DOWN: any = downSprite; y += amount; break;
                       case SDLK_UP: any = upSprite; y -= amount; break;
                       case SDLK_LEFT: any = leftSprite; x -= amount; break;
                       case SDLK_RIGHT: any = rightSprite; x += amount; break;
                       }
                        
                    }
                    else if (e.type == SDL_KEYUP)
                    {
                        switch (e.key.keysym.sym)
                        {
                        case SDLK_DOWN: any = down; break;
                        case SDLK_UP: any = up; break;
                        case SDLK_LEFT: any = qleft; break;
                        case SDLK_RIGHT: any = qright; break;
                        }                    
                    }
                    
                    
                }

                if (x < 0)
                {
                    x += amount;
                }
                else if (x + 50 > screen_width)
                {
                    x -= amount;
                }
                if (y < 0)
                {
                    y += amount;
                }
                else if (y + 75 > screen_height)
                {
                    y -= amount;
                }
                   
                SDL_SetRenderDrawColor(rend_surface, 255, 255, 255, 255); 
                SDL_RenderClear(rend_surface);
                #if 0
                SDL_SetRenderDrawColor(rend_surface, 0, 0, 0, 255);                        
                //Triangle    
                SDL_RenderDrawLine(rend_surface, 20, 0, 150, 200);
                SDL_RenderDrawLine(rend_surface, 20, 0, 20, 200);
                SDL_RenderDrawLine(rend_surface, 20, 200, 150, 200);
                //Rectangle
                SDL_RenderDrawLine(rend_surface, 20, 200, 150, 200);
                SDL_RenderDrawLine(rend_surface, 20, 200, 20, 300);
                SDL_RenderDrawLine(rend_surface, 20, 300, 150, 300);           
                SDL_RenderDrawLine(rend_surface, 150, 200, 150, 300);   

                SDL_SetRenderDrawColor(rend_surface, 123, 0, 255, 255); 

                SDL_SetRenderDrawColor(rend_surface, 0, 0, 0, 255); 
				constexpr size_t size{ 13000 };
				constexpr int xsize{ 150 };
				constexpr int ysize{ 300 };
				SDL_Point array[size]{};
				
				for(size_t i{}; i < size; ++i)
				{
					for (int x_x{ 20 }; x <= xsize; ++x)
					array[i].x = x_x;
							
					for (int y_y{ 200 }; y <= ysize; ++y)
					array[i].y = y_y;
							
				}
				auto fail{ SDL_RenderDrawPoints(rend_surface, array, size) };
				if (fail < 0)
				{
					std::cerr << "This is the problem: " << SDL_GetError() << '\n';
					assert(false);
				}
                #endif
                spriteSheet.render(x, y, &any);              
                   
                SDL_RenderPresent(rend_surface); 
            }
            
        
        }
    }        
    close();
    return 0;
}