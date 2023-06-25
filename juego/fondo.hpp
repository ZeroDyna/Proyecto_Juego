#ifndef FONDO_HPP
#define FONDO_HPP

#include <SFML/Graphics.hpp>

class FondoAleatorio {
public:
    FondoAleatorio(sf::RenderWindow& ventana, float retrasoCambio);
    void dibujar();

private:
    sf::RenderWindow& ventana_;
    std::vector<sf::Texture> texturas_;
    std::vector<sf::Sprite> sprites_;
    float retrasoCambio_; // Tiempo de retraso entre cambios de fondo
    sf::Clock reloj_; // Reloj para rastrear el tiempo transcurrido

    void cambiarFondo(); // Método para cambiar el fondo
    void ajustarSprites(); // Método para ajustar la escala de los sprites a la ventana
};

#endif

