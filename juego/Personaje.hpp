#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>

class Personaje
{
public:
    Personaje(float velocidad);
    void mover(sf::RenderWindow& ventana);
    void dibujar(sf::RenderWindow& ventana);
    void girar(float angulo);
private:
    sf::Sprite sprite;
    sf::Texture textura;
    float velocidad;
};

#endif // PERSONAJE_HPP

