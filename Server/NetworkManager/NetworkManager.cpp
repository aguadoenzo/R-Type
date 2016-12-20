//
// Created by hippolyteb on 12/12/16.
//

#include <EventDispatcher/EventListener.hpp>
#include <Messages/SendNetworkPayloadMessage.hpp>
#include <Messages/NewClientConnectionMessage.hpp>
#include <Messages/SendTCPNetworkPayloadMessage.hpp>
#include <Messages/ReceivedTCPNetworkPayloadMessage.hpp>
#include "NetworkManager/NetworkManager.hpp"

NetworkManager::NetworkManager(const std::shared_ptr<RType::EventManager> &eventManager) : _eventManager(eventManager) {

}

void NetworkManager::Start() {
    _thread = std::unique_ptr<std::thread>(new std::thread(std::bind(&NetworkManager::Run, this)));
}

void NetworkManager::Run() {

    auto sub = RType::EventListener(_eventManager);

    sub.Subscribe<void, SendNetworkPayloadMessage>(SendNetworkPayloadMessage::EventType, [&](void *sender, SendNetworkPayloadMessage *message) {
        Send(message->ConvertToSocketMessage());
    });

    std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::hours(std::numeric_limits<int>::max()));
}

void NetworkManager::Send(RTypeNetworkPayload const &payload) {
    if (_clients.find(payload.Ip) == _clients.end()) {
        _clients[payload.Ip] = std::unique_ptr<RTypeSocket<UDP>>(new RTypeSocket<UDP>(payload.Ip, 9876));
    } else {
        _clients[payload.Ip]->Send(payload);
    }
}


void NetworkManager::StartTCP() {
    auto sub = RType::EventListener(_eventManager);

    sub.Subscribe<void, SendTCPNetworkPayloadMessage>(SendTCPNetworkPayloadMessage::EventType, [&](void *sender, SendTCPNetworkPayloadMessage *message) {
        //SendTCP(message->ConvertToSocketMessage());
    });

    _thread = std::unique_ptr<std::thread>(new std::thread(std::bind(&NetworkManager::RunTCP, this)));
}

void NetworkManager::RunTCP() {
    std::unique_ptr<IRTypeSocket> server = std::unique_ptr<IRTypeSocket>(new RTypeSocket<TCP>(6789));
    server->Bind();
    while (true) {
        std::shared_ptr<IRTypeSocket> newClient = server->Accept();
        if (newClient != nullptr) {
            std::cout << "Accepting New Client connection !" << std::endl;
            _eventManager->Emit(NewClientConnectionMessage::EventType, new NewClientConnectionMessage(newClient), this);
        }
    }
}

void NetworkManager::SendTCP(RTypeNetworkPayload const &payload, std::unique_ptr<IRTypeSocket> &_client) {

}

void NetworkManager::AskClientForRoomName(std::shared_ptr<IRTypeSocket> client) {
    std::thread (&NetworkManager::ThreadAskingRoomName, this, client).detach();
}

void NetworkManager::ThreadAskingRoomName(std::shared_ptr<IRTypeSocket> client) {
    char data[1500];

    RTypeNetworkPayload payload(data, 1500);
    client->Receive(payload);
    std::cout << "Room name : " << payload.Payload << std::endl;
    _eventManager->Emit(ReceivedTCPNetworkPayloadMessage::EventType, new ReceivedTCPNetworkPayloadMessage(payload), this);
}
