#include "Learning.h"
#include "manager folder/File_manager.h"



void layout(std::vector<text>& to_do) {
	text input;
	bool running = true;

	//Running
	while (running)
	{
		//Check perfect
		DisplayText(input);

		if (input == "n" || input == "new")
		{
			CreatingList(to_do);
		}
		else if (input == "s" || input == "see")
		{
			DisplayList(to_do);
		}
		else if (input == "e" || input == "exit")
		{
			std::cout << "\n \n" << "Exiting the program. " << "\n \n";
			running = false;
		}
		else
		{
			std::cout << "\n \n" << "Please give valid input. \n \n";
			DisplayText(input);
		}
	}
}

void DeleteElement(std::vector<text>& list) {
	int elementPos;
	text input;
	std::cout << "Please type \"erase\" to start element removal or continue by entering nothing";
	do
	{
		std::getline(std::cin, input);
	} while (input.empty());
	if (input == "erase")
	{
		std::cout << "Please enter The position of the element";
		std::cin >> elementPos;
		--elementPos;
		if (elementPos <= list.size() && !list.empty() && elementPos >= 0) {
			text* temp_array = nullptr;
			if (list.size() - 1 > 0)
			{
				temp_array = new text[list.size() - 1];
				list[elementPos].erase();
			}
			else
			{
				list.clear();
			}
			std::cout << "Erase Successful \n";
			delete[] temp_array;
			temp_array = nullptr;
		}
	}
	input = "";
}

void DisplayText(text& character) {
	std::cout << "\n \n" << "Write 'n' or 'new' for create a new to do list." << "\n \n" << "Write 's' or 'see' to see existing to do list. \n \n";
	std::cout << "Write 'e' or 'exit' to exit the program." << "\n \n" << std::flush;
	std::cin >> character;
}

void DisplayList(std::vector<text>& list) {
	int all_empty = 0; // Stores the empty value that were encountered during iteration
	int temp = 0; //temporary variable to hold the value of 'i' and increment it later 
	std::cout << std::flush;

	if (list.empty())
	{
		std::cout << "\n \n" << "PLease first enter a to do list" << "\n \n";
	}
	else
	{
		int encountered_i = 0;
		for (int i = 0; i < list.size(); i++)
		{
			if (!list[i].empty() && list[i] != "")
			{
				temp = i - encountered_i + 1;              //store the value of 'i' in temp
				std::cout << "\n \n" << temp << ". " << list[i] << std::endl;
			}
			else                           //Hey, the list was empty at this movement
			{
				++all_empty; //increment all_empty
				encountered_i++;      // And iterator was iterated/added 1 so you know what to do.
				continue;
			}
		}
		if (all_empty == list.size())
		{
			list.clear();
		}
		DeleteElement(list);
	}
}

void CreatingList(std::vector<text>& list) {
	//Logical error: added input does not give me any output back
	//Error resolved: I was stupid, I was adding input to place where we have output, i.e., nowhere.
	text input;
	std::cout << std::flush;

	std::cout << "Enter your list\n \n";
	do
	{
		std::getline(std::cin, input);
	} while (input.empty());
	list.push_back(input);
}