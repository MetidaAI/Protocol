#include "dataPacketServer.h"

dataPacketServer::dataPacketServer(nlohmann::json &data) {
    this->data = data;
    id = (int)packetType::DATA_SERVER;
    direction = packetDirection::SERVER;
}

void dataPacketServer::serialize() {
    std::ifstream f("data/" + this->data["data"]["file"].get<std::string>(), std::ios::in);
    std::string d;
    if(f.is_open())
        d = std::string((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
    else
        logger::error("Error open "+ this->data["data"]["file"].get<std::string>());
    std::string binary = Base64::Encode(d);
    f.close();
    this->data["data"]["binary"] = binary;
    packet::serialize();
    logger::info("file "+this->data["data"]["file"].get<std::string>()+" was send");
}

void dataPacketServer::deserialize(std::string &data) {
    this->data = nlohmann::json::parse(data);
    std::filesystem::create_directories("data/"+this->data["data"]["model"].get<std::string>());
    std::ofstream f("data/"+this->data["data"]["model"].get<std::string>() + "/" + this->data["data"]["file"].get<std::string>(), std::ios::app);
    std::string d;
    Base64::Decode(this->data["data"]["binary"].get<std::string>(), d);
    if(f)
        f << d;

    f.close();
    logger::success("file "+this->data["data"]["file"].get<std::string>()+" was received");
}
