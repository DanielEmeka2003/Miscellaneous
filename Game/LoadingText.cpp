#include "LoadingText.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

void LoadingText::free(){
    if (MainTexture)
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
    if (!loadsurface)
    {
        cout << "Unable to load image! SDL Error: " << path.c_str() << "  " << IMG_GetError() << endl;
    }
    else
    {
        SDL_SetColorKey(loadsurface, SDL_TRUE, SDL_MapRGB(loadsurface->format, 255, 255, 255));
        new_texture = SDL_CreateTextureFromSurface(rend_surface, loadsurface);
        if (!new_texture)
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

void LoadingText::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    SDL_Rect TextureRect {x, y, ImageWidth, ImageHeight}; 

    if (clip != NULL)
    {
        TextureRect.w = clip->w;  
        TextureRect.h = clip->h; 
    }
    

    SDL_RenderCopyEx(rend_surface, MainTexture, clip, &TextureRect, angle, center, flip); 
}

int LoadingText::getWidth()
{
    return ImageWidth;
}

int LoadingText::getHeight()
{
    return ImageHeight;
}

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

void close()
{
    SDL_DestroyRenderer(rend_surface);
    rend_surface = nullptr;
    SDL_DestroyWindow(window);
    window = nullptr;

    IMG_Quit();
    SDL_Quit();
}
