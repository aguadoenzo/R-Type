//
// Created by hippolyteb on 11/28/16.
//

#ifndef R_TYPE_ENTITYPOOL_HPP
#define R_TYPE_ENTITYPOOL_HPP

#include <Entity.hpp>
#include <IDrawable.hpp>
#include <vector>
#include <memory>
#include <ManagedExternalInstance.hpp>

class EntityPool {
protected:
    std::vector<ManagedExternalInstance<Entity>> _pool = std::vector<ManagedExternalInstance<Entity>>();

public:
    virtual ~EntityPool();

public:
    virtual void AddEntity(ManagedExternalInstance<Entity> &entity);
};


#endif //R_TYPE_ENTITYPOOL_HPP
