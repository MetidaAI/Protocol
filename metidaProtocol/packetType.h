#ifndef PACKETTYPE_H
#define PACKETTYPE_H

enum class packetType {
    //UNIVERSAL
    PING_PONG,

    //SERVER
    HANDSHAKE,
    LEARNING_REQUEST,
    LEARNING_DATA,
    DATA_SERVER,

    //CLIENT
};


#endif //PACKETTYPE_H
