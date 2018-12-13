
#include "BD.h" //para incluir la lista de alumnos y funciones BD 
#include "Profesor.h"//para incluir puntero a base de datos
#include "Alumno.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include "consoleLinux.h"//colores menu
#include <iomanip>//formato cout


using namespace std;


//g++ -g -Wall  menuprincipal.cc guardarBD.cc cargarBD.cc Profesor.h Alumno.h consoleLinux.h BD.h Alumno.cc


/*
guardar BD()

Descripción: Carga el contenido de la base de datos guardada en un fichero binario a la lista de alumnos

Valores devueltos: 1 si ha cargado correctamente la base de datos y 0 si no existe el fichero binario que cargar

Parámetros: no recibe ningún parámetro. Accede a listaAlumnos_ para guardarla

//puntero a la dirección de memoria de la base de datos creo que no es necesario para la implementación

*/





bool BD::cargarBD(){
	

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
		
				
		aux.setDNI(datoLectura.dni);
		aux.setNombre(datoLectura.nombre);
		aux.setApellidos(datoLectura.apellidos);
		aux.setFecha_nacimiento(datoLectura.fecha_nacimiento);
		aux.setDomicilio(datoLectura.nombre);
		aux.setEmail_corporativo(datoLectura.nombre);
		aux.setTelefono(datoLectura.telefono);
		aux.setCurso(datoLectura.curso);
		aux.setNota(datoLectura.nota);
		aux.setEquipo(datoLectura.equipo);
		aux.setLider(datoLectura.lider);

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

	cout<<left<<setw(40)<<"|Nombre|"<<
		left<<setw(20)<<"|Curso|"<<endl;
	

	for (i = listaAlumnos_.begin(); i !=listaAlumnos_.end(); ++i)
	{

		if (i->getLider()==true){
			cout.fill('-');
				
			cout<<BOLD_ON<<COLOR_YELLOW<<BLINK<<left<<setw(40)<<setiosflags (ios::uppercase)<<i->getNombre()<<//setiosflags (std::ios::showbase | std::ios::uppercase)
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










