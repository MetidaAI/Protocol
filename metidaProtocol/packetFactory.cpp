#include "packetFactory.h"

std::unique_ptr<packet> packetFactory::create(int packetID, nlohmann::json &data) {
    switch ((packetType)packetID) {
        case packetType::PING_PONG:
            return std::make_unique<pingPacket>();
        case packetType::HANDSHAKE:
            return std::make_unique<handshakePacket>();
        case packetType::LEARNING_REQUEST:
            return nullptr;
        case packetType::LEARNING_DATA:
            return std::make_unique<learningDataPacket>();
        case packetType::DATA_SERVER:
            return std::make_unique<dataPacketServer>(data);
    }
    return nullptr;
}

