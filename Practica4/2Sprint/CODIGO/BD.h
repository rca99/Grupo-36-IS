// BD.h
// Cabecera de la clase BD

#ifndef BD_H
#define BD_H

#include <list>
#include <string>
#include <vector>

#include "Alumno.h"

using namespace std;


class BD {

private:

	list <Alumno> listaAlumnos_;
	string nombreFichero_;
	int numeroAlumnos_;

public:

	inline BD(string nombreFichero="gestionAlumnos"){
		nombreFichero_=nombreFichero;
		numeroAlumnos_=0;
	};

	inline list <Alumno> getAlumnos() const {return listaAlumnos_;}
	inline void setAlumnos(list <Alumno> nuevalista) {listaAlumnos_=nuevalista;}
	inline string getNombreFichero() const {return nombreFichero_;}
	inline void setNombreFichero(string nuevonombre) {nombreFichero_=nuevonombre;}
	inline int getNumeroAlumnos() const {return numeroAlumnos_;}
	inline void setNumeroAlumnos(int num) {numeroAlumnos_=num;}
	inline void addNumeroAlumnos() {numeroAlumnos_++;}
	//bool introducirAlumno(Alumno nuevoAlumno){listaAlumnos_.push_back(nuevoAlumno);return 1;};

	bool introducirAlumno(Alumno &nuevoAlumno);
	bool modificarAlumno(Alumno alumnox, string dni);
	bool eliminarAlumno(Alumno alumnox);

	bool gestionLideres(Alumno alumnox, string dni="");

	void mostrarAlumno();
	void mostrarAlumno(list <Alumno> lista);
	void mostrarAlumno(int opcOrden, string orden);
	void mostrarAlumno(list <Alumno> lista,int opcOrden, string orden);

	void mostrarAlumnoHtml(int opcOrden, string orden);
	void mostrarAlumnoHtml(list <Alumno> lista,int opcOrden, string orden);

	void ordenLista(list <Alumno> &lista);
	void ordenLista();

	bool buscarAlumnos();
	bool buscarAlumnoDNI(list <Alumno> &lista, Alumno a);
	bool buscarAlumnoApellido(list <Alumno> &lista, Alumno a);
	bool buscarAlumnoEquipo(list <Alumno> &lista, int equipo);
	bool buscarAlumno(list <Alumno> &lista, int equipo);

	//Busqueda con vectores
	bool buscarAlumnoDNIv2(vector <Alumno> &vector, Alumno a);
	bool buscarAlumnoApellidov2(vector <Alumno> &vector, Alumno a);
	bool buscarAlumnoEquipov2(vector <Alumno> &vector, int equipo);

	bool guardarBD();
	bool cargarBD();
	bool guardarBackup();
	bool cargarBackup();
	
};

#endif