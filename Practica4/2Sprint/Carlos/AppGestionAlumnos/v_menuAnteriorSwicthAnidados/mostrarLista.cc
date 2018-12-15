//mostrarLista.cc

#include "BD.h"
#include "Alumno.h"
#include <iostream>
#include <list>
#include "consoleLinux.h"//colores menu
#include <iomanip>//formato cout

/*

		string dni_, nombre_, apellidos_, fecha_nacimiento_, email_corporativo_, domicilio_;
		int telefono_, curso_, nota_, equipo_;
		bool lider_;
*/
void saltolinea();
int ordenarDNI(const Alumno &A, const Alumno &B);



void BD::mostrarAlumno(list <Alumno> lista, int opcionOrden, string orden){

	lista.sort(ordenarDNI);
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

void BD::mostrarAlumno(int opcionOrden, string orden){

	list <Alumno>::iterator i;
	cout.fill(' ');
	list<Alumno> aux;
	aux=getAlumnos();
	aux.sort(ordenarDNI);

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

	cout<<BOLD_ON<<COLOR_DARKGREY<<left<<setw(10)<<"|DNI|"<<
		left<<setw(30)<<"|Nombre|"<<
		left<<setw(30)<<"|Apellidos|"<<
		left<<setw(5)<<"|Curso|"<<
		left<<setw(8)<<"|Fecha Nac|"<<
		left<<setw(8)<<"|fecha_n|"<<
		left<<setw(8)<<"|fecha_nacimiento|"<<
		left<<setw(8)<<"|fecha_nacimiento|"<<
		left<<setw(8)<<"|fecha_nacimiento|"<<RESET<<endl;
	

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








void saltolinea(){
	cout<<endl;


}

int ordenarDNI(const Alumno &A, const Alumno &B){

 	if( A.getNombre() == B.getNombre() && A.getApellidos() == B.getApellidos()) return 1;

	   if( A.getNombre() == B.getNombre() && A.getApellidos() < B.getApellidos()) return 1;

	   if( A.getNombre() < B.getNombre() ) return 1;

	   return 0;



}


