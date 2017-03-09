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

Vector Camara::calculandoVectorW(){
	float x, y, z;
	Vector d = this->eje.resta(this->center);
	x = d.getX() / d.modulo();
	y = d.getY() / d.modulo();
	z = d.getZ() / d.modulo();
	return Vector(x, y, z);
}

Vector Camara::calculandoVectorU(){
	Vector productoVectorialUpxW;
	float x, y, z;
	productoVectorialUpxW = this->up.productoVectorial(calculandoVectorW());
	x = productoVectorialUpxW.getX() / productoVectorialUpxW.modulo();
	y = productoVectorialUpxW.getY() / productoVectorialUpxW.modulo();
	z = productoVectorialUpxW.getZ() / productoVectorialUpxW.modulo();
	return Vector(x, y, z);
}

Vector Camara::calculandoVectorV(){
	return calculandoVectorW().productoVectorial(calculandoVectorU());
}

