
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "ball.h"
Ball::Ball(int pX, int pY, int w, int h, int sX, int sY)
	:x(pX), y(pY), width(w), height(h), speedX(sX), speedY(sY)
{

}

Ball::Ball()
	: x(0), y(0), width(32), height(32), speedX(1), speedY(1)
{

}

Ball::~Ball()
{

}


SDL_Rect Ball::toRect()
{
	SDL_Rect rect = { x ,y, width, height };
	return rect;
}

void Ball::draw(SDL_Renderer* renderer)
{
	SDL_Rect rect = toRect();
	SDL_RenderFillRect(renderer, &rect);
}

void Ball::update(int screenWidth, int screenHeight, SoundEffect* soundEffect)
{
	x += speedX;
	y += speedY;
	if (y < 0)
	{
		verticalBounce(0);
		soundEffect->play();
	}

	if ((y + width) > screenHeight)
	{
		verticalBounce(screenHeight - height);
		soundEffect->play();
	}



}

void Ball::horizontalBounce(int xReplace)
{
	speedX *= -1;
	x = xReplace;
}

void Ball::verticalBounce(int yReplace)
{

	speedY *= -1;
	y = yReplace;

}

int Ball::getX() const
{
	return x;
}
int Ball::getWidth() const
{
	return width;
}
void Ball::setX(int newX)
{
	x = newX;
}