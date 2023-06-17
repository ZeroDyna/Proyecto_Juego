#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include "Personaje.hpp"
#include "disparo.hpp"
#include "fondo.hpp"
#include "asteroide.hpp"

int main() {
    sf::RenderWindow ventana(sf::VideoMode(1800, 900), "Mi juego");
    ventana.setFramerateLimit(60);

    Personaje personaje(5);
    FondoAleatorio fondo(ventana);
    sf::Music music;
    if (!music.openFromFile("revival.ogg")) {
        std::cout << "ERROR" << std::endl;
    }
    music.play();
    
    std::vector<Asteroide> asteroides;
    std::vector<Disparo> disparos;

    sf::Clock temporizador;

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

        // Generar un disparo al presionar la tecla "s"
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            sf::Vector2f posicionPersonaje = personaje.getPosicion();
            float anguloPersonaje = personaje.getAngulo();
            Disparo disparo(10.0f, anguloPersonaje, posicionPersonaje);
            disparos.push_back(disparo);
        }

        // Actualizar los asteroides existentes
        for (auto& asteroide : asteroides) {
            asteroide.actualizar(1.0f / 60.0f);
        }

        ventana.clear(sf::Color::Black);
        fondo.dibujar();
        personaje.dibujar(ventana);

        // Dibujar los asteroides existentes
        for (const auto& asteroide : asteroides) {
            asteroide.dibujar(ventana);
        }

        // Actualizar y dibujar los disparos existentes
        for (auto& disparo : disparos) {
            disparo.mover();
            disparo.dibujar(ventana);
        }

        ventana.display();
    }

    return 0;
}

