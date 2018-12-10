
#include "BD.h" //para incluir la lista de alumnos y funciones BD 
#include "Profesor.h"//para incluir puntero a base de datos
#include "Alumno.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;



/*
guardar BD()

Descripción: Carga el contenido de la base de datos guardada en un fichero binario a la lista de alumnos

Valores devueltos: 1 si ha cargado correctamente la base de datos y 0 si no existe el fichero binario que cargar

Parámetros: no recibe ningún parámetro. Accede a listaAlumnos_ para guardarla

//puntero a la dirección de memoria de la base de datos creo que no es necesario para la implementación

*/

bool BD::cargarBD(){
	
	Alumno aux; //para guardar los datos que se van leyendo. Su contenido es añadido a listaAlumnos_ a partir de la función introducirAlumno(alumno)

	Profesor p;// para usar el puntero a la base de datos

	//el método de leer fichero recibe el nombre del fichero como tipo char
	char NombreFicheroBin[50];
	string nameBD=getNombreFichero()+".bin";
	strcpy(NombreFicheroBin, nameBD.c_str());
	
	
	listaAlumnos_.clear();
	cout<<listaAlumnos_.size()<<endl;

	//******leer fichero*********//
	ifstream f(NombreFicheroBin, ios::binary);
	
	if (!f.is_open()){
		return 0;
	} //si existe el fichero lo sobreescribe

	datosAlumno datoLectura;

	p.setFicheroBD(datoLectura);


	
	
	cout<<"**************Datos Fichero******************************"<<endl;
	cout<<"__________________________________________________________"<<endl;

	//fseek(ficheroLectura,0L, SEEK_SET);
	
	f.read( (char *)&datoLectura, sizeof(datosAlumno));
	//fread(p.getFicheroBD(), sizeof(datosAlumno), 1, ficheroLectura);//no funciona para el puntero hacia la base de datos definitdo en  Profesor.h
	
	while(!f.eof()){
		cout<<datoLectura.nombre<<endl;
		cout<<datoLectura.curso<<endl;
				
		aux.setNombre(datoLectura.nombre);
		aux.setCurso(datoLectura.curso);

		introducirAlumno(aux);
		//fread(p.getFicheroBD(), sizeof(datosAlumno), 1, ficheroLectura);//no funciona para el puntero hacia la base de datos definitdo en  Profesor.h
		f.read( (char *)&datoLectura, sizeof(datosAlumno));
		//f.read( (char *)p.getFicheroBD(), sizeof(datosAlumno));//no funciona lo del puntero a la base de datos	
	}	
	

	cout<<listaAlumnos_.size()<<endl;

	list <Alumno>::iterator i;

	for (i = listaAlumnos_.begin(); i !=listaAlumnos_.end(); ++i){
		cout<<i->getNombre()<<endl;
	}
	f.close();

	return 1;

      
  }










