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
#include <cstring>


using namespace std;

bool BD::guardarBD(){

	int tamano, registros;
	datosAlumno datosBD;

	list <Alumno>::iterator i; 
	
	//char NombreFicheroBin[50];
	//string nameBD=getNombreFichero()+".bin";
	//strcpy(NombreFicheroBin, nameBD.c_str());
	
	//controlar la creación del fichero


	cout<<nombreFichero_<<endl;
	cout<<endl;
	
	ofstream ofile(nombreFichero_, ios::binary);

	for (i=listaAlumnos_.begin(); i!=listaAlumnos_.end();i++){
			datosBD.nombre=i->getNombre();
			datosBD.apellidos=i->getApellidos();
			//ofile.write((char*)&listaAlumnos_,sizeof(Alumno));
			//ofile.write((char*)p.getFicheroBD(),sizeof(Alumno));
			ofile.write((const char*)&datosBD, sizeof(datosAlumno));
		
	}

	
	ofile.close();

	ifstream ifile(nombreFichero_, ios::binary);

	ifile.seekg(0L, ios::end);
	tamano=ifile.tellg();

	registros=tamano/sizeof(datosAlumno);
	cout<<"tamaño base datos: "<<tamano<<endl;
	cout<<"nº registros archivo binario: "<<registros<<endl;
	
	ifile.close();

	for (i=listaAlumnos_.begin(); i!=listaAlumnos_.end();i++){

		cout<<"nombre: "<<i->getNombre()<<endl;
		cout<<"apellidos: "<<i->getApellidos()<<endl;
	}

		
	/*
	ifstream ifile(nombreFichero_, ios::binary);

	listaAlumnos_.clear();
		
	if( ifile.is_open() ){
		ifile.read( (char *)&datosBD, sizeof(datosAlumno));
			
		while(!ifile.eof()){
				
			ifile.read( (char *)&datosBD, sizeof(datosAlumno));
			Alumno aux(datosBD);
			listaAlumnos_.push_back(aux);
				
			}
		

		}
		


		cout<<listaAlumnos_.size()<<endl;

		for (i=listaAlumnos_.begin(); i!=listaAlumnos_.end();i++){

			cout<<"nombre: "<<i->getNombre()<<endl;
			cout<<"nombre: "<<i->getApellidos()<<endl;
		}

		

	*/



	
	return 1;


}

/*FILE *ficheroBin;

	ficheroBin=fopen(NombreFicheroBin, "a+b");

	if (ficheroBin==NULL){
		fprintf(stderr, "\nError al abrir el fichero" );
	}



	for (i=listaAlumnos_.begin(); i!=listaAlumnos_.end();i++){
		fwrite(&listaAlumnos_, sizeof(list<Alumno>), 1,ficheroBin);//ofile.write((char*)&listaAlumnos_,sizeof(Alumno));
		//ofile.write((char*)p.getFicheroBD(),sizeof(Alumno));
		cout<<"nombre   ss: "<<i->getNombre()<<endl;

		}

	

	fclose(ficheroBin);
	*/