#include "pingPacket.h"

pingPacket::pingPacket(){
    id = (int)packetType::PING_PONG;
}

void pingPacket::serialize() {
    this->data["data"] = isAnswer() ? "pong" : "ping";
    universalPacket::serialize();
}

void pingPacket::deserialize(nlohmann::json& data) {
    this->data = data;
    if (this->data["data"].is_string()) {
        logger::info(std::string(" recieved " + std::string(this->data["data"])));
        if(!strcmp(std::string(this->data["data"]).c_str(), std::string("ping").c_str())) {
            setIsAnswer(true);
            serialize();
        }
    }
}