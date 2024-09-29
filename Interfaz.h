#pragma once
#define INTERFAZ_H
#include "EspecialidadLista.h";
#include "DoctorLista.h";
#include "PropietarioLista.h";
#include "MascotaLista.h";

class Interfaz
{
private:
	EspecialidadLista* EspeciLista;
	DoctorLista* DocLista;
	PropietarioLista* PropiLista;
	MascotaLista* MascLista;
public:
	Interfaz();

	void Menu();

	void SubmenuAdministracion();
	void opcion1_1();
	void opcion2_1();
	void opcion3_1();
	void opcion4_1();

	void SubmenuControlCitas();
	void opcion1_2();
	void opcion2_2();
	void opcion3_2();
	void opcion4_2();

	void SubmenuBusqueda();
	void opcion1_3();
	void opcion2_3();
	void opcion3_3();
	void opcion4_3();
};