
#include "BD.h" //para incluir la lista de alumnos y funciones BD 
//#include "Profesor.h"//para incluir puntero a base de datos
#include "Alumno.h"
#include "Profesor.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


bool BD::cargarBD(){

	listaAlumnos_.clear();

	Profesor p;
	int registros=0;
	int tamano;
	
	list <Alumno> listaBD;
	list <Alumno>::iterator i; 
	

	ifstream ifile(nombreFichero_, ios::binary);
	
	/*ifile.seekg(0L, ios::end);
	tamano=ifile.tellg();

	registros=tamano/sizeof(Alumno);
	cout<<"tamaño base datos: "<<tamano<<endl;
	cout<<"nº registros archivo binario: "<<registros<<endl;
	*/

	
	if( ifile.is_open() ){
		ifile.read((char*)&listaBD,sizeof(Alumno) );

		while(!ifile.eof() ){
			
			ifile.read((char*)&listaBD,sizeof(Alumno) );
			
		}
	}





	for (i=listaAlumnos_.begin(); i!=listaAlumnos_.end();i++){
		//ifile.read((char*)p.getFicheroBD(),sizeof(Alumno));
		
		cout<<"nombre: "<<i->getNombre()<<endl;
			//cout<<"edad:"<<i->getEdad()<<endl;


	}

	//cout<<"Tamaño Base de Datos: "<<listaAlumnos_.size()<<endl;
	cout<<"Tamaño Base de Datos: "<<listaBD.size()<<endl;
	
	ifile.close();

	return 1;
	
	
	

}


