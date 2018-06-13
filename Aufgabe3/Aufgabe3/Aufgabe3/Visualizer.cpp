#include "stdafx.h"

#include <SDL.h>
#include "Drawer.h"
#include "Vizualizer.h"
#include <fstream>


Drawer* drawer = NULL;

//The window renderer
SDL_Renderer* renderer = NULL;

//The window
SDL_Window* window = NULL;

//Fps Manager


//Event
SDL_Event event;


void init()
{
	//Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);


	//Set texture filtering to linear
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	//Create window
	window = SDL_CreateWindow("SDL_Playground", SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);

	//Create renderer for window (no VSYNC because manual Framerate cap)
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_TARGETTEXTURE);

	drawer = new Drawer(renderer);

	//Initialize renderer color and Target to Texture
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, OPAQUE);
	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderClear(renderer);

	//Init Framerate manager

}

void draw(Line _l)
{
	_l.p = _l.p * (SCREEN_HEIGHT / 100);
	_l.q = _l.q * (SCREEN_HEIGHT / 100);
	drawer->setColor(WHITE);
	SDL_RenderDrawLine(renderer, _l.p.x, _l.p.y, _l.q.x, _l.q.y);
	SDL_RenderPresent(renderer);
}

void draw(Point _p)
{
	//skalieren
	_p = _p * (SCREEN_HEIGHT / 100);
	drawer->setColor(RED);
	drawer->drawcircle(_p.x, _p.y, SCREEN_HEIGHT / 100);
	SDL_RenderPresent(renderer);
}




/*
int main(int argc, char* args[])
{
	bool quit = false;
	//Start up SDL and create window
	init();

	//pre- loop functions

	//pre- loop functions



	while (!quit)
	{

		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			if (event.type == SDL_KEYDOWN)
			{

				SDL_SetRenderDrawColor(renderer, 0, 0, 0, OPAQUE);
				SDL_SetRenderTarget(renderer, NULL);
				SDL_RenderClear(renderer);

				

			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{

			}
		}


		SDL_RenderPresent(renderer);


	}
	//Free resources and close SDL
	close();
	return 0;
}

*/

void clear() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, OPAQUE);
	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderClear(renderer);
}

void close()
{
	//Destroy window and Renderer
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	//Quit SDL
	SDL_Quit();
}




