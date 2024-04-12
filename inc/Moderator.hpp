/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Moderator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:18:55 by ebelfkih          #+#    #+#             */
/*   Updated: 2024/04/09 00:08:27 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Client.hpp"

class Moderator : public Client
{
private:
    bool _isModerator; // false
public:
    Moderator();
    Moderator& operator=(Moderator& obj);
    Moderator(Moderator& obj);
    ~Moderator();

    bool kickUser(std::string channelName, std::string nickName);
    bool banUser(std::string channelName, std::string nickName);
    bool inviteUser(std::string channelName, std::string nickName);
    bool changeTopic(std::string channelName, std::string newTopic);
    bool setPassWord(std::string channelName, std::string newPassword);
    bool setInviteOnlyMode(std::string channelName, bool InviteOnlyMode);
};
