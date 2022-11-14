
#ifndef PONG_GAME_H
#define PONG_GAME_H

#include <SFML/Graphics.hpp>
#include "GameStates/GameStateBase.h"
#include "GameStates/GameMenu.h"
#include "GameStates/GamePlayPlayer.h"
#include "GameStates/GameOver.h"
#include "GameStates/GamePlayAI.h"
#include "GameStates/GamePaused.h"

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  void checkGame(STATE state_id);
  void assignWinner(Player *p1, Player *p2, Player *ai);
  void switchState(STATE state_id);
  void input(sf::Event event);
  void update(float dt);
  void render();

 private:
  sf::RenderWindow& window;
  GameMenu *game_menu;
  GamePlayPlayer *game_play_player;
  GameOver *game_over;
  GamePlayAI *game_play_ai;
  GameStateBase *current_state;
  GamePaused *game_paused;
  GamePlay *current_game;
  WINNER winner;
};

#endif // PONG_GAME_H
