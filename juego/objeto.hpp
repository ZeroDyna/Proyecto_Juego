#ifndef OBJETO_HPP
#define OBJETO_HPP

#include <SFML/Graphics.hpp>

class objeto {
protected:
    sf::CircleShape forma;
    sf::Vector2f velocidad;

public:
    objeto(float radio, const sf::Vector2f& posicionInicial, const sf::Vector2f& velocidadInicial);
    virtual ~objeto();

    virtual void actualizar(float deltaTime) = 0;
    virtual void dibujar(sf::RenderWindow& ventana) const;
    sf::FloatRect obtenerLimitesGlobales() const;
};

#endif

