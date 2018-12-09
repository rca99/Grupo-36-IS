// BD.cc
// Cuerpo de la clase BD

#include "BD.h" //para incluir la lista de alumnos y funciones BD 
//#include "Profesor.h"//para incluir puntero a base de datos
#include "Alumno.h"
#include "Profesor.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool BD::guardarBD(){

	/*Alumno a;
	a.setNombre("Ramón");
	//a.setEdad(65);
	Alumno b;
	b.setNombre("Fernando");
	//b.setEdad(34);
	Alumno c;
	c.setNombre("Akela");
	listaAlumnos_.push_back(a);
	listaAlumnos_.push_back(b);
	listaAlumnos_.push_back(c);
	*/

	Profesor p;
	string nameBD=nombreFichero_+".bin";

	list <Alumno>::iterator i; 

	//int *ficheroBD;
	//ficheroBD=(int*)&listaAlumnos_;
	p.setFicheroBD(listaAlumnos_);
	
	ofstream ofile(nameBD, ios::binary);

	if (listaAlumnos_.empty()){

		return 0;
	}

	else{

		for (i=listaAlumnos_.begin(); i!=listaAlumnos_.end();i++){
			//ofile.write((char*)&listaAlumnos_,sizeof(Alumno));
			ofile.write((char*)p.getFicheroBD(),sizeof(Alumno));

		}

		ofile.close();
		return 1;
	}


}