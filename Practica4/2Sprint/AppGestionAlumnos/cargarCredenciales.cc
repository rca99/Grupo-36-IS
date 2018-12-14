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

Descripción: Guarda el contenido de la lista de alumnos en un fichero binario

Si no existe el fichero binario de la copia de seguridad, lo crea y si existe lo sobreescribe 
con los datos de la lista de alumnos.

Valores devueltos: 1 si ha guardado correctamente la base de datos.

Parámetros: no recibe ningún parámetro. Accede a listaAlumnos_ para guardarla

*/

bool Profesor::cargarCredenciales(string usuarioAcceso, string contrasenyaAcceso){
	
	


	cout<<"asdfadsfas"<<endl;
	
	list <Credencialesprofesor> listaProfesores; //para guardar los datos que se van leyendo. Su contenido es añadido a listaAlumnos_ a partir de la función introducirAlumno(alumno)

	Profesor p;// para usar el puntero a la base de datos

	//el método de leer fichero recibe el nombre del fichero como tipo char
	char NombreFicheroBin[50];
	string nameBD="credenciales.bin";
	strcpy(NombreFicheroBin, nameBD.c_str());
	
	
	

	FILE *ficheroLectura;
	ficheroLectura=fopen(NombreFicheroBin, "rb");
	
	if (ficheroLectura==NULL){
		return 0;
	} //si existe el fichero lo sobreescribe

	Credencialesprofesor cp;

	


	//fseek(ficheroLectura,0L, SEEK_SET);
	
	fread(&cp, sizeof(Credencialesprofesor), 1, ficheroLectura);

	//fread(p.getFicheroBD(), sizeof(datosAlumno), 1, ficheroLectura);//no funciona para el puntero hacia la base de datos definitdo en  Profesor.h
	
	while(!feof(ficheroLectura)){
		cout<<cp.nombreCompleto<<endl;
		cout<<cp.usuario<<endl;
			
		

		listaProfesores.push_back(cp);
		//fread(p.getFicheroBD(), sizeof(datosAlumno), 1, ficheroLectura);//no funciona para el puntero hacia la base de datos definitdo en  Profesor.h
		fread(&cp, sizeof(Credencialesprofesor), 1, ficheroLectura);
		
		//f.read( (char *)p.getFicheroBD(), sizeof(datosAlumno));//no funciona lo del puntero a la base de datos	
	}	
	
	cout<<listaProfesores.size()<<endl;

	list <Credencialesprofesor>::iterator i;

	for (i = listaProfesores.begin(); i !=listaProfesores.end(); ++i){
		cout<<i->usuario<<"-"<<usuarioAcceso<<endl;
		cout<<i->contrasenya<<"-"<<contrasenyaAcceso<<endl;
		if(strcmp(i->usuario, usuarioAcceso.c_str())==0 && strcmp(i->contrasenya, contrasenyaAcceso.c_str())==0){

			
			return 1;
		}
		else{return 0;}

	}
	fclose(ficheroLectura);


	return 1;







      
 }



