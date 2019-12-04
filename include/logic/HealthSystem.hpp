//
// Created by ywzKe on 2019/11/10.
//

#ifndef DINOTRACKS_HEALTHSYSTEM_HPP
#define DINOTRACKS_HEALTHSYSTEM_HPP

#include <string>

#include "components/Component.hpp"
#include "components/Health.hpp"
#include "Entity.hpp"
#include "System.hpp"

namespace dt
{
    class HealthSystem : public System //This system deals with functionality of energy
    {
    public:
        void init(const std::vector<Entity>& entities);
        void update(Entity& entity) override;

        void heal(Entity& dino, int val);
        void set(Entity& dino, int val);
        void eat(Entity& dino, const Entity& food);

    private:
        // Unordered map for buffering changes
        std::unordered_map<int, int> heaBuffer;
    };
}



#endif //DINOTRACKS_HEALTHSYSTEM_HPP
