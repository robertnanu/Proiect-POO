#pragma once

#include "paleta.h"

class jucator_paleta : public paleta
{
public:
    jucator_paleta(int playerNumber);
    void Update();
private:
    int playerNumber;
};
