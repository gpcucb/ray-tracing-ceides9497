#ifndef CAMARA_H
#define CAMARA_H
#include "Vector.h"
class Camara
{
private:
	Vector eje;
	Vector center;
	Vector up;
public:
	Camara();
	Camara(Vector eje, Vector center, Vector up);
	~Camara();
	Vector getEje(){ return this->eje; }
	Vector getCenter(){ return this->center; }
	Vector getUp(){ return this->up; }
	void setEje(Vector eje){ this->eje = eje; }
	void setCenter(Vector eje){ this->center = center; }
	void setUp(Vector eje){ this->up = up; }
	Vector sacandoVectorW();
	Vector sacandoVectorU();
	Vector sacandoVectorV();
};

#endif