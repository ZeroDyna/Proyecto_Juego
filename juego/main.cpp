#include <SFML/Graphics.hpp>
#include "Personaje.hpp"

int main()
{
    sf::RenderWindow ventana(sf::VideoMode(800, 600), "Mi juego");

    Personaje jugador(sf::Vector2f(400, 300), sf::Vector2f(50, 50), sf::Color::Red);

    while (ventana.isOpen())
    {
        sf::Event evento;
        while (ventana.pollEvent(evento))
        {
            if (evento.type == sf::Event::Closed)
            {
                ventana.close();
            }
        }

        sf::Vector2f direccion(0.f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            direccion.y -= 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            direccion.y += 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            direccion.x -= 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            direccion.x += 1.f;
        }

        jugador.mover(direccion);

        ventana.clear();
        jugador.dibujar(ventana);
        ventana.display();
    }

    return 0;
}

