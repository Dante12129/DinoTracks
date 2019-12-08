//
// Created by Dan on 12/2/2019.
//

#include "EndMenu.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

#include <Application.hpp>
#include <InputManager.hpp>
#include <Tags.hpp>

namespace dt
{
    std::string toString(EndMenu::Reason reason)
    {
      switch(reason)
      {

        case EndMenu::Reason::Meteor:
          return "The meteor hit!";
        case EndMenu::Reason::Health:
          return "You ran out of health!";
        case EndMenu::Reason::Energy:
          return "You ran out of energy!";
        case EndMenu::Reason::Pod:
          return "";
        case EndMenu::Reason::None:
          return "ERROR";
      }
      return "ERROR";
    }

    EndMenu::EndMenu(const Logic& logic, Reason reason)
    {
      finalScore = logic.getScore();

      reason_ = reason;
      if(reason == Reason::Pod)
        message = "You won!";
      else
        message = "You lost!";
    }

    void EndMenu::registerActions(class dt::InputManager& input)
    {
      // Clear previous state actions
      input.clearActions();

      // Create actions
      thor::Action nextState(sf::Keyboard::Return, thor::Action::ReleaseOnce);

      // Register actions
      input.associate(nextState, NEXT_STATE);
    }

    void EndMenu::processEvents(const InputManager& input)
    {
      if(input.isActive(NEXT_STATE))
        Application::currentApplication->showStart();
    }

    void EndMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
      sf::Font& font = ResourceManager::currentManager->getFont(MAIN_FONT);
      unsigned textSize = 72;

      sf::Sprite background(ResourceManager::currentManager->getTexture(BACKGROUND_END));
      background.setScale({target.getSize().x / background.getLocalBounds().width, target.getSize().y / background.getLocalBounds().height});
      target.draw(background, states);

      sf::Text messageText(message, font, textSize);
      centerTextHorizontal(messageText, target.getSize());
      target.draw(messageText, states);

      sf::Text reasonText(toString(reason_), font, textSize);
      centerTextHorizontal(reasonText, target.getSize());
      reasonText.setPosition(reasonText.getPosition().x, messageText.getPosition().y + font.getLineSpacing(textSize));
      target.draw(reasonText, states);

      sf::Text scoreText("Final Score: " + std::to_string(finalScore), font, textSize);
      centerTextHorizontal(scoreText, target.getSize());
      scoreText.setPosition(scoreText.getPosition().x, reasonText.getPosition().y + font.getLineSpacing(textSize));
      target.draw(scoreText, states);

      sf::Text replayCommand("Press Enter To Play Again", font, textSize);
      centerTextHorizontal(replayCommand, target.getSize());
      replayCommand.setPosition(replayCommand.getPosition().x, scoreText.getPosition().y + font.getLineSpacing(textSize) * 3);
      target.draw(replayCommand, states);
    }
}
