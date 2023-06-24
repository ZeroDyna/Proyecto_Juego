#include "disparo.hpp"
#include <cmath>

Disparo::Disparo(float velocidad, float angulo, sf::Vector2f posicionInicial) {
    this->velocidad = velocidad;
    shape.setSize(sf::Vector2f(10.0f, 10.0f));  // Tamaño del cuadrado del disparo
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(posicionInicial);

    float radianes = angulo * 3.14159f / 180.0f;
    direccion = sf::Vector2f(std::cos(radianes), std::sin(radianes));
}

void Disparo::mover() {
    shape.move(direccion * velocidad);
}

void Disparo::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(shape);
}

sf::Vector2f Disparo::getPosicion() const {
    return shape.getPosition();
}

float Disparo::getAngulo() const {
    return shape.getRotation();
}

