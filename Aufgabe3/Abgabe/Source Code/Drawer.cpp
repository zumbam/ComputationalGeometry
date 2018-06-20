#include "stdafx.h"
#include "Drawer.h"


SDL_Color Drawer::setTextColor(int color)
{
	SDL_Color SDLcolor;
	switch (color)
	{
	case YELLOW:
		SDLcolor.r=255;
		SDLcolor.g = 255;
		SDLcolor.b = 0;
		break;

	case RED:
		SDLcolor.r = 255;
		SDLcolor.g = 0;
		SDLcolor.b = 0;		
		break;
	case GREEN:
		SDLcolor.r = 0;
		SDLcolor.g = 255;
		SDLcolor.b = 0;		
		break;
	case BLUE:
		SDLcolor.r = 0;
		SDLcolor.g = 0;
		SDLcolor.b = 255;	
		break;
	case BLACK:
		SDLcolor.r = 0;
		SDLcolor.g = 0;
		SDLcolor.b = 0;	
		break;
	case WHITE:
		SDLcolor.r = 255;
		SDLcolor.g = 255;
		SDLcolor.b = 255;		
		break;
	case PINK:
		SDLcolor.r = 255;
		SDLcolor.g = 0;
		SDLcolor.b = 255;
		break;
	case PURPLE:
		SDLcolor.r = 128;
		SDLcolor.g = 0;
		SDLcolor.b = 128;
		break;
	case LIGHTBLUE:
		SDLcolor.r = 0;
		SDLcolor.g = 128;
		SDLcolor.b = 255;
		break;
	case ORANGE:
		SDLcolor.r = 255;
		SDLcolor.g = 128;
		SDLcolor.b = 0;
		break;
	default:
		break;
	}
	return SDLcolor;
}

Drawer::Drawer(SDL_Renderer* newrenderer)
{
	renderer = newrenderer;
	
	memset(collisionMap, 0, (SCREEN_HEIGHT*SCREEN_WIDTH) * sizeof(*collisionMap));
}

void Drawer::drawcircle(int x0, int y0, int radius)
{
	int x = radius;
	int y = 0;
	int err = 0;
	while (x >= y)
	{
		SDL_RenderDrawLine(renderer, x0 + y, y0 + x, x0 - y, y0 + x);
		SDL_RenderDrawLine(renderer, x0 + x, y0 + y, x0 - x, y0 + y);
		SDL_RenderDrawLine(renderer, x0 - y, y0 - x, x0 + y, y0 - x);
		SDL_RenderDrawLine(renderer, x0 - x, y0 - y, x0 + x, y0 - y);




		y += 1;
		err += 1 + 2 * y;
		if (2 * (err - x) + 1 > 0)
		{
			x -= 1;
			err += 1 - 2 * x;
		}
	}
}

void Drawer::drawrectangle(int x, int y, int width, int height, int thickness,int color) {
	
	SDL_Rect rect;
	setColor(color);
	for (int i = 0; i < thickness; i++)
	{
		rect.x = x + i;
		rect.y = y + i;
		rect.w = width - 2 * i;
		rect.h = height - 2 * i;
		SDL_RenderDrawRect(renderer, &rect);
	}



}

void Drawer::setColor(int color)
{
	switch (color)
	{
	case TRANSPARENT:
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		break;
	case YELLOW:
		//yellow default
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x00, OPAQUE);
		break;
	case GREEN:
		//green
		SDL_SetRenderDrawColor(renderer, 0, 0xFF, 0x00, OPAQUE);
		break;
	case BLUE:
		//blue
		SDL_SetRenderDrawColor(renderer, 0, 0, 0xFF, OPAQUE);
		break;
	case RED:
		//red
		SDL_SetRenderDrawColor(renderer, 0xFF, 0, 0, OPAQUE);
		break;
	case BLACK:
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, OPAQUE);
		break;
	case WHITE:
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, OPAQUE);
		break;
	case PINK:
		SDL_SetRenderDrawColor(renderer, 255, 0, 255, OPAQUE);
		break;
	case PURPLE:
		SDL_SetRenderDrawColor(renderer, 128, 0, 128, OPAQUE);
		break;
	case LIGHTBLUE:
		SDL_SetRenderDrawColor(renderer, 0, 128, 255, OPAQUE);
		break;
	case ORANGE:
		SDL_SetRenderDrawColor(renderer, 255, 128, 0, OPAQUE);
		break;

		//up to 255 colours possible

	default:
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, OPAQUE);
		break;
	}
}

void Drawer::horizontallineonarray(bool array[], int x1,int x2, int y ) {
	int x = x1;
	if (x1<x2)
	{
		while (x <= x2)
		{
			array[twodoned(x, y, SCREEN_WIDTH)] = true;
			x++;
		}
	}
	else
	{
		while (x > x2)
		{
			array[twodoned(x, y, SCREEN_WIDTH)] = true;
			x--;
		}
	}

}

void Drawer::verticallineonarray(bool array[], int y1, int y2, int x)
{
	int y = y1;
	if (y1<y2)
	{
		while (y <= y2)
		{
			array[twodoned(x, y, SCREEN_WIDTH)] = true;
			y++;
		}
	}
	else
	{
		while (y > y2)
		{
			array[twodoned(x, y, SCREEN_WIDTH)] = true;
			x--;
		}
	}

}

void Drawer::drawrectonarray(int newx, int newy, int newwidth, int newheight, int thickness)
{
	
	for (int i = 0; i < thickness; i++)
	{
		int x = newx + i;
		int y = newy + i;
		int width = newwidth - 2*i;
		int height= newheight - 2*i;
		verticallineonarray(collisionMap, y, y + height, x);
		verticallineonarray(collisionMap, y, y + height, width + x);
		horizontallineonarray(collisionMap, x, x + width, y);
		horizontallineonarray(collisionMap, x, x + width, y + height);
	}
}

void Drawer::drawoutline(int thickness,int color,int height)
{	
	int x = 0;
	int y = 0;
	
	drawrectangle(x, y, height * 4 / 3, height, thickness, color);
	//drawrectonarray(x, y, width, height, thickness);
}

void Drawer::drawcircleonarray(int x, int y, int radius)
{
	int xcircle = radius;
	int ycircle = 0;
	int err = 0;

	while (xcircle >= ycircle)
	{
		horizontallineonarray(collisionMap, x + ycircle, x - ycircle, y + xcircle);
		horizontallineonarray(collisionMap, x + xcircle, x - xcircle, y + ycircle);
		horizontallineonarray(collisionMap, x - ycircle, x + ycircle, y - xcircle);
		horizontallineonarray(collisionMap, x - xcircle, x + xcircle, y - ycircle);

		ycircle += 1;
		err += 1 + 2 * ycircle;
		if (2 * (err - xcircle) + 1 > 0)
		{
			xcircle -= 1;
			err += 1 - 2 * xcircle;
		}
	}
}



void Drawer::eraserect(int x, int y, int width, int height)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
	setColor(BLACK);
	SDL_RenderFillRect(renderer, &rect);
}

bool Drawer::insideBounds(int x, int y)
{
	if (x < SCREEN_WIDTH&& x>0 && y < SCREEN_HEIGHT&&y>0)return true;
	else return false;
}

string Drawer::int2string(int i)
{
	stringstream out;
	out << i;
	return out.str();

}

SDL_Texture * Drawer::loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("loadTexture: Unable to load image\n");
	}
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0, 0));
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}