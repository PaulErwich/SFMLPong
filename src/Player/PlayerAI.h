//
// Created by perwi on 27/12/2021.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "../Ball.h"

#ifndef PONGSFML_PLAYERAI_H
#define PONGSFML_PLAYERAI_H

class PlayerAI : public Player
{
 public:
  PlayerAI(sf::RenderWindow &game_window, float sb_x, float sb_y);
  void reset();
  void ai_movement(float dt, Ball &ball);
  void update(float dt, Ball &ball);

 private:
  bool init();
};

#endif // PONGSFML_PLAYERAI_H
