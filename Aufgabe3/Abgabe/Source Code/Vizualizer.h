#include "Linie.h"
#define VISUALIZE


//Starts up SDL and creates window
void SDLinit();



void SDLdraw(Line _l,int color);
void SDLdraw(Point _p,int _color,int size);
void SDLbackground();
void SDLrenderTexture();

void SDLrender();

void SDLclearBackground();

void SDLclear();

//Frees media and shuts down SDL
void close();

