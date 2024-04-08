/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:19:10 by ebelfkih          #+#    #+#             */
/*   Updated: 2024/04/07 23:05:41 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <map>
class Client;
class Channel;

class Server
{
private:
    bool _On; // false
    int _Port;
    std::map<std::string, Client> _Client;
    std::map<std::string, Channel> _Channel;
    
public:
    Server();
    Server& operator=(Server& obj);
    Server(Server& obj);
    ~Server();

    void startServer();
    void broadcastMessage(std::string message) const;
    void handleClientconnection(); // ??
    bool authenticateUser() const;
    Channel createChannel(std::string channelName);
};

