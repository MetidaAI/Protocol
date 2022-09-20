cmake_minimum_required(VERSION 3.21)
project(METIDAProtocol)

set(CMAKE_CXX_STANDARD 23)

add_library(METIDAProtocol SHARED
        metidaProtocol/packetType.h
        metidaProtocol/packetFactory.h
        metidaProtocol/packetFactory.cpp
        metidaProtocol/universal/learningDataPacket.h
        metidaProtocol/universal/learningDataPacket.cpp
        metidaProtocol/universal/pingPacket.h
        metidaProtocol/universal/pingPacket.cpp
        metidaProtocol/universal/handshakePacket.h
        metidaProtocol/universal/handshakePacket.cpp
        metidaProtocol/server/dataPacketServer.cpp metidaProtocol/server/dataPacketServer.h metidaProtocol/base64.h)


install(TARGETS METIDAProtocol
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}")

install(DIRECTORY "${CMAKE_SOURCE_DIR}/"
        DESTINATION "include"
        FILES_MATCHING
        PATTERN "*.h"
        PATTERN ".git" EXCLUDE
        PATTERN "build" EXCLUDE
        PATTERN "cmake-build-debug" EXCLUDE
        PATTERN ".idea" EXCLUDE
        )