#include <iostream>
#include "Interfaz.h"

using namespace std;

int main() {
    Interfaz* interfaz = new Interfaz();
    interfaz->Menu();

    delete interfaz;
    return 0;
}