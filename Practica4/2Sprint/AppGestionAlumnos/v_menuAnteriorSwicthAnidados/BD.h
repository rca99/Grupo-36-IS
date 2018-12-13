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

	inline list <Alumno> getAlumnos() const {return listaAlumnos_;}
	inline void setAlumnos(list <Alumno> nuevalista){listaAlumnos_=nuevalista;};
	inline string getNombreFichero() const {return nombreFichero_;}
	inline void setNombreFichero(string nuevonombre){nombreFichero_=nuevonombre;}
	inline int getNumeroAlumnos() const {return numeroAlumnos_;}
	inline void addNumeroAlumnos(){numeroAlumnos_++;};
	bool introducirAlumno(Alumno nuevoAlumno){listaAlumnos_.push_back(nuevoAlumno);return 1;};

	
	bool modificarAlumno(Alumno alumnox);
	bool eliminarAlumno(Alumno alumnox);
	bool buscarAlumno(list <Alumno> &lista, Alumno a);
	bool buscarAlumnoDNI(list <Alumno> &lista, Alumno a);
	bool buscarAlumnoApellido(list <Alumno> &lista, Alumno a);
	void mostrarAlumno(list <Alumno> lista, int opcionOrden, string orden);
	void mostrarAlumno(int opcionOrden, string orden);
	bool buscarAlumno(list <Alumno> &lista, int equipo);
	
	//list <Alumno> buscarAlumno(int grupo);

	inline BD(string nombreFichero="gestionAlumnos"){

		nombreFichero_=nombreFichero;
		numeroAlumnos_=0;

	};
	bool guardarBD();
	bool cargarBD();
	bool guardarBackup();
	bool cargarBackup();
	
};


#endif
