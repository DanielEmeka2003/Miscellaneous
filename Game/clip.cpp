//using sdl2 and c++ standard IO
#include <iostream>
#include <vector>
#include <cmath>

#include "SDL2/SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"


using namespace std;

bool loadMedia();  
void close();
SDL_Window* window = NULL;
SDL_Renderer* rend_surface = NULL;
const int screen_width = 1280, screen_height = 720;


class LoadingText
{
private:
    SDL_Texture* MainTexture;
    int ImageWidth, ImageHeight;
public:
    LoadingText();
    ~LoadingText();
    bool loadImage(string path);
    void free();
    void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0, SDL_Point* center = NULL, SDL_RendererFlip = SDL_FLIP_NONE);
    int getWidth();
    int getHeight();
};

LoadingText::LoadingText()
{
    MainTexture = NULL;
    ImageWidth = 0;
    ImageHeight = 0;
}

LoadingText::~LoadingText()
{
    free();
}

void LoadingText::free(){
    if (MainTexture != NULL)
    {
        SDL_DestroyTexture(MainTexture);
        ImageWidth = 0;
        ImageHeight = 0;
    }
    
}

bool LoadingText::loadImage(string path){
    free();
    SDL_Texture* new_texture = NULL;

    SDL_Surface* loadsurface = IMG_Load(path.c_str());
    if (loadsurface == NULL)
    {
        cout << "Unable to load image! SDL Error: " << path.c_str() << "  " << IMG_GetError() << endl;
    }
    else
    {
        SDL_SetColorKey(loadsurface, SDL_TRUE, SDL_MapRGB(loadsurface->format, 255, 255, 255));
        new_texture = SDL_CreateTextureFromSurface(rend_surface, loadsurface);
        if (new_texture == NULL)
        {
            cout << "Unable to load textue image! SDL_Error: " << SDL_GetError() << endl;
        }
        else
        {
            ImageWidth = loadsurface->w;
            ImageHeight = loadsurface->h;
        }
        
        SDL_FreeSurface(loadsurface);   
    }
    MainTexture = new_texture;
    return MainTexture != NULL;
}

void LoadingText::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip){
    SDL_Rect TextureRect {x, y, ImageWidth, ImageHeight}; 

    if (clip != NULL)
    {
        TextureRect.w = clip->w;  
        TextureRect.h = clip->h; 
    }
    

    SDL_RenderCopyEx(rend_surface, MainTexture, clip, &TextureRect, angle, center, flip); 
}

int LoadingText::getWidth(){
    return ImageWidth;
}

int LoadingText::getHeight(){
    return ImageHeight;
}

LoadingText spriteSheet;
LoadingText backgroundTexture;


bool init(){
    bool success = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
       cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
       success = false;
    }

    else
    {
        window = SDL_CreateWindow("Emeka Daniel", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width, screen_height, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
            success = false;
        }
        else
        {
            rend_surface = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (rend_surface == NULL)
            {
                cout << "Unable to create renderer! SDL_Error: " << SDL_GetError() << endl;
                success = false;
            }
            else
            {
                
                int imgflag= IMG_INIT_PNG;
                if (!(IMG_Init(imgflag) & imgflag))
                {
                   cout << "SDL_image could not initialize! Image_Error: " << IMG_GetError() << endl;
                   success = false;
                }
                 
            }
            
        }
        
          
       
        
    }
    return success;
    
}



bool loadMedia(){
    bool success = true;
    if (!spriteSheet.loadImage("new.png"))
    {
        cout << "Failed to load FrontTexture\n";
        success = false;
    }
   
    
    
    
    
    return success;
}

void close(){
    spriteSheet.free();
    backgroundTexture.free();
    
    SDL_DestroyRenderer(rend_surface);
    rend_surface = NULL;
    SDL_DestroyWindow(window);
    window = NULL;

    IMG_Quit();
    SDL_Quit();
}

int main(int agrc, char* agrs[]){
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
            SDL_Rect any = {0, 0, 50, 75};
            SDL_Rect down = {0, 0, 50, 75};
            SDL_Rect up = {0, 225, 50, 75};
            SDL_Rect qleft = {0, 75, 50, 75};
            SDL_Rect qright = {0, 150, 50, 75};    
            int x = 0, y = 445;
            int amount = 8;

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
                    
                    

                    
                      
                    spriteSheet.render(x, y, &any);                 
                   
                    SDL_RenderPresent(rend_surface); 
                   
                     
            }
            
        
        }
    }        
    close();
    return 0;
}