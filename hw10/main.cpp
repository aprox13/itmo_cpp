#include<iostream>
#include<cstring>
#include<vector>
#include<string>
#include"Program.h"


int main(int argc, char *argv[])
{
	std::vector<std::pair<std::string, std::string>> arguments;
	if (argc == 2) {
		if (strcmp(argv[1], "-help") == 0) {
			Program::help();
			return 0;
		}
	}
	for (int i = 1; i < argc; i++) {
		auto argumentName = std::string(argv[i]);
		i++;
		if (i == argc) {
			std::cerr << "Wrong arguments count" << std::endl;
			return 0;
		}
		auto argumentValue = std::string(argv[i]);
		arguments.emplace_back(argumentName, argumentValue);
	}
	Program program(arguments);
	//system("pause");

	auto result = program.getResult();
	std::cout << "Result size: " << result.size() << std::endl;
	for (size_t i = 0; i < result.size(); i++) {
		std::cout << "Path #" << i+1 << std::endl;
		/*for (size_t j = 0; j < result[i].size(); j++) {
			std::cout << "( " << result[i][j].first << ", " << result[i][j].second << " ) ";
		}*/
		std::cout << result[i];
		std::cout << std::endl;
	}
	return 0;
}