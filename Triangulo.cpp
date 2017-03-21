#include "Triangulo.h"


Triangulo::Triangulo()
{
}

Triangulo::Triangulo(Vector a, Vector b, Vector c){
	this->a = a;
	this->b = b;
	this->c = c;
}

Triangulo::~Triangulo()
{
}

void Triangulo::interseccion(Rayo rayo){
	float t, gama, beta;
	float a, b, c, d, e, f, g, h, i, j, k, l;
	a = this->a.getX() - this->b.getX();
	b = this->a.getY() - this->b.getY();
	c = this->a.getZ() - this->b.getZ();
	d = this->a.getX() - this->c.getX();
	e = this->a.getY() - this->c.getY();
	f = this->a.getZ() - this->c.getZ();

	Vector direccionRayo = rayo.getDireccion();
	Vector posicionRayo = rayo.getPosicion();

	g = direccionRayo.getX();
	h = direccionRayo.getY();
	i = direccionRayo.getZ();

	j = this->a.getX() - posicionRayo.getX();
	k = this->a.getY() - posicionRayo.getY();
	l = this->a.getZ() - posicionRayo.getZ();

	float m;

	m = a*(e*i - h*f) + b*(g*f - d*i) + c*(d*h - e*g);

	beta = (j*(e*i - h*f) + k*(g*f - d*i) + l*(d*h - e*g)) / m;
	gama = (i*(a*k - j*b) + h*(j*c - a*l) + g*(b*l - k*c)) / m;
	t = -1 * ((f*(a*k - j*b) + e*(j*c - a*l) + d*(b*l - k*c)) / m);

	cout << "beta: "<<beta<<", gama: "<<gama<<" ,t: "<<t<<endl;
}