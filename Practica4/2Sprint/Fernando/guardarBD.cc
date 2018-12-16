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

/*
guardar BD()

Descripción: Guarda el contenido de la lista de alumnos en un fichero binario

Si no existe el fichero binario de la copia de seguridad, lo crea y si existe lo sobreescribe 
con los datos de la lista de alumnos.

Valores devueltos: 1 si ha guardado correctamente la base de datos.

Parámetros: no recibe ningún parámetro. Accede a listaAlumnos_ para guardarla

*/

bool BD::guardarBD(){

	
	//cout<<"tamaño lista: "<<listaAlumnos_.size()<<endl;

	//el método de leer fichero recibe el nombre del fichero como tipo char
	char NombreFicheroBin[50];
	string nameBD=getNombreFichero()+".bin";
	strcpy(NombreFicheroBin, nameBD.c_str());



	//*******Escribir Fichero **********//
	FILE *fichero;
	datosAlumno dato;

	fichero=fopen(NombreFicheroBin, "wa+b");
	if (fichero==NULL){
		cout<<"no existe"<<endl;
	} //si existe el fichero lo sobreescribe


	list <Alumno>::iterator i;

	list <Alumno> aux;
	list <Alumno> auxiliarEscribir;

	aux=listaAlumnos_;
	
	for (i = aux.begin(); i!=aux.end(); ++i)
	{
	
		cout<<i->getNombre()<<"-"<<i->getCurso()<<"-"<<i->getApellidos()<<i->getLider()<<endl;
		//dato.nombre=i->getNombre();
		strcpy(dato.dni, i->getDNI().c_str());
		strcpy(dato.nombre, i->getNombre().c_str());
		strcpy(dato.apellidos, i->getApellidos().c_str());
		strcpy(dato.fecha_nacimiento, i->getFecha_nacimiento().c_str());
		strcpy(dato.email_corporativo, i->getEmail_corporativo().c_str());
		strcpy(dato.domicilio, i->getDomicilio().c_str());
		
		dato.curso=i->getCurso();
		dato.telefono=i->getTelefono();
		dato.nota=i->getNota();
		dato.equipo=i->getEquipo();
		dato.lider=i->getLider();

		fwrite(&dato, sizeof(datosAlumno), 1, fichero);

	}

	fclose(fichero);
	return 1;


}

