#include "RGB.h"
#include "Vector.h"
#include "Rayo.h"
#include "Camara.h"
#include "Esfera.h"
#include "Triangulo.h"

/*todas mis pruebas al desarrollar
int main(){
	//inicializacones
	RGB rgb;
	RGB rgb_lleno(12.343, 123.23, 342.342);
	Vector v1(13.12, 25.26, 45.10);
	Vector v2(24.10, 13.58, 81.78);
	Vector vPrueba;
	Rayo rayo(v1, v2);
	//inicioalizaciones para camara
	Vector eje(5, 8, 20);
	Vector center(4, 10, 8);
	Vector up(2, 5, 9);
	Camara camara(eje, center, up, 30, 0.8);

	//RGB Pruebas
	cout << "---------RGB pruebas------" << endl;
	cout << "RGB -> ";
	rgb_lleno.show();


	//Vector Pruebas
	cout << "---------Vector pruebas------" << endl;
	cout << "V1 -> ";
	v1.show();
	cout << "V2 -> ";
	v2.show();
	cout << "Suma de V1 + V2 -> ";
	vPrueba = v1.suma(v2);
	vPrueba.show();

	cout << "Resta de V1 + V2 -> ";
	vPrueba = v1.resta(v2);
	vPrueba.show();

	cout << "Modulo V1 = " << v1.modulo() << endl;
	cout << "Modulo V2 = " << v2.modulo() << endl;

	cout << "Producto escalar V1.V2 = " << v1.productoEscalar(v2) << endl;

	cout << "Producto vectorial V1xV2 ->";
	vPrueba = v1.productoVectorial(v2);
	vPrueba.show();

	//Rayo Pruebas
	cout << "---------Rayo pruebas------" << endl;
	rayo.show();

	//Camara pruebas
	cout << "---------Camara pruebas------" << endl;
	cout << "eje -> ";
	camara.getEje().show();
	cout << "center -> ";
	camara.getCenter().show();
	cout << "up -> ";
	camara.getUp().show();
	cout << "VectorW -> ";
	camara.calculandoVectorW().show();
	cout << "VectorU -> ";
	camara.calculandoVectorU().show();
	cout << "VectorV -> ";
	camara.calculandoVectorV().show();
	cout << "Direccion del rayo -> ";
	camara.calculandoDireccionDelRayo(32,55,640.0,348.0).show();

}*/

int main(){
	Vector e(278, 273, -800);
	Vector center(278, 273, -700);
	Vector	up(0, 1, 0);
	float	fov = 39.31;
	float	df = 0.035;
	float	nx = 640.0;
	float	ny = 480.0;
	//esfera
	Vector posicion(370, 120, 370);
	float	radio = 120;
	//triangulo
	Vector a(552.0, 8, 0.0);
	Vector b(0.0, 0.0, 0.0);
	Vector c(0.0, 0.0, 560.0);
	//inicio
	Camara camara(e, center, up, fov, df);
	//Esfera esfera(radio, posicion);
	Triangulo triangulo(a, b, c);
	for (int i = 0; i < nx; i++)
	{
		for (int j = 0; j < ny; j++)
		{
			Vector dir = camara.calculandoDireccionDelRayo(i, j, nx, ny);
			Rayo rayo(e, dir);
			triangulo.interseccion(rayo);
		}
	}

	return 0;
}