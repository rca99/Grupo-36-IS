//mostrarAlumno.cc

// Esta función hay que incluirla en la correspodneinte clase BD con lo que hay que actualizar el Diagrama de Clases



#include "BD.h" //para incluir la lista de alumnos y funciones BD 
//#include "Profesor.h"//para incluir puntero a base de datos
#include "Alumno.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include "consoleLinux.h"//colores menu
#include <iomanip>//formato cout


void mostrarAlumno(list <Alumno> listaImprimir){
	

	Alumno aux; //para guardar los datos que se van leyendo. Su contenido es añadido a listaAlumnos_ a partir de la función introducirAlumno(alumno)

	Profesor p;// para usar el puntero a la base de datos

	//el método de leer fichero recibe el nombre del fichero como tipo char
	char NombreFicheroBin[50];
	string nameBD=getNombreFichero()+".bin";
	strcpy(NombreFicheroBin, nameBD.c_str());
	
	
	listaAlumnos_.clear();
	cout<<listaAlumnos_.size()<<endl;

	//******leer fichero*********//
	FILE *ficheroLectura;
	ficheroLectura=fopen(NombreFicheroBin, "rb");
	
	if (ficheroLectura==NULL){
		return 0;
	} //si existe el fichero lo sobreescribe

	datosAlumno datoLectura;

	p.setFicheroBD(datoLectura);

	
	cout<<"**************Datos Fichero******************************"<<endl;
	cout<<"__________________________________________________________"<<endl;

	//fseek(ficheroLectura,0L, SEEK_SET);
	
	fread(&datoLectura, sizeof(datosAlumno), 1, ficheroLectura);
	//fread(p.getFicheroBD(), sizeof(datosAlumno), 1, ficheroLectura);//no funciona para el puntero hacia la base de datos definitdo en  Profesor.h
	
	while(!feof(ficheroLectura)){
		cout<<datoLectura.nombre<<endl;
		cout<<datoLectura.curso<<endl;
				
		aux.setNombre(datoLectura.nombre);
		aux.setCurso(datoLectura.curso);

		introducirAlumno(aux);
		//fread(p.getFicheroBD(), sizeof(datosAlumno), 1, ficheroLectura);//no funciona para el puntero hacia la base de datos definitdo en  Profesor.h
		fread(&datoLectura, sizeof(datosAlumno), 1, ficheroLectura);
	}
	

	cout<<listaAlumnos_.size()<<endl;

	list <Alumno>::iterator i;

	system("clear");
	
	cout<<BOLD_ON<<"\tLISTA DE ALUMNOS CARGADA EN EL SISTEMA________________"<<RESET<<endl;
	cout<<""<<endl;
	cout<<endl;
	
	cout<<fixed;
	cout<<setprecision(2);
	cout.fill('*');

	cout<<left<<setw(40)<<"\t|Nombre|"<<
		left<<setw(20)<<"\t|Curso|"<<endl;
	

	for (i = listaAlumnos_.begin(); i !=listaAlumnos_.end(); ++i)
	{

		if (i->getNombre()=="rodolfo"){
			cout.fill('-');
				
			cout<<BOLD_ON<<COLOR_YELLOW<<left<<setw(40)<<setiosflags (ios::uppercase)<<i->getNombre()<<//setiosflags (std::ios::showbase | std::ios::uppercase)
											left<<setw(20)<<i->getCurso()<<RESET<<endl;
		}
		else{
			cout.fill(' ');
			
			cout<<COLOR_BRIGHTRED <<left<<setw(40)<<i->getNombre()<<
											left<<setw(20)<<i->getCurso()<<COLOR_NORMAL<<endl;
		
		}

	}
	getchar();
	getchar();
	system("clear");
	fclose(ficheroLectura);



	return 1;

      
  }














