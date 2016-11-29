//
// Created by hippolyteb on 11/20/16.
//

#include <chrono>
#include <Timer.hpp>
#include <Entity.hpp>
#include <ManagedExternalInstance.hpp>
#include <ExternalClassFactoryLoader.hpp>

int main()
{
    Timer *tmer = new Timer(std::chrono::system_clock::now());
    ManagedExternalInstance<Entity> monster(ExternalClassFactoryLoader::GetInstanceOf<Entity>("../SharedLibs/Entities/Monsters/DummyMonster/libDummyMonster.so", { tmer }));

    Trait trait = Drawable;
    std::cout << monster->ImplementTrait(trait) << std::endl;

    return (0);
}