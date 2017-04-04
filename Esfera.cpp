#include "Esfera.h"


Esfera::Esfera(Vector posicion, float radio,Material material) :Objeto(material)
{
	this->radio = radio;
	this->posicion = posicion;
}

Esfera::~Esfera()
{
}

Interseccion Esfera::calcularinterseccion(Rayo rayo,float t){
	float a, b, c;
	Vector e_c;
	Vector e = rayo.getPosicion();
	Vector d = rayo.getDireccion();
	
	a = d.productoEscalar(d);
	e_c = e.resta(this->posicion);
	b = d.productoVectorPorNumero(2).productoEscalar(e_c);
	c = e_c.productoEscalar(e_c) - pow(radio, 2);

	//cout << "a: "<<a<<", b: "<<b<<", c: "<<c<<endl;

	float discriminante = getDiscriminante(a,b,c);
	bool exito = false;

	if (discriminante < 0.0)
		return Interseccion(exito);

	float t0 = ((b * -1) - sqrt(discriminante))/(2 * a);
	float t1 = ((b * -1) + sqrt(discriminante)) / (2 * a);
	if ((t0 > 0.0) && (t0 < t)){
		t = t0;
		exito = true;
	}	
	if ((t1 > 0.0) && (t1 < t)){
		t = t1;
		exito = true;
	}

	return Interseccion(exito,t);
		
}

float Esfera::getDiscriminante(float a, float b, float c){
	return pow(b, 2) - (4 * a * c);
}

void Esfera::show(){
	cout << "Soy una esfera" << endl;
}
