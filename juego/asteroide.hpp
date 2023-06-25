#ifndef ASTEROIDE_HPP
#define ASTEROIDE_HPP

#include <SFML/Graphics.hpp>
#include "objeto.hpp"

class Asteroide : public objeto {
private:
    sf::Vector2f velocidad;
    sf::RenderWindow* ventana;

public:
    Asteroide(float radio, const sf::Vector2f& posicionInicial, const sf::Vector2f& velocidadInicial, sf::RenderWindow* ventana);

    void actualizar(float deltaTime) override;
    bool colisiona(const sf::FloatRect& bounds) const;
};


#endif // ASTEROIDE_HPP

