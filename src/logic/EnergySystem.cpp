//
// Created by ywzKe on 2019/11/10.
//

#include <iostream>

#include "EnergySystem.hpp"
#include "components/Component.hpp"
#include "Entity.hpp"
#include "Tags.hpp"

namespace dt {
    void EnergySystem::init(const std::vector<Entity>& entities)
    {
      for (int i = 0; i < 35; i++)
      {
        if (entities.at(i).hasComponent(ENERGY))
        {
          eneBuffer.insert({i, entities.at(i).getData(ENERGY).asVec2i.y}); // Init buffer to max health
        }
        else
        {
          eneBuffer.insert({i, 0});
        }
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

        int newene = eneBuffer[id] + val;
        // Check value of energy
        if (newene >= ene.getData().asVec2i.y){
            newene = ene.getData().asVec2i.y;
        }
        else if(newene <= 0){
            newene = 0;
        }

        // Set value in buffer change
        eneBuffer[id] = newene;
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
        const Component& food_ene = food.getComponent(FOOD);

        adjust(dino, food_ene.getData().asVec2i.x);
    }
}

