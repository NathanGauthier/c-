#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <string>


using std::array;
using std::string;



	




int main(int argc, char** argv)
{
	
	
	
	

	string guessWord; 
	const int MAX_WORDS = 5;
	array<array<char, 5> ,MAX_WORDS> words{{
	

		{'f','a','n','t','a'},
		{'a','p','p','l','e'},
		{'o','r','a','n','g',},
		{'o','a','s','i','s'},
		{'w','a','t','e','r'},

	} };

	array<string, 5> Words{ "fanta", "apple", "orang", "oasis", "water" };

	std::cout << "\t this is a jumble word \nfind the word among these : fanta, apple, orang, oasis and water \n";

	
	

	
	
	srand(time(NULL));
	int randomNum = rand() % MAX_WORDS;
	int wordLength = words[randomNum].size();
	string theWord = Words[randomNum];





	for (int i = 0; i < wordLength; i++)
	{
		int letter1 = rand() % wordLength; //Index
		int letter2 = rand() % wordLength; //Index
		char tempLetter;

		tempLetter = words[randomNum][letter1];
		words[randomNum][letter1] = words[randomNum][letter2];
		words[randomNum][letter2] = tempLetter;

	}
	string jumbledWord(begin(words[randomNum]), end(words[randomNum]));
	std::cout << "\n" << "\t" << jumbledWord << std::endl;

	std::cout << "guess the word" << std::endl;
	std::cin >> guessWord;



	


	

	





	while(guessWord != theWord)
	{
		if(guessWord == "quit")
		{
			std::cout << "okay, you want to leave" << std::endl;
			break;
			
		}
		std::cout << " no it's not, try again !" << std::endl;
		std::cout << "guess the word" << std::endl;
		std::cin >> guessWord;
	
		

	
	}
	
	if (guessWord == theWord )
	{
		std::cout << "yes you did it, nice!!!" << std::endl;
	}

	std::cout << " thank you for the game \n \n \n";

	return 0;
}