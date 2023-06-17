#include "objeto.hpp"

objeto::objeto(float radio, const sf::Vector2f& posicionInicial, const sf::Vector2f& velocidadInicial)
    : velocidad(velocidadInicial) {
    forma.setRadius(radio);
    forma.setOrigin(radio, radio);
    forma.setPosition(posicionInicial);
}

void objeto::dibujar(sf::RenderWindow& ventana) const {
    ventana.draw(forma);
}

sf::FloatRect objeto::obtenerLimitesGlobales() const {
    return forma.getGlobalBounds();
}
objeto::~objeto() {}


