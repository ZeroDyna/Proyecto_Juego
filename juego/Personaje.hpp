#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

#include <SFML/Graphics.hpp>
#include "disparo.hpp"
#include "objeto.hpp"

class Personaje{
public:
    Personaje(float velocidad);

    void mover(sf::RenderWindow& ventana);
    void dibujar(sf::RenderWindow& ventana);
    void girar(float angulo);

    sf::Vector2f getPosicion() const;
    float getAngulo() const;

private:
    sf::Sprite sprite;
    sf::Texture textura;
    float velocidad;
	int colisiones;
	bool end;
};

#endif // PERSONAJE_HPP

