#include "Personaje.hpp"
#include <iostream>

Personaje::Personaje(float velocidad) {
    this->velocidad = velocidad;
    if (!textura.loadFromFile("img/wing.png")) {
        std::cerr << "Failed to load image \"img/wing.png\". Reason: Unable to open file" << std::endl;
        exit(EXIT_FAILURE);
    }
    sprite.setTexture(textura);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setScale(0.25f, 0.25f);
}

void Personaje::mover(sf::RenderWindow& ventana) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        sprite.move(0, -velocidad);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        sprite.move(0, velocidad);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        sprite.move(-velocidad, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        sprite.move(velocidad, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        girar(-5);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        girar(5);
    }
}
void Personaje::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(sprite);
}

void Personaje::girar(float angulo) {
    sprite.rotate(angulo);
}

sf::Vector2f Personaje::getPosicion() const {
    return sprite.getPosition();
}

float Personaje::getAngulo() const {
    return sprite.getRotation();
}

