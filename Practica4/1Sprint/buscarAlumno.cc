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
		cout << "No hay alumnos dados de alta en la base de datos" << endl;
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
	else{return false;}

		

		/*if((*i).getApellidos()==datos.apellidos) {alumnox.pushback();}
		if((*i).getEquipo()==datos.equipo) {alumnox.pushback();}
		*/


	/*  

	cout << "Introduzca una opcion de busqueda: /n 1. Buscar por dni /n 2. Buscar por apellidos /n 3. Buscar por grupo" << endl;
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
	}		


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
	*/



}


bool BD::buscarAlumnoDNI(list <Alumno> &lista, Alumno a){
	// Comprueba que haya alumnos dados de alta
	int contador=0;
	if(getNumeroAlumnos()==0) {
		cout << "No hay alumnos dados de alta en la base de datos" << endl;
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
	else{

	
		
		return false;

	}

	

}	

bool BD::buscarAlumnoApellido(list <Alumno> &lista, Alumno a){

		// Comprueba que haya alumnos dados de alta
	int contador=0;
	if(getNumeroAlumnos()==0) {
		cout << "No hay alumnos dados de alta en la base de datos" << endl;
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

		if(buscarAlumnoDNI(lista,a)){

			return true;
		}

		else{return false;}



	}

	

}








	