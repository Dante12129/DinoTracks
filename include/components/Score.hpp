//
// Created by Cindy on 11/25/2019.
//

#ifndef DINOTRACKS_SCORE_HPP
#define DINOTRACKS_SCORE_HPP

#include "Component.hpp"

namespace dt
{
    class Score : public Component
    {
    public:
        Score(int sc);

        std::string getName() const override;

        const ComponentData& getData() const override;
        void setData(const ComponentData& data) override;
    private:
        ComponentData eggScore;
    };
}

#endif //DINOTRACKS_SCORE_HPP
