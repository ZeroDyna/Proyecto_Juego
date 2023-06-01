#include "disparo.hpp"
#include <cmath>

Disparo::Disparo(float velocidad, float angulo, sf::Vector2f posicionInicial) {
    this->velocidad = velocidad;
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(posicionInicial);

    // Calculamos la dirección del disparo basada en el ángulo del personaje
    float radianes = angulo * 3.14159f / 180.0f;
    direccion = sf::Vector2f(std::cos(radianes), std::sin(radianes));
}

void Disparo::mover() {
    shape.move(direccion * velocidad);
}

void Disparo::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(shape);
}

