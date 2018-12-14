// --------------
// MENU PRINCIPAL
// --------------

//g++ -g -Wall  menuprincipal.cc guardarBD.cc cargarBD.cc buscarAlumno.cc Profesor.h Alumno.h consoleLinux.h BD.h Alumno.cc


#include <iostream>
#include <string>
#include <cstdlib>

#include "Alumno.h"
#include "Profesor.h"
#include "BD.h"
#include "consoleLinux.h"

using namespace std;


void mostrarOpciones();
void mostrarOpcionesBusqueda();
bool datosBusqueda(datosAlumno &datos);

int main(int argc, char const *argv[]) {

	BD miBD; //crea un objeto de base de datos con el nombre de fichero gestionAlumnos
	int opc=0;
	int opcbusq=0;

	do {
		mostrarOpciones();
		cout << "Introduzca una opcion: ";
		cin >> opc;
		switch(opc) {
			case 1: {	// INSERTAR ALUMNO
					

					Alumno a,b,c,d,e,f,g;
					a.setNombre("rodolfo");
					a.setCurso(2);
					a.setDNI("30");
					a.setEquipo(1);

					b.setNombre("Artura");
					b.setCurso(3);
					b.setDNI("30");
					b.setEquipo(2);

					c.setNombre("Jeremias");
					c.setApellidos("lopez");
					c.setCurso(2);
					c.setDNI("50");
					c.setEquipo(3);

					d.setNombre("Pablo de las Casas");
					d.setApellidos("lopez");
					d.setCurso(1);
					d.setDNI("60");
					d.setEquipo(2);

					e.setNombre("M del Rosario");
					e.setApellidos("ruiz");
					e.setCurso(3);
					e.setDNI("70");

					f.setDNI("80");
					f.setApellidos("ruiz");

					g.setDNI("60");
					g.setApellidos("garcia");
					g.setEquipo(6);

					miBD.introducirAlumno(a);
					miBD.addNumeroAlumnos();
					miBD.introducirAlumno(b);
					miBD.addNumeroAlumnos();
					miBD.introducirAlumno(c);
					miBD.addNumeroAlumnos();
					miBD.introducirAlumno(d);
					miBD.addNumeroAlumnos();
					miBD.introducirAlumno(e);
					miBD.addNumeroAlumnos();
					
					cout<<BOLD_ON<<COLOR_YELLOW<<BLINK<<miBD.getNumeroAlumnos()<<RESET<<endl;

					list <Alumno> listaBusqueda;


					if (miBD.buscarAlumnoDNI(listaBusqueda, b)){
						cout<<"Encontrado"<<endl;	
					}
					else{
						cout<<"No Encontrado"<<endl;	
					}

					list <Alumno> :: iterator i;

					for(i=listaBusqueda.begin(); i!=listaBusqueda.end(); i++) {
		
						cout<<"Nombre:: "<<i->getNombre()<<endl;
			
					}

					//////////////////**************************************
					listaBusqueda.clear();
					
					if (miBD.buscarAlumnoDNI(listaBusqueda, f)){
						cout<<"Encontrado"<<endl;	
					}
					else{
						cout<<"No Encontrado"<<endl;	
						if(miBD.buscarAlumnoApellido(listaBusqueda, f)){
							cout<<"Encontrado"<<endl;	

						}

					}

					/* for(i=listaBusqueda.begin(); i!=listaBusqueda.end(); i++) {
		
						cout<<"Nombre-----:: "<<i->getNombre()<<endl;
			
					}


					*/


					for(i=listaBusqueda.begin(); i!=listaBusqueda.end(); i++) {
		
						cout<<"Nombre:: "<<i->getNombre()<<endl;
			
					}


					listaBusqueda.clear();

					if (miBD.buscarAlumnoApellido(listaBusqueda, c)){
						cout<<"Encontrado"<<endl;	
					}
					else{
						cout<<"No Encontrado"<<endl;
					}	

					for(i=listaBusqueda.begin(); i!=listaBusqueda.end(); i++) {
		
						cout<<"Nombre:: "<<i->getNombre()<<endl;
			
					}

					listaBusqueda.clear();





					if (miBD.buscarAlumnoGrupo(listaBusqueda, 1)){
						cout<<"Encontrado"<<endl;	
					}
					else{
						cout<<"No Encontrado"<<endl;	
					}

					for(i=listaBusqueda.begin(); i!=listaBusqueda.end(); i++) {
		
						cout<<"Nombre:: "<<i->getNombre()<<endl;
			
					}

					listaBusqueda.clear();

					if (miBD.buscarAlumnoGrupo(listaBusqueda, 2)){
						cout<<"Encontrado"<<endl;	
					}
					else{
						cout<<"No Encontrado"<<endl;	
					}

					for(i=listaBusqueda.begin(); i!=listaBusqueda.end(); i++) {
		
						cout<<"Nombre:: "<<i->getNombre()<<endl;
			
					}

					listaBusqueda.clear();

					if (miBD.buscarAlumnoGrupo(listaBusqueda, 6)){
						cout<<"Encontrado"<<endl;	
					}
					else{
						cout<<"No Encontrado"<<endl;	
					}

					for(i=listaBusqueda.begin(); i!=listaBusqueda.end(); i++) {
		
						cout<<"Nombre:: "<<i->getNombre()<<endl;
			
					}

					listaBusqueda.clear();



					/*
					datosAlumno datos;

					cout << "Introduzca los datos del nuevo alumno" << endl;

					cout << "DNI : " << endl;
					cin >> datos.dni;
					cout << "Nombre : " << endl;
					cin >> datos.nombre;
					cout << "Apellidos : " << endl;
					cin >> datos.apellidos;
					cout << "Fecha de nacimiento : " << endl;
					cin >> datos.fecha_nacimiento;
					cout << "Telefono : " << endl;
					cin >> datos.telefono;
					cout << "Email corporativo : " << endl;
					cin >> datos.email_corporativo;
					cout << "Domicilio : " << endl;
					cin >> datos.domicilio;
					cout << "Curso : " << endl;
					cin >> datos.curso;
					cout << "Nota : " << endl;
					cin >> datos.nota;
					cout << "Equipo : " << endl;
					cin >> datos.equipo;
					cout << "Lider (1: Si; 0: No): " << endl;
					cin >> datos.lider;

					Alumno aux(datos);	// Constructor con estructura

					miBD.introducirAlumno(aux);

					*/
				} break;
			case 2: {	// MODIFICAR ALUMNO
					
				} break;
			case 3: {	// ELIMINAR ALUMNO

				mostrarOpcionesBusqueda();
				cout << "Introduzca una opción de búsqueda: "<<endl;
				cin >> opcbusq;
				switch(opcbusq){
					case 1: {  // buscar por dni

					} break;

					case 2: {  // buscar por apellidos

					} break;
					default: cout << "Opcion no valida" << endl;	// OPC NO VALIDA
				}

				miBD.eliminarAlumno();


					
				} break;
			case 4: {	// MOSTRAR ALUMNOS

				} break;
			case 5: {	// GUARDAR BD

				if (miBD.getAlumnos().size()==0){
					cout<<"No hay datos que guardar"<<endl;
					
					char cargar;	

					do{

						cout<<"Indique si Desea cargar la base de datos"<<endl;
						cout<<"pulse C si desea cargar la base de datos o M si desea salir al menú"<<endl;
						cin>>cargar;
						cout<<endl;
						if (cargar=='C' or cargar=='c'){
							
							if (miBD.cargarBD()){

								cout<<"Base de datos cargada correctamente"<<endl;
								cout<<"vuelva al menú para introducir alumnos"<<endl;
								break;
							}

							else{
								cout<<"No se encuentra el fichero o se ha producido un error cargar la base de datos"<<endl;
								cout<<"compruebe que exista el fichero de copia de seguridad, en caso contrario,"<<endl;
								cout<<"vuelva al menú para introducir alumnos y cree una copia de seguridad antes de cargarla"<<endl;
								break;
							}
						}

						if (cargar=='M' or cargar=='m'){
								cout<<"Vuelva al menú para introducir alumnos antes de guardar la base de datos"<<endl;
								break;
						}
					}
					while(cargar!= 'C'||cargar!='c'||cargar!= 'M'||cargar!='m');
				}

				else{

					cout<<"pulse una tecla para guardar la BD"<<endl;
					getchar();
					//sleep(4);
					if(miBD.guardarBD()){

						cout<<"base de datos guardada correctamente"<<endl;
						//miBD.cargarBD();
					}

					else{cout<<"Error al guardar la Base de Datos"<<endl;}
					}

				} break;
				
			case 6: {	// CARGAR BD

				if (miBD.cargarBD()){

					cout<<"Base de datos cargada correctamente"<<endl;
					cout<<"vuelva al menú para introducir alumnos"<<endl;
					break;
					}

					else{
						cout<<"No se encuentra el fichero o se ha producido un error cargar la base de datos"<<endl;
						cout<<"compruebe que exista el fichero de copia de seguridad, en caso contrario,"<<endl;
						cout<<"vuelva al menú para introducir alumnos y cree una copia de seguridad antes de cargarla"<<endl;
						break;
					}



				} break;
			case 7: {	// GUARDAR BACKUP

				} break;
			case 8: {	// CARGAR BACKUP

				} break;	
			case 9: {	// GESTION PERFIL

				} break;
			case 10: {	// SALIR DE LA APLICACION

				} break;
			default: cout << "Opcion no valida" << endl;	// OPC NO VALIDA
		}
	} while(opc !=10);

	return 0;
}

void mostrarOpciones() {
	cout << "\t::MENU APLICACION::\t" << endl;
	cout << "1. Insertar Alumno" << endl;
	cout << "2. Modificar Alumno" << endl;
	cout << "3. Eliminar Alumno" << endl;
	cout << "4. Mostrar Alumnos" << endl;
	cout << "5. Guardar BD" << endl;
	cout << "6. Cargar BD" << endl;
	cout << "7. Guardar Backup (solo coordinador)"<< endl;
	cout << "8. Cargar Backup (solo coordinador)" << endl;
	cout << "9. Gestion del Perfil" << endl;
	cout << "10. Salir de la aplicacion" << endl;
}

void mostrarOpcionesBusqueda(){
	cout << "\t::MENU BUSQUEDA::\t" << endl;
	cout << "1. Buscar por dni" << endl;
	cout << "2. Buscar por apellidos" << endl;
}