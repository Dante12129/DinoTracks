//
// Created by Dan on 12/2/2019.
//

#include "StartMenu.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <Application.hpp>
#include <InputManager.hpp>
#include <Tags.hpp>

namespace dt
{
    std::string toString(int dinosaurString)
    {
      switch(dinosaurString)
      {
        case 0:
          return STEGOSAURUS;
        case 1:
          return TYRANNOSAURUS;
        case 2:
          return VELOCIRAPTOR;
        case 3:
          return SPINOSAURUS;
        case 4:
          return ALLOSAURUS;
        case 5:
          return PACHYCEPHALOSAURUS;
        case 6:
          return PROTOCERATOPS;
        case 7:
          return PARASAUROLOPHUS;
      }
      return "ERROR";
    }

    StartMenu::StartMenu()
    {}

    void StartMenu::registerActions(InputManager& input)
    {
      // Clear previous state actions
      input.clearActions();

      // Create actions
      thor::Action nextState(sf::Keyboard::Return, thor::Action::ReleaseOnce);
      thor::Action chooseUp(sf::Keyboard::W, thor::Action::ReleaseOnce);
      thor::Action chooseDown(sf::Keyboard::S, thor::Action::ReleaseOnce);
      thor::Action chooseLeft(sf::Keyboard::A, thor::Action::ReleaseOnce);
      thor::Action chooseRight(sf::Keyboard::D, thor::Action::ReleaseOnce);

      // Register actions
      input.associate(nextState, NEXT_STATE);
      input.associate(chooseUp, CHOOSE_UP);
      input.associate(chooseDown, CHOOSE_DOWN);
      input.associate(chooseLeft, CHOOSE_LEFT);
      input.associate(chooseRight, CHOOSE_RIGHT);
    }

    void StartMenu::processEvents(const InputManager& input)
    {
      if(input.isActive(NEXT_STATE))
        Application::currentApplication->startGame(toString(currentDinoSelection), currentLevelSelection);

      if(input.isActive(CHOOSE_UP) || input.isActive(CHOOSE_DOWN))
      {
        chooserSelected = chooserSelected ? 0 : 1;
      }
      if(input.isActive(CHOOSE_RIGHT))
      {
        if(chooserSelected)
        {
          currentLevelSelection++;
          currentLevelSelection = currentLevelSelection > maxLevels ? 1 : currentLevelSelection;
        }
        else
        {
          currentDinoSelection++;
          currentDinoSelection = currentDinoSelection > 7 ? 0 : currentDinoSelection;
        }
      }
      if(input.isActive(CHOOSE_LEFT))
      {
        if(chooserSelected)
        {
          currentLevelSelection--;
          currentLevelSelection = currentLevelSelection < 1 ? maxLevels : currentLevelSelection;
        }
        else
        {
          currentDinoSelection--;
          currentDinoSelection = currentDinoSelection < 0 ? 7 : currentDinoSelection;
        }
      }
    }

    void StartMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
      sf::Font& font = ResourceManager::currentManager->getFont(MAIN_FONT);
      unsigned textSize = 70;

      sf::Sprite background(ResourceManager::currentManager->getTexture(BACKGROUND_START));
      target.draw(background, states);

      sf::Text dinosaurText("Dinosaur: " + toString(currentDinoSelection), font, textSize);
      centerTextHorizontal(dinosaurText, target.getSize());
      dinosaurText.setFillColor(chooserSelected ? normalColor : highlightColor);
      target.draw(dinosaurText, states);

      sf::Text levelText("Level: " + std::to_string(currentLevelSelection), font, textSize);
      centerTextHorizontal(levelText, target.getSize());
      levelText.setPosition(levelText.getPosition().x, dinosaurText.getPosition().y + font.getLineSpacing(textSize));
      levelText.setFillColor(chooserSelected ? highlightColor : normalColor);
      target.draw(levelText, states);

      sf::Text instructions("Use WSAD To Change Values\nPress Enter To Start", font, textSize - 5);
      centerTextHorizontal(instructions, target.getSize());
      instructions.setPosition(instructions.getPosition().x, levelText.getPosition().y + font.getLineSpacing(textSize) * 2);
      instructions.setFillColor(normalColor);
      target.draw(instructions, states);
    }
}
