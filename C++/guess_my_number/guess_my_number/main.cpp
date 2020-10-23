#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


int main()
{
	srand(time(NULL));
	int numberToFind = rand() % 100 + 1;
	int askingNumber = 0;
	int guesses = 1;




	cout << " guess the number" << endl;
	cin >> askingNumber;
	
	


	
	
		while (askingNumber != numberToFind)
		{

			if (askingNumber <= 100 && askingNumber >= 1)
			{

				if (askingNumber > numberToFind)
				{
					cout << "minus" << endl;
					guesses += 1;
					cin >> askingNumber;
				}

				if (askingNumber < numberToFind)
				{
					cout << "plus" << endl;
					guesses += 1;
					cin >> askingNumber;
				}
			}
			
			else
			{
				cout << " guess the number" << endl;
				cin >> askingNumber;
			}
	
		
	
		}


		
		
	

	

	cout << "yes it's that" << endl;
	cout << guesses << " attempts" << endl;
}