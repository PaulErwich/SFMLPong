//
// Created by p2-erwich on 10/12/2021.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

#ifndef PONGSFML_PLAYERTWO_H
#define PONGSFML_PLAYERTWO_H

class PlayerTwo : public Player
{
 public:
  PlayerTwo(sf::RenderWindow& gameWindow, float x, float y);
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);
  void reset();

 private:
  bool init();
};

#endif // PONGSFML_PLAYERTWO_H
