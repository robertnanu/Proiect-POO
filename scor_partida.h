#pragma once

#include<SFML/Graphics.hpp>

class scor_partida : public sf::Text
{
public:
    scor_partida(sf::Font &font, unsigned int size);
    void CresteScor();
    void Update();
    int getScore();
    void setScor();
private:
    int valoare;
};
