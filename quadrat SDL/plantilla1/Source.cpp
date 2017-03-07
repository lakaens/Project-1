#include<iostream>
#include"SDL\SDL.h"
#pragma comment(lib,"lib/SDL2.lib")
#pragma comment(lib,"lib/SDL2main.lib")
SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[]) {
	SDL_Rect rectangle;
	
	SDL_Init(SDL_INIT_EVERYTHING);
	g_pWindow = SDL_CreateWindow("Chapter 1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	if (g_pWindow != 0) {
		g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
	}
	else {
		return 1;
	}
	SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255);
	SDL_RenderClear(g_pRenderer);
	rectangle.x = 50;
	rectangle.y = 50;
	rectangle.h = 50;
	rectangle.w = 50;
	SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 255);
	SDL_RenderFillRect(g_pRenderer, &rectangle);
	SDL_RenderPresent(g_pRenderer);


	SDL_Event event;
	SDL_Rect bullet[2];



	bool running = true;
	bool up = false, down = false, right = false, left=false, space=false;
	int posbx = 0, posby = 0, cont = 0;
	while (running) {
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYUP) {
				switch (event.key.keysym.sym) {
				case SDLK_UP:
					up = false;
					break;
				case SDLK_DOWN:
					down = false;
					break;
				case SDLK_RIGHT:
					right = false;
					break;
				case SDLK_LEFT:
					left = false;
					break;
				default:
					break;
				}
			}
			if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
					running = false;
					break;
				case SDLK_UP:
					up = true;
					break;
				case SDLK_DOWN:
					down = true;
					break;
				case SDLK_RIGHT:
					right = true;
					break;
				case SDLK_LEFT:
					left = true;
					break;
				case SDLK_SPACE:
					space = true;
					bullet[0].x = rectangle.x;
					bullet[0].y = rectangle.y;

					bullet[1].x = rectangle.x;
					bullet[1].y = rectangle.y;
				default:
					break;
				}
			}
		}

		if (rectangle.y != 0 && up) rectangle.y -= 5;
		if (rectangle.y != 430 && down)rectangle.y += 5;
		if (rectangle.x != 590 && right)rectangle.x += 5;
		if (rectangle.x != 0 && left) rectangle.x -= 5;
		


		SDL_SetRenderDrawColor(g_pRenderer, 255, 0, 0, 255);
		SDL_RenderClear(g_pRenderer);

		if (space) {
			space=false;
			bullet[cont].x = 25;
			bullet[cont].y = 25;
			bullet[cont].w = 20;
			bullet[cont].h = 10;
			cont++;
			if (cont == 2) {
				cont = 0;
			}
		}
		for (int i = 0; i < 2; i++) {
			bullet[i].x += 5;
			SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 255);
			SDL_RenderFillRect(g_pRenderer, &bullet[i]);
		}

		SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 255);
		SDL_RenderFillRect(g_pRenderer, &rectangle);
		SDL_RenderPresent(g_pRenderer);
		
	}
	int surface;
	
	SDL_Quit();
	return EXIT_SUCCESS;
 }