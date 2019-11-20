//
// Created by ywzKe on 2019/11/10.
//

#ifndef DINOTRACKS_ENERGYSYSTEM_HPP
#define DINOTRACKS_ENERGYSYSTEM_HPP

#include <string>

#include "components/Component.hpp"
#include "components/Energy.hpp"
#include "components/Food.hpp"
#include "Entity.hpp"
#include "System.hpp"

namespace dt
{
    class EnergySystem : public System //This system deals with functionality of energy
    {
    public:
        EnergySystem();
        virtual void update(Entity& entity) override;

        void adjust(Entity& dino, int val);
        void set(Entity& dino, int val);
        void eat(Entity& dino, const Entity& food);

    private:
        // Component Identifiers
        static const std::string ene_str;
        static const std::string food_str;

        // Unordered map for buffering changes
        std::unordered_map<int, int> eneBuffer;
    };
}



#endif //DINOTRACKS_ENERGYSYSTEM_HPP
