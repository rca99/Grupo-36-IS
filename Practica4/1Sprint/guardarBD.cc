// BD.cc
// Cuerpo de la clase BD

#include "BD.h" //para incluir la lista de alumnos y funciones BD 
//#include "Profesor.h"//para incluir puntero a base de datos
#include "Alumno.h"
#include "Profesor.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool BD::guardarBD(){
	
	int registros=0;
	int tamano;
	list <Alumno> listaBD;
	Alumno a;
	a.setNombre("Ramón");
	//a.setEdad(65);
	Alumno b;
	b.setNombre("Fernando");
	//b.setEdad(34);
	Alumno c;
	c.setNombre("Akela");
	listaBD.push_back(a);
	listaBD.push_back(b);
	listaBD.push_back(c);
	
	Profesor p;
	string nameBD=nombreFichero_+".bin";
	list <Alumno>::iterator i; 

	//int *ficheroBD;
	//ficheroBD=(int*)&listaAlumnos_;
	p.setFicheroBD(listaAlumnos_);
	
	ofstream ofile(nameBD, ios::binary);

	if(ofile.is_open()){
		for (i=listaBD.begin(); i!=listaBD.end();i++){
			//ofile.write((char*)&listaAlumnos_,sizeof(Alumno));
			//ofile.write((char*)p.getFicheroBD(),sizeof(Alumno));
			ofile.write((char*)&listaBD,sizeof(Alumno));

		}
		cout<<listaBD.size();

		ofile.close();
	
		ifstream ifile(nombreFichero_, ios::binary);

		ifile.seekg(0L, ios::end);
		tamano=ifile.tellg();

		registros=tamano/sizeof(Alumno);
		cout<<"tamaño base datos: "<<tamano<<endl;
		cout<<"nº registros archivo binario: "<<registros<<endl;
		//listaBD.clear();

		if( ifile.is_open() ){
			ifile.read( (char *)&listaBD, sizeof(Alumno));
			while(!ifile.eof() ){
				cout<<" ";
				ifile.read( (char *)&listaBD, sizeof(Alumno));
			}
		}

		for (i=listaBD.begin(); i!=listaBD.end();i++){
			//ofile.write((char*)&listaAlumnos_,sizeof(Alumno));
			//ofile.write((char*)p.getFicheroBD(),sizeof(Alumno));
			cout<<"nombre: "<<i->getNombre()<<endl;

		}


		ifile.close();

		return 1;

	}
	else{

		return 0;
	}



	


	


}