//
// Created by MLG Erwich on 27/11/2021.
//
#include "../Scoreboard.h"
#include <SFML/Graphics.hpp>

#ifndef PONGSFML_PLAYER_H
#define PONGSFML_PLAYER_H

class Player
{
 public:
  Player(sf::RenderWindow& game_window, float sb_x, float sb_y);
  ~Player();
  sf::Vector2f getPosition();
  sf::FloatRect getGlobalBounds();
  Scoreboard* getScoreboard();
  void update(float dt);
  void render();

 protected:
  sf::Sprite sprite;
  sf::Texture texture;
  sf::RenderWindow& window;
  const int SPEED = 400;
  float movement;
  Scoreboard *scoreboard;
};

#endif // PONGSFML_PLAYER_H
