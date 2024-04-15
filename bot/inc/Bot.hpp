/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bot.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:30:42 by slaanani          #+#    #+#             */
/*   Updated: 2024/04/15 10:45:38 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOT_HPP
#define BOT_HPP

#include <iostream>
#include <cstring>
#include <vector>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <ctime>
#include <fcntl.h>
#include <poll.h>
#include <cstdlib>

class Bot {
	private:
		int				sockfd_;
		std::string		server_;
		int port_;
		const char*		password_;
		const char*		nickname_ ;

		int				create_socket(std::string server, int port);
		void			close_socket();

	public:
		Bot(std::string server, int port);
		~Bot();

		bool			connect_bot();
		void			send_data(std::string message);
		std::string		receive_data();
		void			handle_message(const std::string& message);
		void			roll_dice(const std::string& args);
		void			coinflip();
		void			time();
		int 			getSockFd();
		int 			getServer();
};


#endif // BOT_HPP