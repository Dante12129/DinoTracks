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
    EndMenu::EndMenu(const Logic& logic, Reason reason)
    {
      finalScore = logic.getScore();

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
      thor::Action nextState(sf::Keyboard::Enter, thor::Action::ReleaseOnce);

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
      sf::Font& font = ResourceManager::currentManager->getFont(METEOR_FONT);
      unsigned textSize = 72;

      sf::Text messageText(message, font, textSize);
      centerTextHorizontal(messageText, target.getSize());
      target.draw(messageText, states);

      sf::Text scoreText("Final Score: " + std::to_string(finalScore), font, textSize);
      centerTextHorizontal(scoreText, target.getSize());
      scoreText.setPosition(scoreText.getPosition().x, messageText.getPosition().y + font.getLineSpacing(textSize) + 2);
      target.draw(scoreText, states);

      sf::Text replayCommand("Press Enter To Play Again", font, textSize);
      centerTextHorizontal(replayCommand, target.getSize());
      replayCommand.setPosition(replayCommand.getPosition().x, scoreText.getPosition().y + font.getLineSpacing(textSize) * 3);
      target.draw(replayCommand, states);
    }
}