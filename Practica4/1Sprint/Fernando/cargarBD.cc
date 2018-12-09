
#include "BD.h" //para incluir la lista de alumnos y funciones BD 
//#include "Profesor.h"//para incluir puntero a base de datos
#include "Alumno.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void reservaMemoriaEstructura(datosAlumno **libreria, int registros);
void contarRegistros(char *nombreFicheroBin, int *registros);




bool BD::cargarBD(){
	Alumno aux;

	char NombreFicheroBin[50];
	string nameBD=getNombreFichero()+".bin";
	strcpy(NombreFicheroBin, nameBD.c_str());
	
	
	listaAlumnos_.clear();
	cout<<listaAlumnos_.size()<<endl;

	//******leer fichero*********//
	FILE *ficheroLectura;
	datosAlumno datoLectura;

	ficheroLectura=fopen("registro.bin", "rb");
	
	cout<<"**************Datos Fichero******************************"<<endl;
	cout<<"__________________________________________________________"<<endl;

	fseek(ficheroLectura,0L, SEEK_SET);
	fread(&datoLectura, sizeof(datosAlumno), 1, ficheroLectura);
	while(!feof(ficheroLectura)){
		cout<<datoLectura.nombre<<endl;
				
		aux.setNombre(datoLectura.nombre);
		introducirAlumno(aux);
		fread(&datoLectura, sizeof(datosAlumno), 1, ficheroLectura);



	}


	cout<<listaAlumnos_.size()<<endl;
	//fclose(ficheroLectura);
	
 
      
  }










