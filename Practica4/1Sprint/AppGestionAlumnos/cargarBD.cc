
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

std::ostream& bold_on(std::ostream& os)
{
    return os << "\e[1m";
}

std::ostream& bold_off(std::ostream& os)
{
    return os << "\e[0m";
}


void centerstring(char* s){
	   
	int l=strlen(s);
	int pos=(int)((80-l)/2);
	for(int i=0;i<pos;i++){
	   	cout<<" ";
	   	cout<<s;

	}
}



bool BD::cargarBD(){
	
	consoleLinux consola;

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
	consola.clearScreen();
	system("clear");
	
	cout<<bold_on<<"\tLISTA DE ALUMNOS CARGADA EN EL SISTEMA________________"<<bold_off<<endl;
	cout<<""<<endl;
	cout<<endl;
	
	cout<<fixed;
	cout<<setprecision(2);
	cout.fill('*');

	cout<<left<<setw(40)<<"|Nombre|"<<
		left<<setw(20)<<"|Curso|"<<endl;
	for (i = listaAlumnos_.begin(); i !=listaAlumnos_.end(); ++i)
	{

		if (i->getNombre()=="rodolfo"){
			cout.fill('-');
				
			cout<<bold_on<<ANSI_COLOR_YELLOW<<left<<setw(40)<<setiosflags (ios::uppercase)<<i->getNombre()<<//setiosflags (std::ios::showbase | std::ios::uppercase)
											left<<setw(20)<<i->getCurso()<<bold_off<<endl;
		}
		else{
			cout.fill(' ');
			
			cout<<ANSI_COLOR_BRIGHTRED <<left<<setw(40)<<i->getNombre()<<
											left<<setw(20)<<i->getCurso()<<ANSI_COLOR_NORMAL<<endl;
		
		}

	}
	getchar();
	getchar();
	system("clear");
	fclose(ficheroLectura);



	return 1;

      
  }










