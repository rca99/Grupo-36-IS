// Carlos Freire Caballero
// Clase : BD
// Funcion : introducirAlumno

#include <iostream>

#include "BD.h"
#include "Alumno.h"
#include "consoleLinux.h"

bool BD::introducirAlumno(Alumno &nuevoAlumno) {
	if(nuevoAlumno.getLider()==true) {
		if(gestionLideres(nuevoAlumno)==false) {
			int opc=0;
			cout << BOLD_RED << "\n\tESTE GRUPO YA TIENE LIDER" << endl;
			cout << COLOR_BRIGHTGREEN << "\n\tPULSE 1 SI DESEA INTRODUCIR EL ALUMNO SIN SER LIDER: " << COLOR_BRIGHTBLUE;
			cin >> opc;
			cout << RESET;
			if(opc != 1) {
				return false;
			}
			nuevoAlumno.setLider(false);
		}
	}

	listaAlumnos_.push_back(nuevoAlumno);
	numeroAlumnos_++;

	return true;
}