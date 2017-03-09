#include "Vector.h"


Vector::Vector()
{
}

Vector::Vector(float x, float y, float z){
	this->x = x;
	this->y = y;
	this->z = z;
}


Vector::~Vector()
{
}

Vector Vector::suma(Vector vector){
	Vector vres;
	vres.x = this->x + vector.x;
	vres.y = this->y + vector.y;
	vres.z = this->z + vector.z;
	return vres;
}

Vector Vector::resta(Vector vector){
	Vector vres;
	vres.x = this->x - vector.x;
	vres.y = this->y - vector.y;
	vres.z = this->z - vector.z;
	return vres;
}

void Vector::show(){
	cout << "X: " << this->x << ", Y: " << this->y << ", Z: " << this->z << endl;
}

int Vector::modulo(){
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector Vector::productoVectorial(Vector v){
	float i, j, k;
	i = (this->y*v.z) - (this->z*v.y);
	j = (this->z*v.x) - (this->x*v.z);
	k = (this->x*v.y) - (this->y*v.x);
	return Vector(i, j, k);
}

float Vector::productoEscalar(Vector v){
	float i, j, k;
	i = this->x*v.x;
	j = this->y*v.y;
	k = this->z*v.z;
	return i+j+k;
}