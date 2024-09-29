#include "PropietarioLista.h"

PropietarioLista::PropietarioLista() {
	this->cantidadDoctores = 0;
	this->cantidad = 0;
	this->tamano = 10;
	this->tamanoDoctores = 10;
	this->vector = new Propietario* [tamano];
	inicializarVector();
}
PropietarioLista::PropietarioLista(int tamano, int tamanodoc) {
	this->cantidad = 0;
	this->cantidadDoctores = 0;
	this->tamano = tamano;
	this->tamanoDoctores = tamanodoc;
	this->vector = new Propietario* [tamano];
	inicializarVector();
}
PropietarioLista::~PropietarioLista() {
	for (int i = 0; i < cantidad; i++) {
		delete vector[i];
	}
	delete[] vector;
}

Propietario* PropietarioLista::BuscarPropietario(string id) {
	for (int i = 0; i < cantidad; i++) {
		if (vector[i]->getID() == id) {
			return vector[i];
		}
	}
	return nullptr;
}
bool PropietarioLista::AgregarPropietario(Propietario* nuevo) {
	if (BuscarPropietario(nuevo->getID()) == nullptr && cantidad < tamano) {
		*vector[cantidad] = *nuevo;
		cantidad++;
		return true;
	}
	return false;
}
string PropietarioLista::RetornoListaPropietario() {
	stringstream s;

	for (int i = 0; i < cantidad; i++) {
		s << "- " << " " << i + 1 << "\n" << vector[i]->toString() << endl;
	}
	return s.str();
}
