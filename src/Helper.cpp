//
// Created by p2-erwich on 17/12/2021.
//

#include "Helper.h"

void Helper::SFMLText(sf::Text& text, const std::string& string, sf::Font& font, int char_size, sf::Color color, float x, float y)
{
    text.setString(string);
    text.setFont(font);
    text.setCharacterSize(char_size);
    text.setFillColor(color);
    text.setPosition(x - text.getGlobalBounds().width / 2, y);
}



