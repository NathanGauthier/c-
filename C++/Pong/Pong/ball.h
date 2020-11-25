#pragma once
#include <SDL_rect.h>
#include "soundEffects.h"



class Ball
{
public:
	Ball(int pX, int pY, int w, int h, int sX, int sY);
	Ball();
	~Ball();
	int y;


	SDL_Rect toRect();
	void draw(SDL_Renderer* renderer);
	void update(int screenWidth, int screeHeight, SoundEffect* soundEffect);

	void horizontalBounce(int xReplace);
	void verticalBounce(int yReplace);
	void setX(int newX);
	int getX() const;
	int getWidth() const;


private:
	int x;

	int width;
	int height;
	int speedX;
	int speedY;

};

