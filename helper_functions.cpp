#include "helper_functions.h"

void removeWhitespaces(std::string& input)
{
	input.erase(0, input.find_first_not_of(" \t\n\r\f\v"));
	input.erase(input.find_last_not_of(" \t\n\r\f\v") + 1);
}
void coutFile(std::string& file_name) 
{
	removeWhitespaces(file_name);
	std::ifstream File2(file_name);
	if (!File2.is_open()) {
		std::cout << "Failed to open the file: " << file_name << std::endl;
	} else {
		std::string line;
		while ( std::getline(File2, line)) {
			std::cout << line << std::endl;
		}
		File2.close();
	}
}
