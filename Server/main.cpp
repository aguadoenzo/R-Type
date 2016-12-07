//
// Created by hippolyteb on 11/20/16.
//

#include <chrono>
#include <Time/Timer.hpp>
#include <Entities/Entity.hpp>
#include <LibraryLoader/ManagedExternalInstance.hpp>
#include <LibraryLoader/ExternalClassFactoryLoader.hpp>

int main()
{
    Timer *tmer = new Timer(std::chrono::steady_clock::now());
    ManagedExternalInstance<Entity> monster(ExternalClassFactoryLoader::Instance->GetInstanceOf<Entity>("", "DummyMonster", { tmer }));

    Trait trait = Drawable;
    std::cout << monster->ImplementTrait(trait) << std::endl;

    return (0);
}