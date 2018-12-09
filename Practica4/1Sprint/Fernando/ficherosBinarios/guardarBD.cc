// BD.cc
// Cuerpo de la clase BD

#include "BD.h" //para incluir la lista de alumnos y funciones BD 
//#include "Profesor.h"//para incluir puntero a base de datos
#include "Alumno.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>


using namespace std;

bool BD::guardarBD(){

	
	cout<<"tamaño lista: "<<listaAlumnos_.size()<<endl;


	//*******Escribir Fichero **********//
	FILE *fichero;
	datosAlumno dato;

	fichero=fopen("registro.bin", "wa+b");
	if (fichero==NULL){
		cout<<"no existe"<<endl;
		return 0;
	}


	list <Alumno>::iterator i;

	list <Alumno> aux;
	aux=listaAlumnos_;

	for (i = aux.begin(); i!=aux.end(); ++i)
	{
		cout<<"*"<<endl;
		cout<<i->getNombre()<<"-"<<i->getCurso()<<"-"<<i->getApellidos()<<endl;
		dato.nombre=i->getNombre();

		//strcpy(dato.nombre, i->getNombre().c_str());
		//strcpy(dato.apellidos, i->getApellidos().c_str());

		//dato.curso=i->getCurso();
		fwrite(&dato, sizeof(datosAlumno), 1, fichero);

	}



	fclose(fichero);
	return 1;


}

