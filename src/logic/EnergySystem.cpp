//
// Created by ywzKe on 2019/11/10.
//

#include "EnergySystem.hpp"

#include "components/Component.hpp"
#include "Entity.hpp"

namespace dt {
    const std::string EnergySystem::ene_str = "Energy";
    const std::string EnergySystem::food_str = "Food";

    void EnergySystem::update(Entity &dino) {
        // Get id
        int id = dino.getID();

        // Get energy and food components
        Component &energyComponent = dino.getComponent(ene_str);
        Component &foodComponent = dino.getComponent(food_str);

        // Use buffer change map to update energy
        energyComponent.setData(ComponentData(eneBuffer[id]));
    }

    //This method add input val to the original energy value
    void EnergySystem::adjust(dt::Entity &dino, int val) {
        // Get id
        int id = dino.getID();

        // Get energy
        Component& ene = dino.getComponent(ene_str);

        // Set value in buffer change
        eneBuffer[id] = ene.getData().asInt+val;
    }

    //This method set input val as the energy value
    void EnergySystem::set(dt::Entity &dino, int val) {
        // Get id
        int id = dino.getID();

        // Get energy
        Component& ene = dino.getComponent(ene_str);

        // Set value in buffer change
        eneBuffer[id] = val;
    }

    void EnergySystem::eat(dt::Entity &dino, const dt::Entity &food) {
        // Get id
        int id = dino.getID();

        // Get energy
        Component& ene = dino.getComponent(ene_str);

        // Get food
        Component& food_ene = dino.getComponent(food_str);

        // Set value in buffer change
        eneBuffer[id] = ene.getData().asInt + food_ene.getData().asInt;
    }





}

