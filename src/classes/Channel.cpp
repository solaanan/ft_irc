/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:17:09 by ebelfkih          #+#    #+#             */
/*   Updated: 2024/04/11 01:09:31 by ebelfkih         ###   ########.fr       */
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
        this->_channelName = obj._channelName;
        this->_client = obj._client;
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
    this->_client.clear();
}

/////////////////////////////////////////////////////////////////////////////////

bool Channel::isMember(Client client)
{
    std::map<std::string, Client>::iterator it;
    if (this->_client.find(client.getNickName()) != this->_client.end())
        return true;
    return false;
    
}

bool Channel::isModerator(Client client)
{
    
    
}

void Channel::brodcastMessage(std::string message, Client sender)
{
    
    
}

std::string Channel::getTopic()
{
    
    
}

bool Channel::canJoin(Client client)
{
    
    
}
