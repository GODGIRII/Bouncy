#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


#define WIDTH 800
#define HEIGHT 800

    //Mains Script

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

    //Ball

typedef Struct() {
    float x, y;
    float dx, dy;
    int radius;
    SDL_Color color;
} Ball;

Ball* create_ball(float x, float y, float dx, float dy, int radius, SDL_Color color); {
    Ball* b = (BALL*) malloc(sizeof(BALL));
    if (!b) {
        printf("Memory Allocation Falied\n");
        exit(1);
    }


    //Renders

SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);

SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);   
SDL_RenderClear(renderer);
SDL_RenderPresent(renderer); 

bool running = true;
SDL_Event event;

while (running) {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            running = false;

        }
    }

SDL_Delay(1);

}

SDL_DestroyWindow(window);
SDL_Quit();
return 0;
}
