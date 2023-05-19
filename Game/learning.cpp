#include "learning.hpp"

static SDL_Rect g1TextureDimensions{};
static SDL_Rect g2TextureDimensions{};
static Ball ball_one{};
static Ball ball_two{};

static SDL_Window* gWindow{nullptr};
static SDL_Renderer* gRenderer{nullptr};
static SDL_Texture* g1Texture{nullptr};
static SDL_Texture* g2Texture{nullptr};

constexpr WindowDimensions width{640};
constexpr WindowDimensions height{480};
static LastFrameRateTime gLastFRT{};

constexpr float xforce{};
constexpr float yforce{300.0};

static float xVelocity{0};
static float yVelocity{70};

constexpr float x_acceleration{xforce/1.0};
constexpr float y_acceleration{yforce/1.0};

bool initialization()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not initialize: " << SDL_GetError() << '\n';
        return false;
    }
    gWindow = SDL_CreateWindow(nullptr, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!gWindow)
    {
        std::cerr << "SDL could not open window: " << SDL_GetError() << '\n';
        return false;
    }
    gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
    if (!gRenderer)
    {
        std::cerr << "SDL could not open renderer: " << SDL_GetError() << '\n';
    }
    return true;
}
void loadMedia(std::string path)
{
    SDL_Surface* surface{IMG_Load(path.c_str())};
    if(!surface)
    {
        std::cerr << "Could not load surface: " << IMG_GetError() << '\n';
        return;
    }

    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 163, 73, 164));
    g1Texture = SDL_CreateTextureFromSurface(gRenderer, surface);
    g2Texture = SDL_CreateTextureFromSurface(gRenderer, surface);
    
    if (!g1Texture and !g2Texture)
    {
        std::cerr << "Could not create texture: " << SDL_GetError() << '\n';
        return; 
    }
    g1TextureDimensions.w = surface->w;
    g1TextureDimensions.h = surface->h;

    g2TextureDimensions.w = surface->w; 
    g2TextureDimensions.h = surface->h;
    SDL_FreeSurface(surface);
}
void setup()
{
    loadMedia("C:/Users/MIKE EMEKA/Documents/C++/Game/IMAGES/ball.bmp");  
    ball_one = {width/4, height/4, g1TextureDimensions.w, g1TextureDimensions.h};  
    ball_two = {width/2, 0, g2TextureDimensions.w, g2TextureDimensions.h};  
}
void processInput()
{ 
    SDL_Event event{}; 
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT: gGameIsRunning = false; break;
        case SDL_KEYDOWN: 
        if (event.key.keysym.sym == SDLK_ESCAPE)
        gGameIsRunning = false;
        break;

        default: 
        break; 
    }
}
void constriant()
{
    if (ball_one.x < 0)
    {
        ball_one.x = 0;
        xVelocity *= -1;
    }
    else if (ball_one.x + ball_one.w > width)
    {
        ball_one.x = width - ball_one.w;
        xVelocity *= -1;
    }
    else if (ball_one.y < 0)
    {
        ball_one.y = 0;
        yVelocity *= -1;
    }
    else if (ball_one.y + ball_one.h > height)
    {
        ball_one.y = height - ball_one.h;
        yVelocity *= -1;
    }

    
    if (ball_two.x < 0)
    {
        ball_two.x = 0;
        xVelocity *= -1;
    }
    else if (ball_two.x + ball_two.w > width)
    {
        ball_two.x = width;
        xVelocity *= -1;
    }
    else if (ball_two.y < 0)
    {
        ball_two.y = 0;
        yVelocity *= -1;
    }
    else if (ball_two.y + ball_two.h > height)
    {
        ball_two.y = height - ball_two.h;
        yVelocity *= -1;
    }
    
    
}
void update()
{
    float deltaTime{(SDL_GetTicks64() - gLastFRT)/1000.0f};

    gLastFRT = SDL_GetTicks64();

    ball_one.x += xVelocity * deltaTime;
    ball_one.y += yVelocity * deltaTime; 

    //ball_two.x += xVelocity * deltaTime;
    //ball_two.y += yVelocity * deltaTime; 

    xVelocity += x_acceleration * deltaTime;
    yVelocity += y_acceleration * deltaTime;
    
    constriant();
}
void render()
{
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(gRenderer);

    g1TextureDimensions = {int(ball_one.x), int(ball_one.y), ball_one.w, ball_one.h};
    g2TextureDimensions = {int(ball_two.x), int(ball_two.y), ball_one.w, ball_one.h};
    
    SDL_RenderCopy(gRenderer, g1Texture, nullptr, &g1TextureDimensions);
    SDL_RenderCopy(gRenderer, g2Texture, nullptr, &g2TextureDimensions);
       
    SDL_RenderPresent(gRenderer);
}
void cleanup()
{
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_DestroyTexture(g1Texture);
    SDL_DestroyTexture(g2Texture);
    SDL_Quit();
    gWindow = nullptr;
    gRenderer = nullptr;
    g1Texture = nullptr;
    g2Texture = nullptr;
}
