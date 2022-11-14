//
// Created by MLG Erwich on 30/11/2021.
//

#include "GameOver.h"

GameOver::GameOver(
  STATE stateId, sf::RenderWindow &game_window) :
  GameStateBase(stateId, game_window)
{
  game_play = nullptr;
  winner = WINNER::P1;
  init();
}

GameOver::~GameOver()
{
  delete game_play;
}

bool GameOver::init()
{
  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "Font didn't load" << std::endl;
    return false;
  }

  Helper::SFMLText(text, "GAME OVER!", font, 60, sf::Color::White,
                   window.getSize().x / 2, window.getSize().y / 4);
  Helper::SFMLText(text_winner, "FAILED TO ASSIGN WINNER", font, 60, sf::Color::White,
                   window.getSize().x / 2, window.getSize().y / 2);

  return true;
}

void GameOver::setWinner(WINNER _winner) {winner = _winner;}

void GameOver::setGame(GamePlay& game) {game_play = &game;}

STATE GameOver::input(sf::Event event)
{
  if (event.key.code == sf::Keyboard::Enter)
  {
    return STATE::GAME_MENU;
  }
  return game_state_id;
}

STATE GameOver::update(float dt)
{
  switch (winner)
  {
    case WINNER::P1:
      text_winner.setString("PLAYER 1 WINS");
      break;
    case WINNER::P2:
      text_winner.setString("PLAYER 2 WINS");
      break;
    case WINNER::AI:
      text_winner.setString("AI WINS");
      break;
    default:
      text_winner.setString("FAILED TO ASSIGN WINNER");
      break;
  }
  return game_state_id;
}

void GameOver::render()
{
  window.draw(text);
  window.draw(text_winner);
}
