#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Especialidad
{
private:
	string nombre;
	string id;
public:
	Especialidad();
	Especialidad(string, string);
	virtual ~Especialidad();

	void setNombre(string);
	void setID(string);

	string getNombre();
	string getID();

	string toString();
};
