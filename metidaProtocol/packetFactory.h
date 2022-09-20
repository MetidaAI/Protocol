#ifndef PACKETFACTORY_H
#define PACKETFACTORY_H

#include <iostream>
#include "tinyNet/packet.h"
#include "packetType.h"
#include "tinyNet/abstractPacketFactory.h"

//packets
#include "universal/handshakePacket.h"
#include "universal/pingPacket.h"
#include "universal/learningDataPacket.h"
#include "server/dataPacketServer.h"

class packetFactory : public abstractPacketFactory{
public:
    std::unique_ptr<packet> create(int packetID, nlohmann::json &data) override;
};

#endif //PACKETFACTORY_H