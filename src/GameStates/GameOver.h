//
// Created by MLG Erwich on 30/11/2021.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameStateBase.h"
#include "GamePlay.h"
#include "../Helper.h"
#include "../WINNER.h"

#ifndef PONGSFML_GAMEOVER_H
#define PONGSFML_GAMEOVER_H

class GameOver : public GameStateBase
{
 public:
  GameOver(STATE stateId, sf::RenderWindow& game_window);
  ~GameOver();
  void setWinner(WINNER _winner);
  void setGame(GamePlay &game);
  STATE input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 private:
  sf::Text text;
  sf::Text text_winner;
  sf::Font font;
  GamePlay *game_play;
  WINNER winner;
  bool init();
};

#endif // PONGSFML_GAMEOVER_H
