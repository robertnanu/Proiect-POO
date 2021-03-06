#pragma once

#include <SFML/Graphics.hpp>
#include<string>

class Entity : public sf::Sprite
{
public:
    sf::Vector2f velocity;

    Entity()
    {
        this->texture = new sf::Texture();
    }

    void load(std::string filename)
    {
        this->texture->loadFromFile("Grafici/Imagini/" + filename);
        this->setTexture(*this->texture);
    }

    virtual void Update()
    {
        this->move(this->velocity);
    }

    bool VerifColiziune(Entity* entity)
    {
        return this->getGlobalBounds().intersects(entity->getGlobalBounds());
    }

    ~Entity()
    {
        delete this->texture;
    }
private:
    sf::Texture* texture;
};
