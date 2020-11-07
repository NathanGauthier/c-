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
	int getHunger();
	int getBoredom();
	void stats();
	void passTime();
	


private:
	int hunger;
	int boredom;

};