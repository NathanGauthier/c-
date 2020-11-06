

#include "tamagochi.h"
#include <iostream>
#include <chrono>
#include <thread>
	using namespace std::chrono;
	using namespace std::this_thread;

	
	void passTime(int Ahunger, int Aboredom)
	{
		Ahunger += 5;
		Aboredom += 5;
		std::cout << Ahunger << std::endl;
		std::cout << Aboredom << std::endl;
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


