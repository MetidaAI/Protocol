#ifndef METIDAPROTOCOL_DATAPACKETSERVER_H
#define METIDAPROTOCOL_DATAPACKETSERVER_H

#include "iostream"
#include "../../tinyNet/packet.h"
#include "../packetType.h"
#include "../base64.h"
#include <fstream>
#include <logger.h>

class dataPacketServer : public packet{
public:
    dataPacketServer(nlohmann::json &data);
    void serialize() override;
    void deserialize(nlohmann::json& data) override;
    virtual ~dataPacketServer() {};
};


#endif //METIDAPROTOCOL_DATAPACKETSERVER_H
