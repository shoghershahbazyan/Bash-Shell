#ifndef SHELL_H
#define SHELL_H

#include <iostream>
#include <string>

#include <sstream>
#include <unistd.h>
#include <dirent.h>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <readline/readline.h>
#include <readline/history.h>


class Shell
{
private:
	std::vector<std::string> m_history;
	// Function declarations for command-line operations
	void cd(const std::string&); // Changes the current directory
	void ls(); // Lists files in the current directory
	void pwd(); // Prints the current working directory
	void echo(const std::string&); // Outputs the given string
	void exit(); // Exits the program
	void help(); // Displays help information
	void history();	// Enables users to display previously executed commands
	void upArrow();	// Allows the user to press the up  arrow key to navigate through the command history
	void downArrow(); 	// Allows the user to press the down arrow key to navigate through the command history
	void date();	// Displays the current date
	void overwrite_input(const std::string&);
	//void overwriteIutput();
	//void appentInput();
	//void appendIutpoot();
	void processInput(std::string&);	// Processes the input
	void cat(const std::string&);	//	Enebles the user to view the file
public:
	// Public method to execute the command-line interface
	void run(); // Runs the command-line interface};

};

#endif // SHELL_H
