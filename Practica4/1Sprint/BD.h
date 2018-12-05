// BD.h
// Cabecera de la clase BD




#ifndef BD_H
#define BD_H

#include <list>
#include <string>
#include "Alumno.h"

using namespace std;


class BD{


private:

	list <Alumno> listaAlumnos_;
	string nombreFichero_;
	int numeroAlumnos_;


public:
	inline BD(string nombreFichero="gestionAlumnos"){

		nombreFichero_=nombreFichero;

	};
	bool introducirAlumno(Alumno newAlumno);
	bool guardarBD();
	bool cargarBD();
};


#endif
