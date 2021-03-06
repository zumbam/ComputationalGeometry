#include "stdafx.h"



#include "Vizualizer.h"

#ifdef VISUALIZE



#include <SDL.h>
#include "Drawer.h"
#include <fstream>



Drawer* drawer = NULL;

//The window renderer
SDL_Renderer* renderer = NULL;

//The window
SDL_Window* window = NULL;

//The buffer Texture
SDL_Texture* mapTexture = NULL;


//Event
SDL_Event event;

#endif
void SDLinit()
{
#ifdef VISUALIZE
	//Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);


	//Set texture filtering to linear
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	//Create window
	window = SDL_CreateWindow("SDL_Playground", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED
		, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);

	//Create renderer for window (no VSYNC because manual Framerate cap)
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_TARGETTEXTURE);

	drawer = new Drawer(renderer);

	//create Buffer Texture
	mapTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);

	//Initialize renderer color and Target to Texture
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, OPAQUE);
	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderClear(renderer);

	//Init Framerate manager
#endif // VISUALIZE

}

void SDLdraw(Line _l,int color)
{
#ifdef VISUALIZE
	_l.p = _l.p * (SCREEN_HEIGHT / 100);
	_l.q = _l.q * (SCREEN_HEIGHT / 100);
	drawer->setColor(color);
	SDL_RenderDrawLine(renderer, _l.p.x, _l.p.y, _l.q.x, _l.q.y);
#endif // VISUALIZE
}

void SDLdraw(Point _p,int _color, int size)
{
#ifdef VISUALIZE
	//skalieren
	_p = _p * (SCREEN_HEIGHT / 100);
	drawer->setColor(_color);
	drawer->drawcircle(_p.x, _p.y, size*SCREEN_HEIGHT / 500);
#endif // VISUALIZE
}

void SDLbackground()
{
#ifdef VISUALIZE
	
		SDL_SetRenderTarget(renderer, mapTexture);
#endif // VISUALIZE
	
}

void SDLrenderTexture() {
#ifdef VISUALIZE
	SDL_Rect rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };
	SDL_RenderCopy(renderer, mapTexture, NULL, &rect);
#endif // VISUALIZE
}

void SDLrender() {
#ifdef VISUALIZE
	SDL_RenderPresent(renderer);
#endif // VISUALIZE	
}

void SDLclearBackground() {
#ifdef VISUALIZE
	SDL_SetRenderTarget(renderer, mapTexture);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, OPAQUE);
	SDL_RenderClear(renderer);
#endif // VISUALIZE

}

void SDLclear() {
#ifdef VISUALIZE
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, OPAQUE);
	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderClear(renderer);
#endif // VISUALIZE
}

void close()
{
#ifdef VISUALIZE
	//Destroy window and Renderer
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	//Quit SDL
	SDL_Quit();
#endif // VISUALIZE
}






