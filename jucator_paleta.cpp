#include "jucator_paleta.h"

jucator_paleta::jucator_paleta(int playerNumber)
{
    this->playerNumber = playerNumber;
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

void jucator_paleta::Update()
{
    switch(this->playerNumber)
    {
    case 0:
        this->velocity.y = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) * PALETA_VITEZA;
        break;
    default:
        this->velocity.y = (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) * PALETA_VITEZA;
        break;
    }

    Entity::Update();

    if(this->getPosition().y < 0)
    {
        this->move(0, PALETA_VITEZA);
    }
    if(this->getPosition().y + this->getGlobalBounds().height > 600)
    {
        this->move(0, -PALETA_VITEZA);
    }
}
