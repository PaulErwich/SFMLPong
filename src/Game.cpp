
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
  srand(time(NULL));
  game_menu = new GameMenu(STATE::GAME_MENU, game_window);
  game_play_player = new GamePlayPlayer(STATE::GAME_PLAY, game_window, 1);
  game_over = new GameOver(STATE::GAME_OVER, game_window);
  game_play_ai = new GamePlayAI(STATE::GAME_PLAY_AI, game_window, 1);
  game_paused = new GamePaused(STATE::GAME_PAUSED, game_window);
  current_game = nullptr;
  current_state = game_menu;
  winner = WINNER::DEFAULT;
}

Game::~Game()
{
  delete game_menu;
  delete game_play_player;
  delete game_over;
  delete game_play_ai;
  delete current_state;
  delete game_paused;
  delete current_game;
}

void Game::checkGame(STATE state_id)
{
  switch(state_id)
  {
    case STATE::GAME_PLAY:
      current_game = game_play_player;
      break;
    case STATE::GAME_PLAY_AI:
      current_game = game_play_ai;
      break;
    default:
      break;
  }
}

void Game::assignWinner(Player *p1, Player *p2, Player *ai)
{
  if (p1->getScoreboard()->getScore() >= GamePlay::getWin())
  {
    winner = WINNER::P1;
  }
  else if (p2->getScoreboard()->getScore() >= GamePlay::getWin())
  {
    winner = WINNER::P2;
  }
  else if (ai->getScoreboard()->getScore() >= GamePlay::getWin())
  {
    winner = WINNER::AI;
  }
  else
  {
    winner = WINNER::DEFAULT;
  }
}

void Game::switchState(STATE state_id)
{
  checkGame(state_id);

  switch(state_id)
  {
    case STATE::GAME_EXIT:
      window.close();
      break;
    case STATE::GAME_MENU:
      current_game = nullptr;
      winner = WINNER::DEFAULT;
      game_play_player->reset();
      game_play_ai->reset();
      current_state = game_menu;
      break;
    case STATE::GAME_PLAY:
      current_state = game_play_player;
      break;
    case STATE::GAME_PLAY_AI:
      current_state = game_play_ai;
      break;
    case STATE::GAME_PAUSED:
      game_paused->setGame(*current_game);
      current_state = game_paused;
      break;
    case STATE::GAME_OVER:
      if (current_game->getStateID() == STATE::GAME_PLAY)
      {
        assignWinner(game_play_player->getPlayer(), game_play_player->getP2(), game_play_ai->getAI());
      }
      else if (current_game->getStateID() == STATE::GAME_PLAY_AI)
      {
        assignWinner(game_play_ai->getPlayer(), game_play_player->getP2(), game_play_ai->getAI());
      }
      game_over->setWinner(winner);
      current_state = game_over;
      break;
    default:
      break;
  }
}

void Game::input(sf::Event event)
{
  if (event.type == sf::Event::KeyPressed)
  {
    switchState(current_state->input(event));
  }
  else if (event.type == sf::Event::KeyReleased)
  {
    game_play_player->keyReleased(event);
    game_play_ai->keyReleased(event);
  }
}

void Game::update(float dt)
{
  switchState(current_state->update(dt));
}

void Game::render()
{
  current_state->render();
}



