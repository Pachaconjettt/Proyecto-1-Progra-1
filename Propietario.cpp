#include "Propietario.h"

Propietario::Propietario() {
	this->nombre = "indef";
	this->id = "indef";
}
Propietario::Propietario(string nombre, string id) {
	this->setNombre(nombre);
	this->setID(id);
}
Propietario::~Propietario() {}

void Propietario::setID(string id) {
	this->id = id;
}
void Propietario::setNombre(string nombre) {
	this->nombre = nombre;
}

string Propietario::getID() { return this->id; }
string Propietario::getNombre() { return this->nombre; }

string Propietario::toString() {
	stringstream s;

	s << "Nombre del duenno: " << " " << nombre << endl;
	s << "Id del duenno: " << " " << id << endl;
	return s.str();
}
