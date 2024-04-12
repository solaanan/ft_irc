/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:18:23 by ebelfkih          #+#    #+#             */
/*   Updated: 2024/04/12 23:37:52 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <map>
#include <netinet/in.h>
#include "Channel.hpp"

class Client
{
private:
    std::string _userName;
    std::string _nickName;
    std::string _IP;
    std::map<std::string, Channel> _channels;
    bool _authenticate; // false
    struct sockaddr_in _clientAddr;
    int _clientFdSocket;
public:
    Client();
    Client(Client& obj);
    Client& operator=(Client& obj);
    ~Client();

    Client(int clientFdSocket, bool authenticate);
    std::string getNickName();
    std::string getIP() const;
    bool joinChannel(std::string ChannelName, std::string PassWord);
    bool leaveChannel(std::string ChannelName);
    void sendMessage(std::string Message, Channel ChannelMessage) const;
    void sendMessage(std::string Message, std::string Recipient) const;
    void handleCommand(std::string Command); // ??
    void disconnect();
};
