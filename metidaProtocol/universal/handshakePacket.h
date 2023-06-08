#ifndef HANDSHAKEPACKET_H
#define HANDSHAKEPACKET_H

#include <iostream>
#include "../../tinyNet/packet.h"
#include "logger.h"
#include "../packetType.h"

class handshakePacket : public packet{
private:
    std::string strAnswer;
    bool answer;
public:
    handshakePacket();
    void deserialize(nlohmann::json& data) override;
    void serialize() override;
    virtual ~handshakePacket() {};
};

#endif //HANDSHAKEPACKET_H
