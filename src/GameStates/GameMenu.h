//
// Created by MLG Erwich on 30/11/2021.
//

#include <SFML/Graphics.hpp>
#include "GameStateBase.h"
#include <iostream>
#include "../MenuOption.h"

#ifndef PONGSFML_GAMEMENU_H
#define PONGSFML_GAMEMENU_H



class GameMenu : public GameStateBase
{
 public:
  GameMenu(STATE stateId, sf::RenderWindow& game_window);
  ~GameMenu();
  STATE input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 private:
  sf::Font font;
  sf::Text text;
  MenuOption* opt_one_player;
  MenuOption* opt_two_player;
  MenuOption* opt_quit;
  MENUOPTION current_option;
  bool init();
};

#endif // PONGSFML_GAMEMENU_H
