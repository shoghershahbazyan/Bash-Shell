#include "shell.h"

void removeWhitespaces(std::string& input)
{
	input.erase(0, input.find_first_not_of(" \t\n\r\f\v"));
	input.erase(input.find_last_not_of(" \t\n\r\f\v") + 1);
}
void Shell::run()
{
	std::string input;
	while (true) {
		// Displaying a prompt
		std::cout << "MyShell <3 ";
		
		// Reading user input
		std::getline(std::cin, input);
		
		m_history.push_back(input);
		// Process the user input
		if (input == "exit") {
			exit();
			break;
		} else if (inpur.find(">>") {
		


		} else if (input.find('>') != std::string::npos) {
			size_t index = input.find_first_of('>');
			std::string command = input.substr(0, index);
			std::string file_name = input.substr(index + 1);	
			removeWhitespaces(file_name);
			removeWhitespaces(command);		
			if (file_name.empty()) {
				std::cout << "parse error near `\n'" << std::endl;
			} else {
				std::ofstream File(file_name);
				if (!File.is_open()) {
				std::cout << "Failed to open the file: " << file_name << std::endl;
				} else {
					auto cout_buf = std::cout.rdbuf();
					std::cout.rdbuf(File.rdbuf());
					processInput(command);
					std::cout.rdbuf(cout_buf);
				}
				File.close();
			}
	/*	} else if (input.find_first_of('|')) { // pipe
	*/		
		} else {
			removeWhitespaces(input);
			processInput(input);
		}
	}
}

void Shell::cd(const std::string& input)
{
	std::string path = input.substr(3);	// Retraves the name of the directory
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
	char cwd[1024];    // Buffer to store the current working directory
	// Check if the current working directory can be retrieved successfully
	if (getcwd(cwd, sizeof(cwd)) != nullptr) {	// If successful, getcwd() returns a pointer to the buffer
		std::cout << "Current directory: " << cwd << std::endl;
	} else {	// If unsuccessful, getcwd() returns a NULL pointer and sets errno
		std::cerr << "Unable to get current directory." << std::endl;
	}
}

void Shell::echo(const std::string& input)	// Prompts the user input
{
	std::cout << input.substr(5) << std::endl;
}

void Shell::exit()	// Prompts the error message
{
	std::cout << "Exiting the shell." << std::endl;
}
void Shell::help() // Prompts the valid commandes
{
    std::cout << "Supported commands:\n"
                 "cd: Change the current working directory.\n"
                 "ls: List all the file and directory names in the current directory.\n"
                 "pwd: Present Current Directory.\n"
                 "echo: Display text or variable values on the screen.\n"
                 "exit: Terminate the shell.\n"
                 "help: Provide information about available commands.\n";
}

void Shell::history()
{
	for (const auto& command : m_history) {
		std::cout << command << std::endl;
	}
}

void Shell::upArrow()
{

}

void Shell::downArrow()
{

}

void Shell::date()
{
	time_t now = time(0);
	char* current_time = ctime(&now);
	std::cout << current_time ;
}
void overwrite_input(const std::string& input)
{

}

void Shell::processInput(const std::string& input)
{
	if (input == "pwd") {
		pwd();
	} else if (input.substr(0, 3) == "cd ") {
		cd(input);
	} else if (input == "ls") {
        	ls(); 
	} else if (input.substr(0, 5) == "echo ") {
        	echo(input);
	} else if (input == "history") {
		history();
	} else if (input == "date") {
		date();
	} else {
            std::cout << "Command not found. Type 'help' for available commands." << std::endl;
        }
}
