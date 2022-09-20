#include "learningDataPacket.h"
//#include "../utils/base64.h"

void learningDataPacket::serialize() {
    this->data.clear();
    this->data["packetName"] = id;
    this->data["data"] = "accepted";
}

void learningDataPacket::deserialize(std::string &data) {
    this->data = nlohmann::json::parse(data);
    logger::info(std::string(this->data["data"].dump()));
    std::ofstream f("1652944890.jpg", std::ios::app);
    std::string d;
    //Base64::Decode(this->data["data"]["6"][0].get<std::string>(), d);
    if(f) {
        f << d;
    }
    f.close();
    serialize();
}