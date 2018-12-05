// BD.cc
// Cuerpo de la clase BD

#include "BD.h" //para incluir la lista de alumnos y funciones BD 
//#include "Profesor.h"//para incluir puntero a base de datos
#include "Alumno.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool BD::guardarBD(){

	Alumno a;
	a.setNombre("Agustín");
	a.setEdad(65);
	Alumno b;
	b.setNombre("Fernando");
	b.setEdad(34);


	listaAlumnos_.push_back(a);
	listaAlumnos_.push_back(b);
	
	string nameBD=nombreFichero_+".bin";

	list <Alumno>::iterator i; 

	int *ficheroBD;
	ficheroBD==(int*)&listaAlumnos_;
	//p.ficheroBD_=&listaAlumnos_;


	ofstream ofile(nameBD, ios::binary);

	if (listaAlumnos_.empty()){

		return 0;
	}

	else{

		for (i=listaAlumnos_.begin(); i!=listaAlumnos_.end();i++){
			//ofile.write((char*)p.ficheroBD_,sizeof(Alumno) );
			//ofile.write((char*)&listaAlumnos_,sizeof(Alumno));
			ofile.write((char*)ficheroBD,sizeof(Alumno));

		}

		ofile.close();
		return 1;
	}


}


bool BD::cargarBD(){


	list <Alumno>::iterator i; 

	ifstream ifile(nombreFichero_, ios::binary);
	ifile.read((char*)&listaAlumnos_,sizeof(Alumno));


	for (i=listaAlumnos_.begin(); i!=listaAlumnos_.end();i++){
			//ofile.write((char*)p.ficheroBD_,sizeof(Alumno) );
			cout<<"nombre:"<<i->getNombre()<<endl;
			cout<<"edad:"<<i->getEdad()<<endl;


		}

	cout<<"Tamaño Base de Datos: "<<listaAlumnos_.size()<<endl;


	return 1;

	
}

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

	listaAlumnos_.push_back(newAlumno); //Lo inserta en la lista de alumnos.
	numeroAlumnos_++; // Incrementa el numero de alumno en el sistema

	// El alumno ha sido insertado y la interfaz 
	// retornara un mensaje de confirmacion
	return true;
}