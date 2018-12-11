// Carlos Freire Caballero
// Clase : BD
// Funcion : introducirAlumno

#include <iostream>

#include "BD.h"
#include "Alumno.h"

bool BD::introducirAlumno(Alumno newAlumno) {
	// Comprueba que el numero de alumnos no supere 150
	if(numeroAlumnos_==150)
		return false;
	// Muestra el numero de alumnos
	else cout << "Numero Alumnos :: " << numeroAlumnos_ << endl;

	/*Alumno aux; // Alumno auxiliar para ir obteniendo datos
	// Datos
	string dni, nombre, apellidos;
	string f_nacimiento, mailcorporativo, domicilio;
	int edad, telefono, curso, nota, equipo;
	bool lider;*/

	/*// Se piden algunos parámetros identificadores de un alumno
	cout << "Introduzca datos para comprobar que el alumno no existe en la BD:" << endl;
	cout << "DNI: ";
	cin >> dni;
	cout << "Nombre: ";
	cin >> nombre;
	cout << "apellidos: ";
	cin >> apellidos;*/

	// Se comprueba que el alumno no esté ya insertado en la BD
	bool repetido=buscarAlumno(newAlumno.dni); // Necesarios más parametros?
	// buscarAlumno(newAlumno.nombre);
	// buscarAlumno(newAlumno.apellidos);

	if(repetido==true) {
		cout << "El alumno ya se encuentra en la BD" << endl;
		return false;
	} // Esto se abreviará más adelante sin usar la variable repetido.

	/*cout << "Alumno no registrado. Introduzca el resto de datos";
	cout << "Fecha Nacimiento: ";
	cin >> f_nacimiento;
	cout << "Telefono: ";
	cin >> telefono_
	cout << "Email corporativo: ";
	cin >> mailcorporativo;
	cout << "Domicilio: ";
	cin >> domicilio;
	cout << "Curso: ";
	cin >> curso;
	cout << "Nota: ";
	cin >> nota;
	cout << "Equipo: ";
	cin >> equipo;
	cout << "Lider: ";
	cin >> lider;*/

	// Comprueba que si introduce lider ha introducido grupo
	// Incluir aquí o en la interfaz del programa??
	if(((newAlumno.getLider())==true) && ((newAlumno.getEquipo())=="")) {
		cout << "Si introduce que el alumno es lider entonces debe indicar el grupo al que pertenece" << endl;
		return false;
	}

	// La gestion de lideres debe realizarse en la interfaz pues
	// la funcion ya recibe un alumno con un posible valor true en lider.
	// ???

	listaAlumnos_.push_back(newAlumno); // Inserta el nuevo alumno en la lista de alumnos.
	numeroAlumnos_++; // Incrementa el numero de alumno en el sistema

	// El alumno ha sido insertado y la interfaz 
	// retornara un mensaje de confirmacion
	return true;
}