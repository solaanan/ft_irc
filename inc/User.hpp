/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   User.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:19:28 by ebelfkih          #+#    #+#             */
/*   Updated: 2024/04/07 22:28:22 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class User
{
private:
    std::string _nickName;
    std::string _IP;
public:
    User();
    User(User &obj);
    User& operator=(User &obj);
    ~User();

    std::string GetNickName() const;
    std::string GetIP() const;
};
