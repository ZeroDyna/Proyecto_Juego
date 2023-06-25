#include "fondo.hpp"

FondoAleatorio::FondoAleatorio(sf::RenderWindow& ventana, float retrasoCambio)
    : ventana_(ventana), retrasoCambio_(retrasoCambio) {
    // Inicializamos la semilla para los números aleatorios
    std::srand(std::time(nullptr));

    texturas_.resize(3);

    if (!texturas_[0].loadFromFile("img/cielo.png") ||
        !texturas_[1].loadFromFile("img/espacio.png") ||
        !texturas_[2].loadFromFile("img/planeta.png")) {
        // Manejo de error en caso de que alguna textura no se pueda cargar
    }

    for (int i = 0; i < 3; i++) {
        sf::Sprite sprite;
        sprite.setTexture(texturas_[i]);
        sprites_.push_back(sprite);
    }

    ajustarSprites(); // Ajustar la escala de los sprites a la ventana
}

void FondoAleatorio::dibujar() {
    cambiarFondo(); // Cambiar el fondo si ha pasado el tiempo de retraso

    for (auto& sprite : sprites_) {
        ventana_.draw(sprite);
    }
}

void FondoAleatorio::cambiarFondo() {
    if (reloj_.getElapsedTime().asSeconds() >= retrasoCambio_) {
        int indice = std::rand() % sprites_.size();
        std::rotate(sprites_.begin(), sprites_.begin() + indice, sprites_.end());
        reloj_.restart();
    }
}

void FondoAleatorio::ajustarSprites() {
    sf::Vector2u ventanaSize = ventana_.getSize();

    for (auto& sprite : sprites_) {
        sf::Vector2u textureSize = sprite.getTexture()->getSize();
        sprite.setScale(static_cast<float>(ventanaSize.x) / textureSize.x,
                        static_cast<float>(ventanaSize.y) / textureSize.y);
    }
}

