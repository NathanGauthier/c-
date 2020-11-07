

#include <iostream>
#include "tamagochi.h"
#include <string>

	using std::string;

	
	

int main(int argc, char* argv)
{
	Tamagochi bobby;
	string action;
	bool quit = false;
	
	

	while (!quit)
	{
		bobby.passTime();

		std::cout << " what you wanna do ? Play ? Talk ? Eat ? Stat ? " << std::endl;
		std::cin >> action;

		if (action == "play")
		{
			bobby.play();
		}

		if (action == "eat")
		{
			bobby.eat();
		}

		if (action == "talk")
		{
			bobby.talk();
		}

		if (action == "stat")
		{

			bobby.stats();
			
		}

		

	}


	
	
	
	
	
	
	
	
	
	

	
	
	

	
	return 0;
} 




























/*#include "tamagochi.h"
#include <iostream>
#include <chrono>
#include <thread>
	using namespace std::chrono;
	using namespace std::this_thread;

	
	
	int T(int n)
	{
		n -= 1;
		std::cout << n << std::endl;
		sleep_for(seconds(3));
	}

int main(int argc, char* argv)
{


	int nomb = 500000;
	while (nomb > 0)
	
	{
		nomb -= 1;
		std::cout << nomb << std::endl;
		sleep_for(seconds(3));
	}
	
	
		

	
	
	

	
	return 0;
} 
*/


