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

	Alumno c;
	c.setNombre("aurelio");
	c.setCurso(12);

	BD BDatos;

	BDatos.introducirAlumno(a);
	BDatos.introducirAlumno(b);
	BDatos.introducirAlumno(c);

	cout<<"tamaño lista: "<<BDatos.getAlumnos().size()<<endl;


	//*******Escribir Fichero **********//
	FILE *fichero;
	datos dato;

	fichero=fopen("registro.bin", "wa+b");
	if (fichero==NULL){
		cout<<"no existe"<<endl;
	}

	/*strcpy (dato.nombre, a.getNombre().c_str());
	dato.curso=a.getCurso();



	fwrite(&dato, sizeof(datos), 1, fichero);

	strcpy (dato.nombre, b.getNombre().c_str());
	dato.curso=b.getCurso();
	
	fwrite(&dato, sizeof(datos), 1, fichero);
	*/

	list <Alumno>::iterator i;

	list <Alumno> aux;
	aux=BDatos.getAlumnos();

	for (i = aux.begin(); i!=aux.end(); ++i)
	{
	
		cout<<i->getNombre()<<i->getCurso()<<endl;
		strcpy(dato.nombre, i->getNombre().c_str());
		dato.curso=i->getCurso();
		fwrite(&dato, sizeof(datos), 1, fichero);

	}



	fclose(fichero);



	//******leer fichero*********//
	FILE *ficheroLectura;
	datos datoLectura;

	ficheroLectura=fopen("registro.bin", "rb");
	
	cout<<"**************Datos Fichero******************************"<<endl;
	cout<<"__________________________________________________________"<<endl;

	fread(&datoLectura, sizeof(datos), 1, ficheroLectura);
	while(!feof(ficheroLectura)){
		cout<<datoLectura.nombre<<endl;
		cout<<datoLectura.curso<<endl;

		fread(&datoLectura, sizeof(datos), 1, ficheroLectura);


	}
	fclose(ficheroLectura);















	

	return 0;
}