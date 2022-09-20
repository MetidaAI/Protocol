#include "handshakePacket.h"

void handshakePacket::serialize() {
    this->data["id"] = id;
    this->data["answer"] = answer;
    this->data["data"] = answer ? strAnswer : "connect";
}

void handshakePacket::deserialize(std::string& data) {
    this->data = nlohmann::json::parse(data);
    if (this->data["data"].is_string() && strstr(std::string(this->data["data"]).c_str(), "connect")) {
        answer = true;
        strAnswer = "connected";
        logger::info(std::string(this->data["data"]));
       // encode();
        //Connect manager = connected;
    }
}

handshakePacket::handshakePacket() {
    id = (int)packetType::HANDSHAKE;
    answer = false;
    direction = packetDirection::UNIVERSAL;
}
