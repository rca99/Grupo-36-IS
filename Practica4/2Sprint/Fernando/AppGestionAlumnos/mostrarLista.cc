//mostrarLista.cc

#include "BD.h"
#include "Alumno.h"
#include <iostream>
#include <list>
#include "consoleLinux.h"//colores menu
#include <iomanip>//formato cout


void saltolinea();



void BD::mostrarAlumno(list <Alumno> lista){

	lista.sort();
	list <Alumno>::iterator i;
		cout.fill(' ');

	cout<<BOLD_ON<<left<<setw(100)<<"|::LISTA ALUMNOS::|"<<RESET<<endl;
	//saltolinea();
	cout.fill(' ');
	cout<<BOLD_ON<<UNDERLINE_ON<<setw(100)<<""<<RESET<<endl;
	saltolinea();
	saltolinea();
	
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
				
			cout<<BOLD_ON<<COLOR_BRIGHTGREEN<<BLINK<<left<<setw(40)<<setiosflags (ios::uppercase)<<i->getNombre()<<//setiosflags (std::ios::showbase | std::ios::uppercase)
											left<<setw(20)<<i->getCurso()<<RESET<<endl;
		}
		else{
			cout.fill(' ');
			
			cout<<COLOR_LIGTHCYAN <<left<<setw(40)<<i->getNombre()<<
											left<<setw(20)<<i->getCurso()<<COLOR_NORMAL<<endl;
		}
	}
}

void BD::mostrarAlumno(){

	list <Alumno>::iterator i;
	cout.fill(' ');
	list<Alumno> aux;
	aux=getAlumnos();
	aux.sort();

	cout<<BOLD_ON<<left<<setw(100)<<"|::LISTA ALUMNOS::|"<<RESET<<endl;
	//saltolinea();
	cout.fill(' ');
	cout<<BOLD_ON<<UNDERLINE_ON<<setw(100)<<""<<RESET<<endl;
	saltolinea();
	saltolinea();
	cout<<""<<endl;
	cout<<endl;
	
	cout<<fixed;
	cout<<setprecision(2);
	cout.fill('-');

	cout<<BOLD_ON<<COLOR_DARKGREY<<left<<setw(30)<<"|Nombre|"<<
		left<<setw(30)<<"|Apellidos|"<<RESET<<
		left<<setw(6)<<"|Curso|"<<RESET<<endl;
	

	for (i = aux.begin(); i!=aux.end(); ++i){

		if (i->getLider()==1){
			cout.fill('-');
				
			cout<<BOLD_ON<<COLOR_BRIGHTGREEN<<BLINK<<left<<setw(30)<<setiosflags (ios::uppercase)<<i->getNombre()<<//setiosflags (std::ios::showbase | std::ios::uppercase)
											left<<setw(30)<<i->getApellidos()<<
											left<<setw(6)<<i->getCurso()<<RESET<<endl;
		}
		else{
			cout.fill(' ');
			
			cout<<COLOR_LIGTHCYAN <<left<<setw(30)<<i->getNombre()<<
											left<<setw(30)<<i->getApellidos()<<RESET<<
											left<<setw(6)<<i->getCurso()<<COLOR_NORMAL<<endl;
		}	

	}

}



void OpcionesOrden(){
	
	cout.fill('*');
	saltolinea();
	cout<<"\t"<<BOLD_ON<<COLOR_CYAN<<UNDERLINE_ON<<left<<setw(40)<<"Opciones Orden"<<RESET<<endl;
	saltolinea();
	saltolinea();
	cout <<"\t"<<COLOR_CYAN<< "1. Ordenar por DNI" << RESET<<endl;
	cout <<"\t"<<COLOR_LIGTHCYAN<<  "2. Ordenar por apellido" << endl;
	cout <<"\t"<<COLOR_CYAN<< "3. Ordenar por Grupo" << endl;
	cout <<"\t"<<COLOR_LIGTHCYAN<<  "4. Ordenar por Curso más alto matriculado" << endl;
	cout <<"\t"<<COLOR_CYAN<<  "5. Volver al menú" << endl;


}




void saltolinea(){
	cout<<endl;


}



