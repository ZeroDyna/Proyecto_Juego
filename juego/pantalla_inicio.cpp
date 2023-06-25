#include "pantalla_inicio.hpp"

PantallaInicio::PantallaInicio(sf::RenderWindow& ventana)
    : ventana_(ventana), iniciarJuegoSeleccionado_(false), salirSeleccionado_(false)
{
    if (!fuente_.loadFromFile("fuente/ultraman.otf")) {
        // Manejar el error si no se puede cargar la fuente
    }

    if (!texturaFondo_.loadFromFile("img/Pantalla.png")) {
        // Manejar el error si no se puede cargar la imagen de fondo
    }

    spriteFondo_.setTexture(texturaFondo_);

    // Obtener las dimensiones de la ventana
    sf::Vector2u tamanoVentana = ventana_.getSize();

    // Ajustar el tamaño del sprite de fondo
    spriteFondo_.setScale(
        tamanoVentana.x / static_cast<float>(spriteFondo_.getTexture()->getSize().x),
        tamanoVentana.y / static_cast<float>(spriteFondo_.getTexture()->getSize().y)
    );

    textoInicio_.setFont(fuente_);
    textoInicio_.setCharacterSize(30);
    textoInicio_.setString("Iniciar Juego");
    textoInicio_.setPosition(100, 100);

    textoSalir_.setFont(fuente_);
    textoSalir_.setCharacterSize(30);
    textoSalir_.setString("Salir");
    textoSalir_.setPosition(100, 150);
}

void PantallaInicio::manejarEventos() {
    sf::Event evento;
    while (ventana_.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed) {
            ventana_.close();
        } else if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i posicionMouse = sf::Mouse::getPosition(ventana_);
            if (textoInicio_.getGlobalBounds().contains(sf::Vector2f(posicionMouse))) {
                iniciarJuegoSeleccionado_ = true;
            } else if (textoSalir_.getGlobalBounds().contains(sf::Vector2f(posicionMouse))) {
                salirSeleccionado_ = true;
            }
        }
    }
}

void PantallaInicio::dibujar()
{
    ventana_.clear();

    // Dibujar el fondo
    ventana_.draw(spriteFondo_);

    // Dibujar los textos
    ventana_.draw(textoInicio_);
    ventana_.draw(textoSalir_);

    ventana_.display();
	sf::sleep(sf::seconds(2)); // Reducción del tiempo de espera a 1 segundo

}

bool PantallaInicio::iniciarJuegoSeleccionado() const
{
    return iniciarJuegoSeleccionado_;
}

bool PantallaInicio::salirSeleccionado() const
{
    return salirSeleccionado_;
}

