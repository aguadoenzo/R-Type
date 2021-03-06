//
// Created by hippolyteb on 12/5/16.
//

#include <iostream>
#include <Messages/ProjectilePositionChangedMessage.hpp>
#include "DrawableSimpleProjectile.hpp"

#ifdef ENTITY_DRW_CTOR
RTYPE_DRAWABLE_ENTITY_REGISTER(DrawableSimpleProjectile)
#endif

DrawableSimpleProjectile::DrawableSimpleProjectile(const std::initializer_list<void *> init) : SimpleProjectile(init) {
    this->RegisterTrait(Trait::Drawable);
}

void DrawableSimpleProjectile::Draw(sf::RenderTexture *rect, TextureBag &bag) {
    auto texture = bag.getTexture("medias/images/r-typesheet1.png", sf::IntRect(249, 105, 16, 8));

    rect->clear(sf::Color::Transparent);
    if (texture == nullptr) {
        auto newtexture = std::make_shared<sf::Texture>();
        newtexture->loadFromFile("medias/images/r-typesheet1.png", sf::IntRect(249, 105, 16, 8));
        texture = bag.AddTexture("medias/images/r-typesheet1.png", sf::IntRect(249, 105, 16, 8), newtexture);
    }
    sf::Sprite sprite;
    sprite.setTexture(*texture);
    rect->draw(sprite);
}

void DrawableSimpleProjectile::Cycle() {
    SimpleProjectile::Cycle();
}

DrawableSimpleProjectile::~DrawableSimpleProjectile() {}

bool DrawableSimpleProjectile::NeedRedraw() {
    return false;
}
