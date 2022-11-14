//
// Created by perwi on 27/12/2021.
//

#include "../Ball.h"
#include "../Player/PlayerOne.h"
#include "../Player/PlayerAI.h"
#include "GamePlay.h"
#include <SFML/Graphics.hpp>

#ifndef PONGSFML_GAMEPLAYAI_H
#define PONGSFML_GAMEPLAYAI_H

class GamePlayAI : public GamePlay
{
 public:
  GamePlayAI(STATE stateId, sf::RenderWindow &game_window, int ball_number);
  ~GamePlayAI();
  void reset() override;
  Player* getAI();
  STATE update(float dt) override;
  void render() override;

 private:
  PlayerAI *player_ai;
};

#endif // PONGSFML_GAMEPLAYAI_H
