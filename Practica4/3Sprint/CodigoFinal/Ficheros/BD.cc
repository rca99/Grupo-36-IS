// BD.cc
// Cuerpo de la clase BD

#include <iostream>
#include <cstdlib>
#include <list>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip> // formato cout
#include <locale> // para función pasar a mayúscula

#include "BD.h"
#include "Alumno.h"
#include "Profesor.h"
#include "consoleLinux.h"

//FUNCIONES AUXILIARES
void LimpiarPantalla() {system("clear");}
void saltolinea() {cout<<endl;}
string convertirMayuscula(string cadena);

//FUNCIONES NECESARIAS PARA MOSTRAR
int ordenarApellidos(const Alumno &A, const Alumno &B);
int ordenarDNI(const Alumno &A, const Alumno &B);
int ordenarGrupo(const Alumno &A, const Alumno &B);
int ordenarCurso(const Alumno &A, const Alumno &B);

bool BD::introducirAlumno(Alumno &nuevoAlumno) {
	if(nuevoAlumno.getLider()==true) {
		if(gestionLideres(nuevoAlumno)==false) {
			int opc=0;
			cout << BOLD_RED << "\n\tESTE GRUPO YA TIENE LIDER" << endl;
			cout << COLOR_BRIGHTGREEN << "\n\tPULSE 1 SI DESEA INTRODUCIR EL ALUMNO SIN SER LIDER: " << COLOR_BRIGHTBLUE;
			cin >> opc;
			cout << RESET;
			if(opc != 1) {
				return false;
			}
			nuevoAlumno.setLider(false);
		}
	}

	listaAlumnos_.push_back(nuevoAlumno);
	
	numeroAlumnos_++;

	return true;
}

bool BD::modificarAlumno(Alumno alumnox, string dni) {

	if(alumnox.getLider()==true) {
		if(gestionLideres(alumnox, dni)==false) {
			int opc=0;
			cout << BOLD_RED << "\n\tESTE GRUPO YA TIENE LIDER" << endl;
			cout << COLOR_BRIGHTGREEN << "\n\tPULSE 1 SI DESEA MODIFICAR EL ALUMNO SIN SER LIDER: " << COLOR_BRIGHTBLUE;
			cin >> opc;
			cout << RESET;
			if(opc != 1)
				return false;
			alumnox.setLider(false);
		}
	}

	list <Alumno> :: iterator i;

	for(i=listaAlumnos_.begin(); i!=listaAlumnos_.end(); i++) {
		if((*i).getDNI()==dni) {
			*i=alumnox;
			return true;
		}
	}

	return false;
}


	


bool BD::gestionLideres(Alumno alumnox, string dni) {

	int myteam=alumnox.getEquipo();
	list <Alumno> grupo;

	// buscarAlumnoporGrupos
	buscarAlumnoEquipo(grupo, myteam);


	// Comprueba que los alumnos del grupo no sean lideres 
	list <Alumno> :: iterator i ; 

	for(i=grupo.begin(); i!=grupo.end(); i++) {
		if(((*i).getLider()==1) && ((*i).getDNI() != dni)) {
			return false;
		} // Si alguno es lider, no se puede asignar un nuevo lider
	}

	// Si sale del for, significa que no hay lideres
	return true;
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

void BD::mostrarAlumnoHtml(list <Alumno> lista, int opcOrden, string orden){

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


	/////GENERAR LISTA HTML CON TODOS LOS ALUMNOS ORDEN ASCENDENTE///////

		FILE *fp;
	
		char NombreFichero[50];
		string nameBD="./listaAlumnos/listaAlumnos.html";
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
		
		char Opcion_OrdenFichero[20];
		char OrdenFichero[20];
		
		strcpy(Opcion_OrdenFichero, OPCION_ORDEN.c_str());
		strcpy(OrdenFichero, ORDEN.c_str());


		fprintf(fp, "<p><strong> Lista de Alumnos del sistema </strong></p>");
		fprintf(fp, "<p> <span style='font-size:12px;''>El o los alumnos se mostrar&aacute;n seg&uacute;n su %s y de forma %s </span></p>", Opcion_OrdenFichero, OrdenFichero);

		//tabla
		fprintf(fp, "<table border='3' cellpadding='1' cellspacing='2' style='width:800px;'>");
			fprintf(fp, "<tbody>");
				//columnas
				fprintf(fp, "<tr>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>DNI   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>NOMBRE   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>APELLIDOS   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>FECHA NACIMIENTO   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>CORREO ELECTRONICO   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>DOMICILIO   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>TELEFONO   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>CURSO   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>NOTA   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>EQUIPO   </strong></span></td>");
					fprintf(fp, "<td style='text-align: center;''><strong> <span style='font-size:15px;''>LIDER   </strong></span></td>");
					
				fprintf(fp, "</tr>");
				//filas
				
				char nombre[40], dni[10],apellidos[40], fecha_nacimiento[20], email_corporativo[50], domicilio[60];
				int curso, telefono, nota, equipo;
				bool lider;
				
				for ( i=lista.begin(); i !=lista.end(); ++i){
					//conversión para añadir alumnos al fichero
					strcpy(nombre, i->getNombre().c_str());
					strcpy(apellidos, i->getApellidos().c_str());
					strcpy(dni, i->getDNI().c_str());
					strcpy(fecha_nacimiento, i->getFecha_nacimiento().c_str());
					strcpy(email_corporativo, i->getEmail_corporativo().c_str());
					strcpy(domicilio, i->getDomicilio().c_str());
					telefono=i->getTelefono();
					curso=i->getCurso();
					nota=i->getNota();
					equipo=i->getEquipo();
					lider=i->getLider();

					//if para controlar si es líder y darle otro formato
					if (lider==1){
						fprintf(fp, "<tr>");
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span></span> </td>", dni);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span></span> </td>", nombre);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span> </span></td>", apellidos);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span> </span></td>", fecha_nacimiento);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span>  </span></td>", email_corporativo);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span> </span> </td>", domicilio);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", telefono);
						fprintf(fp, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", curso);
						fprintf(fp, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", nota);
						fprintf(fp, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", equipo);
						fprintf(fp, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", lider);
						fprintf(fp, "</tr>");



					}
					else{

						fprintf(fp, "<tr>");
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", dni);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", nombre);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", apellidos);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", fecha_nacimiento);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", email_corporativo);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", domicilio);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%d</span></span></td>", telefono);
						fprintf(fp, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%d</span></span></td>", curso);
						fprintf(fp, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%d</span></span></td>", nota);
						fprintf(fp, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%d</span></span></td>", equipo);
						fprintf(fp, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%i</span></span></td>", lider);
						fprintf(fp, "</tr>");
					}

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
		system("chmod +x abrirCarpetaLista.sh");
		system("./abrirCarpetaLista.sh");


		///*****************************************///
	}

	if (orden=="DESC"){
	
		//orden descendente
		list <Alumno>::reverse_iterator ri;
		
		FILE *fpdescendente;

		char NombreFichero[50];
		string nameBD="./listaAlumnos/listaAlumnos.html";
		strcpy(NombreFichero, nameBD.c_str());

	
		cout<<BOLD_ON<<COLOR_YELLOW<<BLINK<<getNumeroAlumnos()<<RESET<<endl;
		
		/* Abrir archivo para escritura */
		fpdescendente = fopen(NombreFichero, "w");
		fprintf(fpdescendente, "<html> \n");
		fprintf(fpdescendente, "<head> \n");
		fprintf(fpdescendente, "<title>LISTA ALUMNOS</title>\n");
		fprintf(fpdescendente, "<head> \n");
		fprintf(fpdescendente, "<body> \n");
		fprintf(fpdescendente, "<p><a href='https://www.uco.es/eps/nodeorder/term/29' target='_blank'><img alt='' src='https://www.uco.es/eps/sites/default/files/info_general/logos/escudo_informatica.jpg' style='width: 150px; height: 150px;'' /></a></p>");
		fprintf(fpdescendente, "<p><span style='color:#003399;''><span style='font-family:comic sans ms,cursive;''><span style='font-size:24px;''><strong>GestionAlumnos&nbsp; - Grupo 36 IS</strong></span></span></span></p>");
		
		char Opcion_OrdenFichero[20];
		char OrdenFichero[20];
		
		strcpy(Opcion_OrdenFichero, OPCION_ORDEN.c_str());
		strcpy(OrdenFichero, ORDEN.c_str());


		fprintf(fpdescendente, "<p><strong> Lista de Alumnos del sistema </strong></p>");
		fprintf(fpdescendente, "<p> <span style='font-size:12px;''>El o los alumnos se mostrar&aacute;n seg&uacute;n su %s y de forma %s </span></p>", Opcion_OrdenFichero, OrdenFichero);


		//tabla
		fprintf(fpdescendente, "<table border='3' cellpadding='1' cellspacing='2' style='width:800px;'>");
			fprintf(fpdescendente, "<tbody>");
				//columnas
				fprintf(fpdescendente, "<tr>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>DNI   </strong></span></td>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>NOMBRE   </strong></span></td>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>APELLIDOS   </strong></span></td>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>FECHA NACIMIENTO   </strong></span></td>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>CORREO ELECTRONICO   </strong></span></td>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>DOMICILIO   </strong></span></td>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>TELEFONO   </strong></span></td>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>CURSO   </strong></span></td>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>NOTA   </strong></span></td>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>EQUIPO   </strong></span></td>");
					fprintf(fpdescendente, "<td style='text-align: center;''><strong> <span style='font-size:15px;''>LIDER   </strong></span></td>");
					
				fprintf(fpdescendente, "</tr>");
				//filas
				

				char nombre[40], dni[10],apellidos[40], fecha_nacimiento[20], email_corporativo[50], domicilio[60];
				int curso, telefono, nota, equipo;
				bool lider;
				
				for ( ri=lista.rbegin(); ri !=lista.rend(); ++ri){
					//conversión para añadir alumnos al fichero
					strcpy(nombre, ri->getNombre().c_str());
					strcpy(apellidos, ri->getApellidos().c_str());
					strcpy(dni, ri->getDNI().c_str());
					strcpy(fecha_nacimiento, ri->getFecha_nacimiento().c_str());
					strcpy(email_corporativo, ri->getEmail_corporativo().c_str());
					strcpy(domicilio, ri->getDomicilio().c_str());
					telefono=ri->getTelefono();
					curso=ri->getCurso();
					nota=ri->getNota();
					equipo=ri->getEquipo();
					lider=ri->getLider();

					//if para controlar si es líder y darle otro formato
					if (lider==1){
						fprintf(fpdescendente, "<tr>");
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span></span> </td>", dni);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span></span> </td>", nombre);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span> </span></td>", apellidos);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span> </span></td>", fecha_nacimiento);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span>  </span></td>", email_corporativo);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span> </span> </td>", domicilio);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", telefono);
						fprintf(fpdescendente, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", curso);
						fprintf(fpdescendente, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", nota);
						fprintf(fpdescendente, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", equipo);
						fprintf(fpdescendente, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", lider);
						fprintf(fpdescendente, "</tr>");



					}
					else{

						fprintf(fpdescendente, "<tr>");
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", dni);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", nombre);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", apellidos);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", fecha_nacimiento);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", email_corporativo);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", domicilio);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%d</span></span></td>", telefono);
						fprintf(fpdescendente, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%d</span></span></td>", curso);
						fprintf(fpdescendente, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%d</span></span></td>", nota);
						fprintf(fpdescendente, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%d</span></span></td>", equipo);
						fprintf(fpdescendente, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%i</span></span></td>", lider);
						fprintf(fpdescendente, "</tr>");
					}

				}	
		
			fprintf(fpdescendente, "</tbody>");
		fprintf(fpdescendente, "</table>\n");
		//fin tabla
		fprintf(fpdescendente, "<br />");
	
		fprintf(fpdescendente, "<body> \n");
		fprintf(fpdescendente, "<html> \n");

		/* Cerrar el archivo antes de terminar el programa */
		fclose(fpdescendente);
		printf("Se ha creado el archivo: listaAlumnos.html \n");
		system("chmod +x abrirCarpetaLista.sh");
		system("./abrirCarpetaLista.sh");

		///*****************************************///
	}	
}

void BD::mostrarAlumnoHtml(int opcOrden, string orden){

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
		
		/////GENERAR LISTA HTML CON TODOS LOS ALUMNOS///////

		FILE *fp;
	
		char NombreFichero[50];
		string nameBD="./listaAlumnos/listaAlumnos.html";
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
		
		char Opcion_OrdenFichero[20];
		char OrdenFichero[20];
		
		strcpy(Opcion_OrdenFichero, OPCION_ORDEN.c_str());
		strcpy(OrdenFichero, ORDEN.c_str());


		fprintf(fp, "<p><strong> Lista de Alumnos del sistema </strong></p>");
		fprintf(fp, "<p> <span style='font-size:12px;''>El o los alumnos se mostrar&aacute;n seg&uacute;n su %s y de forma %s </span></p>", Opcion_OrdenFichero, OrdenFichero);

		//tabla
		fprintf(fp, "<table border='3' cellpadding='1' cellspacing='2' style='width:800px;'>");
			fprintf(fp, "<tbody>");
				//columnas
				fprintf(fp, "<tr>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>DNI   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>NOMBRE   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>APELLIDOS   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>FECHA NACIMIENTO   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>CORREO ELECTRONICO   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>DOMICILIO   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>TELEFONO   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>CURSO   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>NOTA   </strong></span></td>");
					fprintf(fp, "<td><strong> <span style='font-size:12px;''>EQUIPO   </strong></span></td>");
					fprintf(fp, "<td style='text-align: center;''><strong> <span style='font-size:15px;''>LIDER   </strong></span></td>");
					
				fprintf(fp, "</tr>");
				//filas
				
				char nombre[40], dni[10],apellidos[40], fecha_nacimiento[20], email_corporativo[50], domicilio[60];
				int curso, telefono, nota, equipo;
				bool lider;
				
				for ( i=aux.begin(); i !=aux.end(); ++i){
					//conversión para añadir alumnos al fichero
					strcpy(nombre, i->getNombre().c_str());
					strcpy(apellidos, i->getApellidos().c_str());
					strcpy(dni, i->getDNI().c_str());
					strcpy(fecha_nacimiento, i->getFecha_nacimiento().c_str());
					strcpy(email_corporativo, i->getEmail_corporativo().c_str());
					strcpy(domicilio, i->getDomicilio().c_str());
					telefono=i->getTelefono();
					curso=i->getCurso();
					nota=i->getNota();
					equipo=i->getEquipo();
					lider=i->getLider();

					//if para controlar si es líder y darle otro formato
					if (lider==1){
						fprintf(fp, "<tr>");
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span></span> </td>", dni);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span></span> </td>", nombre);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span> </span></td>", apellidos);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span> </span></td>", fecha_nacimiento);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span>  </span></td>", email_corporativo);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span> </span> </td>", domicilio);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", telefono);
						fprintf(fp, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", curso);
						fprintf(fp, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", nota);
						fprintf(fp, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", equipo);
						fprintf(fp, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", lider);
						fprintf(fp, "</tr>");



					}
					else{

						fprintf(fp, "<tr>");
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", dni);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", nombre);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", apellidos);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", fecha_nacimiento);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", email_corporativo);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", domicilio);
						fprintf(fp, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%d</span></span></td>", telefono);
						fprintf(fp, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%d</span></span></td>", curso);
						fprintf(fp, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%d</span></span></td>", nota);
						fprintf(fp, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%d</span></span></td>", equipo);
						fprintf(fp, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%i</span></span></td>", lider);
						fprintf(fp, "</tr>");
					}

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
		system("chmod +x abrirCarpetaLista.sh");
		system("./abrirCarpetaLista.sh");

		///*****************************************///
	}

	if (orden=="DESC"){
	
		//orden descendente
		list <Alumno>::reverse_iterator ri;
		
		
		FILE *fpdescendente;

		char NombreFichero[50];
		string nameBD="./listaAlumnos/listaAlumnos.html";
		strcpy(NombreFichero, nameBD.c_str());

		cout<<BOLD_ON<<COLOR_YELLOW<<BLINK<<getNumeroAlumnos()<<RESET<<endl;
		
		/* Abrir archivo para escritura */
		fpdescendente = fopen(NombreFichero, "w");
		fprintf(fpdescendente, "<html> \n");
		fprintf(fpdescendente, "<head> \n");
		fprintf(fpdescendente, "<title>LISTA ALUMNOS</title>\n");
		fprintf(fpdescendente, "<head> \n");
		fprintf(fpdescendente, "<body> \n");
		fprintf(fpdescendente, "<p><a href='https://www.uco.es/eps/nodeorder/term/29' target='_blank'><img alt='' src='https://www.uco.es/eps/sites/default/files/info_general/logos/escudo_informatica.jpg' style='width: 150px; height: 150px;'' /></a></p>");
		fprintf(fpdescendente, "<p><span style='color:#003399;''><span style='font-family:comic sans ms,cursive;''><span style='font-size:24px;''><strong>GestionAlumnos&nbsp; - Grupo 36 IS</strong></span></span></span></p>");
		
		char Opcion_OrdenFichero[20];
		char OrdenFichero[20];
		
		strcpy(Opcion_OrdenFichero, OPCION_ORDEN.c_str());
		strcpy(OrdenFichero, ORDEN.c_str());

		fprintf(fpdescendente, "<p><strong> Lista de Alumnos del sistema </strong></p>");
		fprintf(fpdescendente, "<p> <span style='font-size:12px;''>El o los alumnos se mostrar&aacute;n seg&uacute;n su %s y de forma %s </span></p>", Opcion_OrdenFichero, OrdenFichero);

		//tabla
		fprintf(fpdescendente, "<table border='3' cellpadding='1' cellspacing='2' style='width:800px;'>");
			fprintf(fpdescendente, "<tbody>");
				//columnas
				fprintf(fpdescendente, "<tr>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>DNI   </strong></span></td>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>NOMBRE   </strong></span></td>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>APELLIDOS   </strong></span></td>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>FECHA NACIMIENTO   </strong></span></td>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>CORREO ELECTRONICO   </strong></span></td>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>DOMICILIO   </strong></span></td>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>TELEFONO   </strong></span></td>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>CURSO   </strong></span></td>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>NOTA   </strong></span></td>");
					fprintf(fpdescendente, "<td><strong> <span style='font-size:12px;''>EQUIPO   </strong></span></td>");
					fprintf(fpdescendente, "<td style='text-align: center;''><strong> <span style='font-size:15px;''>LIDER   </strong></span></td>");
					
				fprintf(fpdescendente, "</tr>");
				//filas
				
				char nombre[40], dni[10],apellidos[40], fecha_nacimiento[20], email_corporativo[50], domicilio[60];
				int curso, telefono, nota, equipo;
				bool lider;
				
				for ( ri=aux.rbegin(); ri !=aux.rend(); ++ri){
					//conversión para añadir alumnos al fichero
					strcpy(nombre, ri->getNombre().c_str());
					strcpy(apellidos, ri->getApellidos().c_str());
					strcpy(dni, ri->getDNI().c_str());
					strcpy(fecha_nacimiento, ri->getFecha_nacimiento().c_str());
					strcpy(email_corporativo, ri->getEmail_corporativo().c_str());
					strcpy(domicilio, ri->getDomicilio().c_str());
					telefono=ri->getTelefono();
					curso=ri->getCurso();
					nota=ri->getNota();
					equipo=ri->getEquipo();
					lider=ri->getLider();

					//if para controlar si es líder y darle otro formato
					if (lider==1){
						fprintf(fpdescendente, "<tr>");
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span></span> </td>", dni);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span></span> </td>", nombre);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span> </span></td>", apellidos);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span> </span></td>", fecha_nacimiento);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span>  </span></td>", email_corporativo);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%s</span></span> </span> </td>", domicilio);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", telefono);
						fprintf(fpdescendente, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", curso);
						fprintf(fpdescendente, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", nota);
						fprintf(fpdescendente, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", equipo);
						fprintf(fpdescendente, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='color:#FF0000;'><span style='font-size:11px;''>%d</span></span> </span></td>", lider);
						fprintf(fpdescendente, "</tr>");
					}
					else{

						fprintf(fpdescendente, "<tr>");
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", dni);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", nombre);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", apellidos);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", fecha_nacimiento);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", email_corporativo);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%s</span></span></td>", domicilio);
						fprintf(fpdescendente, "<td><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%d</span></span></td>", telefono);
						fprintf(fpdescendente, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%d</span></span></td>", curso);
						fprintf(fpdescendente, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%d</span></span></td>", nota);
						fprintf(fpdescendente, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%d</span></span></td>", equipo);
						fprintf(fpdescendente, "<td style='text-align: center;''><span style='font-family:tahoma,geneva,sans-serif;'><span style='font-size:11px;''>%i</span></span></td>", lider);
						fprintf(fpdescendente, "</tr>");
					}

				}	
				
			fprintf(fpdescendente, "</tbody>");
		fprintf(fpdescendente, "</table>\n");
		//fin tabla
		fprintf(fpdescendente, "<br />");
	
		fprintf(fpdescendente, "<body> \n");
		fprintf(fpdescendente, "<html> \n");

		/* Cerrar el archivo antes de terminar el programa */
		fclose(fpdescendente);
		printf("Se ha creado el archivo: listaAlumnos.html \n");
		system("chmod +x abrirCarpetaLista.sh");
		system("./abrirCarpetaLista.sh");

		///*****************************************///
	}	
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


//ORDENLISTA (EN menuprincipal.cc)


bool BD::buscarAlumnos() { // Comprueba que haya alumnos dados de alta
	if(getNumeroAlumnos() == 0) 
		return false;
	else return true;
}

bool BD::buscarAlumnoDNI(list <Alumno> &lista, Alumno a){
	int contador=0;

	list <Alumno> :: iterator i;

	string dniAlumno=convertirMayuscula(a.getDNI());
	
	for(i=listaAlumnos_.begin(); i!=listaAlumnos_.end(); i++) {
		string dniLista=convertirMayuscula((*i).getDNI());
		
		if(dniLista.compare(dniAlumno)==0){
			(lista).push_back(*i);
			contador++;
		}
		/*
		if((*i).getDNI()==a.getDNI()) {
			(lista).push_back(*i);
			contador++;
		}
		*/
	}

	if (contador>0){
		return true;
	}
	else{
		return false;
	}
}	

bool BD::buscarAlumnoApellido(list <Alumno> &lista, Alumno a){
	int contador=0;
	
	/*//Convertir string a mayúsculas
	string cadena;
	getline(cin, cadena);
	cout<<"Cadena introducida en mayusculas"<<cadena<<endl;
	cadena=convertirMayuscula(cadena);
	cout<<cadena<<endl;
	*/

	list <Alumno> :: iterator i;
	
	string apellidoAlumno=convertirMayuscula(a.getApellidos());
	//cout<<"apellido que se busca: "<<apellidoAlumno<<endl;

	for(i=listaAlumnos_.begin(); i!=listaAlumnos_.end(); i++) {
		string apellidoLista=convertirMayuscula((*i).getApellidos());

		//cout<<"apellido en lista: "<<apellidoLista<<endl;
		/*este método de comparación no va bien supongo que es al acceder con punteros a la lista
		if((*i).getApellidos()==a.getApellidos()) {
			(lista).push_back(*i);
			contador++;
		}
		*/
		if(apellidoLista.compare(apellidoAlumno)==0){
			(lista).push_back(*i);
			contador++;
		}
	}

	if (contador>0) {
		return true;
	}
	else {
		return false;
	}
}

bool BD::buscarAlumnoEquipo(list <Alumno> &lista,int equipo){

	int contador=0;
	list <Alumno> :: iterator i;


	for(i=listaAlumnos_.begin(); i!=listaAlumnos_.end(); i++) {

		if((*i).getEquipo()==equipo) {
			lista.push_back(*i);
			contador++;
		}
	}

	if (contador>0) {
		return true;
	} else return false;
}


string convertirMayuscula(string cadena){

  	locale loc;
 	string s=cadena;
 	
  	for (string::size_type i=0; i<s.length(); ++i){

  		 s[i]=toupper((s)[i],loc);
	
  	}
	return s;
}

bool BD::buscarAlumnoDNIv2(vector <Alumno> &vector, Alumno a) {
	list <Alumno> :: iterator i;

	for(i=listaAlumnos_.begin(); i!=listaAlumnos_.end(); i++)
		if((*i).getDNI()==a.getDNI())
			vector.push_back(*i);

	if (vector.size()>0)
		return true;
	else return false;
}

bool BD::buscarAlumnoApellidov2(vector <Alumno> &vector, Alumno a) {
	list <Alumno> :: iterator i;

	for(i=listaAlumnos_.begin(); i!=listaAlumnos_.end(); i++)
		if((*i).getApellidos()==a.getApellidos())
			vector.push_back(*i);

	if (vector.size()>0)
		return true;
	else return false;
}

bool BD::buscarAlumnoEquipov2(vector <Alumno> &vector, int equipo) {
	list <Alumno> :: iterator i;

	for(i=listaAlumnos_.begin(); i!=listaAlumnos_.end(); i++)
		if((*i).getEquipo()==equipo)
			vector.push_back(*i);

	if (vector.size()>0)
		return true;
	else return false;
}

bool BD::guardarBD(){
	//cout<<"tamaño lista: "<<listaAlumnos_.size()<<endl;

	//el método de leer fichero recibe el nombre del fichero como tipo char
	char NombreFicheroBin[50];
	string nameBD=getNombreFichero()+".bin";
	strcpy(NombreFicheroBin, nameBD.c_str());



	//*******Escribir Fichero **********//
	FILE *fichero;
	datosAlumno dato;

	fichero=fopen(NombreFicheroBin, "wa+b");
	if (fichero==NULL){
		cout<<"no existe"<<endl;
	} //si existe el fichero lo sobreescribe


	list <Alumno>::iterator i;

	list <Alumno> aux;
	list <Alumno> auxiliarEscribir;

	aux=listaAlumnos_;
	
	for (i = aux.begin(); i!=aux.end(); ++i)
	{
	
		cout<<i->getNombre()<<"-"<<i->getCurso()<<"-"<<i->getApellidos()<<i->getLider()<<endl;
		//dato.nombre=i->getNombre();
		strcpy(dato.dni, i->getDNI().c_str());
		strcpy(dato.nombre, i->getNombre().c_str());
		strcpy(dato.apellidos, i->getApellidos().c_str());
		strcpy(dato.fecha_nacimiento, i->getFecha_nacimiento().c_str());
		strcpy(dato.email_corporativo, i->getEmail_corporativo().c_str());
		strcpy(dato.domicilio, i->getDomicilio().c_str());
		
		dato.curso=i->getCurso();
		dato.telefono=i->getTelefono();
		dato.nota=i->getNota();
		dato.equipo=i->getEquipo();
		dato.lider=i->getLider();

		fwrite(&dato, sizeof(datosAlumno), 1, fichero);

	}

	fclose(fichero);
	return 1;
}

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
		aux.setEmail_corporativo(datoLectura.email_corporativo);
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

bool BD::guardarBackup(){
	system("chmod +x guardarExterna.sh");
	system("./guardarExterna.sh");
	return 1;
}

bool BD::cargarBackup(){
	getchar();
	system("chmod +x cargarExterna.sh");
	system("./cargarExterna.sh");
	
	Alumno aux; //para guardar los datos que se van leyendo. Su contenido es añadido a listaAlumnos_ a partir de la función introducirAlumno(alumno)

	Profesor p;// para usar el puntero a la base de datos

	//el método de leer fichero recibe el nombre del fichero como tipo char
	char NombreFicheroBin[50];
	//system("cd CopiaSeguridad");
	string nameBD="CopiaSeguridad/gestionAlumnos.bin";
	strcpy(NombreFicheroBin, nameBD.c_str());
	
	
	listaAlumnos_.clear();
	cout<<listaAlumnos_.size()<<endl;

	//******leer fichero*********//
	FILE *ficheroLectura;
	ficheroLectura=fopen(NombreFicheroBin, "rb");
	
	if (ficheroLectura==NULL){
		//return 0;
	} //si existe el fichero lo sobreescribe

	datosAlumno datoLectura;

	p.setFicheroBD(datoLectura);

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

		introducirAlumnoCopiaExterna(aux);
		//fread(p.getFicheroBD(), sizeof(datosAlumno), 1, ficheroLectura);//no funciona para el puntero hacia la base de datos definitdo en  Profesor.h
		fread(&datoLectura, sizeof(datosAlumno), 1, ficheroLectura);
	}

	cout<<"nº alumnos"<<listaAlumnos_.size()<<endl;

	list <Alumno>::iterator i;

	system("clear");
	
	cout<<BOLD_ON<<"\tCOPIA DE SEGURIDAD EXTERNA CARGADA EN EL SISTEMA________________"<<RESET<<endl;
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


bool BD::eliminarAlumno(string dni) {

	list <Alumno> :: iterator i;

	for(i=listaAlumnos_.begin(); i!=listaAlumnos_.end(); i++) {
		if((*i).getDNI()==dni) {
		
			listaAlumnos_.erase(i);
			return true;
		}
	}


	return false;
}
