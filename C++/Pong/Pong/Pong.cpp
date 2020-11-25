#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <cstdio>
#include "ball.h"
#include "paddle.h"
#include "InputState.h"
#include "text.h"
#include "soundEffects.h"



// Definitions
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 480;
bool quit = false;
Ball ball = Ball(0, 350, 32, 32, 4, 4);
Paddle paddle = Paddle(0, 200, 32, 128, 5);
Paddle paddleOpponent = Paddle(SCREEN_WIDTH - 32, 200, 32, 128, 5);
SDL_Rect ballRect = { 0, 0, 32, 32 };
InputState inputState;
int ScorePlayer = 0;
int scoreAI = 0;
Text playerScoreText = Text(220, 100, 50, 75);
Text opponentScoreText = Text(550, 100, 50, 75);
int result = 0;
Text resultText = Text(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 3, 150, 50);

//Sounds
SoundEffect defeatSound = SoundEffect("defeat.wav");
SoundEffect outSound = SoundEffect("out.wav");
SoundEffect pingSound = SoundEffect("ping.wav");
SoundEffect restartSound = SoundEffect("restart.wav");
SoundEffect victorySound = SoundEffect("victory.wav");
SoundEffect wallSound = SoundEffect("wall.wav");


bool handleInput();
void update(SDL_Renderer* renderer);
bool AABBcollision(SDL_Rect* rectA, SDL_Rect* rectB);
void load(SDL_Renderer*);
void draw(SDL_Renderer*);
void close(SDL_Window*, SDL_Renderer*);


// Program
int main(int argc, char* args[])
{
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;


	//init window
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	TTF_Init();
	Mix_Init(MIX_INIT_OGG | MIX_INIT_MP3);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);


	//load
	load(renderer);

	while (!quit)
	{
		//Inputs
		quit = handleInput();

		//Update
		update(renderer);

		//Draw
		draw(renderer);

	}

	//End
	close(window, renderer);

	return 0;
}


void load(SDL_Renderer* renderer)
{
	playerScoreText.load(renderer, "0");
	opponentScoreText.load(renderer, "0");
	resultText.load(renderer, "");
	defeatSound.load();
	outSound.load();
	pingSound.load();
	victorySound.load();
	restartSound.load();
	wallSound.load();


}

bool handleInput()
{

	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_z)
			{
				inputState.paddleUp = true;
			}

			else if (e.key.keysym.sym == SDLK_s)
			{
				inputState.paddleDown = true;
			}
		}

		else if (e.type == SDL_KEYUP)
		{
			if (e.key.keysym.sym == SDLK_z)
			{
				inputState.paddleUp = false;
			}

			else if (e.key.keysym.sym == SDLK_s)
			{
				inputState.paddleDown = false;
			}
		}
		else if (e.type == SDL_QUIT)
		{
			return true;
		}
	}
	return false;
}

void update(SDL_Renderer* renderer)
{
	if (result == 0)
	{
		ball.update(SCREEN_WIDTH, SCREEN_HEIGHT, &wallSound);
		paddle.update(&inputState, SCREEN_HEIGHT);
		paddleOpponent.updateAI(SCREEN_HEIGHT, ball.y);

		//collision

		SDL_Rect ballRect = ball.toRect();
		SDL_Rect paddleRect = paddle.toRect();
		SDL_Rect paddleOpponentRect = paddleOpponent.toRect();

		if (AABBcollision(&ballRect, &paddleRect))           // collision left paddle/ball
		{
			ball.horizontalBounce(paddleRect.x + paddleRect.w);
			pingSound.play();
		}

		if (AABBcollision(&ballRect, &paddleOpponentRect))                  // collision right paddle/ball
		{
			ball.horizontalBounce(paddleOpponentRect.x - ballRect.w);
			pingSound.play();
		}


		//points
		if (ball.getX() < 0)
		{
			++scoreAI;
			ball.setX(SCREEN_WIDTH / 2);
			char newText[2];
			sprintf_s(newText, "%d", scoreAI);
			opponentScoreText.changeText(renderer, newText);
			outSound.play();

			//Defeat
			if (scoreAI >= 7)
			{
				result = 2;
				resultText.changeText(renderer, "Defeat");
				defeatSound.play();
			}
		}
		else if (ball.getX() > SCREEN_WIDTH - ball.getWidth())
		{
			++ScorePlayer;
			ball.setX(SCREEN_WIDTH / 2);
			char newText[2];
			sprintf_s(newText, "%d", ScorePlayer);
			playerScoreText.changeText(renderer, newText);
			outSound.play();

			//Victory
			if (ScorePlayer >= 7)
			{
				result = 1;
				resultText.changeText(renderer, "Victory");
				victorySound.play();
			}
		}
	}
	else
	{

	}
}


bool AABBcollision(SDL_Rect* rectA, SDL_Rect* rectB)
{
	int xMinA = rectA->x;
	int xMaxA = rectA->x + rectA->w;
	int yMinA = rectA->y;
	int yMaxA = rectA->y + rectA->h;
	int xMinB = rectB->x;
	int xMaxB = rectB->x + rectB->w;
	int yMinB = rectB->y;
	int yMaxB = rectB->y + rectB->h;
	return!(xMinA > xMaxB || xMaxA < xMinB || yMinA > yMaxB || yMaxA < yMinB);
}



void draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	playerScoreText.draw(renderer);
	opponentScoreText.draw(renderer);
	ball.draw(renderer);
	paddle.draw(renderer);
	paddleOpponent.draw(renderer);
	resultText.draw(renderer);

	SDL_RenderPresent(renderer);
}



void close(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_CloseAudio();
	Mix_Quit();
	TTF_Quit();
	SDL_Quit();
}
