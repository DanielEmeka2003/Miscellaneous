#if !defined(LEARNING_HPP)
#define LEARNING_HPP
#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <SDL.h>
#include <SDL_image.h>

using WindowDimensions = int;
using LastFrameRateTime = long long unsigned int;

inline bool gGameIsRunning{};

struct Ball
{
    float x;
    float y;
    int w;
    int h;
};

bool initialization();
void loadMedia(std::string path);
void setup(); 
void processInput();
void update();
void render();
void cleanup();

class Ty
{
private:
    int width; 
    int any;
    
public:
    Ty(/* args */) {}
    ~Ty() {}
};


#endif // LEARNING_HPP
