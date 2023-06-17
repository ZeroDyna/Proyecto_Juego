#include "asteroide.hpp"

Asteroide::Asteroide(float radio, const sf::Vector2f& posicionInicial, const sf::Vector2f& velocidadInicial, sf::RenderWindow& ventana)
    : objeto(radio, posicionInicial, velocidadInicial), ventana(ventana) {}

void Asteroide::actualizar(float deltaTime) {
    sf::Vector2f posicion = forma.getPosition();
    posicion += velocidad * deltaTime;
    forma.setPosition(posicion);
}

void Asteroide::dibujar(sf::RenderWindow& ventana) const {
    ventana.draw(forma);
}

void Asteroide::alColisionar(objeto& otro) {
    // Implementa la lógica para eliminar o destruir el asteroide cuando colisiona con otro objeto específico
    // Código de eliminación o destrucción del asteroide
}

