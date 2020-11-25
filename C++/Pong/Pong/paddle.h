#pragma once
#include <SDL.h>
#include "InputState.h"



class Paddle
{
public:
	Paddle(int pX, int pY, int w, int h, int sY);


	SDL_Rect toRect();
	void draw(SDL_Renderer* renderer);

	void update(InputState* inputState, int screenHeight);
	void updateAI(int screeHeight, int ballY);

	void moveUp(int screenHeight);
	void moveDown(int screenHeight);

private:
	int x;
	int y;
	int width;
	int height;
	int speedY;


};