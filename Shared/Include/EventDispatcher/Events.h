//
// Created by aguado_e on 11/21/16.
//

#ifndef R_TYPE_EVENTS_H
#define R_TYPE_EVENTS_H

// List all events here
namespace RType {
    enum Event {
        BULLET_DAMAGE_CHANGE,
        BULLET_POS_CHANGE,
        NEW_ENTITY,
        POSITION_CHANGED_COLLISION,
        USER_INPUT,
        USER_INPUT_ENTRY,
        SOUND_SYSTEM,
        MENU_LOBBY,
        SEND_NET_MESSAGE,
        START_RECEIVE_NET_MESSAGE,
        STOP_RECEIVE_NET_MESSAGE,
        RECEIVED_NET_MESSAGE
    };
}

#endif //R_TYPE_EVENTS_H
