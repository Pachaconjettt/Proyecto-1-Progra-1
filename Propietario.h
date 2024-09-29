#pragma once
#include "Doctor.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Propietario
{
private:
	string id;
	string nombre;
public:
	Propietario();
	Propietario(string, string);
	virtual ~Propietario();
	
	void setID(string);
	void setNombre(string);
	
	string getID();
	string getNombre();

	string toString();
};