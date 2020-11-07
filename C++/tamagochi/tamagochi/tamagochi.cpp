#include <iostream>
#include "tamagochi.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;


Tamagochi::Tamagochi(int pHunger, int pBoredom) : hunger(pHunger), boredom(pBoredom)
{
	

}

Tamagochi::Tamagochi()
{
	hunger = 50;
	boredom = 50;
}

Tamagochi::~Tamagochi()
{

}

void Tamagochi::talk() const
{
	cout << "jsuis a la zone sans casque sur un scooter kite" << endl;

}

void Tamagochi::play()
{
	cout << "hihihahahihaihaihhahhiahiahiha" << endl;
	boredom -= 10;
	if(boredom < 0)
	{
		boredom = 0;
	}
}

void Tamagochi::eat()
{
	cout << "MMMMmiiam" << endl;
	hunger -= 10;
	if(hunger < 0)
	{
		hunger = 0;
	}
}

int Tamagochi::getHunger()
{
	return hunger;
}

int Tamagochi::getBoredom()
{
	return boredom;
}

void Tamagochi::stats()
{
	cout << "Hunger : " << getHunger() << endl;
	cout << "Boredom : "<<  getBoredom() << endl;

}


void Tamagochi::passTime()
{	sleep_for(seconds(1));
	hunger += 5;
	boredom += 5;
	
	if (hunger > 100)
	{
		hunger = 100;
	}
	if (boredom > 100)
	{
		boredom = 100;
	}
	std::cout << "\n \t Hunger : " << hunger << std::endl;
	std::cout << "\n  \t Boredom :  " << boredom << std::endl;
	
}