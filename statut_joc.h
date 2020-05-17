#pragma once

#include<SFML/Graphics.hpp>

class primul_statut
{
public:
    virtual void Initializare(sf::RenderWindow* window) = 0;

    virtual void Update(sf::RenderWindow* window) = 0;

    virtual void Render(sf::RenderWindow* window) = 0;

    virtual void Distruge(sf::RenderWindow* window) = 0;
};

class statut_joc
{
public:
    statut_joc()
    {
        this->statut = NULL;
    }

    void SetareWindow(sf::RenderWindow* window)
    {
        this->window = window;
    }

    void SetareStatut(primul_statut* statut)
    {
        if(this->statut != NULL)
        {
            this->statut->Distruge(this->window);
        }
        this->statut = statut;
        if(this->statut != NULL)
        {
            this->statut->Initializare(this->window);
        }
    }

    void Update()
    {
        if(this->statut != NULL)
        {
            this->statut->Update(this->window);
        }
    }
    void Render()
    {
        if(this->statut != NULL)
        {
            this->statut->Render(this->window);
        }
    }

    ~statut_joc()
    {
        if(this->statut != NULL)
        {
            this->statut->Distruge(this->window);
        }
    }
private:
    sf::RenderWindow* window;
    primul_statut* statut;
};

extern statut_joc coreState;
extern bool quitGame;


