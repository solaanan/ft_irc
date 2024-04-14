/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Message.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:46:53 by ebelfkih          #+#    #+#             */
/*   Updated: 2024/04/14 06:46:54 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_HPP
#define MESSAGE_HPP
#include <iostream>

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
    std::string getBuffer()const;
};

#endif
