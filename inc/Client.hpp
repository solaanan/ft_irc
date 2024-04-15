/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:18:23 by ebelfkih          #+#    #+#             */
/*   Updated: 2024/04/07 23:05:21 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <map>
#include "User.hpp"
#include "Channel.hpp"

class Client : public User
{
private:
    std::map<std::string, Channel> _Channels;
    bool _Online; // false
public:
    Client();
    Client(Client& obj);
    Client& operator=(Client& obj);
    ~Client();

    bool JoinChannel(std::string ChannelName, std::string PassWord);
    bool LeaveChannel(std::string ChannelName);
    void SendMessage(std::string Message, Channel ChannelMessage) const;
    void SendMessage(std::string Message, std::string Recipient) const;
    void HandleCommand(std::string Command); // ??
    void Disconnect();
};
