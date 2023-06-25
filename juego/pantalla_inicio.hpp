#ifndef PANTALLA_INICIO_HPP
#define PANTALLA_INICIO_HPP

#include <SFML/Graphics.hpp>

class PantallaInicio {
public:
    PantallaInicio(sf::RenderWindow& ventana);

    void manejarEventos();
    void dibujar();

    bool iniciarJuegoSeleccionado() const;
    bool salirSeleccionado() const;

private:
    sf::RenderWindow& ventana_;
    sf::Font fuente_;
    sf::Text textoInicio_;
    sf::Text textoSalir_;
    sf::Texture texturaFondo_;  // Nueva variable para la textura del fondo
    sf::Sprite spriteFondo_;    // Nueva variable para el sprite del fondo
    bool iniciarJuegoSeleccionado_;
    bool salirSeleccionado_;
};

#endif // PANTALLA_INICIO_HPP

