#ifndef DISPARO_HPP
#define DISPARO_HPP

#include <SFML/Graphics.hpp>

class Disparo {
public:
    Disparo(float velocidad, float angulo, sf::Vector2f posicionInicial);

    void mover();
    void dibujar(sf::RenderWindow& ventana);

    sf::Vector2f getPosicion() const;
    float getAngulo() const;

private:
    sf::RectangleShape shape;
    float velocidad;
    sf::Vector2f direccion;
};

#endif // DISPARO_HPP

