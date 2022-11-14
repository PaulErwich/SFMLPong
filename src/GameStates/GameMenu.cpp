//
// Created by MLG Erwich on 30/11/2021.
//

#include "GameMenu.h"

GameMenu::GameMenu(
  STATE stateId, sf::RenderWindow& game_window) :
  GameStateBase(stateId, game_window)
{
  init();
  current_option = MENUOPTION::TWOPLAYER;
}

GameMenu::~GameMenu()
{
  delete opt_one_player;
  delete opt_two_player;
  delete opt_quit;
}

bool GameMenu::init()
{
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
      std::cout << "Font didn't load" << std::endl;
      return false;
  }
  Helper::SFMLText(text, "PONG", font, 72, sf::Color::White,
                   window.getSize().x / 2, window.getSize().y / 8);

  opt_one_player = new MenuOption(MENUOPTION::ONEPLAYER, "1 PLAYER", font,
                                  40, window.getSize().x / 4,
                                  window.getSize().y / 3, false);

  opt_two_player = new MenuOption(MENUOPTION::TWOPLAYER, "2 PLAYER", font,
                                  40, window.getSize().x / 2,
                                  window.getSize().y / 3, true);

  opt_quit = new MenuOption(MENUOPTION::QUIT, "EXIT GAME", font,
                            40, window.getSize().x / 4 + window.getSize().x / 2,
                            window.getSize().y / 3, false);

  return true;
}

STATE GameMenu::input(sf::Event event)
{
  if (event.key.code == sf::Keyboard::Left)
  {
    switch(current_option)
    {
      case MENUOPTION::ONEPLAYER:
        opt_one_player->setSelected(false);
        opt_quit->setSelected(true);
        current_option = MENUOPTION::QUIT;
        break;
      case MENUOPTION::TWOPLAYER:
        opt_two_player->setSelected(false);
        opt_one_player->setSelected(true);
        current_option = MENUOPTION::ONEPLAYER;
        break;
      case MENUOPTION::QUIT:
        opt_quit->setSelected(false);
        opt_two_player->setSelected(true);
        current_option = MENUOPTION::TWOPLAYER;
        break;
    }
  }
  else if (event.key.code == sf::Keyboard::Right)
  {
    switch(current_option)
    {
      case MENUOPTION::ONEPLAYER:
        opt_one_player->setSelected(false);
        opt_two_player->setSelected(true);
        current_option = MENUOPTION::TWOPLAYER;
        break;
      case MENUOPTION::TWOPLAYER:
        opt_two_player->setSelected(false);
        opt_quit->setSelected(true);
        current_option = MENUOPTION::QUIT;
        break;
      case MENUOPTION::QUIT:
        opt_quit->setSelected(false);
        opt_one_player->setSelected(true);
        current_option = MENUOPTION::ONEPLAYER;
        break;
    }
  }

  if (event.key.code == sf::Keyboard::Enter)
  {
    switch(current_option)
    {
      case MENUOPTION::ONEPLAYER:
      {
        return STATE::GAME_PLAY_AI;
      }
      case MENUOPTION::TWOPLAYER:
      {
        return STATE::GAME_PLAY;
      }
      case MENUOPTION::QUIT:
      {
        return STATE::GAME_EXIT;
      }
    }
  }

  return game_state_id;
}

STATE GameMenu::update(float dt)
{
  opt_one_player->update();
  opt_two_player->update();
  opt_quit->update();
  return game_state_id;
}

void GameMenu::render()
{
  window.draw(text);
  window.draw(opt_one_player->getText());
  window.draw(opt_two_player->getText());
  window.draw(opt_quit->getText());
}

