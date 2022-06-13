// *** File IO Google Home ***
//Code By Kelley Kramer
//CSC275

//include libraries
#include <iostream>
//allows for i/o to files
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

//first write to a file
//prototype functions
void WriteLineToFile(std::string lineOfText);
std::string ReadLineFromFile(std::string searchWord);

//make start method
int main()
{
	//Dialog to display to user
	std::cout << "\n\n\t\t*** Section 31 Files ***\n\n";
	//todo: put intro for user

	//declare variables
	std::string fileData;
	bool isUserDone = false;
	int userChoice;
	std::string userDoneData;
	std::string searchWord;
		
	//ask what the user would like to do
	std::cout << "What would you like to do?\n";
	std::cout << "\t1) Enter data to save to archive.\n";
	std::cout << "\t2) Retreve Data\n";
	//ask for user response
	std::cout << "Action: ";
	//get user answer
	std::cin >> userChoice;

	if (userChoice == 1)
	{
		do
		{
			//ask user for data
			std::cout << "Please input the information you would like to save: \n";
			//get data from user
			std::cin >> fileData;
			//write data to file
			WriteLineToFile(fileData);

			//determin if user is done entering data
			//ask if they want to enter more
			std::cout << "Is ther any other information you wish to save? (y/n)\n";
			//get answer
			std::cin >> userDoneData;

			//determin is answer is true or false
			if (userDoneData == "y" || userDoneData == "Y")
			{
				isUserDone = false;
			}
			else
			{
				isUserDone = true;
			}
		} while (isUserDone == false);

		//exit message
		std::cout << "\n\n\tThank you, Your file data is now saved!\t\n\n";
	}
	else if (userChoice == 2)
	{
		ifstream ifs("memory.txt");
		cout << ifs.rdbuf() << endl;
	}
	
		
	system ("pause");
	return 0;
}

void WriteLineToFile(std::string lineOfText)
{
	//Make a file object to use as a file handel
	std::ofstream myFile;
	//todo: check if the file exsits before I try to open it
	//todo: check if the file is already open

	//open file
	myFile.open("memory.txt", std::ios_base::app);

	//write one line of text to the file
	myFile << lineOfText << std::endl;

	//Write to display line of text that was writen to file
	std::cout << lineOfText << " -has been written to the memory.txt\n";

	//Close the file
	myFile.close();

}

std::string ReadLineFromFile(std::string searchWord)
{
	int offset;
	std::string line1;
	std::ifstream Myfile;
	Myfile.open("memory.txt");

	if (Myfile.is_open())
	{
		while (!Myfile.eof())
		{
			getline(Myfile, line1);
			if ((offset = line1.find(searchWord)) != std::string::npos)
			{
				return line1;
			}
		}
		Myfile.close();
	}
	else
		std::cout << "couldn't open...." << std::endl;

	//set up a loop to read each line
	//line by line from the file
	//and inside the loop check each line 
	//and see if it contains the seach word
	//if the current line contains the se3ach word
	//return that line to screen
	//if didnt find anything return erro message
	
	//Make a file object to use as a file handel
	//std::ofstream myFile;

	//open file
	//myFile.open("memory.txt", std::ios_base::app);

}