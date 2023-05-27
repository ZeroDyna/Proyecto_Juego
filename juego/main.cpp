#include <SFML/Graphics.hpp>
#include "Personaje.hpp"
#include "SFML/Audio.hpp"
#include "fondo.hpp"
int main() {
    sf::RenderWindow ventana(sf::VideoMode(1800, 920), "Mi juego");
    ventana.setFramerateLimit(60);

    Personaje personaje(5);
    FondoAleatorio fondo(ventana); // Creamos un objeto FondoAleatorio
    sf::Music music;
    if (!music.openFromFile("revival.ogg")){
        std::cout << "ERROR" << std::endl;
    }
    music.play();
    
    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }
        }

        personaje.mover(ventana);

        ventana.clear(sf::Color::Black);
        fondo.dibujar(); // Dibujamos el fondo antes del personaje
        personaje.dibujar(ventana);
        ventana.display();
    }

    return 0;
}
