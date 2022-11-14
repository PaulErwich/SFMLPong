//
// Created by MLG Erwich on 30/11/2021.
//

#include "../Ball.h"
#include "../Player/PlayerOne.h"
#include "../Helper.h"
#include "GameStateBase.h"
#include <SFML/Graphics.hpp>

#ifndef PONGSFML_GAMEPLAY_H
#define PONGSFML_GAMEPLAY_H

class GamePlay : public GameStateBase
{
 public:
  GamePlay(STATE stateId, sf::RenderWindow &game_window, int ball_number);
  ~GamePlay();
  virtual void reset();
  Player* getPlayer();
  static int getWin();
  virtual void keyReleased(sf::Event event);
  STATE input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 protected:
  PlayerOne *player_one;
  Ball *ball[3];
  int number_of_balls;
  sf::Font font;
  sf::Text text;
  static const int WIN = 10;
  bool init();
};

#endif // PONGSFML_GAMEPLAY_H
