//bin.cc
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

#include "Alumno.h"
#include "BD.h"

using namespace std;


typedef struct{
	
	char nombre[20];
	int curso;
}datos;

int main(int argc, char const *argv[]){

	Alumno a;
	a.setNombre("Rodolfo");
	a.setCurso(4);

	Alumno b;
	b.setNombre("Fernando");
	b.setCurso(12);


	BD BDatos;

	BDatos.listaAlumnos_.push_back(a);
	BDatos.listaAlumnos_.push_back(b);

	

	cout<<"tamaño lista: "<<aux.size()<<endl;



















	FILE *fichero;
	datos dato;

	fichero=fopen("registro.bin", "wa+b");
	if (fichero==NULL){
		cout<<"no existe"<<endl;
	}

	strcpy (dato.nombre, a.getNombre().c_str());
	dato.curso=a.getCurso();


	cout<<dato.nombre<<endl;
	cout<<dato.curso<<endl;

	fwrite(&dato, sizeof(datos), 1, fichero);
	fclose(fichero);



	FILE *ficheroLectura;
	datos datoLectura;

	ficheroLectura=fopen("registro.bin", "rb");

	fread(&datoLectura, sizeof(datos), 1, fichero);
	while(!feof(ficheroLectura)){

		cout<<datoLectura.nombre<<endl;
		cout<<datoLectura.curso<<endl;

		fread(&datoLectura, sizeof(datos), 1, fichero);


	}

	return 0;
}