#ifndef SHELL_H
#define SHELL_H

#include <iostream>
#include <string>
#include <unistd.h>
#include <dirent.h>


class Shell
{
private:
	// Function declarations for command-line operations
	void cd(const std::string&); // Changes the current directory
	void ls(); // Lists files in the current directory
	void pwd(); // Prints the current working directory
	void echo(const std::string&); // Outputs the given string
	void exit(); // Exits the program
	void help(); // Displays help information

public:
	// Public method to execute the command-line interface
	void run(); // Runs the command-line interface};

};

#endif // SHELL_H
