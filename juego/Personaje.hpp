#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

#include <SFML/Graphics.hpp>

class Personaje
{
public:
    Personaje(sf::Vector2f posicion, sf::Vector2f tamano, sf::Color color);

    void mover(sf::Vector2f direccion);
    void dibujar(sf::RenderWindow& ventana);

private:
    sf::RectangleShape m_rectangulo;
};

#endif // PERSONAJE_HPP

