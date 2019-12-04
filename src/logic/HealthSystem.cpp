//
// Created by ywzKe on 2019/11/10.
//

#include "HealthSystem.hpp"
#include "components/Component.hpp"
#include "Entity.hpp"
#include "Tags.hpp"
#include "iostream"

namespace dt {
    HealthSystem::HealthSystem()
    {}

    void HealthSystem::update(Entity &dino) {
        // Get id
        int id = dino.getID();

        // Get energy and food components
        Component &healthComponent = dino.getComponent(HEALTH);

        // Use buffer change map to update energy
        healthComponent.setData(ComponentData(heaBuffer[id]));
    }

    //This method add input val to the original energy value
    void HealthSystem::heal(dt::Entity &dino, int val) {
        // Get id
        int id = dino.getID();

        // Get health
        Component &hea = dino.getComponent(HEALTH);

        int newhea = hea.getData().asVec2i.x + val;
        // Check value of health
        if (newhea>=hea.getData().asVec2i.y){
            newhea = hea.getData().asVec2i.y;
        }
        else if(newhea<=0){
            newhea = 0;
        }

        // Set value in buffer change
        heaBuffer[id] = newhea;
    }

    //This method set input val as the energy value
    void HealthSystem::set(dt::Entity &dino, int val) {
        // Get id
        int id = dino.getID();

        // Set value in buffer change
        heaBuffer[id] = val;
    }

    void HealthSystem::eat(dt::Entity &dino, const dt::Entity &food) {
        // Get id
        int id = dino.getID();

        // Get health
        Component& hea = dino.getComponent(HEALTH);

        // Get food
        const Component& food_hea = food.getComponent(FOOD);


        heal(dino, food_hea.getData().asVec2i.y);
    }

    void HealthSystem::setentities(std::vector<Entity>& ents) {
        for (int i=0; i<ents.size(); i++){
            std::cout<<ents.size();
            if(ents[i].hasComponent(HEALTH)){
                int maxhea = ents[i].getComponent(HEALTH).getData().asVec2i.y;
                heaBuffer.insert({i,maxhea});
            }
        }
    }

}