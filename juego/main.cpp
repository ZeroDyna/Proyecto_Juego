#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include "Personaje.hpp"
#include "disparo.hpp"
#include "fondo.hpp"
#include "asteroide.hpp"
#include <random>

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
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> disX(0.0f, static_cast<float>(ventana.getSize().x));
    std::uniform_real_distribution<float> disVelocidad(50.0f, 200.0f);
    std::uniform_real_distribution<float> disRadio(20.0f, 40.0f);

    int colisiones = 0;

    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }
        }

        personaje.mover(ventana);
        // Generar un nuevo asteroide cada segundo
        if (temporizador.getElapsedTime().asSeconds() >= 1.0f) {
            float posX = disX(gen);
            float velocidadY = 500.0f; // Cambia este valor para ajustar la velocidad de caída
            float radio = disRadio(gen);
            asteroides.emplace_back(radio, sf::Vector2f(posX, 0.0f), sf::Vector2f(0.0f, velocidadY), &ventana);
            temporizador.restart();
        }

        // Generar un disparo al presionar la tecla "S"
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            sf::Vector2f posicionPersonaje = personaje.getPosicion();
            float anguloPersonaje = personaje.getAngulo();
            Disparo disparo(10.0f, anguloPersonaje - 90 , posicionPersonaje);
            disparos.push_back(disparo);
        }

        // Actualizar los asteroides existentes
        for (auto it = asteroides.begin(); it != asteroides.end();) {
            it->actualizar(1.0f / 60.0f);

            // Comprobar colisión entre asteroide y disparos
            bool colision = false;
            for (auto itDisparo = disparos.begin(); itDisparo != disparos.end(); ++itDisparo) {
                if (itDisparo->colisiona(it->obtenerLimitesGlobales())) {
                    colision = true;
                    itDisparo = disparos.erase(itDisparo);
                    break;  // Romper el bucle al encontrar una colisión
                }
            }

            if (colision) {
                it = asteroides.erase(it);
                colisiones++;
            } else {
                ++it;
            }
        }

        // Actualizar los disparos existentes
        for (auto& disparo : disparos) {
            disparo.mover();
        }

        ventana.clear(sf::Color::Black);
        fondo.dibujar();
        personaje.dibujar(ventana);

        // Dibujar los asteroides existentes
        for (const auto& asteroide : asteroides) {
            asteroide.dibujar(ventana);
        }

        // Dibujar los disparos existentes
        for (const auto& disparo : disparos) {
            disparo.dibujar(ventana);
        }

        ventana.display();
    }

    return 0;
}

