#include "mingea.h"
#include "smart_pointer.h"
#include "Singleton.h"

mingea::mingea(scor_partida* scor1, scor_partida* scor2, paleta* jucator1, paleta* jucator2)
{
    this->load("rsz_minge_caterinca_finala.png");
    this->scor1 = scor1;
    this->scor2 = scor2;
    this->jucator1 = jucator1;
    this->jucator2 = jucator2;


    this->buffer = new sf::SoundBuffer();
    this->buffer->loadFromFile("Sunete/bounce.wav");
    this->sunet = new sf::Sound(*this->buffer);
}

void mingea::operator+=(paleta* paleta)
{
    if(abs(this->velocity.y) < VITEZA_MAXIMA_MINGE)
        {
            if(this->velocity.y > 0)
            {
                if(paleta->velocity.y > 0)
                {
                    this->velocity.y += this->velocity.y * 1.05f;
                }
                else if(paleta->velocity.y < 0)
                {
                    this->velocity.y += this->velocity.y * -1.05f;
                }
            }
            else if(this->velocity.y < 0)
            {
                if(paleta->velocity.y > 0)
                {
                    this->velocity.y += this->velocity.y * -1.05f;
                }
                else if(paleta->velocity.y < 0)
                {
                    this->velocity.y += this->velocity.y * 1.05f;
                }
            }
        }
        else
        {
                throw(viteza_depasita("Viteza maxima a fost depasita."));
        }
}

void mingea::Update(sf::RenderWindow* window)
{
    if(this->VerifColiziune(this->jucator1))
    {
        this->velocity.x *= -1;
        *this += this->jucator1;
        this->sunet->play();
    }
    if(this->VerifColiziune(this->jucator2))
    {
        this->velocity.x *= -1;
        *this += this->jucator2;
        this->sunet->play();
    }
    if(this->getPosition().y < 0 || this->getPosition().y + this->getGlobalBounds().height > window->getSize().y)
    {
        this->velocity.y *= -1;
        this->sunet->play();
    }

    if(this->getPosition().x < this->jucator1->getGlobalBounds().width - 25/*70*/)
    {
        this->inscrieri.push_back(2);
        this->scor2->CresteScor();
        this->Reset(window);
    }
    if(this->getPosition().x + this->getGlobalBounds().width> window->getSize().x - this->jucator2->getGlobalBounds().width + 25)
    {
        this->inscrieri.push_back(1);
        this->scor1->CresteScor();
        this->Reset(window);
    }
    if(this->scor1->getScore() == 3 || this->scor2->getScore() == 3)
    {
        std::unique_ptr<Entitate> entitate = std::make_unique<Entitate>();
        entitate->Print();
        this->scor1->setScor();
        this->scor2->setScor();
        for(int i=0;i<inscrieri.size();++i)
            std::cout<<inscrieri[i]<<' ';
        std::cout<<std::endl;
        std::cout<<"castigatorul este: jucatorul ";
        float number = Random::Float();
        std::cout<<number<<std::endl;
        this->Reset(window);
    }
    Entity::Update();
}

void mingea::Reset(sf::RenderWindow* window)
{
    this->velocity.x = VITEZA_MINGE;
    this->velocity.y = ((rand() % 2) == 0) ? VITEZA_MINGE : VITEZA_MINGE;
    this->setPosition(window->getSize().x / 2, window->getSize().y / 2);
    this->jucator2->setPosition(window->getSize().x - this->jucator2->getGlobalBounds().width, window->getSize().y / 2 + this->jucator2->getGlobalBounds().height / 4);
    this->jucator1->setPosition(0, window->getSize().y / 2 + this->jucator1->getGlobalBounds().height / 4);
}

mingea::~mingea()
{
    delete this->sunet;
    delete this->buffer;
}
