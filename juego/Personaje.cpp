#include "Personaje.hpp"

Personaje::Personaje(float velocidad) {
    rectangulo.setSize(sf::Vector2f(50, 50));
    rectangulo.setPosition(sf::Vector2f(400, 300));
    rectangulo.setFillColor(sf::Color::Red);
    this->velocidad = velocidad;
}

void Personaje::mover(sf::RenderWindow& ventana) {
    sf::Vector2u tamanoVentana = ventana.getSize();

    // Mover hacia arriba
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && rectangulo.getPosition().y > 0)
    {
        rectangulo.move(0, -velocidad);
    }

    // Mover hacia abajo
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && rectangulo.getPosition().y < tamanoVentana.y - rectangulo.getSize().y)
    {
        rectangulo.move(0, velocidad);
    }

    // Mover hacia la izquierda
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && rectangulo.getPosition().x > 0)
    {
        rectangulo.move(-velocidad, 0);
    }

    // Mover hacia la derecha
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && rectangulo.getPosition().x < tamanoVentana.x - rectangulo.getSize().x)
    {
        rectangulo.move(velocidad, 0);
    }
}

void Personaje::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(rectangulo);
}

