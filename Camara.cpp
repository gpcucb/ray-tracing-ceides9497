#include "Camara.h"


Camara::Camara()
{
}

Camara::Camara(Vector eje, Vector center, Vector up, float fov, float df)
{
	this->eje = eje;
	this->center = center;
	this->up = up;
	this->fov = fov;
	this->df = df;
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

Vector Camara::calculandoDireccionDelRayo(float i, float j, float nx, float ny){
	float t, r, l, b, u, v;
	Vector dw, uu, vv;
	t = calcularT();
	r = calcularR(nx, ny);
	b = -t;
	l = -r;

	u = l + ((r - l)*(i + 0.5)) / nx;
	v = b + ((t - b)*(j + 0.5)) / ny;

	dw = calculandoVectorW().productoVectorPorNumero(-df);
	uu = calculandoVectorU().productoVectorPorNumero(u);
	vv = calculandoVectorV().productoVectorPorNumero(v);

	return (dw.suma(uu)).suma(vv);
}

float Camara::calcularT(){
	return this->df * tan(((this->fov)*pi / 180) / 2);
}

float Camara::calcularR(float nx, float ny){
	return (calcularT() - nx) / ny;
}

