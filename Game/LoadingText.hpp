#pragma once

#include "C:\Users\MIKE EMEKA\Documents\C++\includes.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

inline SDL_Window* window{nullptr}; 
inline SDL_Renderer* rend_surface{nullptr};
inline const int screen_width{640}; 
inline const int screen_height{480};
bool init();
void close();

class LoadingText
{
    SDL_Texture* MainTexture{nullptr};
    int ImageWidth{0}; 
    int ImageHeight{0};
public:
    LoadingText() = default;
    
    ~LoadingText() 
    {
        free();
    }

    bool loadImage(string path);
    void free();
    void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0, SDL_Point* center = NULL, SDL_RendererFlip = SDL_FLIP_NONE);
    int getWidth();
    int getHeight();
};


