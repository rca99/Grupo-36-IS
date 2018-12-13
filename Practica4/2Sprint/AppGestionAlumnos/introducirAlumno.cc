// Carlos Freire Caballero
// Clase : BD
// Funcion : introducirAlumno

#include <iostream>

#include "BD.h"
#include "Alumno.h"

bool BD::introducirAlumno(Alumno nuevoAlumno) {
	if(nuevoAlumno.getLider()==true) {
		if(gestionLideres(nuevoAlumno)) {
			cout << "Este grupo ya tiene lider" << endl;
			return false;
		}
	}

	listaAlumnos_.push_back(nuevoAlumno);
	numeroAlumnos_++;

	return true;
}