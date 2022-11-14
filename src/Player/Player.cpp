//
// Created by MLG Erwich on 27/11/2021.
//

#include "Player.h"
#include <iostream>

Player::Player(sf::RenderWindow& game_window, float sb_x, float sb_y) : window(game_window)
{
  movement = 0;
  scoreboard = new Scoreboard(game_window, sb_x, sb_y);
}

Player::~Player()
{
  delete scoreboard;
}

sf::Vector2f Player::getPosition()
{
  return sprite.getPosition();
}

sf::FloatRect Player::getGlobalBounds()
{
  return sprite.getGlobalBounds();
}

Scoreboard* Player::getScoreboard()
{
  return scoreboard;
}

void Player::update(float dt)
{
  sprite.move(0, movement * SPEED * dt);

  scoreboard->update(dt);
  if (sprite.getPosition().y < 10)
  {
    sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + sprite.getGlobalBounds().height/2);
  }
  else if (sprite.getPosition().y + sprite.getGlobalBounds().height > window.getSize().y - 10)
  {
    sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - sprite.getGlobalBounds().height/2);
  }
}

void Player::render()
{
  window.draw(sprite);
  scoreboard->render();
}

