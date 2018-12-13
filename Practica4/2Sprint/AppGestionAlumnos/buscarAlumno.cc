// funcion buscar alumno
// clase BD

#include "BD.h"
#include "Alumno.h"
#include <iostream>
#include <string>

using namespace std;

bool BD::buscarAlumno(list <Alumno> &lista, Alumno a) {
	// Comprueba que haya alumnos dados de alta
	int contador=0;
	if(getNumeroAlumnos()==0) {
		cout << "\nNo hay alumnos dados de alta en la base de datos" << endl << endl;
		return false;
	}

	list <Alumno> listaAuxiliar;

	listaAuxiliar=getAlumnos();
	list <Alumno> :: iterator i;

	for(i=listaAuxiliar.begin(); i!=listaAuxiliar.end(); i++) {
		if((*i).getDNI()==a.getDNI()) {
			(lista).push_back(*i);
			contador++;
		}
	}
	if (contador>0)
		return true;
	else return false;
}

bool BD::buscarAlumnoDNI(list <Alumno> &lista, Alumno a){
	// Comprueba que haya alumnos dados de alta
	int contador=0;
	if(getNumeroAlumnos()==0) {
		cout << "\nNo hay alumnos dados de alta en la base de datos" << endl << endl;
		return false;
	}

	list <Alumno> listaAuxiliar;

	listaAuxiliar=getAlumnos();
	list <Alumno> :: iterator i;

	for(i=listaAuxiliar.begin(); i!=listaAuxiliar.end(); i++) {
		if((*i).getDNI()==a.getDNI()) {
			(lista).push_back(*i);
			contador++;
		}
	}

	if (contador>0){
		return true;
	}
	else return false;
}

bool BD::buscarAlumnoApellido(list <Alumno> &lista, Alumno a){
	// Comprueba que haya alumnos dados de alta
	int contador=0;
	if(getNumeroAlumnos()==0) {
		cout << "\nNo hay alumnos dados de alta en la base de datos" << endl << endl;
		return false;
	}

	list <Alumno> listaAuxiliar;

	listaAuxiliar=getAlumnos();
	list <Alumno> :: iterator i;

	for(i=listaAuxiliar.begin(); i!=listaAuxiliar.end(); i++) {
		if((*i).getApellidos()==a.getApellidos()) {
			(lista).push_back(*i);
			contador++;
		}
	}

	if (contador>0){
		return true;
	}
	else{
		return false;
	}
}

bool BD::buscarAlumnoEquipo(list <Alumno> &lista, int equipo) {
	int contador=0;
	if(getNumeroAlumnos()==0) {
		cout << "\nNo hay alumnos dados de alta en la base de datos" << endl << endl;
		return false;
	}

	list <Alumno> listaAuxiliar;
	listaAuxiliar=getAlumnos();

	list <Alumno> :: iterator i;

	for(i=listaAuxiliar.begin(); i!=listaAuxiliar.end(); i++) {
		if((*i).getEquipo()==equipo) {
			(lista).push_back(*i);
			contador++;
		}
	}

	lista=listaAuxiliar;

	if (contador>0)
		return true;
	else return false;
}
