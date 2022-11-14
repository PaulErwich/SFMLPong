//
// Created by MLG Erwich on 09/01/2022.
//

#include "GamePaused.h"
GamePaused::GamePaused(STATE stateId, sf::RenderWindow& game_window) :
  GameStateBase(stateId, game_window)
{
  init();
  game_play = nullptr;
}

GamePaused::~GamePaused()
{
  delete game_play;
}

bool GamePaused::init()
{
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "Font didn't load" << std::endl;
    return false;
  }

  Helper::SFMLText(text_paused, "PAUSED", font, 40,
                   color_text, window.getSize().x / 2, window.getSize().y / 4);

  Helper::SFMLText(text_unpause, "PRESS P TO UNPAUSE", font, 40,
                   color_text, window.getSize().x / 2, window.getSize().y / 2);

  Helper::SFMLText(text_return_to_menu, "PRESS ESC TO RETURN TO MENU",
                   font, 40,color_text, window.getSize().x / 2,
                   window.getSize().y / 4 + window.getSize().y / 2);

  return true;
}

void GamePaused::setGame(GamePlay &game)
{
  game_play = &game;
}

STATE GamePaused::input(sf::Event event)
{
  if (event.key.code == sf::Keyboard::P)
  {
    return game_play->getStateID();
  }

  if (event.key.code == sf::Keyboard::Escape)
  {
    return STATE::GAME_MENU;
  }
  return game_state_id;
}

STATE GamePaused::update(float dt)
{
  return game_state_id;
}

void GamePaused::render()
{
  game_play->render();
  window.draw(text_paused);
  window.draw(text_unpause);
  window.draw(text_return_to_menu);
}
