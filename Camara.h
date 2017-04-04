#ifndef CAMARA_H
#define CAMARA_H
#include "Vector.h"
#include "Rayo.h"
class Camara
{
private:
	Vector eye;
	Vector center;
	Vector up;
	float fov;
	float df;
public:
	Camara();
	Camara(Vector eye, Vector center, Vector up, float fov, float df);
	~Camara();
	Vector getEje(){ return this->eye; }
	Vector getCenter(){ return this->center; }
	Vector getUp(){ return this->up; }
	void setEje(Vector eye){ this->eye = eye; }
	void setCenter(Vector center){ this->center = center; }
	void setUp(Vector up){ this->up = up; }
	Vector calculandoVectorW();
	Vector calculandoVectorU();
	Vector calculandoVectorV();
	Vector calculandoDireccionDelRayo(float i, float j, float nx, float ny);
	float calcularT();
	float calcularR(float nx, float ny);
	Rayo crearRayo(Vector rayDirection);
};

#endif