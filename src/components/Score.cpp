//
// Created by cinde on 11/25/2019.
//

#include "Score.hpp"
#include "Tags.hpp"

namespace dt
{
    Score::Score(int sc) : eggScore(sc)
    {}

    std::string Score::getName() const
    {
        return SCORE;
    }

    const ComponentData& Score::getData() const
    {
        return eggScore;
    }

    void Score::setData(const ComponentData& data)
    {
        eggScore.asInt = data.asInt;
    }
}