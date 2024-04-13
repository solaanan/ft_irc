/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:19:10 by ebelfkih          #+#    #+#             */
/*   Updated: 2024/04/13 20:55:48 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IRC.hpp"


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
    void handleClientConnection();
    void handleClientMessage(Client client);

    // Channel createChannel(std::string channelName);
};

