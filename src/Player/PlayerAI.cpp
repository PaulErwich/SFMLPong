//
// Created by perwi on 27/12/2021.
//

#include "PlayerAI.h"

PlayerAI::PlayerAI(sf::RenderWindow &game_window, float sb_x, float sb_y) :
  Player(game_window, sb_x, sb_y)
{
  init();
  movement = 1.75;
}

bool PlayerAI::init()
{
  if (!texture.loadFromFile("Data/Images/paddleRed2.png"))
  {
    std::cout << "Paddle didn't load";
    return false;
  }
  sprite.setTexture(texture);
  sprite.setPosition(window.getSize().x - 100,
                     (window.getSize().y / 2) - (sprite.getGlobalBounds().height / 2));

  return true;
}

void PlayerAI::reset()
{
  scoreboard->reset();
  sprite.setPosition(window.getSize().x - 100,
                     (window.getSize().y / 2) - (sprite.getGlobalBounds().height / 2));
}

void PlayerAI::ai_movement(float dt, Ball &ball)
{
  if (sprite.getPosition().y + sprite.getGlobalBounds().height < ball.getSprite().getPosition().y)
  {
    movement = 1.75;
  }
  else if (sprite.getPosition().y > ball.getSprite().getPosition().y)
  {
    movement = -1.75;
  }
}

void PlayerAI::update(float dt, Ball &ball)
{
  sprite.move(0, movement * SPEED * dt);
  ai_movement(dt, ball);

  scoreboard->update(dt);
}
