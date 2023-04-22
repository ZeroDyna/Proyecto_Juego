#include "Personaje.hpp"
#include <iostream>
Personaje::Personaje(float velocidad) {
    this->velocidad = velocidad;
    if(!textura.loadFromFile("img/wing.png")) {
        std::cerr << "Failed to load image \"img/wing.png\". Reason: Unable to open file" << std::endl;
        exit(EXIT_FAILURE);
    }
    sprite.setTexture(textura);
    sprite.setOrigin(sprite.getGlobalBounds().width/2, sprite.getGlobalBounds().height/2); // Se establece el punto central de la imagen como el origen
	sprite.setScale(0.25f, 0.25f);

}

void Personaje::mover(sf::RenderWindow& ventana) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        sprite.move(0, -velocidad);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        sprite.move(0, velocidad);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        girar(-5);
        sprite.move(-velocidad, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        girar(5);
        sprite.move(velocidad, 0);
    }
}

void Personaje::dibujar(sf::RenderWindow& ventana) {
    ventana.draw(sprite);
}

void Personaje::girar(float angulo) {
    sprite.rotate(angulo);
}
