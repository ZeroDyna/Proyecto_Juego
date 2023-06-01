#include <SFML/Graphics.hpp>
#include "Personaje.hpp"
#include "SFML/Audio.hpp"
#include "fondo.hpp"
#include "asteroide.hpp"
#include <SFML/Graphics.hpp>
#include "Personaje.hpp"
#include "SFML/Audio.hpp"
#include "fondo.hpp"
#include "asteroide.hpp"

int main() {
    sf::RenderWindow ventana(sf::VideoMode(1800, 900), "Mi juego");
    ventana.setFramerateLimit(60);

    Personaje personaje(5);
    FondoAleatorio fondo(ventana); // Creamos un objeto FondoAleatorio
    sf::Music music;
    if (!music.openFromFile("revival.ogg")) {
        std::cout << "ERROR" << std::endl;
    }
    music.play();
    
    std::vector<Asteroide> asteroides; // Vector para almacenar los asteroides generados
    sf::Clock temporizador; // Temporizador para generar asteroides cada segundo

    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }
        }

        personaje.mover(ventana);

        // Generar un nuevo asteroide cada 3 segundos
        if (temporizador.getElapsedTime().asSeconds() >= 3.0f) {
            asteroides.emplace_back(30.0f, sf::Vector2f(400.0f, 0.0f), sf::Vector2f(0.0f, 100.0f), ventana);
            temporizador.restart();
        }

        // Actualizar los asteroides existentes
        for (auto& asteroide : asteroides) {
            asteroide.actualizar(1.0f / 60.0f); // Actualizamos cada asteroide con un deltaTime constante de 1/60 (60 FPS)
        }

        ventana.clear(sf::Color::Black);
        fondo.dibujar(); // Dibujamos el fondo antes del personaje
        personaje.dibujar(ventana);

        // Dibujar los asteroides existentes
        for (const auto& asteroide : asteroides) {
            asteroide.dibujar(ventana);
        }

        ventana.display();
    }

    return 0;
}

