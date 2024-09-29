#include "Especialidad.h"

Especialidad::Especialidad() {
	nombre = "indef";
	id = "indef";
}
Especialidad::Especialidad(string nombre, string id) {
	this->setNombre(nombre);
	this->setID(id);
}
Especialidad::~Especialidad() {}

void Especialidad::setNombre(string nombre) {
	this->nombre = nombre;
}
void Especialidad::setID(string id) {
	this->id = id;
}
string Especialidad::getNombre() { return this->nombre; }
string Especialidad::getID() { return this->id; }

string Especialidad::toString() {
	stringstream s;

	s << "Especialidad :" << " " << nombre << endl;
	s << "Id de la especialidad :" << " " << id << endl;
	return s.str();
}