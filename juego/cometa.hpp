//esta clase debe de sre similar a la cclase asteroideper al moemnto de aoareccer en bez de hace ruq vaya haceia abajo ccomo asteroide, recorreraa un camino de zig zag para alcanzar mas facil al jugador
#ifndef COMETA_HPP
#define COMETA_HPP
#include "objeto.hpp"
using namespace sf;
class cometa : public objeto {
	protected:
	CircleShape forma;
	Vector2f veloz;
	RenderWindow ventana;
	public:
	virtual void actualizar;
};

#endif
