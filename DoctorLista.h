#pragma once
#include "Doctor.h"
class DoctorLista
{
private:
	int cantidad;
	int tamano;
	Doctor** vector;
	void inicializarVector() {
		for (int i = 0; i < cantidad; i++) {
			vector[i] = new Doctor();
		}
	}
public:
	DoctorLista();
	DoctorLista(int);
	virtual ~DoctorLista();

	Doctor* buscarDoctor(string);
	bool AgregarDoctor(Doctor*);
	void ingresarHoraCita(int vec[], Mascota*, Doctor*);
	void eliminarCita(int dia, int hora, string, Doctor*);
	string BuscarNombreEspecifico(string);
	string ListaDoctoresEspecialidad(Especialidad*);
	string ListaDoctoresXIdCita(string);
	string RetornoDoctor();
	string HorarioDeDoctor(Doctor*);
};

