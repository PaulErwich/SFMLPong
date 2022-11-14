//
// Created by perwi on 27/12/2021.
//

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GamePlay.h"
#include "../Player/PlayerTwo.h"

#ifndef PONGSFML_GAMEPLAYPLAYER_H
#define PONGSFML_GAMEPLAYPLAYER_H

class GamePlayPlayer : public GamePlay
{
 public:
  GamePlayPlayer(STATE stateId, sf::RenderWindow &game_window, int ball_number);
  ~GamePlayPlayer();
  void reset() override;
  Player* getP2();
  void keyReleased(sf::Event event) override;
  STATE input(sf::Event event) override;
  STATE update(float dt) override;
  void render() override;

 private:
  PlayerTwo *player_two;
};

#endif // PONGSFML_GAMEPLAYPLAYER_H
