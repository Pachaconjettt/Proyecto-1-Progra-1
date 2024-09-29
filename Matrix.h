#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Mascota.h"
using namespace std;

class Mascota;

class Matrix {
private:
	int filas;
	int columnas;
	int horasOcupadas;
	Mascota*** matriz;
public:
	Matrix();
	virtual ~Matrix();

	string ingresarCita(int vec[], Mascota*);
	string eliminarCita(int dia, int hora, string);
	bool BuscarPropietarioXMascota(string mtrix);
	string ImprimirPropietariosXDoctor();
	string buscarNombreEspecifico(string);
	string pintarMatriz();
};
