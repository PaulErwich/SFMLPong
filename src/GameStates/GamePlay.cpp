//
// Created by MLG Erwich on 30/11/2021.
//

#include "GamePlay.h"

GamePlay::GamePlay(
  STATE stateId, sf::RenderWindow &game_window, int ball_number) :
  GameStateBase(stateId, game_window)
{
  player_one = new PlayerOne(game_window, 200, 50);

  number_of_balls = ball_number;

  for(int i = 0; i < number_of_balls; i++)
  {
    ball[i] = new Ball(game_window);
  }
  init();
}

GamePlay::~GamePlay()
{
  delete player_one;
  for (int i = 0; i < number_of_balls; i++)
  {
    delete ball[i];
  }
  //delete ball;
}

bool GamePlay::init()
{
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "Font didn't load" << std::endl;
    return false;
  }

  Helper::SFMLText(text, "Press P to pause", font, 20, sf::Color::White,
                   window.getSize().x / 2, 50);

  return true;
}

void GamePlay::reset()
{
  player_one->reset();
  for (int i = 0; i < number_of_balls; i++)
  {
    ball[i]->resetPos();
  }
  //ball->resetPos();
}

Player* GamePlay::getPlayer() {return player_one;}

int GamePlay::getWin() {return WIN;}

void GamePlay::keyReleased(sf::Event event)
{
  player_one->keyReleased(event);
}

STATE GamePlay::input(sf::Event event)
{
  player_one->keyPressed(event);
  if (event.key.code == sf::Keyboard::P)
  {
    return STATE::GAME_PAUSED;
  }
  return game_state_id;
}

STATE GamePlay::update(float dt)
{
  //ball->update(dt, *player_one, *player_two);
  if (player_one->getScoreboard()->getScore() == WIN)
  {
      return STATE::GAME_OVER;
  }
  return game_state_id;
}

void GamePlay::render()
{
  for (int i = 0; i < number_of_balls; i++)
  {
    ball[i]->render();
  }
  player_one->render();
  window.draw(text);
}

