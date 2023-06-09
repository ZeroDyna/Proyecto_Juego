#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

#include <SFML/Graphics.hpp>
#include "disparo.hpp"
#include "objeto.hpp"

class Personaje {
public:
    Personaje(float velocidad, sf::RenderWindow& ventana);

    void mover(sf::RenderWindow& ventana);
    void dibujar(sf::RenderWindow& ventana);
    void girar(float angulo);
    void incrementarChoques();
    bool colisiona(const sf::FloatRect& bounds) const;
    bool alcanzoLimiteChoques() const;

    sf::Vector2f getPosicion() const;
    float getAngulo() const;

private:
    sf::Sprite sprite;
    sf::Texture textura;
    float velocidad;
    int choques;
    bool end;
};

#endif // PERSONAJE_HPP
