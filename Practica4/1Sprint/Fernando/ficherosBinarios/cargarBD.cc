
#include "BD.h" //para incluir la lista de alumnos y funciones BD 
//#include "Profesor.h"//para incluir puntero a base de datos
#include "Alumno.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;





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

	//fseek(ficheroLectura,0L, SEEK_SET);
	
	fread(&datoLectura, sizeof(datosAlumno), 1, ficheroLectura);
	while(!feof(ficheroLectura)){
		cout<<datoLectura.nombre<<endl;
		cout<<datoLectura.curso<<endl;
				
		aux.setNombre(datoLectura.nombre);
		aux.setCurso(datoLectura.curso);

		introducirAlumno(aux);
		fread(&datoLectura, sizeof(datosAlumno), 1, ficheroLectura);
	}
	

	cout<<listaAlumnos_.size()<<endl;

	list <Alumno>::iterator i;

	for (i = listaAlumnos_.begin(); i !=listaAlumnos_.end(); ++i)
	{
		cout<<i->getNombre()<<endl;
	}
	fclose(ficheroLectura);

	

      
  }










