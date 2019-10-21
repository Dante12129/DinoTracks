//
// Created by ywzKe on 2019/10/21.
//

#include <SFML/System/Vector2.hpp>
#include "components/Components.hpp"
#include "components/Position.hpp"
#include "components/Velocity.hpp"
#include "Entity.hpp"




namespace dt
{
    void moveUp(dt::Entity& dino) {

        //get position and velocity from component
        std::string posi_str = "Position";
        std::string velo_str = "Velocity";
        Components& posi = dino.getComponent(posi_str);
        Components& velo = dino.getComponent(velo_str);

        //move position of the entity by subtracting y-coordinate with y-velocity
        sf::Vector2i cur_velo = velo.getVectorData();
        sf::Vector2i cur_posi = posi.getVectorData();
        cur_posi.y = cur_posi.y - cur_velo.y;
        posi.setData(cur_posi);

    }
    void moveDown(dt::Entity& dino) {

        //get position and velocity from component
        std::string posi_str = "Position";
        std::string velo_str = "Velocity";
        Components& posi = dino.getComponent(posi_str);
        Components& velo = dino.getComponent(velo_str);

        //move position of the entity by adding y-coordinate with y-velocity
        sf::Vector2i cur_velo = velo.getVectorData();
        sf::Vector2i cur_posi = posi.getVectorData();
        cur_posi.y = cur_posi.y + cur_velo.y;
        posi.setData(cur_posi);

    }
    void moveLeft(dt::Entity& dino) {

        //get position and velocity from component
        std::string posi_str = "Position";
        std::string velo_str = "Velocity";
        Components& posi = dino.getComponent(posi_str);
        Components& velo = dino.getComponent(velo_str);

        //move position of the entity by subtracting x-coordinate with x-velocity
        sf::Vector2i cur_velo = velo.getVectorData();
        sf::Vector2i cur_posi = posi.getVectorData();
        cur_posi.x = cur_posi.x - cur_velo.x;
        posi.setData(cur_posi);

    }
    void moveRight(dt::Entity& dino) {

        //get position and velocity from component
        std::string posi_str = "Position";
        std::string velo_str = "Velocity";
        Components& posi = dino.getComponent(posi_str);
        Components& velo = dino.getComponent(velo_str);

        //move position of the entity by adding x-coordinate with x-velocity
        sf::Vector2i cur_velo = velo.getVectorData();
        sf::Vector2i cur_posi = posi.getVectorData();
        cur_posi.x = cur_posi.x + cur_velo.x;
        posi.setData(cur_posi);

    }
    void stop(dt::Entity& dino) {

        //get position and velocity from component
        std::string posi_str = "Position";
        std::string velo_str = "Velocity";
        Components& posi = dino.getComponent(posi_str);
        Components& velo = dino.getComponent(velo_str);

        //set velocity as 0
        sf::Vector2i cur_velo = velo.getVectorData();
        cur_velo.x = 0;
        cur_velo.y = 0;
        velo.setData(cur_velo);
    }

}