#include "cometa.hpp"
#include <random>

Cometa::Cometa(float radio, const sf::Vector2f& posicionInicial, const sf::Vector2f& velocidadInicial, sf::RenderWindow* ventana)
    : objeto(radio, posicionInicial, velocidadInicial), ventana(ventana) {
    velocidad = velocidadInicial;
	forma.setFillColor(sf::Color(72, 60, 50)); // Color café oscuro (RGB: 72, 60, 50)

}

void Cometa::actualizar(float deltaTime) {
    sf::Vector2f posicion = forma.getPosition();
    posicion += velocidad * deltaTime;

    // Si el cometa sale de la pantalla, reiniciar su posición en el lado opuesto
    if (posicion.x > ventana->getSize().x || posicion.x < 0) {
        // Generar una posición aleatoria en el eje Y dentro de la ventana
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> disY(0.0f, static_cast<float>(ventana->getSize().y));
        float posY = disY(gen);

        // Reiniciar la posición en el lado opuesto de la ventana
        if (posicion.x > ventana->getSize().x)
            posicion.x = -forma.getRadius();
        else
            posicion.x = ventana->getSize().x + forma.getRadius();

        posicion.y = posY;
    }

    forma.setPosition(posicion);
}

bool Cometa::colisiona(const sf::FloatRect& bounds) const {
    return forma.getGlobalBounds().intersects(bounds);
}
