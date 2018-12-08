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
<<<<<<< HEAD

	inline BD(string nombreFichero="gestionAlumnos"){nombreFichero_=nombreFichero;}
	inline list <Alumno> getAlumnos() const {return listaAlumnos_;}
	void setAlumnos(list <Alumno> nuevalista);
	inline string getNombreFichero() const {return nombreFichero_;}
	void setNombreFichero(string nuevonombre);
	inline int getNumeroAlumnos() const {return numeroAlumnos_;}
	void setNumeroAlumnos();
	bool introducirAlumno(Alumno nuevoAlumno);
	bool modificarAlumno(Alumno alumnox);
	bool eliminarAlumno(Alumno alumnox);
	bool buscarAlumno(Alumno alumnox);
	//list <Alumno> buscarAlumno(int grupo);
=======
	BD(string nombreFichero="gestionAlumnos"){

		nombreFichero_=nombreFichero;
		numeroAlumnos_=0;

	};
>>>>>>> 2139134f0f03f5ef81a03edde1493763111931d6
	bool guardarBD();
	bool cargarBD();
	bool guardarBackup();
	bool cargarBackup();
	
};


#endif