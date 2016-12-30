//
// Created by aguado_e on 12/29/16.
//

#ifndef R_TYPE_STARTNEWGAMEMESSAGE_HPP
#define R_TYPE_STARTNEWGAMEMESSAGE_HPP

#include <EventDispatcher/IMessage.hpp>
#include <EventDispatcher/Events.h>
#include <string>
#include <Entities/PlayerRef.hpp>

class StartNewGameMessage : public IMessage {
public:
    static constexpr RType::Event EventType = RType::Event::START_NEW_GAME;

private:
    std::string _partitionName;
    std::vector<PlayerRef> _playerRefs;

public:
    StartNewGameMessage(std::string &partition, std::vector<PlayerRef> &refs) :
            _partitionName(partition),
            _playerRefs(refs) {}

    const std::string &getId() const {
        return _partitionName;
    }

    const std::vector<PlayerRef> &getPlayerRefs() const {
        return _playerRefs;
    }
};

#endif //R_TYPE_STARTNEWGAMEMESSAGE_HPP
