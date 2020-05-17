#include "scor_partida.h"

scor_partida::scor_partida(sf::Font &font, unsigned int size) : sf::Text("scor_partida: 0", font, size)
{
    this->valoare = 0;
}

void scor_partida::CresteScor()
{
    this->valoare += 1;
}

void scor_partida::Update()
{
    this->setString("Scor: " + std::to_string(this->valoare));
}


int scor_partida::getScore()
{
    return valoare;
}

void scor_partida::setScor()
{
    this->valoare=0;
}
