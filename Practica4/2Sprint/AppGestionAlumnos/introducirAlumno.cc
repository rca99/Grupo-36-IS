// Carlos Freire Caballero
// Clase : BD
// Funcion : introducirAlumno

#include <iostream>

#include "BD.h"
#include "Alumno.h"
#include "consoleLinux.h"
	
string ConvertirMayuscula(string cadena);


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
	/*
	Alumno alumnoMayusculas;
	alumnoMayusculas=nuevoAlumno;

	alumnoMayusculas.setNombre(ConvertirMayuscula(nuevoAlumno.getNombre()));
	alumnoMayusculas.setApellidos(ConvertirMayuscula(nuevoAlumno.getApellidos()));
	alumnoMayusculas.setDNI(ConvertirMayuscula(nuevoAlumno.getDNI()));
	listaAlumnos_.push_back(alumnoMayusculas);
	*/

	listaAlumnos_.push_back(nuevoAlumno);
	

	numeroAlumnos_++;

	return true;
}

string ConvertirMayuscula(string cadena){

  	locale loc;
 	string s=cadena;
 	
  	for (string::size_type i=0; i<s.length(); ++i){

  		 s[i]=toupper((s)[i],loc);
	
  	}


	return s;

}
