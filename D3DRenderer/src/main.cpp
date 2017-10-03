// Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <d3d11.h>
#include <SimpleMath.h>

// Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main(int argc, char* args[])
{
    // Start SDL
    int pid = SDL_Init(SDL_INIT_EVERYTHING);
    if (pid < 0)
    {
        printf("Could not initialize SDL - SDL_Error : %s\n", SDL_GetError());
        return -1;
    }

    // Create Window
    SDL_Window *window = SDL_CreateWindow("D3D Renderer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Could not create window - SDL_Error : %s\n", SDL_GetError());
        return -1;
    }

    // Create Surface
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    if (surface == NULL)
    {
        printf("Could not create surface - SDL_Error : %s\n", SDL_GetError());
        return -1;
    }
    SDL_UpdateWindowSurface(window);



    SDL_DestroyWindow(window);

    // Quit SDL
    SDL_Quit();

    return 0;
}
