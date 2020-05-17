#include "main_game.h"
#include "main_menu.h"

void main_game::Initializare(sf::RenderWindow* window)
{
    this->font = new sf::Font();
    this->font->loadFromFile("font.ttf");
    this->scor1 = new scor_partida(*font, 64U);
    this->scor2 = new scor_partida(*font, 64U);

    this->numaratoare = new sf::Text("Paused\nPress Escape to Quit", *font, 80U);
	this->numaratoare->setOrigin(this->numaratoare->getGlobalBounds().width / 2, this->numaratoare->getGlobalBounds().height / 2);
	this->numaratoare->setPosition(window->getSize().x / 2, window->getSize().y / 2);


    this->scor2->setPosition(window->getSize().x - this->scor2->getGlobalBounds().width, 0);


    this->jucator1 = new jucator_paleta(0);


    this->jucator2 = new paleta_AI(1, aiDificultate);

    this->mingeObiect = new mingea(this->scor1, this->scor2, this->jucator1, this->jucator2);

    //this->jucator2->SetareMinge(this->mingeObiect);
    if (typeid(*this->jucator2) == typeid(paleta_AI))
	{
		(reinterpret_cast<paleta_AI*>(this->jucator2))->SetareMinge(this->mingeObiect);
	}
    this->mingeObiect->Reset(window);
}
void main_game::Update(sf::RenderWindow* window)
{
    this->startElapsed = this->startNumaratoare.getElapsedTime();
    if(this->startElapsed.asSeconds() > 4)
    {
        this->mingeObiect->Update(window);
        this->jucator1->Update();
        this->jucator2->Update();
        this->scor1->Update();
        this->scor2->Update();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        {
            coreState.SetareStatut(new main_menu());
        }
        this->numaratoare->setOrigin(this->numaratoare->getGlobalBounds().width / 2, this->numaratoare->getGlobalBounds().height / 2);
        this->numaratoare->setPosition(800 / 2 + 18, 600 / 2 -100);
    }
    else
    {
        switch((int)this->startElapsed.asSeconds())
        {
        case 0:
            this->numaratoare->setString("3");
            break;
        case 1:
            this->numaratoare->setString("2");
            break;
        case 2:
            this->numaratoare->setString("1");
            break;
        default:
            this->numaratoare->setString("GO!");
            break;
        }
        this->numaratoare->setOrigin(this->numaratoare->getGlobalBounds().width / 2, this->numaratoare->getGlobalBounds().height / 2);
        this->numaratoare->setPosition(800 / 2 + 18, 600 / 2 - 100);
    }
}
void main_game::Render(sf::RenderWindow* window)
{
    window->draw(*this->mingeObiect);
    window->draw(*this->jucator1);
    window->draw(*this->jucator2);
    window->draw(*this->scor1);
    window->draw(*this->scor2);

    this->startElapsed = this->startNumaratoare.getElapsedTime();
    if(this->startElapsed.asSeconds() < 4)
    {
        window->draw(*this->numaratoare);
    }
}
void main_game::Distruge(sf::RenderWindow* window)
{
    delete this->jucator1;
    delete this->jucator2;
    delete this->mingeObiect;
    delete this->scor1;
    delete this->scor2;
    delete this->font;
}
