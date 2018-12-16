// Profesor.cc
// Cuerpo de la clase Profesor

#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <cstring>

#include "Profesor.h"

using namespace std;

Credencialesprofesor Profesor::registro(string usuarioAcceso, string contrasenyaAcceso) {

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
	}
	return cp;
}

bool Profesor::credencialesBin(){

	//cout<<"tamaño lista: "<<listaAlumnos_.size()<<endl;

	//el método de leer fichero recibe el nombre del fichero como tipo char
	char NombreFicheroBin[50];
	string nameBD="credenciales.bin";
	strcpy(NombreFicheroBin, nameBD.c_str());

	//*******Escribir Fichero **********//
	FILE *fichero;
	Credencialesprofesor p1;
	Credencialesprofesor p2;
	Credencialesprofesor c;
	
	strcpy(p1.nombreCompleto, "David Guijo");
	strcpy(p1.usuario, "dguijo");
	strcpy(p1.rol, "ayudante");
	strcpy(p1.contrasenya, "1111");

	strcpy(p2.nombreCompleto, "Antonio Durán");
	strcpy(p2.usuario, "aduran");
	strcpy(p2.rol, "ayudante");
	strcpy(p2.contrasenya, "2222");

	strcpy(c.nombreCompleto, "Isabel");
	strcpy(c.usuario, "isa");
	strcpy(c.rol, "coordinador");
	strcpy(c.contrasenya, "0000");

	fichero=fopen(NombreFicheroBin, "wa+b");
	if (fichero==NULL){
		cout<<"no existe"<<endl;
	} 

	fwrite(&p1, sizeof(Credencialesprofesor), 1, fichero);
	fwrite(&p2, sizeof(Credencialesprofesor), 1, fichero);
	fwrite(&c, sizeof(Credencialesprofesor), 1, fichero);

	fclose(fichero);
	return 1;
}