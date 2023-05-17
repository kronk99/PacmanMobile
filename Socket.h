//
// Created by huevitoentorta on 16/05/23.
//

#ifndef PACMANMOBILE_SOCKET_H
#define PACMANMOBILE_SOCKET_H
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include "Player.h"

class Socket {
private:
    Player *player;
public:
    Socket(Player* players);
    void socketServer();
};


#endif //PACMANMOBILE_SOCKET_H
