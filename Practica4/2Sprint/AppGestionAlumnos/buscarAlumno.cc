// funcion buscar alumno
// clase BD

#include "BD.h"
#include "Alumno.h"
#include <iostream>
#include <string>

using namespace std;

bool BD::buscarAlumnos() { // Comprueba que haya alumnos dados de alta
	if(numeroAlumnos_ == 0) 
		return false;
	else return true;
}

bool BD::buscarAlumnoDNI(list <Alumno> &lista, Alumno a){
	int contador=0;

	list <Alumno> :: iterator i;

	for(i=listaAlumnos_.begin(); i!=listaAlumnos_.end(); i++) {
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
	int contador=0;

	list <Alumno> :: iterator i;

	for(i=listaAlumnos_.begin(); i!=listaAlumnos_.end(); i++) {
		if((*i).getApellidos()==a.getApellidos()) {
			(lista).push_back(*i);
			contador++;
		}
	}

	if (contador>0) {
		return true;
	} else return false;
}

bool BD::buscarAlumnoEquipo(list <Alumno> &lista, int equipo) {
	int contador=0;

	list <Alumno> :: iterator i;

	for(i=listaAlumnos_.begin(); i!=listaAlumnos_.end(); i++) {
		if((*i).getEquipo()==equipo) {
			(lista).push_back(*i);
			contador++;
		}
	}

	if (contador>0)
		return true;
	else return false;
}
