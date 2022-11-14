//
// Created by MLG Erwich on 27/11/2021.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Helper.h"


#ifndef PONGSFML_SCOREBOARD_H
#define PONGSFML_SCOREBOARD_H

class Scoreboard
{
 public:
  Scoreboard(sf::RenderWindow& game_window, float x, float y);
  ~Scoreboard();
  void reset();
  void scoreUpdate();
  int getScore();
  void update(float dt);
  void render();

 private:
  sf::RenderWindow &window;
  sf::Font font;
  sf::Text board;
  int score;

  bool init(float x, float y);
};

#endif // PONGSFML_SCOREBOARD_H