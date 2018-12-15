// funcion eliminar alumno
// clase BD

#include "BD.h"
#include "Alumno.h"
#include "consoleLinux.h"
#include <iostream>
#include <list>
#include <string>

using namespace std;

bool BD::eliminarAlumno(Alumno alumnox, string dni) {

	list <Alumno> :: iterator i;

	for(i=listaAlumnos_.begin(); i!=listaAlumnos_.end(); i++) {
		if((*i).getDNI()==dni) {
			listaAlumnos_.pop_back();
			return true;
		}
	}

	return false;
}



