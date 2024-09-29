#include "Mascota.h"

Mascota::Mascota() {
	this->nombre = "Disponible";
	this->animal = "indef";
	this->duennio = new Propietario();
}
Mascota::Mascota(string nombre, string animal, Propietario* nuevo) {
	this->setNombre(nombre);
	this->setAnimal(animal);
	this->setDuennio(nuevo);
}
Mascota::~Mascota() {
	delete duennio;
}

void Mascota::setNombre(string nombre) {
	this->nombre = nombre;
}
void Mascota::setAnimal(string animal) {
	this->animal = animal;
}
void Mascota::setDuennio(Propietario* propietario) {
	if (this->duennio) {
		delete this->duennio;
	}
	this->duennio = new Propietario();
	*(this->duennio) = *propietario;
}

string Mascota::getNombre() { return this->nombre; }
string Mascota::getAnimal() { return this->animal; }
Propietario* Mascota::getPropietario() { return this->duennio; }

string Mascota::toString() {
	stringstream s;

	s << "------ Mascota ------" << endl;
	s << "Nombre: " << " " << nombre << endl;
	s << "Tipo de animal: " << " " << animal << endl;

	if (duennio != nullptr) {
		s << duennio->toString() << endl;
	}
	else {
		s << "No existe propietario" << endl;
	}
	return s.str();
}
