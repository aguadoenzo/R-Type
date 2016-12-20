//
// Created by hippolyteb on 11/29/16.
//

#include <Messages/ReceivedNetworkPayloadMessage.hpp>
#include "ClientEntityPool.hpp"

void ClientEntityPool::Draw(sf::RenderTexture &target, TextureBag &bag) {
    for (const auto& i : _pool)
    {
        if (i.second->ImplementTrait(Trait::Drawable)) {
            IDrawable *entity = dynamic_cast<IDrawable*>(i.second.GetInstance());
            auto renderTarget = entity->getRenderTexture();
            if (renderTarget == nullptr)
                renderTarget = entity->createRenderTexture((unsigned int) i.second->GetRenderRect().x, (unsigned int) i.second->GetRenderRect().y);
            entity->Draw(renderTarget, bag);
            renderTarget->display();
            sf::Sprite sprite;
            sprite.setTexture(renderTarget->getTexture());
            sprite.setPosition(i.second->GetPosition().x, i.second->GetPosition().y);
            target.draw(sprite);
        }
    }
}

void ClientEntityPool::AddEntity(std::string const &entityName, uint16_t id, vec2<float> const &initialPos, TimeRef const &startTime, std::initializer_list<void *> *params) {
    auto now = startTime;
    auto pos = initialPos;
    ManagedExternalInstance<Entity> entity(ExternalClassFactoryLoader::Instance->GetInstanceOf<Entity>("", "Drawable" + entityName, { &id, &_timer, &_eventManager, &now, &pos, params }, "createDrawable", "destroyDrawable"));
    _factory.RegisterEntityType(entity->getTypeId(), "Drawable" + entityName);
    EntityPool::AddEntity(entity);
}

ClientEntityPool::ClientEntityPool(const std::shared_ptr<Timer> &timer,
                                   const std::shared_ptr<RType::EventManager> &eventManager) : EntityPool(timer),
                                                                                               _globalEventManager(eventManager),
                                                                                               _globalEventListener(std::unique_ptr<RType::EventListener>(new RType::EventListener(eventManager))) {

}

void ClientEntityPool::AddEntity(const ManagedExternalInstance<Entity> &instance) {
    EntityPool::AddEntity(instance);
}
