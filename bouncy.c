#include <SDL3/SDL.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 800

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL Init failed: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Bouncy Ball", WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
    if (!window) {
        printf("Window creation failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);   
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer); 

    SDL_Delay(3000);

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

