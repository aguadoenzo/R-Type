//
// Created by hippolyteb on 12/6/16.
//

#ifndef R_TYPE_FIREPROJECTILEMESSAGE_HPP
#define R_TYPE_FIREPROJECTILEMESSAGE_HPP

#include <EventDispatcher/IMessage.hpp>
#include <string>
#include <vec2.hpp>
#include <EventDispatcher/Events.h>

class FireProjectileMessage : public IMessage {
public:
    static constexpr RType::Event EventType = RType::NEW_ENTITY;

private:
    const std::string _projectileName;
    const vec2<float> _spawnPosition;
    const uint16_t _id;

public:
    FireProjectileMessage(const uint16_t id, const std::string &projectileName, const vec2<float> &spawnPosition) :
            _projectileName(projectileName), _spawnPosition(spawnPosition), _id(id) {}

    const std::string &getProjectileName() const {
        return _projectileName;
    }

    const vec2<float> &getSpawnPosition() const {
        return _spawnPosition;
    }

    const uint16_t &getId() const {
        return _id;
    }
};

#endif //R_TYPE_FIREPROJECTILEMESSAGE_HPP
