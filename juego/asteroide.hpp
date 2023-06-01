#ifndef ASTEROIDE_HPP
#define ASTEROIDE_HPP

#include <SFML/Graphics.hpp>
#include "objeto.hpp"

class Asteroide:public objeto  {
private:
    sf::CircleShape forma;
    sf::Vector2f velocidad;
    sf::RenderWindow& ventana;

public:
    Asteroide(float radio, const sf::Vector2f& posicionInicial, const sf::Vector2f& velocidadInicial, sf::RenderWindow& ventana);

    virtual void actualizar(float deltaTime);
    void dibujar(sf::RenderWindow& ventana) const; 
	virtual void alColisionar(objeto& otro);

};

#endif

