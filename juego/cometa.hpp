#ifndef COMETA_HPP
#define COMETA_HPP

#include <SFML/Graphics.hpp>
#include "objeto.hpp"

class Cometa : public objeto {
private:
    sf::Vector2f velocidad;
    sf::RenderWindow* ventana;

public:
    Cometa(float radio, const sf::Vector2f& posicionInicial, const sf::Vector2f& velocidadInicial, sf::RenderWindow* ventana);

    void actualizar(float deltaTime) override;
    bool colisiona(const sf::FloatRect& bounds) const;
};

#endif // COMETA_HPP
