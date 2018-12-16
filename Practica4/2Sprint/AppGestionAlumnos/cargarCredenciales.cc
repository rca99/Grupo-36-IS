// BD.cc
// Cuerpo de la clase BD

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

Descripción: 

Valores devueltos: 

Parámetros: 
*/

Credencialesprofesor Profesor::registro(string usuarioAcceso, string contrasenyaAcceso){
	
	
	list <Credencialesprofesor> listaProfesores; //para guardar los datos que se van leyendo. Su contenido es añadido a listaAlumnos_ a partir de la función introducirAlumno(alumno)

	Profesor p;// para usar el puntero a la base de datos

	//el método de leer fichero recibe el nombre del fichero como tipo char
	char NombreFicheroBin[50];
	string nameBD="credenciales.bin";
	strcpy(NombreFicheroBin, nameBD.c_str());
	
	
	

	FILE *ficheroLectura;
	ficheroLectura=fopen(NombreFicheroBin, "rb");
	
	if (ficheroLectura==NULL){
		cout<<"no se encuentra fichero credenciales"<<endl;
	} //si existe el fichero lo sobreescribe

	Credencialesprofesor cp;
	Credencialesprofesor A;
	//fseek(ficheroLectura,0L, SEEK_SET);
	
	fread(&cp, sizeof(Credencialesprofesor), 1, ficheroLectura);

	//fread(p.getFicheroBD(), sizeof(datosAlumno), 1, ficheroLectura);//no funciona para el puntero hacia la base de datos definitdo en  Profesor.h
	
	while(!feof(ficheroLectura)){
		//cout<<cp.nombreCompleto<<endl;
		//cout<<cp.usuario<<endl;
			
		listaProfesores.push_back(cp);
		//fread(p.getFicheroBD(), sizeof(datosAlumno), 1, ficheroLectura);//no funciona para el puntero hacia la base de datos definitdo en  Profesor.h
		fread(&cp, sizeof(Credencialesprofesor), 1, ficheroLectura);
		
		//f.read( (char *)p.getFicheroBD(), sizeof(datosAlumno));//no funciona lo del puntero a la base de datos	
	}	
	
	cout<<listaProfesores.size()<<endl;

	list <Credencialesprofesor>::iterator i;

	for (i = listaProfesores.begin(); i !=listaProfesores.end(); ++i){
		//cout<<i->usuario<<"-"<<usuarioAcceso<<endl;
		//cout<<i->contrasenya<<"-"<<contrasenyaAcceso<<endl;
		if(strcmp(i->usuario, usuarioAcceso.c_str())==0 && strcmp(i->contrasenya, contrasenyaAcceso.c_str())==0){
			strcpy(cp.rol,i->rol);
			strcpy(cp.usuario,i->usuario);
			strcpy(cp.contrasenya,i->contrasenya);
			strcpy(cp.nombreCompleto,i->nombreCompleto);
			
			return cp;
			
			
		}
		else{
			
		}

	}
	
<<<<<<< HEAD
	return cp;
=======
	return cp;     
>>>>>>> da5ab4eb5b0a0e30d88eea1f7b0c3c02e2768ac6
 }



