// BD.cc
// Cuerpo de la clase BD

#include "Profesor.h"//para incluir puntero a base de datos
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
