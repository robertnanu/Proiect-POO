#include<iostream>
#include "main_menu.h"
#include "main_game.h"

void main_menu::Initializare(sf::RenderWindow* window)
{
    this->selectat = 0;
    this->mod = 0;

    this->marime = 1;
    this->marimeIncrementare = VITEZA_MARIME;

    this->font = new sf::Font();
    this->font->loadFromFile("font.ttf");

    this->title = new sf::Text("Sponge-Pong", *this->font, 280U);
    this->title->setOrigin(this->title->getGlobalBounds().width / 2, this->title->getGlobalBounds().height / 2);
    this->title->setPosition(window->getSize().x / 2, window->getSize().y / 20);

    this->play = new sf::Text("Easy", *this->font, 128U);
    this->play->setOrigin(this->play->getGlobalBounds().width / 2, this->play->getGlobalBounds().height / 2);
    this->play->setPosition(window->getSize().x / 2 /*- 90*/, window->getSize().y / 2);

    this->quit = new sf::Text("Quit", *this->font, 128U);
    this->quit->setOrigin(this->quit->getGlobalBounds().width / 2, this->quit->getGlobalBounds().height / 2);
    this->quit->setPosition(window->getSize().x / 2 - 5, window->getSize().y / 2 + this->play->getGlobalBounds().height + 20);
}
void main_menu::Update(sf::RenderWindow* window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !this->upKey)
    {
        this->selectat -= 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !this->downKey)
    {
        this->selectat += 1;
    }
    if(this->selectat > 1)
    {
        this->selectat = 0;
    }
    if(this->selectat < 0)
    {
        this->selectat = 1;
    }

    if(this->selectat == 0)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !this->leftKey)
        {
            this->mod -= 1;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && !this->rightKey)
        {
            this->mod += 1;
        }

        if(this->mod > 2)
        {
            this->mod = 0;
        }
        if(this->mod < 0)
        {
            this->mod = 2;
        }
    }

    switch(this->mod)
    {
    case 0:
        this->play->setString("Easy");
        this->play->setPosition(window->getSize().x / 2 /*- 90*/, window->getSize().y / 2);
        break;
    case 1:
        this->play->setString("Medium");
        this->play->setPosition(window->getSize().x / 2 - 50, window->getSize().y / 2);
        break;
    case 2:
        this->play->setString("Hard");
        this->play->setPosition(window->getSize().x / 2 - 10, window->getSize().y / 2);
        break;
    }

    this->play->setScale(1, 1);
    this->quit->setScale(1, 1);

    switch(this->selectat)
    {
    case 0:
        this->play->setScale(this->marime, this->marime);
        break;
    case 1:
        this->quit->setScale(this->marime, this->marime);
        break;
    }

    this->marime += this->marimeIncrementare;

    if(this->marime > 1.0f + MAX_MARIME || this->marime < 1.0f - MAX_MARIME)
    {
        this->marimeIncrementare *= -1;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
    {
        switch(this->selectat)
        {
        case 0:
            coreState.SetareStatut(new main_game(this->mod));
            break;
        case 1:
            quitGame = true;
            break;
        }
    }

    this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
    this->leftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
    this->rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}
void main_menu::Render(sf::RenderWindow* window)
{
    this->play->setColor(sf::Color::White);
    this->quit->setColor(sf::Color::White);
    switch(this->selectat)
    {
    case 0:
        this->play->setColor(sf::Color::Yellow);
        break;
    case 1:
        this->quit->setColor(sf::Color::Yellow);
        break;
    }
    window->draw(*this->title);
    window->draw(*this->play);
    window->draw(*this->quit);
}
void main_menu::Distruge(sf::RenderWindow* window)
{
    delete this->font;
    delete this->title;
    delete this->play;
    delete this->quit;
}
