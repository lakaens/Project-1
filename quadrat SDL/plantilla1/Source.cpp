#include<iostream>
#include"SDL\SDL.h"
#pragma comment(lib,"lib/SDL2.lib")
#pragma comment(lib,"lib/SDL2main.lib")
SDL_Window* g_pWindow = 0;
SDL_Renderer* g_pRenderer = 0;

int main(int argc, char* args[]) {
	SDL_Rect rectangle;

	SDL_Texture* ship = NULL;
	SDL_Texture* laser = NULL;


	SDL_Init(SDL_INIT_EVERYTHING);
	
	g_pWindow = SDL_CreateWindow("Pre-Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
	if (g_pWindow != 0) {
		g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_PRESENTVSYNC);
		ship = SDL_CreateTextureFromSurface(g_pRenderer, SDL_LoadBMP("player.bmp"));
		laser=SDL_CreateTextureFromSurface(g_pRenderer,SDL_LoadBMP("laser.bmp"));
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
	SDL_Rect bulletw[2];
	SDL_Rect bulletq[2];
	SDL_Rect bullete[2];

	bool running = true;
	bool up = false, down = false, right = false, left=false, w=false, q = false, e = false;
	int contw = 0, contq = 0, conte = 0;
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
			if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
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
				case SDLK_w:
					w = true;
					bulletw[contw].x = rectangle.x;
					bulletw[contw].y = rectangle.y;
					break;	
				case SDLK_q:
					q = true;
					bulletq[contq].x = rectangle.x;
					bulletq[contq].y = rectangle.y;
					break;

				case SDLK_e:
					e = true;
					/*
					bullete[conte].x = rectangle.x;
					bullete[conte].y = rectangle.y;
					*/
					break;

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

		if (w) {
			w = false;
			bulletw[contw].x = rectangle.x + 15;
			bulletw[contw].y = rectangle.y + 15;
			bulletw[contw].w = 10;
			bulletw[contw].h = 40;

			contw++;

			if (contw == 2) {
				contw = 0;
			}
		}
		for (int i = 0; i < 2; i++) {
			bulletw[i].y -= 10;
			//SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 255);
			SDL_RenderCopy(g_pRenderer, laser, NULL, &bulletw[i]);
			//SDL_RenderFillRect(g_pRenderer, &bulletw[i]);
			
		}
		

		if (q) {
			q = false;
			bulletq[contq].x = rectangle.x + 15;
			bulletq[contq].y = rectangle.y + 15;
			bulletq[contq].w = 10;
			bulletq[contq].h = 40;
			contq++;
			if (contq == 2) {
				contq = 0;
			}

		}
		for (int i = 0; i < 2; i++) {
			bulletq[i].x -= 10;
			bulletq[i].y -= 10;
			//SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 255);
			//SDL_RenderFillRect(g_pRenderer, &bulletq[i]);
			SDL_RenderCopy(g_pRenderer, laser, NULL, &bulletq[i]);
		}
		if (e) {
			e = false;
			bullete[contq].x = rectangle.x + 15;
			bullete[contq].y = rectangle.y + 15;
			bullete[contq].w = 10;
			bullete[contq].h = 40;
			conte++;
			if (conte == 2) {
				conte = 0;
			}

		}
		for (int i = 0; i < 2; i++) {
			bullete[i].x += 10;
			bullete[i].y -= 10;
			//SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 255, 255);
			//SDL_RenderFillRect(g_pRenderer, &bullete[i]);
			SDL_RenderCopy(g_pRenderer, laser, NULL, &bullete[i]);
		}

		SDL_RenderCopy(g_pRenderer, ship, NULL, &rectangle);
		SDL_RenderPresent(g_pRenderer);
		
	}

	
	SDL_Quit();
	return EXIT_SUCCESS;
 }