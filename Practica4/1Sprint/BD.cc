//BD.cc

#include "BD.h" //para incluir la lista de alumnos y funciones BD 
//#include "Profesor.h"//para incluir puntero a base de datos
#include "Alumno.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool BD::guardarBD(){

	Alumno a;
	a.setNombre("Agustín");
	a.setEdad(5);
	Alumno b;
	b.setNombre("Fernando");
	b.setEdad(34);


	listaAlumnos_.push_back(a);
	listaAlumnos_.push_back(b);
	
	string nameBD=nombreFichero_+".bin";

	list <Alumno>::iterator i; 

	int *ficheroBD;
	ficheroBD==(int*)&listaAlumnos_;
	//p.ficheroBD_=&listaAlumnos_;


	ofstream ofile(nameBD, ios::binary);

	if (listaAlumnos_.empty()){

		return 0;
	}

	else{

		for (i=listaAlumnos_.begin(); i!=listaAlumnos_.end();i++){
			//ofile.write((char*)p.ficheroBD_,sizeof(Alumno) );
			//ofile.write((char*)&listaAlumnos_,sizeof(Alumno));
			ofile.write((char*)ficheroBD,sizeof(Alumno));

		}

		ofile.close();
		return 1;
	}


}


bool BD::cargarBD(){


	list <Alumno>::iterator i; 

	ifstream ifile(nombreFichero_, ios::binary);
	ifile.read((char*)&listaAlumnos_,sizeof(Alumno));


	for (i=listaAlumnos_.begin(); i!=listaAlumnos_.end();i++){
			//ofile.write((char*)p.ficheroBD_,sizeof(Alumno) );
			cout<<"nombre:"<<i->getNombre()<<endl;
			cout<<"edad:"<<i->getEdad()<<endl;


		}

	cout<<"Tamaño Base de Datos: "<<listaAlumnos_.size()<<endl;


	return 1;

	
}