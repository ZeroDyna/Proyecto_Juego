#include "asteroide.hpp"
#include <random>

Asteroide::Asteroide(float radio, const sf::Vector2f& posicionInicial, const sf::Vector2f& velocidadInicial, sf::RenderWindow* ventana)
    : objeto(radio, posicionInicial, velocidadInicial), ventana(ventana) {
    velocidad = velocidadInicial;
    forma.setFillColor(sf::Color(72, 60, 50)); // Color café oscuro (RGB: 72, 60, 50)

}

void Asteroide::actualizar(float deltaTime) {
    sf::Vector2f posicion = forma.getPosition();
    posicion += velocidad * deltaTime;

    // Si el asteroide sale de la pantalla, reiniciar su posición en la parte superior
    if (posicion.y > ventana->getSize().y) {
        // Generar una posición aleatoria en el eje X dentro de la ventana
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> disX(0.0f, static_cast<float>(ventana->getSize().x));
        float posX = disX(gen);

        // Reiniciar la posición en la parte superior de la ventana
        posicion.x = posX;
        posicion.y = -forma.getRadius();
    }

    forma.setPosition(posicion);
}

bool Asteroide::colisiona(const sf::FloatRect& bounds) const {
    return forma.getGlobalBounds().intersects(bounds);
}

