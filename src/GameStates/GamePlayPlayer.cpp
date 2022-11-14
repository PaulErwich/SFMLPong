//
// Created by perwi on 27/12/2021.
//

#include "GamePlayPlayer.h"
GamePlayPlayer::GamePlayPlayer(STATE stateId, sf::RenderWindow& game_window, int ball_number) :
  GamePlay(stateId, game_window, ball_number)
{
  player_two = new PlayerTwo(window, window.getSize().x - 200,
                                 50);
}

GamePlayPlayer::~GamePlayPlayer()
{
  delete player_two;
}

void GamePlayPlayer::reset()
{
  GamePlay::reset();
  player_two->reset();
}

Player* GamePlayPlayer::getP2() {return player_two;}

void GamePlayPlayer::keyReleased(sf::Event event)
{
  GamePlay::keyReleased(event);
  player_two->keyReleased(event);
}

STATE GamePlayPlayer::input(sf::Event event)
{
  player_two->keyPressed(event);
  return GamePlay::input(event);
}

STATE GamePlayPlayer::update(float dt)
{
  player_one->update(dt);
  player_two->update(dt);
  for (int i = 0; i < number_of_balls; i++)
  {
    ball[i]->update(dt, *player_one, *player_two);
  }

  if (player_two->getScoreboard()->getScore() == WIN)
  {
    return STATE::GAME_OVER;
  }
  return GamePlay::update(dt);
}

void GamePlayPlayer::render()
{
  GamePlay::render();
  player_two->render();
}
