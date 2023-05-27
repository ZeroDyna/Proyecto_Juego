#include "fondo.hpp"
#include <cstdlib> // Para generar números aleatorios
#include <ctime> // Para inicializar la semilla de los números aleatorios

FondoAleatorio::FondoAleatorio(sf::RenderWindow& ventana) : ventana_(ventana) {
    // Inicializamos la semilla para los números aleatorios
    std::srand(std::time(nullptr));

    // Reservamos espacio para las texturas
    texturas_.resize(3);

    // Cargamos las texturas para los fondos
    if (!texturas_[0].loadFromFile("img/cielo.png") ||
        !texturas_[1].loadFromFile("img/espacio.png") ||
        !texturas_[2].loadFromFile("img/planeta.png")) {
        // Manejar el error si no se puede cargar alguna de las texturas
    }

    // Creamos los sprites para los fondos
    for (int i = 0; i < 3; i++) {
        sf::Sprite sprite;
        sprite.setTexture(texturas_[i]);
        sprites_.push_back(sprite);
    }

    // Configuramos los sprites para que se ajusten a la ventana
    for (auto& sprite : sprites_) {
        sprite.setScale(ventana.getSize().x / sprite.getLocalBounds().width,
                         ventana.getSize().y / sprite.getLocalBounds().height);
    }
}

void FondoAleatorio::dibujar() {
    for (auto& sprite : sprites_) {
        ventana_.draw(sprite);
    }
}

