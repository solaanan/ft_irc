/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:18:23 by ebelfkih          #+#    #+#             */
/*   Updated: 2024/04/13 20:56:13 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IRC.hpp"


class Client
{
private:
    std::string _userName;
    std::string _nickName;
    std::string _IP;
    Channel _currentChannel;
    std::vector<Channel> _channels;
    bool _authenticate;
    int _clientFdSocket;
    Message _msg;
public:
    Client();
    Client(Client& obj);
    Client& operator=(Client& obj);
    ~Client();

    Client(int clientFdSocket, bool authenticate);
    std::string getNickName() const;
    std::string getUserName() const;
    std::string getIP() const;
    int getFd()const;
    Channel getCurrentChannel()const;
    void disconnect();
    void setMessage(Message msg);
    
    // bool leaveChannel(std::string ChannelName);
    // void sendMessage(std::string Message, Channel ChannelMessage) const;
    // void sendMessage(std::string Message, std::string Recipient) const;
    // void handleCommand(std::string Command); // ??
};
