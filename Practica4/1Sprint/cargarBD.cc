
#include "BD.h" //para incluir la lista de alumnos y funciones BD 
//#include "Profesor.h"//para incluir puntero a base de datos
#include "Alumno.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


bool BD::cargarBD(){

	listaAlumnos_.clear();

	int registros=0;
	int tamano;
	list <Alumno>::iterator i; 
	

	ifstream ifile(nombreFichero_, ios::in | ios::binary);
	
	ifile.seekg(0L, ifile.end);
	tamano=ifile.tellg();

	registros=tamano/sizeof(Alumno);
	cout<<"tamaño base datos"<<endl;
	//cout<<"nº registros archivo binario:"<<registros<<endl;

	//ifile.read((char*)&listaAlumnos_,sizeof(Alumno)*registros);

	for (i=listaAlumnos_.begin(); i!=listaAlumnos_.end();i++){
			//ofile.write((char*)p.ficheroBD_,sizeof(Alumno) );
		cout<<"nombre:"<<i->getNombre()<<endl;
			//cout<<"edad:"<<i->getEdad()<<endl;


	}

	//cout<<"Tamaño Base de Datos: "<<listaAlumnos_.size()<<endl;
	ifile.close();

		return 1;
	
	

}


