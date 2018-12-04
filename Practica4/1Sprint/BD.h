//BD.h





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


public:
	BD(string nombreFichero="gestionAlumnos"){

		nombreFichero_=nombreFichero;

	};
	bool guardarBD();
	bool cargarBD();
};


#endif
