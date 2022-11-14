//
// Created by perwi on 27/12/2021.
//

#include "GamePlayAI.h"
GamePlayAI::GamePlayAI(
  STATE stateId, sf::RenderWindow& game_window, int ball_number) :
  GamePlay(stateId, game_window, ball_number)
{
  player_ai = new PlayerAI(window, window.getSize().x - 200, 50);
}

GamePlayAI::~GamePlayAI()
{
  delete player_ai;
}

void GamePlayAI::reset()
{
  GamePlay::reset();
  player_ai->reset();
}

Player* GamePlayAI::getAI() {return player_ai;}

STATE GamePlayAI::update(float dt)
{
  player_one->update(dt);
  player_ai->update(dt, *ball[0]);
  for (int i = 0; i < number_of_balls; i++)
  {
    ball[i]->update(dt, *player_one, *player_ai);
  }

  if (player_ai->getScoreboard()->getScore() == WIN)
  {
    return STATE::GAME_OVER;
  }
  return GamePlay::update(dt);
}

void GamePlayAI::render()
{
  GamePlay::render();
  player_ai->render();
}
