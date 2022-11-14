//
// Created by p2-erwich on 10/12/2021.
//

#include "PlayerOne.h"
PlayerOne::PlayerOne(sf::RenderWindow& gameWindow, float x, float y) :
  Player(gameWindow, x, y)
{
  init();
}

bool PlayerOne::init()
{
  if (!texture.loadFromFile("Data/Images/paddleBlue2.png"))
  {
    std::cout << "Paddle didn't load";
    return false;
  }
  sprite.setTexture(texture);
  sprite.setPosition(100,
                     (window.getSize().y / 2) - (sprite.getGlobalBounds().height / 2));
  return true;
}

void PlayerOne::keyPressed(sf::Event event)
{
  if (event.key.code == sf::Keyboard::W)
  {
    movement = -1;
  }
  else if (event.key.code == sf::Keyboard::S)
  {
    movement = 1;
  }
}

void PlayerOne::keyReleased(sf::Event event)
{
  if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::S)
  {
    movement = 0;
  }
}

void PlayerOne::reset()
{
  scoreboard->reset();
  sprite.setPosition(100,
                     (window.getSize().y / 2) - (sprite.getGlobalBounds().height / 2));
}
