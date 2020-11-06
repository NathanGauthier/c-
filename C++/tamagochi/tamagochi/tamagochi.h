#pragma once
#include <string>

class Tamagochi
{
public:
	Tamagochi(int pHunger, int pBoredom);
	Tamagochi();
	~Tamagochi();
	void play();
	void eat();
	void talk() const;


private:
	int hunger;
	int boredom;

};