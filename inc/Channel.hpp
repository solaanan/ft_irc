/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:16:50 by ebelfkih          #+#    #+#             */
/*   Updated: 2024/04/14 06:33:02 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHANNEL_HPP
#define CHANNEL_HPP
#include <iostream>
#include <map>
#include "Client.hpp"
class Client;

class Channel
{
private:
    int _userLimit;
    std::string _channelName;
    std::map<int, Client> _clients;
    std::map<int, Client> _operators;
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
    void removeClient(int fdClient);
};

#endif