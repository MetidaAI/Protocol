#ifndef PINGPONGPACKET_H
#define PINGPONGPACKET_H

#include <iostream>
#include "logger.h"
#include "../../tinyNet/universalPacket.h"
#include "../packetType.h"

class pingPacket : public universalPacket{
public:
    pingPacket();
    void deserialize(nlohmann::json& data) override;
    void serialize() override;
    virtual ~pingPacket() {};
};


#endif //PINGPONGPACKET_H
