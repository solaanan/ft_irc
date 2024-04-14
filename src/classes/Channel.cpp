/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:17:09 by ebelfkih          #+#    #+#             */
/*   Updated: 2024/04/14 06:38:57 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Channel.hpp"

Channel::Channel()
{
    this->_channelName = "";
    this->_passWord = "";
    this->_topic = "";
}

Channel& Channel::operator=(const Channel& obj)
{
    if (this != &obj)
    {
        this->_operators = obj._operators;
        this->_channelName = obj._channelName;
        this->_clients = obj._clients;
        this->_passWord = obj._passWord;
        this->_topic = obj._topic;
    }
    return *this;
}

Channel::Channel(const Channel& obj)
{
    *this = obj;
}

Channel::~Channel()
{
    this->_clients.clear();
}

/////////////////////////////////////////////////////////////////////////////////

bool Channel::isMember(Client client)
{
    std::map<int, Client>::iterator it;
    if (this->_clients.find(client.getFd()) != this->_clients.end())
        return true;
    return false;
    
}

bool Channel::isModerator(Client client)
{
    if (this->_operators.find(client.getFd()) != this->_operators.end())
        return true;
    return false;
    
}

void Channel::brodcastMessage(std::string message, Client sender)
{
    (void)message;
    (void)sender;
    
}

std::string Channel::getTopic()
{
    return this->_topic;
}

bool Channel::canJoin(Client client)
{
    (void)client;
    return false; // for now
    
}

void Channel::removeClient(int fdClient)
{
    if (this->_clients.find(fdClient) != this->_clients.end())
        this->_clients.erase(fdClient);
}
