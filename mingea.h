#pragma once

#include<SFML/Audio.hpp>
#include "jucator_paleta.h"
#include "scor_partida.h"
#include "viteza_depasita.h"
#include<vector>
#include<iostream>

#define VITEZA_MINGE 4.25
#define VITEZA_MAXIMA_MINGE (VITEZA_MINGE * 1.25f)

class mingea : public Entity
{
public:
    mingea(scor_partida* scor1, scor_partida* scor2, paleta* jucator1, paleta* jucator2);
    void operator+=(paleta* paleta);
    void Update(sf::RenderWindow* window);
    void Reset(sf::RenderWindow* window);
    ~mingea();
private:
    std::vector <int> inscrieri;  ///retin ordinea in care a inscris fiecare
    scor_partida* scor1;
    scor_partida* scor2;
    paleta* jucator1;
    paleta* jucator2;
    sf::SoundBuffer* buffer;
    sf::Sound* sunet;
};
