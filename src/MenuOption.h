//
// Created by perwi on 26/12/2021.
//

#include <SFML/Graphics.hpp>
#include "Helper.h"
#include <string>

#ifndef PONGSFML_MENUOPTION_H
#define PONGSFML_MENUOPTION_H

enum MENUOPTION {ONEPLAYER = 0, TWOPLAYER = 1, QUIT = 2};

class MenuOption
{
 public:
  MenuOption(MENUOPTION _option, const std::string& string, sf::Font& font,
             int char_size, float x, float y, bool selection);
  sf::Text getText();
  void setSelected(bool select);
  void update();

 private:
  bool selected;
  MENUOPTION option;
  sf::Text text;
  const sf::Color Cdefaut = sf::Color::White;
  const sf::Color Cselected = sf::Color::Blue;
};

#endif // PONGSFML_MENUOPTION_H
