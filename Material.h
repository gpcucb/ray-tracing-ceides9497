#ifndef MATERIAL_H
#define MATERIAL_H
#include "Color.h"
class Material
{
private:
	Color diffuseColor;
	Color specularColor;
	float reflectiveCoeficient;
	float power;
public:
	Material();
	Material(Color diffuse, Color specular, float reflective, float shiny);
	~Material();
	Color getDiffuse(){ return this->diffuseColor; }
	Color getSpecular(){ return this->specularColor; }
	float getReflective(){ return this->reflectiveCoeficient; }
	float getPower(){ return this->power; }
	void setDiffuse(Color diffuseColor){this->diffuseColor = diffuseColor; }
	void setSpecular(Color specularColor){ this->specularColor = specularColor; }
	void setReflective(float reflectiveCoeficient){ this->reflectiveCoeficient = reflectiveCoeficient; }
	void setPower(float power){ this->power = power; }
};

#endif
