#pragma once
#include "Propietario.h"
#include "string"
using namespace std;

class Propietario;

class Mascota
{
private:
	string nombre;
	string animal;
	Propietario* duennio;

public:
	Mascota();
	Mascota(string, string, Propietario*);
	virtual ~Mascota();
	
	void setNombre(string);
	void setAnimal(string);
	void setDuennio(Propietario*);
	
	string getNombre();
	string getAnimal();
	Propietario* getPropietario();
	
	string toString();
};
