#include "Interfaz.h"

Interfaz::Interfaz() {
	this->PropiLista = new PropietarioLista();
	this->DocLista = new DoctorLista();
	this->MascLista = new MascotaLista();
	this->EspeciLista = new EspecialidadLista();
}

void Interfaz::Menu() {
	int opcion = 1;

	while (opcion != 0) {

		cout << "---------------MENU PRINICIPAL--------------" << endl;
		cout << "(1) Submenu Administracion" << endl;
		cout << "(2) Submenu Control de Citas" << endl;
		cout << "(3) Submenu Busquedas y Listados" << endl;
		cout << "(0) Salir " << endl;
		cout << "---------------------------------------------" << endl;
		cout << "Digite una opcion del menu: ";
		cin >> opcion;

		switch (opcion) {
		case 1: {
			system("cls");
			SubmenuAdministracion();
			break;
		}
		case 2: {
			system("cls");
			SubmenuControlCitas();
			break;
		}
		case 3: {
			system("cls");
			SubmenuBusqueda();
			break;
		}
		case 0: {
			cout << "Saliendo del programa..." << endl;
			break;
		}
		default: {
			cout << "Opcion invalida." << endl;
			cin.ignore();
			cin.get();
			break;
		}
		}
		system("cls");
	}
	exit(0);
	system("cls");
}

void Interfaz::SubmenuAdministracion() {
	int opcionSubmenu1 = 1;

	while (opcionSubmenu1 != 0) {

		cout << "-------------------SUBMENU ADMINISTRACION-----------------" << endl;
		cout << "(1) Ingresar Especialidades" << endl;
		cout << "(2) Ingresar Doctor" << endl;
		cout << "(3) Ingresar Duennio" << endl;
		cout << "(4) Ingresar Mascota" << endl;
		cout << "(0) Regresar al menu principal" << endl << endl;
		cout << "------------------------------------------------------------" << endl;
		cout << "Digite una opcion del submenu: ";
		cin >> opcionSubmenu1;

		switch (opcionSubmenu1) {
		case 1: {
			system("cls");
			opcion1_1();

			cin.ignore();
			cin.get();
			break;
		}
		case 2: {
			system("cls");
			opcion2_1();

			cin.ignore();
			cin.get();
			break;
		}
		case 3: {
			system("cls");
			opcion3_1();

			cin.ignore();
			cin.get();
			break;
		}
		case 4: {
			system("cls");
			opcion4_1();

			cin.ignore();
			cin.get();
			break;
		}
		case 0: {
			break;
		}
		default: {
			cout << "Opcion invalida." << endl;
			cin.ignore();
			cin.get();
			break;
		}
		}
		system("cls");
	}
	system("cls");
}
void Interfaz::opcion1_1() {
	string nombre;
	string id;
	Especialidad* especi = nullptr;

	cout << "-------------------------------(1) Ingresar Especialidad --------------------------" << endl;
	cout << "Ingresa el nombre de la especialidad: ";
	cin >> nombre;
	cout << endl;
	cout << "Ingresa el id de la especialidad: ";
	cin >> id;

	especi = new Especialidad(nombre, id);

	if (EspeciLista->AgregarEspecialidad(especi) == true) {
		system("cls");
		cout << "Especialidad registarda con exito!" << endl;
	}
	else {
		system("cls");
		cout << "Error registarando especialidad." << endl;
	}
	delete especi;
}
void Interfaz::opcion2_1() {
	cout << "------------------(2) Ingresar Doctor -----------------------------" << endl;
	if (EspeciLista->RetornoEspecialidad() == "") {
		cout << "No hay especialidades disponibles, por lo tanto, no se puede agregar doctores." << endl;
	}
	else {
		string nombre;
		string id;
		string Idirector;
		Especialidad* aux = nullptr;
		Doctor* doctorUI = nullptr;
		Matrix* horario = new Matrix();

		cout << "Nombre de doctor: ";
		cin >> nombre;
		cout << endl;
		cout << "ID del doctor: ";
		cin >> id;

		system("cls");
		cout << EspeciLista->RetornoEspecialidad() << endl;
		cout << "Ingresa nombre de especialidad: ";
		cin >> Idirector;

		aux = EspeciLista->buscarEspecialidad(Idirector);

		while (aux == nullptr) {
			system("cls");
			cout << EspeciLista->RetornoEspecialidad() << endl;
			cout << "Especialidad invalida. Intente de nuevo: ";
			cin >> Idirector;
		}

		doctorUI = new Doctor(nombre, id, EspeciLista->buscarEspecialidad(Idirector), horario);

		if (DocLista->AgregarDoctor(doctorUI) == true) {
			system("cls");
			cout << "Doctor ingresado con exito!" << endl;
		}
		else {
			system("cls");
			cout << "Error registrando doctor." << endl;
		}
		delete aux;
		delete doctorUI;
		delete horario;
	}
}
void Interfaz::opcion3_1() {
	string nombre;
	string id;
	Propietario* due = nullptr;

	cout << "------------------------------(3) Ingresar Duennio-------------------------" << endl;
	cout << "Ingrese el nombre del duennio: ";
	cin >> nombre;
	cout << endl;
	cout << "Ingrese el id del duennio: ";
	cin >> id;

	due = new Propietario(nombre, id);

	if (PropiLista->AgregarPropietario(due) == true) {
		system("cls");
		cout << "Duenio registardo con exito!" << endl;
	}
	else {
		system("cls");
		cout << "Error registarndo al duenio." << endl;
	}
}
void Interfaz::opcion4_1() {
	cout << "--------------------------------------(4) Ingresar Mascota-----------------------" << endl;
	if (PropiLista->RetornoListaPropietario() == "") {
		cout << "No hay duenios registrados, por lo tanto, no se puede ingresar una mascota." << endl;
	}
	else {
		string nombre;
		string animal;
		string idPropietario;
		Propietario* aux = nullptr;
		Mascota* mascotaUI = nullptr;

		cout << "Ingrese el nombre de la mascota: ";
		cin >> nombre;
		cout << endl;
		cout << "Ingrese que animal es: ";
		cin >> animal;

		system("cls");
		cout << PropiLista->RetornoListaPropietario() << endl;
		cout << "Ingrese el id del duennio: ";
		cin >> idPropietario;

		aux = PropiLista->BuscarPropietario(idPropietario);

		while (aux == nullptr) {
			system("cls");
			cout << PropiLista->RetornoListaPropietario() << endl;
			cout << "Id invalido. Intente de nuevo: ";
			cin >> idPropietario;
			aux = PropiLista->BuscarPropietario(idPropietario);
		}

		mascotaUI = new Mascota(nombre, animal, PropiLista->BuscarPropietario(idPropietario));

		if (MascLista->AgregarMascota(mascotaUI) == true) {
			system("cls");
			cout << "Mascota registrada con exito!" << endl;
		}
		else {
			system("cls");
			cout << "Error registarando mascota." << endl;
		}
		delete aux;
		delete mascotaUI;
	}
}

void Interfaz::SubmenuControlCitas() {
	int opcionSubmenu2 = 1;

	while (opcionSubmenu2 != 0) {

		cout << "--------------------------- SUBMENU CONTROL CITAS -------------------------------" << endl;
		cout << "(1) Sacar Cita" << endl;
		cout << "(2) Cancelar Cita" << endl;
		cout << "(3) Mostar calendario de citas por doctor" << endl;
		cout << "(4) Mostar citas por duennio" << endl;
		cout << "(0) Regresar al menu principal" << endl << endl;
		cout << "-----------------------------------------------------------------------------------" << endl;
		cout << "Digite una opcion del submenu: ";
		cin >> opcionSubmenu2;

		switch (opcionSubmenu2) {
		case 1: {
			system("cls");
			opcion1_2();

			cin.ignore();
			cin.get();
			break;
		}
		case 2: {
			system("cls");
			opcion2_2();

			cin.ignore();
			cin.get();
			break;
		}
		case 3: {
			system("cls");
			opcion3_2();

			cin.ignore();
			cin.get();
			break;
		}
		case 4: {
			system("cls");
			opcion4_2();

			cin.ignore();
			cin.get();
			break;
		}
		case 0: {
			break;
		}
		default: {
			cout << "Opcion ivalida." << endl;
			cin.ignore();
			cin.get();
			break;
		}
		}
		system("cls");
	}
	system("cls");
}
void Interfaz::opcion1_2() {
	cout << "-----------------------SACAR CITA---------------------" << endl;
	if (PropiLista->RetornoListaPropietario() == "") {
		cout << "No hay propietarios registardos." << endl;
	}
	else if (DocLista->RetornoDoctor() == "") {
		cout << "No hay doctores registrados." << endl;
	}
	else {
		string id;
		string nombre;
		string nombreEspeci;
		string IdDoctor;
		int vec[2];
		Propietario* aux = nullptr;
		Mascota* mascotaUI = nullptr;
		Especialidad* especialidadUI = nullptr;
		Doctor* doctorUI = nullptr;

		cout << "Ingrese el id del duennio de las mascota/s: ";
		cin >> id;

		aux = PropiLista->BuscarPropietario(id);

		while (aux == nullptr) {
			system("cls");
			cout << "Id invalido. Intente de nuevo: ";
			cin >> id;
			aux = PropiLista->BuscarPropietario(id);
		}
		if (MascLista->ListasDeMascotaDe(aux) == "") {
			system("cls");
			cout << "El propietario no tiene mascotas registardas." << endl;
		}
		else {
			cout << endl;
			cout << MascLista->ListasDeMascotaDe(aux);
			cout << "Cual mascota quiere elegir: ";
			cin >> nombre;

			mascotaUI = MascLista->buscarMascota(nombre);

			while (mascotaUI == nullptr) {
				system("cls");
				cout << MascLista->ListasDeMascotaDe(aux) << endl;
				cout << "Nombre de mascota no registrado. Ingreselo otra vez: ";
				cin >> nombre;
				mascotaUI = MascLista->buscarMascota(nombre);
			}
			system("cls");
			cout << EspeciLista->RetornoEspecialidad() << endl;
			cout << "Ingrese el nombre de la especialidad deseada: ";
			cin >> nombreEspeci;

			especialidadUI = EspeciLista->buscarEspecialidad(nombreEspeci);

			while (especialidadUI == nullptr) {
				system("cls");
				cout << EspeciLista->RetornoEspecialidad() << endl << endl;
				cout << "Especialidad no registrada. Intente de nuevo: ";
				cin >> nombreEspeci;
				especialidadUI = EspeciLista->buscarEspecialidad(nombreEspeci);
			}
			cout << endl;
			cout << DocLista->ListaDoctoresEspecialidad(especialidadUI);
			cout << "Ingrese el id del doctor al que le gustaria ser atendido: ";
			cin >> IdDoctor;

			doctorUI = DocLista->buscarDoctor(IdDoctor);

			while (doctorUI == nullptr) {
				system("cls");
				cout << DocLista->ListaDoctoresEspecialidad(EspeciLista->buscarEspecialidad(nombreEspeci)) << endl;
				cout << "Id invalido. Intente de nuevo: ";
				cin >> IdDoctor;
				doctorUI = DocLista->buscarDoctor(IdDoctor);
			}
			system("cls");
			cout << "HORARIO DEL DOCTOR SELECCIONADO: " << endl << endl;
			cout << DocLista->HorarioDeDoctor(doctorUI) << endl;

			cout << "ELIJA UNA HORA Y UN DIA DISPONIBLE PARA LA CITA: " << endl << endl;
			cout << "Ingrese la hora (8-19): ";
			cin >> vec[0];

			cout << endl;
			cout << "Ingrese el dia (0-5, donde 0 es Lunes y 5 es sabado): ";
			cin >> vec[1];
			DocLista->ingresarHoraCita(vec, mascotaUI, doctorUI);
			cout << endl;

			system("cls");
			cout << DocLista->HorarioDeDoctor(doctorUI) << endl;
			cout << "Cita registrada con exito!" << endl;
		}
		delete aux;
		delete mascotaUI;
		delete doctorUI;
		delete especialidadUI;
	}
}
void Interfaz::opcion2_2() {
	cout << "-------------------CANCELAR CITA----------------------" << endl;
	if (PropiLista->RetornoListaPropietario() == "") {
		cout << "No hay propietarios registardos." << endl;
	}
	else if (DocLista->RetornoDoctor() == "") {
		cout << "No hay doctores registrados." << endl;
	}
	else {
		string idDuennio;
		string idDoctor;
		string masct;
		int dia;
		int hora;
		Propietario* duenioUI = nullptr;
		Doctor* doctorUI = nullptr;
		Mascota* mascotaUI = nullptr;

		cout << "Ingrese el id del duennio: ";
		cin >> idDuennio;

		duenioUI = PropiLista->BuscarPropietario(idDuennio);

		while (duenioUI == nullptr) {
			system("cls");
			cout << "Id invalido. Intente de nuevo: ";
			cin >> idDuennio;
			duenioUI = PropiLista->BuscarPropietario(idDuennio);
		}
		if (MascLista->ListasDeMascotaDe(duenioUI) == "") {
			cout << "El propietario no tiene mascotas registardas." << endl;
		}
		else {
			if (DocLista->ListaDoctoresXIdCita(idDuennio) == "") {
				cout << "No tiene citas registaradas." << endl;
			}
			else {
				cout << endl;
				cout << "Doctores con los que tiene cita: " << endl << endl;
				cout << DocLista->ListaDoctoresXIdCita(idDuennio);
				cout << "Ingrese el id doctor que quiere cancelar la cita: ";
				cin >> idDoctor;

				doctorUI = DocLista->buscarDoctor(idDoctor);

				while (doctorUI == nullptr) {
					system("cls");
					cout << "Doctores con los que tiene cita: " << endl << endl;
					cout << DocLista->ListaDoctoresXIdCita(idDuennio) << endl;
					cout << "Id invalido. Intente de nuevo: ";
					cin >> idDoctor;
					doctorUI = DocLista->buscarDoctor(idDoctor);
				}
				system("cls");
				cout << DocLista->HorarioDeDoctor(doctorUI) << endl;
				cout << endl;
				cout << MascLista->ListasDeMascotaDe(duenioUI);
				cout << "Digite el nombre de la mascota: ";
				cin >> masct;

				mascotaUI = MascLista->buscarMascota(masct);

				while (mascotaUI == nullptr) {
					system("cls");
					cout << DocLista->HorarioDeDoctor(doctorUI) << endl;
					cout << MascLista->ListasDeMascotaDe(duenioUI) << endl;
					cout << "Nombre de mascota no registrado. Ingreselo otra vez: ";
					cin >> masct;
					mascotaUI = MascLista->buscarMascota(masct);
				}
				cout << endl;
				cout << "Ingrese el dia que quiere quitar la mascota (Lunes es 0 y Domingo es 5): ";
				cin >> dia;
				cout << endl;
				cout << "Ingrese la hora del dia que quiere quitar (8-19): ";
				cin >> hora;

				DocLista->eliminarCita(dia, hora, masct, doctorUI);

				system("cls");
				cout << "Horario del doctor actualizado: " << endl;
				cout << endl;
				cout << DocLista->HorarioDeDoctor(doctorUI) << endl;
				cout << "Cita cancelada con exito!" << endl;
			}
		}
		delete duenioUI;
		delete doctorUI;
		delete mascotaUI;
	}
}
void Interfaz::opcion3_2() {
	cout << "---------------- MOSTRAR CALENDARIO DE CITAS POR DOCTOR -------------------" << endl;
	if (DocLista->RetornoDoctor() == "") {
		cout << "No hay doctores registrados." << endl;
	}
	else {
		string nombre;
		Doctor* doctorUI = nullptr;

		cout << DocLista->RetornoDoctor() << endl;
		cout << "Ingrese el id del doctor para saber el calendario de este mismo: ";
		cin >> nombre;

		doctorUI = DocLista->buscarDoctor(nombre);

		while (doctorUI == nullptr) {
			system("cls");
			cout << DocLista->RetornoDoctor() << endl;
			cout << "Id invalido. Intente de nuevo: ";
			cin >> nombre;
			doctorUI = DocLista->buscarDoctor(nombre);
		}
		system("cls");
		cout << "Horario del doctor solicitado :" << endl;
		cout << endl;
		cout << DocLista->HorarioDeDoctor(doctorUI) << endl;

		delete doctorUI;
	}
}
void Interfaz::opcion4_2() {
	cout << "----------------- MOSTRAR CITAS POR PROPIETARIO ---------------" << endl;
	if (PropiLista->RetornoListaPropietario() == "") {
		cout << "No hay duenios registrados." << endl;
	}
	else {
		string nombre;
		string mascotaName;
		Propietario* duenioUI = nullptr;
		Mascota* mascotaUI = nullptr;

		cout << "Ingrese el id del propietario: ";
		cin >> nombre;

		duenioUI = PropiLista->BuscarPropietario(nombre);

		while (duenioUI == nullptr) {
			system("cls");
			cout << "Id invalido. Intente de nuevo: ";
			cin >> nombre;
			duenioUI = PropiLista->BuscarPropietario(nombre);
		}
		if (MascLista->ListasDeMascotaDe(duenioUI) == "") {
			cout << "El propietario no tiene mascotas registardas." << endl;
		}
		else {
			system("cls");
			cout << "Lista de mascotas del propietario: " << endl;
			cout << endl;
			cout << MascLista->ListasDeMascotaDe(PropiLista->BuscarPropietario(nombre));
			cout << "Escriba el nombre de la mascota (Sin agregar mayusculas o algun cambio pequenio): ";
			cin >> mascotaName;

			mascotaUI = MascLista->buscarMascota(mascotaName);

			while (mascotaUI == nullptr) {
				system("cls");
				cout << MascLista->ListasDeMascotaDe(duenioUI) << endl;
				cout << "Masocta no registrada. Intente de nuevo: ";
				cin >> mascotaName;
				mascotaUI = MascLista->buscarMascota(mascotaName);
			}
			if (DocLista->BuscarNombreEspecifico(mascotaName) == "") {
				cout << "La mascota no tiene citas registradadas." << endl;
			}
			else {
				cout << "Citas que tiene la mascota: " << endl << endl;
				cout << DocLista->BuscarNombreEspecifico(mascotaName) << endl;
			}
		}
		delete duenioUI;
		delete mascotaUI;
	}
}

void Interfaz::SubmenuBusqueda() {
	int opcionSubmenu3 = 1;

	while (opcionSubmenu3 != 0) {

		cout << "-------------------------- SUBMENU BUSQUEDA Y LISTADO ----------------------------" << endl;
		cout << "(1) Mostrar Listado de Especialidades" << endl;
		cout << "(2) Mostar Lista de Doctores por Especialidad" << endl;
		cout << "(3) Mostar Duennios con sus Mascotas" << endl;
		cout << "(4) Mostrar Pacientes por doctor" << endl;
		cout << "(0) Regresar al Menu Principal" << endl;
		cout << "----------------------------------------------------------------------------------" << endl;
		cout << "Digite una opcion del submenu: ";
		cin >> opcionSubmenu3;

		switch (opcionSubmenu3) {
		case 1: {
			system("cls");
			opcion1_3();

			cin.ignore();
			cin.get();
			break;
		}
		case 2: {
			system("cls");
			opcion2_3();

			cin.ignore();
			cin.get();
			break;
		}
		case 3: {
			system("cls");
			opcion3_3();

			cin.ignore();
			cin.get();
			break;
		}
		case 4: {
			system("cls");
			opcion4_3();

			cin.ignore();
			cin.get();
			break;
		}
		case 0: {
			break;
		}
		default: {
			cout << "Opcion invalida.";
			cin.ignore();
			cin.get();
			break;
		}
		}
		system("cls");
	}
	system("cls");
}
void Interfaz::opcion1_3() {
	cout << "---------------------------- Mostrar Especialidades Existentes ---------------------" << endl << endl;
	if (EspeciLista->RetornoEspecialidad() == "") {
		cout << "No hay especialidades registradas." << endl;
	}
	else {
		cout << EspeciLista->RetornoEspecialidad() << endl;
	}
}
void Interfaz::opcion2_3() {
	cout << "---------------------------- Mostrar Doctores Por Especialidad ---------------------" << endl << endl;
	if (EspeciLista->RetornoEspecialidad() == "") {
		cout << "No hay especialidades registradas." << endl;
	} 
	else {
		string aux_especialidad;
		Especialidad* especialidadUI = nullptr;

		cout << EspeciLista->RetornoEspecialidad() << endl;
		cout << "Digite el nombre de una especialidad para ver sus doctores: ";
		cin >> aux_especialidad;

		especialidadUI = EspeciLista->buscarEspecialidad(aux_especialidad);

		while (especialidadUI == nullptr) {
			system("cls");
			cout << EspeciLista->RetornoEspecialidad() << endl << endl;
			cout << "Especialidad no registrada. Intente de nuevo: ";
			cin >> aux_especialidad;
			especialidadUI = EspeciLista->buscarEspecialidad(aux_especialidad);
		}
		system("cls");
		cout << DocLista->ListaDoctoresEspecialidad(especialidadUI) << endl;

		delete especialidadUI;
	}
}
void Interfaz::opcion3_3() {
	cout << "---------------------------- Mostrar Duenios y sus Mascotas ---------------------" << endl << endl;
	if (PropiLista->RetornoListaPropietario() == "") {
		cout << "No hay duenios registrados." << endl;
	}
	else {
		string id;
		Propietario* duenioUI = nullptr;
		cout << "Digite el id del duenio del cual quiera ver sus mascotas : ";
		cin >> id;

		duenioUI = PropiLista->BuscarPropietario(id);

		while (duenioUI == nullptr) {
			system("cls");
			cout << "Id invalido. Intente de nuevo: ";
			cin >> id;
			duenioUI = PropiLista->BuscarPropietario(id);
		}
		system("cls");
		if (MascLista->ListasDeMascotaDe(duenioUI) == "") {
			cout << "El duenio no tiene mascotas registradas." << endl;
		}
		else {
			cout << MascLista->ListasDeMascotaDe(duenioUI) << endl;
		}
		delete duenioUI;
	}
}
void Interfaz::opcion4_3() {
	cout << "---------------------------- Mostrar Pacienres por Doctor ---------------------" << endl << endl;
	if (DocLista->RetornoDoctor() == "") {
		cout << "No hay doctores registrados." << endl;
	}
	else {
		string id;
		Doctor* aux = nullptr;
		cout << "Digite el id del doctor del cual quiera ver sus pacientes: ";
		cin >> id;

		aux = DocLista->buscarDoctor(id);

		while (aux == nullptr) {
			system("cls");
			cout << "Id invalido. Intente de nuevo: ";
			cin >> id;
			aux = DocLista->buscarDoctor(id);
		}
		system("cls");
		if (aux->getMatrix()->ImprimirPropietariosXDoctor() == "") {
			cout << "El doctor no tiene pacientes." << endl;
		}
		else {
			cout << aux->getMatrix()->ImprimirPropietariosXDoctor() << endl;
		}
		delete aux;
	}
}