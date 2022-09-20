#ifndef MLSERVER_LEARNINGDATAPACKET_H
#define MLSERVER_LEARNINGDATAPACKET_H

#include <iostream>
#include "tinyNet/packet.h"
#include "logger.h"
#include "../packetType.h"
#include <list>

class learningDataPacket : public packet{
private:
    packetType name = packetType::LEARNING_REQUEST;
public:
    void deserialize(std::string& data) override;
    void serialize() override;
    virtual ~learningDataPacket() {};
};


#endif //MLSERVER_LEARNINGDATAPACKET_H
