#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int OBJECT_WIDTH = 50;
const int OBJECT_HEIGHT = 50;
const int OBJECT_SPEED = 2;

// Structure to represent a moving object
struct MovingObject {
    int x, y;
    int dx, dy;
};

bool init(SDL_Window **window, SDL_Renderer **renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    *window = SDL_CreateWindow("Moving Object Animation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (*window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (*renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

void close(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main() {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Event e;
    struct MovingObject object = {SCREEN_WIDTH / 2 - OBJECT_WIDTH / 2, SCREEN_HEIGHT / 2 - OBJECT_HEIGHT / 2, OBJECT_SPEED, OBJECT_SPEED};

    if (!init(&window, &renderer)) {
        return 1;
    }

    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        // Move the object
        object.x += object.dx;
        object.y += object.dy;

        // If the object goes out of bounds, wrap it around
        if (object.x < 0 - OBJECT_WIDTH) {
            object.x = SCREEN_WIDTH;
        } else if (object.x > SCREEN_WIDTH) {
            object.x = 0 - OBJECT_WIDTH;
        }

        if (object.y < 0 - OBJECT_HEIGHT) {
            object.y = SCREEN_HEIGHT;
        } else if (object.y > SCREEN_HEIGHT) {
            object.y = 0 - OBJECT_HEIGHT;
        }

        // Render the object
        SDL_Rect objectRect = {object.x, object.y, OBJECT_WIDTH, OBJECT_HEIGHT};
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &objectRect);

        // Update the screen
        SDL_RenderPresent(renderer);

        // Delay to control animation speed
        SDL_Delay(10);
    }

    close(window, renderer);

    return 0;
}
