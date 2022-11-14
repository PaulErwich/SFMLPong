//
// Created by p2-erwich on 10/12/2021.
//

#include "PlayerTwo.h"
PlayerTwo::PlayerTwo(sf::RenderWindow& gameWindow, float x, float y) : Player(gameWindow,x , y)
{
  init();
}

bool PlayerTwo::init()
{
  if (!texture.loadFromFile("Data/Images/paddleRed2.png"))
  {
    std::cout << "Paddle didn't load";
    return false;
  }
  sprite.setTexture(texture);
  sprite.setPosition(window.getSize().x - 100, (window.getSize().y / 2) - (sprite.getGlobalBounds().height / 2));
  return true;
}

void PlayerTwo::keyPressed(sf::Event event)
{
  if (event.key.code == sf::Keyboard::Up)
  {
    movement = -1;
  }
  else if (event.key.code == sf::Keyboard::Down)
  {
    movement = 1;
  }
}

void PlayerTwo::keyReleased(sf::Event event)
{
  if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down)
  {
    movement = 0;
  }
}

void PlayerTwo::reset()
{
  scoreboard->reset();
  sprite.setPosition(window.getSize().x - 100, (window.getSize().y / 2) - (sprite.getGlobalBounds().height / 2));
}
