//
// Created by MLG Erwich on 27/11/2021.
//

#include "Ball.h"
Ball::Ball(sf::RenderWindow& game_window) : window(game_window)
{
  direction = new Vector(2, random(1, 3));
  init();
}

Ball::~Ball()
{
  delete direction;
}

void Ball::init()
{
  if (!texture.loadFromFile("Data/Images/ballGrey.png")) std::cout << "Ball didn't load";
  sprite.setTexture(texture);

  sprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
  sprite.scale(1, 1);
}

sf::Sprite Ball::getSprite() {return sprite;}

void Ball::movement(float dt)
{
  // Constantly move in the direction of the vector
  sprite.move(direction->getVectorx() * dt * ball_speed, direction->getVectory() * dt * ball_speed);
}

void Ball::wallCollision()
{
  // Rebound of the top/bottom of the screen
  if ((sprite.getPosition().y < 0 && direction->getVectory() < 0) ||
      (sprite.getPosition().y + sprite.getGlobalBounds().height > window.getSize().y && direction->getVectory() > 0))
  {
    direction->setVector(direction->getVectorx(), -direction->getVectory());
  }
}

void Ball::playerCollision(Player &bat)
{
  //Change direction when hitting player. Randomise the Y
  if (sprite.getPosition().x < bat.getPosition().x + bat.getGlobalBounds().width &&
  sprite.getPosition().x + sprite.getGlobalBounds().width > bat.getPosition().x &&
  sprite.getPosition().y < bat.getPosition().y + bat.getGlobalBounds().height &&
  sprite.getPosition().y + sprite.getGlobalBounds().height > bat.getPosition().y)
  {
      direction->setVector(-direction->getVectorx() * 1.1, random(2,4));
  }
}

void Ball::outOfBounds(Scoreboard &score_one, Scoreboard &score_two)
{
  // Give relevant player score when ball goes off the left/right side
  if (sprite.getPosition().x < 0)
  {
    direction->setVector(-direction->getVectorx(), direction->getVectory());
    score_two.scoreUpdate();
    resetPos();
  }
  else if (sprite.getPosition().x + sprite.getGlobalBounds().width > window.getSize().x)
  {
    direction->setVector(-direction->getVectorx(), direction->getVectory());
    score_one.scoreUpdate();
    resetPos();
  }
}

void Ball::resetPos()
{
  sprite.setPosition(window.getSize().x / 2, window.getSize().y / 2);
  direction->setVector(2, random(1, 3));
  int temp = random(1, 2);
  if (temp == 1)
  {
    direction->setVector(2, direction->getVectory());
  }
  else if (temp == 2)
  {
    direction->setVector(-2, direction->getVectory());
  }
}

void Ball::update(float dt, Player &bat, Player &bat2)
{
  movement(dt);
  wallCollision();
  outOfBounds(*bat.getScoreboard(), *bat2.getScoreboard());

  // Only check for collision in a certain direction
  // This stops buggy interactions between the ball and the bat
  if (direction->getVectorx() < 0)
  {
    playerCollision(bat);
  }
  else if (direction->getVectorx() > 0)
  {
    playerCollision(bat2);
  }
}

void Ball::render()
{
  window.draw(sprite);
}

