// Learning.cpp : Defines the entry point for the application.
//

#include "Functions.h"
#include "Learning.h"

//Function declaration
void layout(std::vector<text>& to_do);
void DeleteElement(std::vector<text>& list);
void DisplayText(text& character);
void DisplayList(std::vector<text>& list);
void CreatingList(std::vector<text>& list);

int main()
{
	text temp_input_store;
	int size = 1;
	std::vector<text> to_do; //later will be replaced by std::vector. New update :- f*k std::vector, I will made my own vector but function. New update part 2: Sorry std::vector
	bool running = true;
	text input;

	std::cout << std::flush;
	layout(to_do);
	return 0;
}