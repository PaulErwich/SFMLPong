//
// Created by perwi on 26/12/2021.
//
#include <SFML/Graphics.hpp>

#ifndef PONGSFML_GAMESTATEBASE_H
#define PONGSFML_GAMESTATEBASE_H

// Enum for the different states in my game
enum class STATE {GAME_UNKNOWN = -1, GAME_EXIT = 0, GAME_MENU = 1, GAME_PLAY = 2,
  GAME_PLAY_AI = 3, GAME_PAUSED = 4, GAME_OVER = 5};

// Setting up a base class for my game screens/states
// This allows me to create a state machine within the "Game" class
class GameStateBase
{
 public:
  GameStateBase(STATE state_id, sf::RenderWindow &game_window);
  ~GameStateBase();
  STATE getStateID();
  virtual STATE input(sf::Event event);
  virtual STATE update(float dt);
  virtual void render();

 protected:
  STATE game_state_id;
  sf::RenderWindow &window;
};

#endif // PONGSFML_GAMESTATEBASE_H
