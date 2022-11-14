//
// Created by p2-erwich on 17/12/2021.
//

#include <SFML/Graphics.hpp>

#ifndef PONGSFML_HELPER_H
#define PONGSFML_HELPER_H

class Helper
{
public:
    static void SFMLText(sf::Text& text, const std::string& string, sf::Font& font,
                      int char_size, sf::Color color, float x, float y);
};

#endif //PONGSFML_HELPER_H
