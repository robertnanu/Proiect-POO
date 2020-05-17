#pragma once

#include "statut_joc.h"
#include "jucator_paleta.h"
#include "paleta_AI.h"
#include "mingea.h"
#include "scor_partida.h"

class main_game : public primul_statut
{
public:
    main_game(int mod) : primul_statut()
    {
        this->aiDificultate = mod;
    };
    void Initializare(sf::RenderWindow* window);
    void Update(sf::RenderWindow* window);
    void Render(sf::RenderWindow* window);
    void Distruge(sf::RenderWindow* window);
private:
    int aiDificultate;
    jucator_paleta* jucator1;
    paleta_AI* jucator2;
    mingea* mingeObiect;
    scor_partida* scor1;
    scor_partida* scor2;

    sf::Text* numaratoare;

    sf::Font* font;

    sf::Clock startNumaratoare;
    sf::Time startElapsed;

    bool paused, enterKey;
};
