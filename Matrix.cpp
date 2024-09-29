#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

Matrix::Matrix() {
    columnas = 6;
    filas = 12;
    horasOcupadas = 0;
    matriz = new Mascota * *[columnas];

    for (int i = 0; i < columnas; i++) {
        matriz[i] = new Mascota * [filas];

        for (int j = 0; j < filas; j++) {
            matriz[i][j] = new Mascota();
        }
    }
}
Matrix::~Matrix() {
    for (int i = 0; i < columnas; i++) {
        for (int j = 0; j < filas; j++) {
            delete matriz[i][j];
        }
        delete[] matriz[i];
    }
    delete[] matriz;
}

string Matrix::ingresarCita(int vec[], Mascota* paciente) {
    stringstream s;
    int dia = vec[1];
    int hora = vec[0];

    if (hora < 8 || hora > 19 || dia < 0 || dia >= columnas) {
        s << "Curso no pudo ser ingresado. Dia o hora incorrectos.....\n";
    }
    else {
        *matriz[dia][hora - 8] = *paciente;
        horasOcupadas++;
        s << "Cita ingresada exitosamente. \n";
    }
    return s.str();
}
string Matrix::eliminarCita(int dia, int hora, string paciente) {
    stringstream s;

    if (dia < 0 || dia >= columnas || hora < 8 || hora > 19) {
        s << "Dia o hora incorrectos." << endl;
    }

    int horaIndex = hora - 8;

    if (matriz[dia][horaIndex]->getNombre() == paciente) {
        delete matriz[dia][horaIndex];
        matriz[dia][horaIndex] = new Mascota();
        horasOcupadas--;
        s << "Cita eliminada exitosamente." << endl;
    }
    else {
        s << "No se encontró una cita para la mascota en la hora y día especificados." << endl;
    }
    return s.str();
}
bool Matrix::BuscarPropietarioXMascota(string matrix) {
    bool condicion = false;

    for (int i = 0; i < columnas; i++) {
        for (int j = 0; j < filas; j++) {
            if (matriz[i][j]->getPropietario()->getID() == matrix) {
                condicion = true;
                break;
            }
        }
        if (condicion) {
            break;
        }
    }
    return condicion;
}
string Matrix::ImprimirPropietariosXDoctor() {
   stringstream s;

    for (int i = 0; i < columnas; i++) {
        for (int j = 0; j < filas; j++) {
            if (matriz[i][j]->getNombre() != "Disponible") {
                    s << matriz[i][j]->toString() << endl;
            }
        }
    }
    return s.str();
}
string Matrix::buscarNombreEspecifico(string nueva) {
    stringstream citas;
    string dias[] = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };

    for (int i = 0; i < columnas; i++) {
        for (int j = 0; j < filas; j++) {
            if (matriz[i][j]->getNombre() == nueva) {
                int horaReal = j + 8;
                citas << dias[i] << " a las " << horaReal << ":00\n";
            }
        }
    }
    return citas.str();
}

string Matrix::pintarMatriz() {
    stringstream t;
    string dias[] = { "Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado" };
    int ancho_columnas = 12;
    int longitud_total = (ancho_columnas * columnas) + (columnas + 18);

    t << " Hora  |  " << setw(ancho_columnas) << left << dias[0]
        << "|  " << setw(ancho_columnas) << left << dias[1]
        << "|  " << setw(ancho_columnas) << left << dias[2]
        << "|  " << setw(ancho_columnas) << left << dias[3]
        << "|  " << setw(ancho_columnas) << left << dias[4]
        << "|  " << setw(ancho_columnas) << left << dias[5] << "|\n";
    t << string(longitud_total, '-') << endl;

    for (int hora = 0; hora < filas; hora++) {
        int horaReal = hora + 8;

        t << (horaReal < 10 ? " " : "") << horaReal << ":00  |";
        for (int dia = 0; dia < columnas; dia++) {
            t << "  " << setw(ancho_columnas) << left << matriz[dia][hora]->getNombre() << "|";
        }
        t << endl;
        t << string(longitud_total, '-') << endl;
    }
    return t.str();
}
