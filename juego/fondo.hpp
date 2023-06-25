#ifndef FONDO_HPP
#define FONDO_HPP

#include <SFML/Graphics.hpp>

class FondoAleatorio {
public:
    FondoAleatorio(sf::RenderWindow& ventana);
    void dibujar();

private:
    sf::RenderWindow& ventana_;
    std::vector<sf::Texture> texturas_;
    std::vector<sf::Sprite> sprites_;
};

#endif

