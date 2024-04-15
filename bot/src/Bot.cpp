/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bot.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:31:31 by slaanani          #+#    #+#             */
/*   Updated: 2024/04/11 00:47:45 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bot.hpp"

Bot::Bot(std::string server, int port) : server_(server), port_(port) {
	nickname_ = "HamraDroid";
}

int Bot::create_socket(std::string hostname, int port)
{
	struct sockaddr_in serverAddr;
	struct hostent *server;

	server = gethostbyname(hostname.c_str());
	if (server == NULL)
	{
		std::cout << "Error: Cannot resolve host." << std::endl;
		return -1;
	}

	sockfd_ = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd_ == -1)
	{
		std::cout << "Error: Cannot create socket." << std::endl;
		return -1;
	}

	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	memcpy(&serverAddr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
	serverAddr.sin_port = htons(port);

	if (connect(sockfd_, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
	{
		std::cout << "Error: Cannot connect to server socket." << std::endl;
		close(sockfd_);
		return -1;
	}

	int flags = fcntl(sockfd_, F_GETFL, 0);
	fcntl(sockfd_, F_SETFL, flags | O_NONBLOCK);

	return sockfd_;
}

void Bot::close_socket()
{
	close(sockfd_);
}

bool Bot::connect_bot() {
	int fd = create_socket(server_, port_);
	return fd > 0;
}

int Bot::getSockFd() {
	return sockfd_;
}

Bot::~Bot() {
	close_socket();
}