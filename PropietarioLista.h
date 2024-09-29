#pragma once
#include "Propietario.h"

class PropietarioLista {
private:
	int cantidad;
	int tamano;
	int cantidadDoctores;
	int tamanoDoctores;
	Propietario** vector;
	void inicializarVector() {
		for (int i = 0; i < tamano; i++) {
			vector[i] = new Propietario();
		}
	}
public:
	PropietarioLista();
	PropietarioLista(int, int);
	virtual ~PropietarioLista();

	Propietario* BuscarPropietario(string id);
	bool AgregarPropietario(Propietario* nuevo);
	string RetornoListaPropietario();
};
