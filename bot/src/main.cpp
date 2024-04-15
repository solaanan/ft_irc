/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:34:59 by slaanani          #+#    #+#             */
/*   Updated: 2024/04/11 00:27:28 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bot.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	std::cout << "Hello I am HamraDroid!" << std::endl;

	if (argc != 3)
	{
		std::cout << "Usage: ./hamradoid <host> <port>" << std::endl;
		exit(1);
	}

	std::string host = argv[1];
	std::string port = argv[2];

	Bot bot = Bot(host, stoi(port));

	return 0;
}
