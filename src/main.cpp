#include "IRC.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 3)
	{
		printUsage();
		printErrorAndExit(INVALID_ARGUMENT_ERROR);
	}
	else
	{
		printHeader();
		std::cout << std::endl;
		std::cout << ES_GREEN << "Welcome to ft_irc!" << ES_RESET << std::endl;
		std::cout << "We are currently under development.." << std::endl;
		std::cout << std::endl;
		std::cout << "Port:     " << argv[1] << std::endl;
		std::cout << "Password: " << argv[2] << std::endl;
	}

	return 0;
}