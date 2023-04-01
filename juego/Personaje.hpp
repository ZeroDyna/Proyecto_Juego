#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

#include <SFML/Graphics.hpp>

class Personaje
{
public:
	Personaje(float velocidad);
    void mover(sf::RenderWindow& ventana);
    void dibujar(sf::RenderWindow& ventana);
private:
    sf::RectangleShape rectangulo;
	float velocidad;
};

#endif // PERSONAJE_HPP

