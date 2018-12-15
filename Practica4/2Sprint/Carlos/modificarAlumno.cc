#include <iostream>

#include "BD.h"
#include "Alumno.h"
#include "consoleLinux.h"

using namespace std;

bool BD::modificarAlumno(Alumno alumnox, string dni) {

	if(alumnox.getLider()==true) {
		if(gestionLideres(alumnox, dni)==false) {
			int opc=0;
			cout << BOLD_RED << "\n\tESTE GRUPO YA TIENE LIDER" << endl;
			cout << COLOR_BRIGHTGREEN << "\n\tPULSE 1 SI DESEA MODIFICAR EL ALUMNO SIN SER LIDER: " << COLOR_BRIGHTBLUE;
			cin >> opc;
			cout << RESET;
			if(opc != 1)
				return false;
			alumnox.setLider(false);
		}
	}

	list <Alumno> :: iterator i;

	for(i=listaAlumnos_.begin(); i!=listaAlumnos_.end(); i++) {
		if((*i).getDNI()==dni) {
			*i=alumnox;
			return true;
		}
	}

	return false;
}