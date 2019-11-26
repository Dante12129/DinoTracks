//
// Created by ywzKe on 2019/11/10.
//

#include "EnergySystem.hpp"
#include "components/Component.hpp"
#include "Entity.hpp"
#include "Tags.hpp"

namespace dt {
    EnergySystem::EnergySystem(){
        for (int i=0; i<=40; i++){
            eneBuffer.insert({i,100});
        }
    }

    void EnergySystem::update(dt::Entity &dino) {
        // Get id
        int id = dino.getID();

        // Get energy and food components
        Component& energyComponent = dino.getComponent(ENERGY);

        // Use buffer change map to update energy
        energyComponent.setData(ComponentData(eneBuffer[id]));
    }

    //This method add input val to the original energy value
    void EnergySystem::adjust(dt::Entity &dino, int val) {
        // Get id
        int id = dino.getID();

        // Get energy
        Component& ene = dino.getComponent(ENERGY);

        // Set value in buffer change
        eneBuffer[id] = ene.getData().asInt+val;
    }

    //This method set input val as the energy value
    void EnergySystem::set(dt::Entity &dino, int val) {
        // Get id
        int id = dino.getID();

        // Get energy
        Component& ene = dino.getComponent(ENERGY);

        // Set value in buffer change
        eneBuffer[id] = val;
    }

    void EnergySystem::eat(dt::Entity &dino, const dt::Entity &food) {
        // Get id
        int id = dino.getID();

        // Get energy
        Component& ene = dino.getComponent(ENERGY);

        // Get food
        Component& food_ene = dino.getComponent(ENERGY);

        // Set value in buffer change
        eneBuffer[id] = ene.getData().asInt + food_ene.getData().asVec2i.x;
    }





}

