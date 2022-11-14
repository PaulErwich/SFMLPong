//
// Created by perwi on 26/12/2021.
//

#include "MenuOption.h"
MenuOption::MenuOption(
  MENUOPTION _option, const std::string& string, sf::Font& font, int char_size,
  float x, float y, bool selection)
{
  selected = selection;
  option = _option;
  Helper::SFMLText(text, string, font, char_size, Cdefaut, x, y);
}

sf::Text MenuOption::getText() {return text;}

void MenuOption::setSelected(bool select) {selected = select;}

void MenuOption::update()
{
  if (selected)
  {
    text.setFillColor(Cselected);
  }
  else
    text.setFillColor(Cdefaut);
}
