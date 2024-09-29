#pragma once
#include "Especialidad.h"
class EspecialidadLista
{
private:
	int cantidad;
	int tamano;
	Especialidad** vector;
	void inicializarEspecialidad() {
		for (int i = 0; i < tamano; i++) {
			vector[i] = new Especialidad();
		}
	}
public:
	EspecialidadLista();
	EspecialidadLista(int);
	virtual ~EspecialidadLista();

	Especialidad* buscarEspecialidad(string);
	bool AgregarEspecialidad(Especialidad*);
	string RetornoEspecialidad();
};