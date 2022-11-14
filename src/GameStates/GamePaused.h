//
// Created by MLG Erwich on 09/01/2022.
//

#include <SFML/Graphics.hpp>
#include "../Helper.h"
#include "GameStateBase.h"
#include "GamePlay.h"

#ifndef PONGSFML_GAMEPAUSED_H
#define PONGSFML_GAMEPAUSED_H

class GamePaused : public GameStateBase
{
 public:
  GamePaused(STATE stateId, sf::RenderWindow &game_window);
  ~GamePaused();
  void setGame(GamePlay &game);
  STATE input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 private:
  sf::Font font;
  sf::Text text_paused;
  sf::Text text_unpause;
  sf::Text text_return_to_menu;
  GamePlay *game_play;
  const sf::Color color_text = sf::Color(245, 245, 245, 150);
  bool init();
};

#endif // PONGSFML_GAMEPAUSED_H
