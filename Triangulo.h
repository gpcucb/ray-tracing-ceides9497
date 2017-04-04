#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "Objeto.h"
class Triangulo: public Objeto
{
private:
	Vector a;
	Vector b;
	Vector c;
	Material material;
public:
	Triangulo(Vector a, Vector b, Vector c, Material material);
	~Triangulo();
	Interseccion calcularinterseccion(Rayo rayo, float t);
	void show();
};

#endif

