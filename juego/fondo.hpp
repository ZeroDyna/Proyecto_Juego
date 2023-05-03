#pragma once

#include <SFML/Graphics.hpp>

class FondoAleatorio {
public:
    FondoAleatorio(sf::RenderWindow& ventana);

    void dibujar();

private:
    std::vector<sf::Sprite> sprites_;
    std::vector<sf::Texture> texturas_;
    sf::RenderWindow& ventana_;
};

