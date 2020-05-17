#pragma once

#include "statut_joc.h"

#define VITEZA_MARIME 0.016f
//#define MIN_MARIME 0.7f
#define MAX_MARIME 0.26

class main_menu : public primul_statut
{
public:
    void Initializare(sf::RenderWindow* window);
    void Update(sf::RenderWindow* window);
    void Render(sf::RenderWindow* window);
    void Distruge(sf::RenderWindow* window);
private:
    sf::Font* font;
    sf::Text* title;
    sf::Text* play;
    sf::Text* quit;

    int selectat;
    int mod;

    float marime;
    float marimeIncrementare;

    bool upKey, downKey, leftKey, rightKey;

    void UpdateMod(sf::RenderWindow* window);
};
