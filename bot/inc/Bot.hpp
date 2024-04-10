/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bot.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:30:42 by slaanani          #+#    #+#             */
/*   Updated: 2024/04/08 23:31:24 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOT_HPP
#define BOT_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <ctime>

class Bot {
	private:
		int sockfd_;
		const char* server_;
		int port_;
		const char* password_;
		const char* username_;
		const char* nickname_;
		int create_socket(const char* hostname, int port);
		void close_socket();

	public:
		Bot(const char* server, int port, const char* password,
					const char* username, const char* nickname) :
			server_(server), port_(port), password_(password),
			username_(username), nickname_(nickname) {}
		bool connect_bot();
		void send_data(const char* message);
		std::string receive_data();
		void handle_message(const std::string& message);
		void roll_dice(const std::string& args);
		void coinflip();
		void time(); // Display current server time
};


#endif // BOT_HPP