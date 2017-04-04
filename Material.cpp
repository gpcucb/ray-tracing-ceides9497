#include "Material.h"


Material::Material()
{
}


Material::Material(Color diffuseColor, Color specularColor, float reflectiveCoeficient, float power)
{
	this->diffuseColor = diffuseColor;
	this->specularColor = specularColor;
	this->reflectiveCoeficient = reflectiveCoeficient;
	this->power = power;
}



Material::~Material()
{
}
