#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "Vector.h"
#include "Rayo.h"
class Triangulo
{
private:
	Vector a;
	Vector b;
	Vector c;
public:
	Triangulo();
	Triangulo(Vector a, Vector b, Vector c);
	~Triangulo();
	bool interseccion(Rayo rayo);
};

#endif

