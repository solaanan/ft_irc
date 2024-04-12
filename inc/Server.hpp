/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:19:10 by ebelfkih          #+#    #+#             */
/*   Updated: 2024/04/12 23:38:39 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <map>
#include <cstring>
#include <cstdlib>
#include "Client.hpp"
#include "Channel.hpp"
#include <cstdio>
#include <vector>
#include <cerrno>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <poll.h>


class Server
{
private:
    uint16_t _port;
    std::string _passWord;
    std::vector<pollfd> _fds;
    std::map<int, Client> _clients;
    std::map<std::string, Channel> _channels;
    
public:
    Server();
    Server& operator=(Server& obj);
    Server(Server& obj);
    ~Server();

    Server(std::string port, std::string password);
    void startServer();
    bool authenticateUser() const;

    void handleClientconnection(); // ??
    Channel createChannel(std::string channelName);
};

