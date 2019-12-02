//
// Created by Ben on 12/2/2019
//

#ifndef DINOTRACKS_AIVIEW_HPP
#define DINOTRACKS_AIVIEW_HPP

#include <vector>

#include <SFML/Graphics/Sprite.hpp>

namespace dt
{
    // Forward Delcarations
    class Logic;

    class AIView
    {
    public:
        // Constructors
        AIView();
        
        //Game Loop
        void processEvents(Logic& logic);
        void sendCommands(Logic& logic) const;
        void updateFrom(const Logic& logic);

    private:
		std::vector<bool> enemyStates;

    };
}

#endif //DINOTRACKS_AIVIEW_HPP
