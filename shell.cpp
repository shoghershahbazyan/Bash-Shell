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
void Shell::run()
{
	std::string input;
	while (true) {
        // Displaying a prompt
        std::cout << "MyShell> ";
        
        // Reading user input
        std::getline(std::cin, input);

        // Process the user input
        if (input == "exit") {
		exit();
		break;
        } else if (input == "help") {
		help();
        } else if (input == "pwd") {
		pwd();
	} else if (input.substr(0, 3) == "cd ") {
		cd(input);
	} else if (input == "ls") {
        	ls(); 
	} else if (input.substr(0, 5) == "echo ") {
        	echo(input);
        } else {
            std::cout << "Command not found. Type 'help' for available commands." << std::endl;
        }
    }
}

void Shell::cd(const std::string& input)
{
	std::string path = input.substr(3);
	if (chdir(path.c_str()) != 0) {
		std::cerr << "Failed to change directory." << std::endl;
	}
}

void Shell::ls()
{
	DIR *dir;	// DIR is a type defined in the dirent.h header that represents a directory stream
	struct dirent *ent;	// struct dirent is used to hold information about directory entries
	if ((dir = opendir(".")) != nullptr) {	// Attempt to open the current directory
		while ((ent = readdir(dir)) != nullptr) {	// Loop through directory entries.
	// readdir(dir) reads the next directory entry within the directory stream specified by dir
	// For each valid directory entry, the pointer to struct dirent (ent) is updated with the information of the entry.
			std::cout << ent->d_name << std::endl;	// Access the name of the current directory entry
		}	// The loop continues until readdir returns nullptr, indicating the end of directory
		closedir(dir);	// closedir() function is called to close the directory stream specified by dir
	} else {	// an error message is printed if there was an error opening the directory
		std::cerr << "Error opening directory." << std::endl;
	}
}

void Shell::pwd()
{
	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != nullptr) {
		std::cout << "Current directory: " << cwd << std::endl;
	} else {
		std::cerr << "Unable to get current directory." << std::endl;
	}
}

void Shell::echo(const std::string& input)
{
	std::cout << input.substr(5) << std::endl;
}

void Shell::exit()
{
	std::cout << "Exiting the shell." << std::endl;
}
void Shell::help() 
{
    std::cout << "Supported commands:\n"
                 "cd: Change the current working directory.\n"
                 "ls: List all the file and directory names in the current directory.\n"
                 "pwd: Present Current Directory.\n"
                 "echo: Display text or variable values on the screen.\n"
                 "exit: Terminate the shell.\n"
                 "help: Provide information about available commands.\n";
}

#endif	// SHELL_H
