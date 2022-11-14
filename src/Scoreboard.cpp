//
// Created by MLG Erwich on 27/11/2021.
//

#include "Scoreboard.h"


Scoreboard::Scoreboard(sf::RenderWindow& game_window, float x, float y) : window(game_window)
{
  score = 0;
  init(x, y);
}

Scoreboard::~Scoreboard()
{

}

bool Scoreboard::init(float x, float y)
{
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "Font didn't load";
    return false;
  }

  Helper::SFMLText(board, "0", font, 40, sf::Color::White, x, y);
  return true;
}

void Scoreboard::reset()
{
  score = 0;
}

void Scoreboard::scoreUpdate()
{
  score++;
}

int Scoreboard::getScore() { return score; }

void Scoreboard::update(float dt)
{
  board.setString(std::to_string(score));
}

void Scoreboard::render()
{
  window.draw(board);
}
