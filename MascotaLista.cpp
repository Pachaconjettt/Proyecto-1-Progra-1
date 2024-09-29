#include "MascotaLista.h"

MascotaLista::MascotaLista() {
	this->cantidad = 0;
	this->tamano = 10;
	this->vector = new Mascota* [tamano];
	inicializarVector();
}
MascotaLista::MascotaLista(int tamano) {
	this->cantidad = 0;
	this->tamano = tamano;
	this->vector = new Mascota* [tamano];
	inicializarVector();
}
MascotaLista::~MascotaLista() {
	for (int i = 0; i < cantidad; i++) {
		delete vector[i];
	}
	delete[] vector;
}

Mascota* MascotaLista::buscarMascota(string nombre) {
	for (int i = 0; i < cantidad; i++) {
		if (vector[i]->getNombre() == nombre) {
			return vector[i];
		}
	}
	return nullptr;
}
string MascotaLista::ListasDeMascotaDe(Propietario* duennio) {
	stringstream s;

	for (int i = 0; i < cantidad; i++) {
		if (vector[i]->getPropietario()->getID() == duennio->getID()) {
			s << vector[i]->toString() << endl;
		}
		else {
			s << "Ningun animal registrado bajo el ID de este propietario.." << endl;
		}
	}
	return s.str();
}
bool MascotaLista::AgregarMascota(Mascota* nuevo) {
	if (buscarMascota(nuevo->getNombre()) == nullptr && cantidad < tamano) {
		*vector[cantidad] = *nuevo;
		cantidad++;
		return true;
	}
	return false;
}

string MascotaLista::RetornoMascotas() {
	stringstream s;

	for (int i = 0; i < cantidad; i++) {
		s << "- " << " " << i + 1 << "\n" << vector[i]->toString() << endl;
	}
	return s.str();
}
