/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:46:53 by ebelfkih          #+#    #+#             */
/*   Updated: 2024/04/13 20:56:21 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IRC.hpp"

class Message
{
private:
    std::string _buffer;
    int _fdsender;
public:
    Message();
    Message& operator=(const Message& obj);
    Message(const Message& obj);
    ~Message();

    Message(std::string buffer, int sender);
    Message& operator+(const std::string& str);
};


