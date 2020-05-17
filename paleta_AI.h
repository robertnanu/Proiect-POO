#pragma once

#include "paleta.h"
#include "mingea.h"

#define MARGINI_MINGE_AI 10.0f

class paleta_AI : public paleta
{
public:
    paleta_AI(int playerNumber, int dificultate);
    void SetareMinge(mingea* mingeObiect);
    void Update();
private:
    sf::Vector2f tinta;
    mingea* mingeObiect;
    int playerNumber;
    float viteza;
    bool mingeDeparte();
};

