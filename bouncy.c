#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 800

typedef struct {
    float x, y;
    float dx, dy;
    int radius;
    SDL_Color color;
} Ball;

Ball* create_ball(float x, float y, float dx, float dy, int radius, SDL_Color color) {
    Ball* b = (Ball*) malloc(sizeof(Ball));
    if (!b) {
        printf("Memory Allocation Failed\n");
        exit(1);
    }
    b->x = x;
    b->y = y;
    b->dx = dx;
    b->dy = dy;
    b->radius = radius;
    b->color = color;
    return b;
}

void draw_circle(SDL_Renderer* renderer, int x, int y, int radius) {
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderPoint(renderer, x + dx, y + dy);
            }
        }
    }
}

void update_ball(Ball* b, float gravity, float deltaTime, int screenWidth, int screenHeight) {
    b->dy += gravity * deltaTime;
    b->x += b->dx * deltaTime;
    b->y += b->dy * deltaTime;

    if (b->x - b->radius < 0 || b->x + b->radius > screenWidth) {
        b->dx *= -1;
    }

    if (b->y + b->radius > screenHeight) {
        b->y = screenHeight - b->radius;
        b->dy *= -1;
    }
}

void destroy_ball(Ball* b) {
    free(b);
}

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
    SDL_Color red = {255, 0, 0, 255};
    Ball* ball = create_ball(400, 100, 100, 0, 20, red);  // starts in air, falling down

    float gravity = 500.0f;
    uint64_t lastTime = SDL_GetTicks();

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        uint64_t currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        update_ball(ball, gravity, deltaTime, WIDTH, HEIGHT);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, ball->color.r, ball->color.g, ball->color.b, ball->color.a);
        draw_circle(renderer, (int)ball->x, (int)ball->y, ball->radius);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }

    destroy_ball(ball);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

