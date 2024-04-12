/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:16:50 by ebelfkih          #+#    #+#             */
/*   Updated: 2024/04/11 00:43:13 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <map>
#include "Client.hpp"



class Channel
{
private:
    int _userLimit;
    std::string _channelName;
    std::map<std::string,  Client> _client;
    // list Moderator ??
    std::string _passWord;
    std::string _topic;
    std::string _mode;
    
public:
    Channel();
    Channel& operator=(const Channel& obj);
    Channel(const Channel& obj);
    ~Channel();

    bool isMember(Client client);
    bool isModerator(Client client);
    void brodcastMessage(std::string message, Client sender);
    std::string getTopic();
    bool canJoin(Client client);
};

