/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testserver.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 00:00:28 by slaanani          #+#    #+#             */
/*   Updated: 2024/04/12 21:00:34 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>


int main(void)
{
	int port = 1604;
	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(port);
	serverAddress.sin_addr.s_addr = INADDR_ANY;

	int bindResult = bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
	if (bindResult < 0)
		std::cout << "[ERROR] Bind error." << std::endl;
	std::cout << "[LOG] Server bound to port " << port << std::endl;

	int listenResult = listen(serverSocket, 5);
	if (listenResult < 0)
		std::cout << "[ERROR] Listen error." << std::endl;
	std::cout << "[LOG] Server listening... " << std::endl;

	while (1)
	{
		int clientSocket = accept(serverSocket, NULL, NULL);
		if (clientSocket < 0)
		{
			std::cout << "[ERROR] Accept error." << std::endl;
			continue;
		}

		// Get client IP address (optional)
		sockaddr_in clientAddr;
		socklen_t clientAddrSize = sizeof(clientAddr);
		if (getpeername(clientSocket, (struct sockaddr *)&clientAddr, &clientAddrSize) == 0)
		{
			std::cout << "[LOG] Client connected! (fd: " << clientSocket << ", IP: " << inet_ntoa(clientAddr.sin_addr) << ")" << std::endl;
		}
		else
		{
			std::cout << "[LOG] Client connected! (IP address unavailable)" << std::endl;
		}

		while (1)
		{
			char buffer[1024] = {0};
			int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
			if (bytesReceived <= 0)
			{
				std::cout << "[LOG] uejcbfgrkgfldilbvvfbhgunjClient disconnected (fd: " << clientSocket << ")" << std::endl;
				close(clientSocket);
				break;
			}
			std::cout << "[LOG] Message from client (fd: " << clientSocket << "): " << buffer << std::endl;
		}
	}

	close(serverSocket);

	return 0;
}
