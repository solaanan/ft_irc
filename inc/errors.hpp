/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:16:57 by ebelfkih          #+#    #+#             */
/*   Updated: 2024/04/07 20:16:58 by ebelfkih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <sstream>

#define			FILE_OPEN_ERROR							1
#define			MEMORY_ALLOCATION_ERROR					2
#define			INVALID_ARGUMENT_ERROR					3

std::string		getErrorString(int errorCode);
void			printErrorAndExit(int errorCode);


#endif // ERRORS_HPP