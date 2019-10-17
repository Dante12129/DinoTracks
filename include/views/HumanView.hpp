//
// Created by dan9c on 10/16/2019.
//

#ifndef DINOTRACKS_HUMANVIEW_HPP
#define DINOTRACKS_HUMANVIEW_HPP

#include <SFML/Graphics/RenderWindow.hpp>

namespace dt
{
    // Forward Delcarations
    class Logic;

    class HumanView
    {
    public:
        // Constructors
        HumanView();

        // Game Loop
        void processEvents();
        void sendCommands(Logic& logic) const;
        void updateFrom(const Logic& logic);
        void draw();

    private:
        sf::RenderWindow window;
    };
}


#endif //DINOTRACKS_HUMANVIEW_HPP
