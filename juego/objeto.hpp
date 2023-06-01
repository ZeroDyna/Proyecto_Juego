#include "SFML/Graphics.hpp"
class objeto {
protected:
	sf::CircleShape forma;
	sf::Vector2f velocidad;
protected:
    objeto(float radio, const sf::Vector2f& posicionInicial, const sf::Vector2f& velocidadInicial)
        : velocidad(velocidadInicial) {
        forma.setRadius(radio);
        forma.setOrigin(radio, radio);
        forma.setPosition(posicionInicial);
    }

    virtual void actualizar(float deltaTime) = 0;

    void dibujar(sf::RenderWindow& ventana) {
        ventana.draw(forma);
    }

    sf::FloatRect obtenerLimitesGlobales() const {
        return forma.getGlobalBounds();
    }

    bool verificarColision(const objeto& otro) const {
        sf::FloatRect limitesEste = forma.getGlobalBounds();
        sf::FloatRect limitesOtro = otro.forma.getGlobalBounds();
        return limitesEste.intersects(limitesOtro);
    }

    virtual void alColisionar(objeto& otro) = 0;
};
