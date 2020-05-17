#include "paleta_AI.h"

paleta_AI::paleta_AI(int playerNumber, int dificultate)
{
    this->playerNumber = playerNumber;
    this->mingeObiect = mingeObiect;
    //this->viteza = 2.0f;
    switch(dificultate)
    {
    case 0:
        this->viteza = 0.9f * PALETA_VITEZA;
        break;
    case 1:
        this->viteza = 1.50f * PALETA_VITEZA;
        break;
    default:
        this->viteza = 1.65f * PALETA_VITEZA;
        break;
    }

    switch(this->playerNumber)
    {
    case 0:
        this->load("spongebob.png");
        break;
    default:
        this->load("spongebob.png");
        break;
    }
}

void paleta_AI::SetareMinge(mingea* mingeObiect)
{
    this->mingeObiect = mingeObiect;
}

bool paleta_AI::mingeDeparte()
{
    if(this->playerNumber == 0)
    {
        return this->mingeObiect->velocity.x > 0;
    }
    return this->mingeObiect->velocity.x < 0;
}

void paleta_AI::Update()
{
    if(this->mingeObiect != NULL)
    {
        if(this->mingeDeparte())
        {
            if(tinta.x < 0)
            {
                tinta.x = 1;
                tinta.y = rand() % 600;
            }
            float temp = (this->getPosition().y + this->getGlobalBounds().height / 2) - this->tinta.y;
            if(temp < -MARGINI_MINGE_AI)
            {
                this->velocity.y = this->viteza;
            }
            else if(temp > MARGINI_MINGE_AI)
            {
                this->velocity.y = -this->viteza;
            }
            else
            {
                this->velocity.y = 0;
            }
        }
        else
        {
            tinta = sf::Vector2f(-1,0);
            float temp = (this->getPosition().y + this->getGlobalBounds().height / 2) - this->mingeObiect->getPosition().y;
            if(temp < -MARGINI_MINGE_AI)
            {
                this->velocity.y = this->viteza;
            }
            else if(temp > MARGINI_MINGE_AI)
            {
                this->velocity.y = -this->viteza;
            }
            else
            {
                this->velocity.y = 0;
            }
        }
    }
    Entity::Update();

    if(this->getPosition().y < 0)
    {
        this->move(0, this->viteza);
    }
    if(this->getPosition().y + this->getGlobalBounds().height > 600)
    {
        this->move(0, -this->viteza);
    }
}
