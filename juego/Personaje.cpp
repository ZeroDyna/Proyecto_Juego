#include "Personaje.hpp"
#include <iostream>

Personaje::Personaje(float velocidad, sf::RenderWindow& ventana) {
    this->velocidad = velocidad;
    if (!textura.loadFromFile("img/wing.png")) {
        std::cerr << "Failed to load image \"img/wing.png\". Reason: Unable to open file" << std::endl;
        exit(EXIT_FAILURE);
    }
    sprite.setTexture(textura);
    sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
    sprite.setScale(0.25f, 0.25f);

    choques = 0;
    end = false;

	sf::Vector2u ventanaSize = ventana.getSize();
    sprite.setPosition(ventanaSize.x / 2.0f, ventanaSize.y / 2.0f);
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

void Personaje::incrementarChoques() {
    choques++;
    if (choques >= 3) {
        end = true;
    }
}

bool Personaje::colisiona(const sf::FloatRect& bounds) const {
    return sprite.getGlobalBounds().intersects(bounds);
}

bool Personaje::alcanzoLimiteChoques() const {
    return end;
}

sf::Vector2f Personaje::getPosicion() const {
    return sprite.getPosition();
}

float Personaje::getAngulo() const {
    return sprite.getRotation();
}
