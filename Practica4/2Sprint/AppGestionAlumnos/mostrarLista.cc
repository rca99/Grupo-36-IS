//mostrarLista.cc

#include "BD.h"
#include "Alumno.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <list>
#include "consoleLinux.h"//colores menu
#include <iomanip>//formato cout

/*
		string dni_, nombre_, apellidos_, fecha_nacimiento_, email_corporativo_, domicilio_;
		int telefono_, curso_, nota_, equipo_;
		bool lider_;
*/

void saltolinea();
void LimpiarPantalla();

int ordenarApellidos(const Alumno &A, const Alumno &B);
int ordenarDNI(const Alumno &A, const Alumno &B);
int ordenarGrupo(const Alumno &A, const Alumno &B);
int ordenarCurso(const Alumno &A, const Alumno &B);


//mostrarAlumno(lista, orden, ascendente)

//en mostrar alumno, ordenar lista en función orden e imprimir ascendente o descendente
//if orden 1 list.sort(orden1)


void BD::mostrarAlumno(list <Alumno> lista, int opcOrden, string orden){


	string OPCION_ORDEN;
	string ORDEN;

	if (opcOrden==1){

		lista.sort(ordenarDNI);
		OPCION_ORDEN="DNI";

	}

	if (opcOrden==2){

		lista.sort(ordenarApellidos);
		OPCION_ORDEN="Apellido";

	}

	if (opcOrden==3){

		lista.sort(ordenarGrupo);
		OPCION_ORDEN="Equipo";

	}

	if (opcOrden==4){

		lista.sort(ordenarCurso);
		OPCION_ORDEN="Curso más alto";

	}


	if(orden=="ASC"){

		ORDEN="ASCENDENTE";
	}
	if(orden=="DESC"){

		ORDEN="DESCENDENTE";
	}







	if (orden=="ASC"){

		//orden ascendente
		list <Alumno>::iterator i;
		
		cout.fill(' ');
		cout<<COLOR_BRIGHTGREEN<<"El o los alumnos se mostrarán según su  "<<RESET<<BOLD_ON<<OPCION_ORDEN<<COLOR_BRIGHTGREEN<< " y de forma "<<RESET<<BOLD_ON<<ORDEN<<RESET<<endl;
		saltolinea();
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
			left<<setw(30)<<"|Apellidos|"<<
			left<<setw(30)<<"|Nombre|"<<
			left<<setw(6)<<"|Nota|"<<
			left<<setw(7)<<"|Curso|"<<
			left<<setw(8)<<"|Equipo|"<<
			left<<setw(9)<<"|Líder|"<<
			left<<setw(30)<<"|Correo Electronico|"<<RESET<<endl;
		
		for (i = lista.begin(); i!=lista.end(); ++i){

			if (i->getLider()==1){
				cout.fill('-');
					
				cout<<BOLD_ON<<COLOR_BRIGHTGREEN<<BLINK<<left<<setw(10)<<i->getDNI()<<//setiosflags (std::ios::showbase | std::ios::uppercase)
												left<<setw(30)<<i->getApellidos()<<
												left<<setw(30)<<i->getNombre()<<
												left<<setw(6)<<i->getNota()<<
												left<<setw(7)<<i->getCurso()<<
												left<<setw(8)<<i->getEquipo()<<
												left<<setw(9)<<i->getLider()<<
												left<<setw(30)<<i->getEmail_corporativo()<<RESET<<endl;

			}
			else{
				cout.fill(' ');
				
				cout<<BOLD_ON<<COLOR_LIGTHCYAN<<left<<setw(10)<<i->getDNI()<<//setiosflags (std::ios::showbase | std::ios::uppercase)
												left<<setw(30)<<i->getApellidos()<<
												left<<setw(30)<<i->getNombre()<<
												left<<setw(6)<<i->getNota()<<
												left<<setw(7)<<i->getCurso()<<
												left<<setw(8)<<i->getEquipo()<<
												left<<setw(9)<<i->getLider()<<
												left<<setw(30)<<i->getEmail_corporativo()<<RESET<<endl;
			}	
		}
	}








	if (orden=="DESC"){
	
		//orden descendente
		list <Alumno>::reverse_iterator ri;
		
		cout.fill(' ');
		cout<<COLOR_BRIGHTGREEN<<"El o los alumnos se mostrarán según su  "<<RESET<<BOLD_ON<<OPCION_ORDEN<<COLOR_BRIGHTGREEN<< " y de forma "<<RESET<<BOLD_ON<<ORDEN<<RESET<<endl;
		saltolinea();
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
			left<<setw(30)<<"|Apellidos|"<<
			left<<setw(30)<<"|Nombre|"<<
			left<<setw(6)<<"|Nota|"<<
			left<<setw(7)<<"|Curso|"<<
			left<<setw(8)<<"|Equipo|"<<
			left<<setw(9)<<"|Líder|"<<
			left<<setw(30)<<"|Correo Electronico|"<<RESET<<endl;
		
		for (ri = lista.rbegin(); ri !=lista.rend(); ++ri){
			if (ri->getLider()==1){
				cout.fill('-');
					
				cout<<BOLD_ON<<COLOR_BRIGHTGREEN<<BLINK<<left<<setw(10)<<ri->getDNI()<<//setiosflags (std::ios::showbase | std::ios::uppercase)
												left<<setw(30)<<ri->getApellidos()<<
												left<<setw(30)<<ri->getNombre()<<
												left<<setw(6)<<ri->getNota()<<
												left<<setw(7)<<ri->getCurso()<<
												left<<setw(8)<<ri->getEquipo()<<
												left<<setw(9)<<ri->getLider()<<
												left<<setw(30)<<ri->getEmail_corporativo()<<RESET<<endl;

			}
			else{
				cout.fill(' ');
				
				cout<<BOLD_ON<<COLOR_LIGTHCYAN<<left<<setw(10)<<ri->getDNI()<<//setiosflags (std::ios::showbase | std::ios::uppercase)
												left<<setw(30)<<ri->getApellidos()<<
												left<<setw(30)<<ri->getNombre()<<
												left<<setw(6)<<ri->getNota()<<
												left<<setw(7)<<ri->getCurso()<<
												left<<setw(8)<<ri->getEquipo()<<
												left<<setw(9)<<ri->getLider()<<
												left<<setw(30)<<ri->getEmail_corporativo()<<RESET<<endl;
			}
		}
	}	
}

void BD::mostrarAlumno(int opcOrden, string orden){

	list <Alumno>::iterator i;
	cout.fill(' ');
	list<Alumno> aux;
	aux=getAlumnos();

	string OPCION_ORDEN;
	string ORDEN;

	if (opcOrden==1){

		aux.sort(ordenarDNI);
		OPCION_ORDEN="DNI";
		cout<<"1"<<endl;

	}

	if (opcOrden==2){

		aux.sort(ordenarApellidos);
		OPCION_ORDEN="Apellido";

	}

	if (opcOrden==3){

		aux.sort(ordenarGrupo);
		OPCION_ORDEN="Equipo";

	}

	if (opcOrden==4){

		aux.sort(ordenarCurso);
		OPCION_ORDEN="Curso más alto";

	}


	if(orden=="ASC"){

		ORDEN="ASCENDENTE";
	}
	if(orden=="DESC"){

		ORDEN="DESCENDENTE";
	}


	if (orden=="ASC"){

		//orden ascendente
		list <Alumno>::iterator i;
		
		cout.fill(' ');
		cout<<COLOR_BRIGHTGREEN<<"El o los alumnos se mostrarán según su  "<<RESET<<BOLD_ON<<OPCION_ORDEN<<COLOR_BRIGHTGREEN<< " y de forma "<<RESET<<BOLD_ON<<ORDEN<<RESET<<endl;
		
		saltolinea();
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
			left<<setw(30)<<"|Apellidos|"<<
			left<<setw(30)<<"|Nombre|"<<
			left<<setw(6)<<"|Nota|"<<
			left<<setw(7)<<"|Curso|"<<
			left<<setw(8)<<"|Equipo|"<<
			left<<setw(9)<<"|Líder|"<<
			left<<setw(30)<<"|Correo Electronico|"<<RESET<<endl;
		
		for (i = aux.begin(); i!=aux.end(); ++i){

			if (i->getLider()==1){
				cout.fill('-');
					
				cout<<BOLD_ON<<COLOR_BRIGHTGREEN<<BLINK<<left<<setw(10)<<i->getDNI()<<//setiosflags (std::ios::showbase | std::ios::uppercase)
												left<<setw(30)<<i->getApellidos()<<
												left<<setw(30)<<i->getNombre()<<
												left<<setw(6)<<i->getNota()<<
												left<<setw(7)<<i->getCurso()<<
												left<<setw(8)<<i->getEquipo()<<
												left<<setw(9)<<i->getLider()<<
												left<<setw(30)<<i->getEmail_corporativo()<<RESET<<endl;

			}
			else{
				cout.fill(' ');
				
				cout<<BOLD_ON<<COLOR_LIGTHCYAN<<left<<setw(10)<<i->getDNI()<<//setiosflags (std::ios::showbase | std::ios::uppercase)
												left<<setw(30)<<i->getApellidos()<<
												left<<setw(30)<<i->getNombre()<<
												left<<setw(6)<<i->getNota()<<
												left<<setw(7)<<i->getCurso()<<
												left<<setw(8)<<i->getEquipo()<<
												left<<setw(9)<<i->getLider()<<
												left<<setw(30)<<i->getEmail_corporativo()<<RESET<<endl;
			}	
		}


		/////GENERAR LISTA HTML CON TODOS LOS ALUMNOS///////



		FILE *fp;

	
		char NombreFichero[50];
		string nameBD="listaAlumnos.html";
		strcpy(NombreFichero, nameBD.c_str());

	
		cout<<BOLD_ON<<COLOR_YELLOW<<BLINK<<getNumeroAlumnos()<<RESET<<endl;
		

		/* Abrir archivo para escritura */
		fp = fopen(NombreFichero, "w");
		fprintf(fp, "<html> \n");
		fprintf(fp, "<head> \n");
		fprintf(fp, "<title>LISTA ALUMNOS</title>\n");
		fprintf(fp, "<head> \n");
		fprintf(fp, "<body> \n");
		fprintf(fp, "<p><a href='https://www.uco.es/eps/nodeorder/term/29' target='_blank'><img alt='' src='https://www.uco.es/eps/sites/default/files/info_general/logos/escudo_informatica.jpg' style='width: 150px; height: 150px;'' /></a></p>");
		fprintf(fp, "<p><span style='color:#003399;''><span style='font-family:comic sans ms,cursive;''><span style='font-size:24px;''><strong>GestionAlumnos&nbsp; - Grupo 36 IS</strong></span></span></span></p>");
		

		fprintf(fp, "<p><strong> Lista de Alumnos del sistema </strong></p>");

		fprintf(fp, "<ul>");
			fprintf(fp, "<li></li>");
			fprintf(fp, "<li>  </li>");
			fprintf(fp, "<li></li><br />");
		fprintf(fp, "<ul>");
		
		fprintf(fp, "<p></p>");

		//tabla
		fprintf(fp, "<table border='1' cellpadding='1' cellspacing='1' style='width:500px;'>");
			fprintf(fp, "<tbody>");
				//columnas
				fprintf(fp, "<tr>");
					fprintf(fp, "<td><strong> <span style='font-size:10px;''>NOMBRE   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:10px;''>APELLIDOS   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:10px;''>NOMBRE   </strong></span></td>");
					
				fprintf(fp, "</tr>");
				//filas
				
				char nombre[40];
				char apellidos[40];
				
				for ( i=aux.begin(); i !=aux.end(); ++i){
					//conversión para añadir alumnos al fichero
					strcpy(nombre, i->getNombre().c_str());
					strcpy(apellidos, i->getApellidos().c_str());

					//if para controlar si es líder y darle otro formato

					fprintf(fp, "<tr>");
					fprintf(fp, "<td>  '%s'   </td>", nombre);
					fprintf(fp, "<td>  '%s'    </td>", apellidos);
					fprintf(fp, "<td>   </td>");
					fprintf(fp, "<td>    <td>");
					fprintf(fp, "</tr>");
				}	
				

			fprintf(fp, "</tbody>");
		fprintf(fp, "</table>\n");
		//fin tabla
		fprintf(fp, "<br />");
		



		
	
		

	
		



		fprintf(fp, "<body> \n");
		fprintf(fp, "<html> \n");

		/* Cerrar el archivo antes de terminar el programa */
		fclose(fp);
		printf("Se ha creado el archivo: listaAlumnos.html \n");




















		///*****************************************/////////



































	}

	if (orden=="DESC"){
	
		//orden descendente
		list <Alumno>::reverse_iterator ri;
		
		cout.fill(' ');
		cout<<COLOR_BRIGHTGREEN<<"El o los alumnos se mostrarán según su  "<<RESET<<BOLD_ON<<OPCION_ORDEN<<COLOR_BRIGHTGREEN<< " y de forma "<<RESET<<BOLD_ON<<ORDEN<<RESET<<endl;
		
		saltolinea();
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
			left<<setw(30)<<"|Apellidos|"<<
			left<<setw(30)<<"|Nombre|"<<
			left<<setw(6)<<"|Nota|"<<
			left<<setw(7)<<"|Curso|"<<
			left<<setw(8)<<"|Equipo|"<<
			left<<setw(9)<<"|Líder|"<<
			left<<setw(30)<<"|Correo Electronico|"<<RESET<<endl;
		
		for (ri = aux.rbegin(); ri !=aux.rend(); ++ri){
			if (ri->getLider()==1){
				cout.fill('-');
					
				cout<<BOLD_ON<<COLOR_BRIGHTGREEN<<BLINK<<left<<setw(10)<<ri->getDNI()<<//setiosflags (std::ios::showbase | std::ios::uppercase)
												left<<setw(30)<<ri->getApellidos()<<
												left<<setw(30)<<ri->getNombre()<<
												left<<setw(6)<<ri->getNota()<<
												left<<setw(7)<<ri->getCurso()<<
												left<<setw(8)<<ri->getEquipo()<<
												left<<setw(9)<<ri->getLider()<<
												left<<setw(30)<<ri->getEmail_corporativo()<<RESET<<endl;

			}
			else{
				cout.fill(' ');
				
				cout<<BOLD_ON<<COLOR_LIGTHCYAN<<left<<setw(10)<<ri->getDNI()<<//setiosflags (std::ios::showbase | std::ios::uppercase)
												left<<setw(30)<<ri->getApellidos()<<
												left<<setw(30)<<ri->getNombre()<<
												left<<setw(6)<<ri->getNota()<<
												left<<setw(7)<<ri->getCurso()<<
												left<<setw(8)<<ri->getEquipo()<<
												left<<setw(9)<<ri->getLider()<<
												left<<setw(30)<<ri->getEmail_corporativo()<<RESET<<endl;
			}
		}
	}	


}




void LimpiarPantalla(){
	system("clear");


}



void saltolinea(){
	cout<<endl;


}

int ordenarApellidos(const Alumno &A, const Alumno &B){

 	if( A.getApellidos() == B.getApellidos() && A.getNombre() == B.getNombre()) return 1;

	if( A.getNombre() == B.getNombre() && A.getApellidos() < B.getApellidos()) return 1;

	if( A.getApellidos() < B.getApellidos() ) return 1;

	   return 0;



}



int ordenarDNI(const Alumno &A, const Alumno &B){
	
	if( A.getDNI() == B.getDNI() && A.getApellidos() == B.getApellidos()) return 1;

	if( A.getApellidos() == B.getApellidos() && A.getDNI() < B.getDNI()) return 1;

	if( A.getDNI() < B.getDNI() ) return 1;
	
	return 0;

}
int ordenarGrupo(const Alumno &A, const Alumno &B){
	
	if( A.getEquipo() == B.getEquipo() && A.getApellidos() == B.getApellidos()) return 1;

	if( A.getApellidos() == B.getApellidos() && A.getEquipo() < B.getEquipo()) return 1;

	if( A.getEquipo() < B.getEquipo() ) return 1;
	
	return 0;

}
int ordenarCurso(const Alumno &A, const Alumno &B){

	 if( A.getCurso() == B.getCurso() && A.getNombre() == B.getNombre()) return 1;

	if( A.getNombre() == B.getNombre() && A.getCurso() < B.getCurso()) return 1;

	if( A.getCurso() < B.getCurso() ) return 1;


	return 0;
}










