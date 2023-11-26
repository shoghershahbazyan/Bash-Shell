#ifndef SHELL_H
#define SHELL_H

#include <iostream>
#include <string>
#include <unistd.h>
#include <dirent.h>
#include <vector>
#include <string>


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
public:
	// Public method to execute the command-line interface
	void run(); // Runs the command-line interface};
	void upArrow();	// Allows the user to press the up  arrow key to navigate through the command history

	void downArrow(); 	// Allows the user to press the down arrow key to navigate through the command history


};

#endif // SHELL_H
