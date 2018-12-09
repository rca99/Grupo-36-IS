
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

	list <Alumno>::iterator i; 

	ifstream ifile(nombreFichero_, ios::in | ios::binary);
	

		ifile.read((char*)&(listaAlumnos_),sizeof(Alumno));


	
	//while(!ifile.eof()){

		//ifile.read((char*)&listaAlumnos_,sizeof(Alumno));
	//}

	for (i=listaAlumnos_.begin(); i!=listaAlumnos_.end();i++){
			//ofile.write((char*)p.ficheroBD_,sizeof(Alumno) );
		cout<<"nombre:"<<i->getNombre()<<endl;
			//cout<<"edad:"<<i->getEdad()<<endl;


	}

	cout<<"Tamaño Base de Datos: "<<listaAlumnos_.size()<<endl;
	ifile.close();

		return 1;
	
	

}


