#include<SFML/Audio.hpp>
#include "statut_joc.h"
#include "main_menu.h"
#include <time.h>

void sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

statut_joc coreState;
bool quitGame = false;

#include<iostream>

int main()
{
    try{
         sf::RenderWindow window(sf::VideoMode(800, 600), "Sponge-Ping");

        coreState.SetareWindow(&window);
        coreState.SetareStatut(new main_menu());

        sf::Clock timer;
        sf::Time elapsed;

        sf::SoundBuffer musicBuffer;
        musicBuffer.loadFromFile("Sunete/battle_music.wav");
        sf::Sound music(musicBuffer);

        music.setLoop(true);
        music.play();

        // run the program as long as the window is open
        while (window.isOpen())
        {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window.pollEvent(event))
            {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            elapsed = timer.getElapsedTime();

            if(elapsed.asMicroseconds() > 16666)
            {
                window.clear(sf::Color::Blue);

                coreState.Update();
                coreState.Render();

                window.display();

                if(quitGame)
                {
                    window.close();
                }
                timer.restart();
            }

            //sleep(5000);
        }

        music.stop();
    } catch(std::exception& e ) {
        std::cout << e.what();
    }
    return 0;
}
