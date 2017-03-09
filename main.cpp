#include "RGB.h"
#include "Vector.h"
#include "Rayo.h"
#include "Camara.h"

int main(){
	//inicializacones
	RGB rgb;
	RGB rgb_lleno(12.343, 123.23, 342.342);
	Vector v1(13.12, 25.26, 45.10);
	Vector v2(24.10, 13.58, 81.78);
	Vector vPrueba;
	Rayo rayo(v1,v2);
	//inicioalizaciones para camara
	Vector eje(0, 0, 0);
	Vector center(4, 10, 8);
	Vector up(2,5,9);
	Camara camara(eje,center,up);

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

	cout << "Producto escalar V1.V2 = "<< v1.productoEscalar(v2)<<endl;

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

	return 0;
}