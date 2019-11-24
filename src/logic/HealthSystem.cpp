//
// Created by ywzKe on 2019/11/10.
//

#include "HealthSystem.hpp"
#include "components/Component.hpp"
#include "Entity.hpp"
#include "Tags.hpp"

namespace dt {
    HealthSystem::HealthSystem(){
        for (int i=0; i<=40; i++){
            heaBuffer.insert({i,100});
        }
    }

    void HealthSystem::update(Entity &dino) {
        // Get id
        int id = dino.getID();

        // Get energy and food components
        Component &energyComponent = dino.getComponent(HEALTH);

        // Use buffer change map to update energy
        energyComponent.setData(ComponentData(heaBuffer[id]));
    }

    //This method add input val to the original energy value
    void HealthSystem::heal(dt::Entity &dino, int val) {
        // Get id
        int id = dino.getID();

        // Get energy
        Component &ene = dino.getComponent(HEALTH);

        // Set value in buffer change
        heaBuffer[id] = ene.getData().asInt + val;
    }

    //This method set input val as the energy value
    void HealthSystem::set(dt::Entity &dino, int val) {
        // Get id
        int id = dino.getID();

        // Get energy
        Component &ene = dino.getComponent(HEALTH);

        // Set value in buffer change
        heaBuffer[id] = val;
    }



}