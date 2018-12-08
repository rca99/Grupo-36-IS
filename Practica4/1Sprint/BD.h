// BD.h
// Cabecera de la clase BD




//BD.h





#ifndef BD_H
#define BD_H

#include "Alumno.h"
#include <list>
#include <string>



using namespace std;


class BD{


private:

	list <Alumno> listaAlumnos_;
	string nombreFichero_;
	int numeroAlumnos_;


public:
	BD(string nombreFichero="gestionAlumnos"){

		nombreFichero_=nombreFichero;
		numeroAlumnos_=0;

	};
	bool guardarBD();
	bool cargarBD();
};


#endif