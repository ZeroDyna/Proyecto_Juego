#include "Personaje.hpp"

Personaje::Personaje(sf::Vector2f posicion, sf::Vector2f tamano, sf::Color color)
    : m_rectangulo(tamano)
{
    m_rectangulo.setPosition(posicion);
    m_rectangulo.setFillColor(color);
}

void Personaje::mover(sf::Vector2f direccion)
{
    m_rectangulo.move(direccion);
}

void Personaje::dibujar(sf::RenderWindow& ventana)
{
    ventana.draw(m_rectangulo);
}

