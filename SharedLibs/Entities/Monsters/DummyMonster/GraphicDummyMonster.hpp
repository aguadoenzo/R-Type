//
// Created by hippolyteb on 11/29/16.
//

#ifndef R_TYPE_GRAPHICDUMMYMONSTER_HPP
#define R_TYPE_GRAPHICDUMMYMONSTER_HPP

#include <Entities/DrawableEntity.hpp>
#include "DummyMonster.hpp"

class GrahicDummyMonster : DrawableEntity, public DummyMonster {

public:
    GrahicDummyMonster(const std::initializer_list<void *> init);

public:
    void Draw(sf::RenderTexture *rect, TextureBag &) override;
    vec2<float> GetRenderRect() override;
    vec2<float> GetPosition() override;

    void Cycle() override;
};

#endif //R_TYPE_GRAPHICDUMMYMONSTER_HPP
