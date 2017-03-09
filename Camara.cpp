#include "Camara.h"


Camara::Camara()
{
}

Camara::Camara(Vector eje, Vector center, Vector up)
{
	this->eje = eje;
	this->center = center;
	this->up = up;
}


Camara::~Camara()
{
}

Vector Camara::sacandoVectorW(){
	float x, y, z;
	x = this->eje.getX() / this->eje.modulo();
	y = this->eje.getY() / this->eje.modulo();
	z = this->eje.getZ() / this->eje.modulo();
	return Vector(x, y, z);
}

Vector Camara::sacandoVectorU(){
	Vector productoVectorial;
	float x, y, z;
	productoVectorial = this->up.productoVectorial(sacandoVectorW());
	x = this->eje.getX() / this->eje.modulo();
	y = this->eje.getY() / this->eje.modulo();
	z = this->eje.getZ() / this->eje.modulo();
	return Vector(x, y, z);
}

