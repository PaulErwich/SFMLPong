//
// Created by MLG Erwich on 27/11/2021.
//

#include "Player/Player.h"
#include "Vector.h"
#include <SFML/Graphics.hpp>
#include <iostream>

#define random(min, max) rand() % (max + 1 - min) + min // The function I've used to generate random numbers

#ifndef PONGSFML_BALL_H
#define PONGSFML_BALL_H

class Ball
{
 public:
  Ball(sf::RenderWindow &game_window);
  ~Ball();
  sf::Sprite getSprite();
  void movement(float dt);
  void wallCollision();
  void playerCollision(Player &bat);
  void outOfBounds(Scoreboard &score_one, Scoreboard &score_two);
  void resetPos();
  void update(float dt, Player &bat, Player &bat2);
  void render();

 private:
  sf::Texture texture;
  sf::Sprite sprite;
  sf::RenderWindow& window;
  Vector *direction;
  const float ball_speed = 200;
  void init();
};

#endif // PONGSFML_BALL_H
