/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:17:33 by ebelfkih          #+#    #+#             */
/*   Updated: 2024/04/12 23:49:47 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Server.hpp"

Server::Server()
{
    this->_passWord = "";
    this->_port = -1;
}

Server& Server::operator=(Server& obj)
{
    
}

Server::Server(Server& obj)
{
    
}

Server::~Server()
{
    
}
 
///////////////////////////////////////////////////////////////////////////////////

Server::Server(std::string port, std::string password) : _passWord(password)
{
    int p;
    char *end;
    int fdSocket;
    struct sockaddr_in serverAddr;


    p = strtod(port.c_str(), &end);
    if (port.find('.') || !strcmp("", end) || p < 1024 || p > 49151)
    {
        std::cerr << "ERROR: bad input" << std::endl;
        exit(EXIT_FAILURE);
    }
    this->_port = htons(p);
    
}

void Server::startServer()
{
    int fdSocket;
    struct sockaddr_in serverAddr;

    fdSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (fdSocket < 0)
    {
        std::cerr << "Error: creating socket: " << std::endl;
        exit(EXIT_FAILURE);
    }
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = this->_port;
    serverAddr.sin_family = AF_INET;
    if (bind(fdSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
    {
        std::cerr << "Error binding socket: " << strerror(errno) << std::endl;
        close(fdSocket);
        exit(EXIT_FAILURE);
    }
    
    if (listen(fdSocket, SOMAXCONN) < 0)
    {

        std::cerr << "listen() failed" << std::endl;
        close(fdSocket);
        exit(EXIT_FAILURE);
    }
    pollfd tmp;
    tmp.fd = fdSocket;
    tmp.events = POLLIN;
    this->_fds.push_back(tmp);
}

void Server::handleClientconnection()
{
    while (true)
    {
        int NReady = poll(&(this->_fds[0]), this->_fds.size(), -1);
        if (NReady < 0){
            std::cerr << "poll() failed" << std::endl;
            exit(EXIT_FAILURE);
        }
        // Check for new connections
        if (this->_fds[0].revents & POLLIN){
            int clientFdSocket = accept(this->_fds[0].fd, NULL, NULL);
            if (clientFdSocket < 0)
            std::cerr << "accept() failed" << std::endl;
            else {
                std::cout << "New client connected" << std::endl;
                pollfd tmp;
                tmp.fd = clientFdSocket;
                tmp.events = POLLIN;
                this->_fds.push_back(tmp);
                Client tmp(clientFdSocket, false);
                this->_clients[clientFdSocket] = tmp; // ?
            }
        }
        
        // Check for data on client sockets
        for (size_t i = 1; i < this->_fds.size(); i++){
            
        }
    }
}

bool Server::authenticateUser() const
{
    
}

Channel Server::createChannel(std::string channelName)
{
    
}
