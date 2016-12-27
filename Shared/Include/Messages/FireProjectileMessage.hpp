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
    const uint16_t _projectileType;
    const vec2<float> _spawnPosition;
    const uint16_t _id;

public:
    FireProjectileMessage(const uint16_t id, const uint16_t projectileType, const vec2<float> &spawnPosition) :
            _projectileType(projectileType), _spawnPosition(spawnPosition), _id(id) {}

    uint16_t getProjectileName() const {
        return _projectileType;
    }

    const vec2<float> &getSpawnPosition() const {
        return _spawnPosition;
    }

    uint16_t getId() const {
        return _id;
    }
};

#endif //R_TYPE_FIREPROJECTILEMESSAGE_HPP
