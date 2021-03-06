//
// Created by pasteu_e on 10/12/16.
//

#include "DrawableMenu/MenuSoundVolume.hpp"

MenuSoundVolume::MenuSoundVolume(std::shared_ptr<RType::EventManager> &eventManager) : _eventListener(eventManager) {
    _eventManager = eventManager;
    _menuMap[0] = std::make_pair(true, "Back");
    _menuName = "Sound Volume";
    _menuType = HORIZONTAL;
    _canMove = false;

    _eventListener.Subscribe<Entity, UserInputMessage>(UserInputMessage::EventType, [&](Entity *, UserInputMessage *message) {
        if (_active) {
            if (message->PressedContainsOnly(USER_RIGHT) && _volume < 100) {
                _volume++;
                _eventManager->Emit(SoundSystemMessage::EventType, new SoundSystemMessage(VOLUME_SOUND, _volume), this);
            } else if (message->PressedContainsOnly(USER_LEFT) && _volume > 0) {
                _volume--;
                _eventManager->Emit(SoundSystemMessage::EventType, new SoundSystemMessage(VOLUME_SOUND, _volume), this);
            }

        }
    });
}

void MenuSoundVolume::specialDrawing(sf::RenderTexture &context, sf::Text &text) {
    text.setFillColor(sf::Color::White);
    text.setPosition(context.getSize().x / 2 - ((50 * 12) / 3), context.getSize().y / 4);
    text.setString("Sound Volume");
    context.draw(text);
    sf::RectangleShape bar(sf::Vector2f((context.getSize().x / 3) * 2, 2));
    bar.setPosition(sf::Vector2f((context.getSize().x / 2) - ((context.getSize().x / 3)), context.getSize().y / 2.15f));
    context.draw(bar);
    sf::CircleShape vol(10);
    int posX = (context.getSize().x / 2) - ((context.getSize().x / 3));
    posX += (_volume * ((context.getSize().x / 3) * 2) / 100);
    vol.setPosition(sf::Vector2f(posX, context.getSize().y / 2.2f));
    context.draw(vol);
}
