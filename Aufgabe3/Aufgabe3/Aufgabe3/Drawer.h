#pragma once
#include <SDL.h>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

#define log(message) SDL_Log(message)
//defining fps for Game (for cap_framerate to use)
#define Project_FPS 60

//default Transparency for Renderer nontransparent
#define OPAQUE 0xFF

//convert 2d array input to 1d array input
#define twodoned(x,y,sizex) x+(y*sizex)

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 1024;

//Color constants
typedef enum {
	TRANSPARENT,
	BLACK,
	WHITE,
	YELLOW,
	//possible Player colors
	RED,
	GREEN,
	BLUE,
	PINK,
	PURPLE,
	LIGHTBLUE,
	ORANGE

	
}COLOR;





class Drawer
{
private:
	SDL_Color setTextColor(int color);
public:
	//The window renderer
	SDL_Renderer* renderer;
	//Collision Map is a 2d array mapped to a 1d array
	bool collisionMap[SCREEN_WIDTH*SCREEN_HEIGHT];
	//Font for rendering text


	Drawer(SDL_Renderer* newrenderer);

	void drawcircle(int x0, int y0, int radius);

	void horizontallineonarray(bool array[], int x1, int x2, int y);

	void verticallineonarray(bool array[], int y1, int y2, int x);

	void drawrectonarray(int x, int y, int width, int height, int thickness);

	void setColor(int color);

	void drawrectangle(int x, int y, int width, int height, int thickness,int color);

void drawoutline(int thickness, int color, int height);
		
	void drawcircleonarray(int x0, int y0, int radius);
	
	//draws a black rectangle
	void eraserect(int x, int y, int width, int height);

	bool insideBounds(int x, int y);

	string int2string(int i);

	SDL_Texture * loadTexture(std::string path);

	
	

	
};

