#include <iostream>

int main(int argc, char** argv)
{
	/*char initial = 'N';
	char name[] = "Gauthier";
	int age = 18;
	int height = 168;

	std::cout << " Hello, I am " << initial << " " << name << "." << std::endl;
	std::cout << " I am " << age  << " Years old "  << std::endl;
	std::cout << " I am " << height << " cm tall " << std::endl;
	std::cout << sizeof(age) << std::endl;
	return 0;*/

	int* scorePointer = nullptr;
	int score = 1000;
	scorePointer = &score;
	//std::cout << *scorePointer << std::endl;



	std::cout << &score << std::endl;
	std::cout << scorePointer << std::endl;
	std::cout << score << std::endl;
	std::cout << *scorePointer << std::endl;

	score += 500;

	std::cout << score << std::endl;
	std::cout << *scorePointer << std::endl;

	*scorePointer += 500;

	std::cout << score << std::endl;
	std::cout << *scorePointer << std::endl;


	int newScore = 5000;
	scorePointer = &newScore;

	std::cout << &score << std::endl;
	std::cout << &newScore << std::endl;
	std::cout << scorePointer << std::endl;
	std::cout << score << std::endl;
	std::cout << newScore << std::endl;
	std::cout << *scorePointer << std::endl;





}