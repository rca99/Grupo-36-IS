//mostrarLista.cc

#include "BD.h"
#include <iostream>
#include <list>
#include "consoleLinux.h"//colores menu
#include <iomanip>//formato cout

void BD::mostrarAlumno(list <Alumno> lista){

	list <Alumno>::iterator i;
	cout.fill('*');

	cout<<BOLD_ON<<left<<setw(40)<<"|::LISTA ALUMNOS::|"<<RESET<<endl;
	
	cout<<""<<endl;
	cout<<endl;
	
	cout<<fixed;
	cout<<setprecision(2);
	cout.fill('-');

	cout<<left<<setw(40)<<"|Nombre|"<<
		left<<setw(20)<<"|Curso|"<<endl;
	
	for (i = lista.begin(); i !=lista.end(); ++i){

		if (i->getLider()==1){
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
}

void BD::mostrarAlumno(){

	list <Alumno>::iterator i;
	cout.fill('*');
	list<Alumno> aux;
	aux=getAlumnos();
	cout<<BOLD_ON<<left<<setw(80)<<"|::LISTA ALUMNOS::|"<<RESET<<endl;
	
	cout<<""<<endl;
	cout<<endl;
	
	cout<<fixed;
	cout<<setprecision(2);
	cout.fill('-');

	cout<<BOLD_ON<<COLOR_DARKGREY<<left<<setw(30)<<"|Nombre|"<<
		left<<setw(6)<<"|Curso|"<<RESET<<endl;
	

	for (i = aux.begin(); i!=aux.end(); ++i){

		cout.fill(' ');
			
		cout<<COLOR_BRIGHTBLUE<<left<<setw(30)<<i->getNombre()<<
			left<<setw(6)<<i->getCurso()<<COLOR_NORMAL<<endl;
			

	}





}








