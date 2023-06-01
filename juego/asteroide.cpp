#include "asteroide.hpp"

Asteroide::Asteroide(float radio, const sf::Vector2f& posicionInicial, const sf::Vector2f& velocidadInicial, sf::RenderWindow& ventana)
    : velocidad(velocidadInicial), ventana(ventana) {
    forma.setRadius(radio);
    forma.setOrigin(radio, radio);
    forma.setPosition(posicionInicial);
}

void Asteroide::actualizar(float deltaTime) {
    sf::Vector2f posicion = forma.getPosition();
    posicion += velocidad * deltaTime;
    forma.setPosition(posicion);

    // Si el asteroide sale de la pantalla por la parte inferior, lo reposicionamos en la parte superior
    if (posicion.y > ventana.getSize().y) {
        posicion.y = -forma.getRadius();
        forma.setPosition(posicion);
    }
}

void Asteroide::dibujar(sf::RenderWindow& ventana) const {
    ventana.draw(forma);
}

