#include <iostream>
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include "Personaje.hpp"
#include "disparo.hpp"
#include "fondo.hpp"
#include "asteroide.hpp"
#include "pantalla_inicio.hpp"
#include "cometa.hpp"
#include <random>

int main()
{
    sf::RenderWindow ventana(sf::VideoMode(1800, 900), "Mi juego");
    ventana.setFramerateLimit(60);

    Personaje personaje(5, ventana);
    float retrasoCambio = 5.0f; // Tiempo de retraso entre cambios de fondo
    FondoAleatorio fondo(ventana, retrasoCambio);
    sf::Music music;
    if (!music.openFromFile("revival.ogg")) {
        std::cout << "ERROR" << std::endl;
    }
    music.play();

    std::vector<Asteroide> asteroides;
    std::vector<Disparo> disparos;
    std::vector<Cometa> cometas;

    sf::Clock temporizador;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> disX(0.0f, static_cast<float>(ventana.getSize().x));
    std::uniform_real_distribution<float> disVelocidad(50.0f, 200.0f);
    std::uniform_real_distribution<float> disRadio(20.0f, 40.0f);

    int colisiones = 0;

    PantallaInicio pantallaInicio(ventana);
    bool juegoIniciado = false;

    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }

            pantallaInicio.manejarEventos();
        }

        if (!juegoIniciado) {
            ventana.clear(sf::Color::Black);
            pantallaInicio.dibujar();
            ventana.display();

            if (pantallaInicio.iniciarJuegoSeleccionado()) {
                juegoIniciado = true;
            }
            else if (pantallaInicio.salirSeleccionado()) {
                ventana.close();
            }
        }
        else {
            personaje.mover(ventana);

            if (temporizador.getElapsedTime().asSeconds() >= 0.5f) {
                float posX = disX(gen);
                float velocidadY = 700.0f;
                float radio = disRadio(gen);
                asteroides.emplace_back(radio, sf::Vector2f(posX, 0.0f), sf::Vector2f(0.0f, velocidadY), &ventana);
                temporizador.restart();

                float posYCometa = disX(gen);
                sf::Vector2f velocidadCometa(-100.0f, 100.0f);
                Cometa cometa(radio, sf::Vector2f(ventana.getSize().x, posYCometa), velocidadCometa, &ventana);
                cometas.push_back(cometa);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                sf::Vector2f posicionPersonaje = personaje.getPosicion();
                float anguloPersonaje = personaje.getAngulo();
                Disparo disparo(10.0f, anguloPersonaje - 90, posicionPersonaje);
                disparos.push_back(disparo);
            }

            for (auto itAster = asteroides.begin(); itAster != asteroides.end();) {
                Asteroide& asteroide = *itAster;
                asteroide.actualizar(1.0f / 60.0f);

                if (personaje.colisiona(asteroide.obtenerLimitesGlobales())) {
                    personaje.incrementarChoques();
                    itAster = asteroides.erase(itAster);
                    colisiones++;
                }
                else {
                    bool colisionado = false;
                    for (auto itDisp = disparos.begin(); itDisp != disparos.end();) {
                        Disparo& disparo = *itDisp;
                        if (disparo.colisiona(asteroide.obtenerLimitesGlobales())) {
                            itDisp = disparos.erase(itDisp);
                            colisionado = true;
                            break;
                        }
                        else {
                            ++itDisp;
                        }
                    }

                    if (!colisionado) {
                        ++itAster;
                    }
                    else {
                        itAster = asteroides.erase(itAster);
                        colisiones++;
                    }
                }
            }

            for (auto itCometa = cometas.begin(); itCometa != cometas.end();) {
                Cometa& cometa = *itCometa;
                cometa.actualizar(1.0f / 60.0f);

                if (personaje.colisiona(cometa.obtenerLimitesGlobales())) {
                    personaje.incrementarChoques();
                    itCometa = cometas.erase(itCometa);
                    colisiones++;
                }
                else {
                    bool colisionado = false;
                    for (auto itDisp = disparos.begin(); itDisp != disparos.end();) {
                        Disparo& disparo = *itDisp;
                        if (disparo.colisiona(cometa.obtenerLimitesGlobales())) {
                            itDisp = disparos.erase(itDisp);
                            colisionado = true;
                            break;
                        }
                        else {
                            ++itDisp;
                        }
                    }

                    if (!colisionado) {
                        ++itCometa;
                    }
                    else {
                        itCometa = cometas.erase(itCometa);
                        colisiones++;
                    }
                }
            }

            for (auto& disparo : disparos) {
                disparo.mover();
            }

            ventana.clear(sf::Color::Black);
            fondo.dibujar();
            personaje.dibujar(ventana);

            for (const auto& asteroide : asteroides) {
                asteroide.dibujar(ventana);
            }

            for (const auto& cometa : cometas) {
                cometa.dibujar(ventana);
            }

            for (const auto& disparo : disparos) {
                disparo.dibujar(ventana);
            }

            ventana.display();

            if (personaje.alcanzoLimiteChoques()) {
                ventana.close();
            }
        }
    }

    return 0;
}
