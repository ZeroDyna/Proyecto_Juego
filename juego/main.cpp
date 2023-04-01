#include <SFML/Graphics.hpp>
#include "Personaje.hpp"

int main() {
    sf::RenderWindow ventana(sf::VideoMode(1800, 920), "Mi juego");
    ventana.setFramerateLimit(60);

    Personaje personaje(5);

    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }
        }

        personaje.mover(ventana);

        ventana.clear(sf::Color::Black);
        personaje.dibujar(ventana);
        ventana.display();
    }

    return 0;
}


