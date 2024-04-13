/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:17:14 by ebelfkih          #+#    #+#             */
/*   Updated: 2024/04/13 20:32:28 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Client.hpp"

Client::Client()
{
    this->_userName = "";
    this->_nickName = "";
    this->_IP = "";
    this->_authenticate = false;
    this->_clientFdSocket = -1;
}

Client::Client(Client& obj)
{
    *this = obj;
}

Client& Client::operator=(Client& obj)
{
    if (this != &obj)
    {
        this->_userName = obj._userName;
        this->_nickName = obj._nickName;
        this->_IP = obj._IP;
        this->_currentChannel = obj._currentChannel;
        this->_channels = obj._channels;
        this->_authenticate = obj._authenticate;
        this->_clientFdSocket = obj._clientFdSocket;
        this->_msg = obj._msg;
    }
    return *this;
}

Client::~Client()
{
    this->_userName.clear();
    this->_nickName.clear();
    this->_IP.clear();
    this->_channels.clear();
}



/////////////////////////////////////////////////////////////////



Client::Client(int clientFdSocket, bool authenticate) : _clientFdSocket(clientFdSocket), _authenticate(authenticate)
{
}

std::string Client::getNickName() const
{
    return this->_nickName;
}

std::string Client::getUserName() const
{
    return this->_userName;
    
}

std::string Client::getIP() const
{
    return this->_IP;
    
}

int Client::getFd()const
{
    return this->_clientFdSocket;
    
}

Channel Client::getCurrentChannel()const
{
    return this->_currentChannel;
}


void Client::disconnect()
{
    
    if (this->_authenticate)
    {
        for (std::vector<Channel>::iterator it = this->_channels.begin(); it < this->_channels.end(); it++)
            (*it).removeClient(this->_clientFdSocket);        
    }
    this->~Client();
}

void Client::setMessage(Message msg)
{
    this->_msg = msg;
}