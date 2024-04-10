/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bot.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaanani <slaanani@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:31:31 by slaanani          #+#    #+#             */
/*   Updated: 2024/04/08 23:34:52 by slaanani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bot.hpp"

int Bot::create_socket(const char *hostname, int port)
{
    struct sockaddr_in serverAddr;
    struct hostent *server;

    server = gethostbyname(hostname);
    if (server == nullptr)
    {
        return -1;
    }

    sockfd_ = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd_ == -1)
    {
        return -1;
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    memcpy(&serverAddr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
    serverAddr.sin_port = htons(port);

    if (connect(sockfd_, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
    {
        close(sockfd_);
        return -1;
    }

    return sockfd_;
}

void Bot::close_socket()
{
    close(sockfd_);
}