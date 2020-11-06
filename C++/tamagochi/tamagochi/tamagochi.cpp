#include <iostream>
#include "tamagochi.h"
using namespace std;


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
	cout << "jsuis a la zone sans casque sur un scooter kité" << endl;

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