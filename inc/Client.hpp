/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:18:23 by ebelfkih          #+#    #+#             */
/*   Updated: 2024/04/14 09:28:58 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
#define CLIENT_HPP
#include <iostream>
#include <vector>
#include "Message.hpp"
#include "Channel.hpp"
class Channel;



class Client
{
private:
    std::string _currentChannel;
    std::string _userName;
    std::string _nickName;
    std::string _IP;
    std::vector<Channel> _channels;
    bool _authenticate;
    int _clientFdSocket;
    Message _msg;
public:
    Client();
    Client(const Client& obj);
    Client& operator=(const Client& obj);
    ~Client();

    Client(int clientFdSocket, bool authenticate);
    std::string getNickName() const;
    std::string getUserName() const;
    std::string getIP() const;
    int getFd()const;
    std::string getCurrentChannel()const;
    void disconnect();
    void setMessage(Message msg);
    Message getMessage() const;
    void setFD(int fd);
    // bool leaveChannel(std::string ChannelName);
    // void sendMessage(std::string Message, Channel ChannelMessage) const;
    // void sendMessage(std::string Message, std::string Recipient) const;
    // void handleCommand(std::string Command); // ??
};

#endif
