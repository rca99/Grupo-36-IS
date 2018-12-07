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

	inline BD(string nombreFichero="gestionAlumnos"){nombreFichero_=nombreFichero;}
	inline list <Alumno> getAlumnos() const {return listaAlumno;}
	void setAlumnos(list <Alumno> nuevalista);
	inline getNombreFichero() const {return nombrefichero;}
	void setNombreFichero(string nuevonombre);
	inline int getNumeroAlumnos() const {return numeroalumnos};
	void setNumeroAlumnos();
	bool introducirAlumno(Alumno nuevoAlumno);
	bool modificarAlumno(Alumno alumnox);
	bool eliminarAlumno(Alumno alumnox);
	bool buscarAlumno(Alumno alumnox);
	//list <Alumno> buscarAlumno(int grupo);
	bool guardarBD();
	bool cargarBD();
	bool guardarBackup();
	bool cargarBackup();
	
};


#endif
