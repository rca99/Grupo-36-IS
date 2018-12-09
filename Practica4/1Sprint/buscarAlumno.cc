// funcion buscar alumno
// clase BD

#include "BD.h"
#include "Alumno.h"
#include <iostream>
#include <string>

using namespace std;

bool BD::buscarAlumno(list <Alumno> &alumnox, datosAlumno datos) {
	// Comprueba que haya alumnos dados de alta
	if(getNumeroAlumnos()==0) {
		cout << "No hay alumnos dados de alta en la base de datos" << endl;
		return false;
	}

	list <Alumno> :: iterator i;
	for(i=listaAlumno_.begin(); i!=listaAlumno_.end(); i++) {
		if((*i).getDni()==datos.dni) {alumnox.pushback();}
		if((*i).getApellidos()==datos.apellidos) {alumnox.pushback();}
		if((*i).getEquipo()==datos.equipo) {alumnox.pushback();}
	} 
	return false;
}

	/*  cout << "Introduzca una opcion de busqueda: /n 1. Buscar por dni /n 2. Buscar por apellidos /n 3. Buscar por grupo" << endl;
	cin >> opc;
	switch(opc) {
			case 1: { // Buscar por dni
				datosAlumno datos;
				if(!datosBusqueda(datos)) break;
				Alumno aux(datos);	// Constructor con estructura


			} break;
			
			case 2: { // Buscar por apellidos
				datosAlumno datos;
				if(!datosBusqueda(datos)) break;
				Alumno aux(datos);	// Constructor con estructura


			} break;	

			case 3: { // Buscar por grupo
				datosAlumno datos;
				if(!datosBusqueda(datos)) break;
				Alumno aux(datos);	// Constructor con estructura
				// crear funcion aparte para buscar por grupo?

			} break;
			default: cout << "Opcion no valida" << endl;
	}		*/


	bool datosBusqueda(datosAlumno &datos) {
	int opcbusqueda=0;

	cout << "Introduzca como buscar el alumno:" << endl;
	cout << "1. DNI\n2. Apellidos\n3.Equipo";
	cin >> opcbusqueda;

	if(opcbusqueda == 1) {
		cout << "DNI : ";
		cin >> datos.dni;
	} else if (opcbusqueda == 2) {
		cout << "Apellidos : ";
		cin >> datos.apellidos;
	} else if(opcbusqueda==3){
		cout << "Equipo : ";
		cin >> datos.equipo;
	} 
	else {
		cout << "Opcion no valida";
		return false;
	}

	return true;
	}
	