//
// Created by Cindy on 11/10/2019.
//

#ifndef DINOTRACKS_VISUAL_HPP
#define DINOTRACKS_VISUAL_HPP

#include "components/Component.hpp"

namespace dt
{
    class Visual : public Component
    {
    public:
        Visual(std::string str);

        std::string getName() const override;

        const ComponentData& getData() const override;
        void setData(const ComponentData& data) override;

        const std::string& getString() const;
        void setString(const std::string& string);

    private:
        ComponentData dummy;
        std::string vis;
    };
}

#endif //DINOTRACKS_VISUAL_HPP
