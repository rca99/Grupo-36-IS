// --------------
// MENU PRINCIPAL
// --------------

// g++ menuprincipal.cc Alumno.cc cargarBD.cc introducirAlumno.cc mostrarLista.cc buscarAlumno.cc guardarBD.cc Profesor.cc gestionLideres.cc BD.h Alumno.h Profesor.h

//Revisar todos los char que tengan el mismo tamaño
//por defecto lider_=0;

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip> //formato cout
#include <stdio.h>
#include <cstdlib>

#include "Alumno.h"
#include "Profesor.h"
#include "BD.h"
#include "consoleLinux.h"

using namespace std;

void saltoLinea();
void mostrarOpciones();
void OpcionesMostrar();
void OpcionesInsertar();
void limpiarPantalla();
bool datosBusqueda(datosAlumno &datos);
void printAlumno(Alumno aux);

int main(int argc, char const *argv[]) {
	limpiarPantalla();
	BD miBD; //crea un objeto de base de datos con el nombre de fichero gestionAlumnos
	int opc=0;
	int opcBusqueda=0;
	int opcMostrar=0;
	string basura;

	//miBD.setNumeroAlumnos(150);

	do {
		mostrarOpciones();
		saltoLinea();
		cout<<"\t"<<BOLD_ON<<COLOR_LIGHTGREY<<"Introduzca una opción: "<<COLOR_BRIGHTBLUE;
		cin>>opc;
		cout<<RESET<<endl;
		limpiarPantalla();
		
		switch(opc) {
			case 1: {	// INSERTAR ALUMNO

					// Comprueba que el numero de alumnos no supere 150
					if(miBD.getNumeroAlumnos()==150) {
						cout << "Error, maximo de alumnos alcanzado" << endl;
						saltoLinea();
						cout << "PULSE UNA TECLA PARA VOLVER AL MENÚ" << endl;
						cin.ignore();
						cin.get();
						limpiarPantalla();
						break;
					} else { // Muestra el numero de alumnos
						OpcionesInsertar();
						cout<< "\tNUMERO DE ALUMNOS: " << miBD.getNumeroAlumnos();
						saltoLinea();
						saltoLinea();
					}
					
					datosAlumno datos;
					inicializardatos(datos);

					cout << "Introduzca los datos obligatorios del nuevo alumno" << endl;

					cout << "DNI : ";
					cin.ignore();
					cin.getline(datos.dni, 10, '\n');
					cout << "Nombre : ";
					cin.getline(datos.nombre, 10, '\n');
					cout << "Apellidos : ";
					cin.getline(datos.apellidos, 10, '\n');
					cout << "Fecha de nacimiento : ";
					cin.getline(datos.fecha_nacimiento, 10, '\n');
					cout << "Telefono : ";
					cin >> datos.telefono;
					cout << "Email corporativo : ";
					cin.ignore();
					cin.getline(datos.email_corporativo, 10, '\n');
					cout << "Domicilio : ";
					cin.getline(datos.domicilio, 10, '\n');
					cout << "Curso : ";
					cin >> datos.curso;

					Alumno aux(datos); // Constructor con estructura
					list <Alumno> alumnosencontrados;

					bool encontrado;

					saltoLinea();
					cout << "Comprobando que el alumno no esta dado de alta..." << endl;
					cout << "Opcion de busqueda" << endl;
					cout << "1. DNI\n2. Apellidos\n\n";
					cout << "¿Como desea buscar? : ";
					cin >> opcBusqueda;

					if(opcBusqueda==1) {
						encontrado=miBD.buscarAlumnoDNI(alumnosencontrados, aux);
					} else if (opcBusqueda == 2) {
						encontrado=miBD.buscarAlumnoApellido(alumnosencontrados, aux);
					} else {
						cout << "\nIntroduccion de opcion de busqueda incorrecta" << endl;
						cout << BOLD_ON << "\nPULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;
						cin.ignore();
						cin.get();
						limpiarPantalla();
						break;
					}

					if(encontrado==true) {
						cout << "\nEl alumno ya se encuentra en la BD" << endl;
						cout << BOLD_ON << "\nPULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;
						cin.ignore();
						cin.get();
						limpiarPantalla();
						break;
					} 

					cout << "El alumno no se encuentra en la BD" << endl;

					cout << "\n¿Desea introducir datos adicionales?" << endl;
					cout << "DATOS ADICIONALES:" << endl;
					cout << "\tNOTA\n\tEQUIPO\n\tLIDER\n";
					cout << "Pulse 1 si desea introducir datos adicionales" << endl;	

					int datosAd;
					cin >> datosAd;
					
					if(datosAd == 1) {
						cout << "Nota : ";
						cin >> datos.nota;
						cout << "Equipo : ";
						cin >> datos.equipo;
						cout << "Lider (1: Si; 0: No): ";
						cin >> datos.lider;
						if((datos.lider != 1) && (datos.lider != 0)) {
							cout << "Introduccion de lider incorrecta" << endl;
							cout << BOLD_ON << "PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;
							cin.ignore();
							cin.get();
							limpiarPantalla();
							break;
						}
						aux.setNota(datos.nota);
						aux.setEquipo(datos.equipo);
						aux.setLider(datos.lider);
					}

					printAlumno(aux);

					if(!miBD.introducirAlumno(aux)) {
						cout << "Error al introducir el alumno" << endl;
					} else cout << "Alumno introducido correctamente" << endl;

					cout<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
					limpiarPantalla();







				} break;
			case 2: {	// MODIFICAR ALUMNO
					list <Alumno> listaux;
					datosAlumno a;
					bool encontrado; 

					cout << "Introduzca la opcion para buscar: " << endl;
					cout << "1. DNI\n2. Apellidos\n3. Grupo" << endl;
					cin >> opcBusqueda;

					if(opcBusqueda==1) {
						cout << "DNI: ";
						cin >> a.dni ;

						Alumno aux(a);
						encontrado=miBD.buscarAlumnoDNI(listaux, aux);
					} else if (opcBusqueda==2) {
						cout << "Apellido: ";
						cin >> a.apellidos ;

						Alumno aux(a);
						encontrado=miBD.buscarAlumnoApellido(listaux, aux);
					} else if (opcBusqueda==3) {
						cout << "EQUIPO: ";
						cin >> a.equipo ;

						encontrado=miBD.buscarAlumnoEquipo(listaux, a.equipo);
					} else {
						cout << "Opcion no valida" << endl;
						break;
					}

					if(encontrado==true) {

					}


				} break;
			case 3: {	// ELIMINAR ALUMNO
					
				} break;
			case 4: {	// MOSTRAR ALUMNOS

					
				Alumno z;
				string DNI;
				string Apellidos;
				int equipo;



				do{
					OpcionesMostrar();
					saltoLinea();
					cout<<"\t"<<BOLD_ON<<COLOR_DARKGREY<<"Indique qué desea mostrar: "<<COLOR_BRIGHTBLUE;cin>>opcMostrar;
					cout<<RESET<<endl;
					limpiarPantalla();

					switch(opcMostrar) {
						case 1: {
							list <Alumno> listaBusqueda;
							/*
							cin>>DNI;
							getchar();
							cout<<"DNI: "<<z.getDNI();	
							*/
							
							/*Prueba búsqueda
							z.setDNI("30");
							cout<<"DNI: "<<z.getDNI();							
							if (miBD.buscarAlumnoDNI(listaBusqueda, z)){
								cout<<"Encontrado"<<endl;	
							}
							*/
							//introducir DNI que buscar
							cout<<COLOR_DARKGREY<<"Indique el DNI del alumno que desea mostrar: "<<COLOR_BLUE;cin>>DNI;getchar();
							z.setDNI(DNI);	
							cout<<RESET<<endl;

							
							if (miBD.buscarAlumnoDNI(listaBusqueda, z)){
								saltoLinea();
								cout<<COLOR_GREEN<<"El alumno con DNI: "<<z.getDNI()<<" ha sido encontrado."<<RESET<<endl;
								saltoLinea();
								miBD.mostrarAlumno(listaBusqueda);

							}
							
							else{
								saltoLinea();
								cout<<COLOR_RED<<"No Encontrado por DNI"<<RESET<<endl;	
								saltoLinea();
								//Introducir el apellido que buscar
								cout<<COLOR_DARKGREY<<"Indique ahora el apellido: "<<COLOR_BLUE;cin>>Apellidos;getchar();
								cout<<RESET<<endl;
								z.setApellidos(Apellidos);

								if(miBD.buscarAlumnoApellido(listaBusqueda, z)){
									limpiarPantalla();
									saltoLinea();
									cout<<COLOR_GREEN<<"Se ha encontrado los siguientes alumnos con el apellido: "<<z.getApellidos()<<RESET<<endl;	
									saltoLinea();	
									miBD.mostrarAlumno(listaBusqueda);

								}
								else{
									saltoLinea();
									cout<<COLOR_RED<<"Tampoco Encontrado por apellido"<<endl;	
								}

							}
							saltoLinea();
							cout<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();
							listaBusqueda.clear();
							limpiarPantalla();

						}break;


						case 2: {
							list <Alumno> listaBusqueda;
							saltoLinea();
							cout<<COLOR_DARKGREY<<"Indique el Equipo de alumnos que desea mostrar: "<<COLOR_BLUE;cin>>equipo;getchar();
							cout<<RESET<<endl;
							
							if(miBD.buscarAlumnoEquipo(listaBusqueda, equipo)){
								limpiarPantalla();
								saltoLinea();
								cout<<COLOR_GREEN<<"Se han encontrado "<<listaBusqueda.size()<<" alumno/s que forman parte del equipo: "<<equipo<<RESET<<endl;	
								saltoLinea();	
								miBD.mostrarAlumno(listaBusqueda);

							}
							else{
								saltoLinea();
								cout<<COLOR_RED<<"El equipo "<<equipo<<" no tiene alumnos"<<endl;	
							}

							saltoLinea();
							cout<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
							limpiarPantalla();
						
						
						}break;


						case 3: {
							saltoLinea();
							miBD.mostrarAlumno();
							saltoLinea();
							cout<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
							limpiarPantalla();
						
						}break;


						case 4: {
							break;	
						
						}

						default: {
							saltoLinea();
							cout <<"\t"<<"OPCIÓN NO VÁLIDA" << endl;
							cout<<"\t"<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
							limpiarPantalla();

						}	
					}

				}while (opcMostrar!=4);
			}break;

				

			case 5: {	// GUARDAR BD

				if (miBD.getAlumnos().size()==0){
					cout<<"No hay datos que guardar"<<endl;
					
					char cargar;	

					do{

						cout<<COLOR_DARKGREY<<"Indique si Desea cargar la base de datos"<<endl;
						cout<<"pulse C si desea cargar la base de datos o M si desea salir al menú"<<COLOR_BLUE<<endl;
						cin>>cargar;
						cout<<RESET<<endl;

						saltoLinea();
						if (cargar=='C' or cargar=='c'){
							
							if (miBD.cargarBD()){

								cout<<COLOR_GREEN<<"Base de datos cargada correctamente"<<RESET<<endl;
								cout<<"vuelva al menú para introducir alumnos"<<endl;
								saltoLinea();
								cout<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
								limpiarPantalla();
								break;
							}

							else{
								cout<<COLOR_RED"No se encuentra el fichero o se ha producido un error cargar la base de datos"<<RESET<<endl;
								cout<<"compruebe que exista el fichero de copia de seguridad, en caso contrario,"<<endl;
								cout<<"vuelva al menú para introducir alumnos y cree una copia de seguridad antes de cargarla"<<endl;
								saltoLinea();
								cout<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
								limpiarPantalla();

								break;
							}
						}

						if (cargar=='M' or cargar=='m'){
								cout<<"Vuelva al menú para introducir alumnos antes de guardar la base de datos"<<endl;
								break;
						}
					}while(cargar!= 'C'||cargar!='c'||cargar!= 'M'||cargar!='m');
				}

				else{

					cout<<"pulse una tecla para guardar la BD"<<endl;
					getchar();
					//sleep(4);
					if(miBD.guardarBD()){

						cout<<COLOR_GREEN<<"base de datos guardada correctamente"<<RESET<<endl;
						saltoLinea();
						cout<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
						limpiarPantalla();
						//miBD.cargarBD();
					}

					else{cout<<COLOR_RED<<"Error al guardar la Base de Datos"<<RESET<<endl;}
					}

				} break;
				
			case 6: {	// CARGAR BD

				if (miBD.cargarBD()){

					cout<<COLOR_GREEN<<"Base de datos cargada correctamente"<<RESET<<endl;
					cout<<"vuelva al menú para introducir alumnos"<<endl;
					saltoLinea();
					cout<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
					limpiarPantalla();
					break;
				}

				else{
					cout<<COLOR_RED<<"No se encuentra el fichero o se ha producido un error cargar la base de datos"<<RESET<<endl;
					cout<<"compruebe que exista el fichero de copia de seguridad, en caso contrario,"<<endl;
					cout<<"vuelva al menú para introducir alumnos y cree una copia de seguridad antes de cargarla"<<endl;
					saltoLinea();
					cout<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
					limpiarPantalla();
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
			default: {
				saltoLinea();
				cout <<"\t"<<"OPCIÓN NO VÁLIDA" << endl;
				cout<<"\t"<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
				limpiarPantalla();
			}
			// OPC NO VALIDA
		}
	} while(opc !=10);

	return 0;
}

void mostrarOpciones() {
	cout.fill('*');
	saltoLinea();
	cout<<"\t"<<BOLD_ON<<COLOR_LIGHTGREY<<setw(40)<<""<<endl;
	cout.fill(' ');
	saltoLinea();
	cout<<"\t"<<BOLD_ON<<COLOR_LIGHTGREY<<left<<setw(40)<<"|::MENÚ APLICACIÓN::|"<<RESET<<endl;
	saltoLinea();
	cout.fill('*');
	cout<<"\t"<<BOLD_ON<<COLOR_LIGHTGREY<<setw(40)<<""<<endl;
	saltoLinea();
	saltoLinea();
	cout <<"\t"<<COLOR_DARKGREY<< "1. Insertar Alumno" << endl;
	cout <<"\t"<<COLOR_LIGHTGREY<< "2. Modificar Alumno" << endl;
	cout <<"\t"<<COLOR_DARKGREY<< "3. Eliminar Alumno" << endl;
	cout <<"\t"<<COLOR_LIGHTGREY<< "4. Mostrar Alumnos" << endl;
	cout <<"\t"<<COLOR_DARKGREY<< "5. Guardar BD" << endl;
	cout <<"\t"<<COLOR_LIGHTGREY<< "6. Cargar BD" << endl;
	cout <<"\t"<<COLOR_DARKGREY<< "7. Guardar Backup (solo coordinador)"<< endl;
	cout <<"\t"<<COLOR_LIGHTGREY<< "8. Cargar Backup (solo coordinador)" << endl;
	cout <<"\t"<<COLOR_DARKGREY<< "9. Gestion del Perfil" << endl;
	cout <<"\t"<<COLOR_LIGHTGREY<< "10. Salir de la aplicacion" << endl;
}


void OpcionesMostrar(){
	
	cout.fill('*');
	saltoLinea();
	cout<<"\t"<<BOLD_ON<<COLOR_GREEN<<setw(40)<<""<<endl;
	cout.fill(' ');
	saltoLinea();
	cout<<"\t"<<BOLD_ON<<COLOR_GREEN<<left<<setw(40)<<"|::MOSTRAR ALUMNOS::|"<<RESET<<endl;
	saltoLinea();
	cout.fill('*');
	cout<<"\t"<<BOLD_ON<<COLOR_GREEN<<setw(40)<<""<<endl;
	saltoLinea();
	saltoLinea();
	cout <<"\t"<<COLOR_GREEN<< "1. Mostrar Alumno" << RESET<<endl;
	cout <<"\t"<<COLOR_BRIGHTGREEN<<  "2. Mostrar Alumnos de un grupo" << endl;
	cout <<"\t"<<COLOR_GREEN<< "3. Mostrar todos los alumnos" << endl;
	cout <<"\t"<<COLOR_BRIGHTGREEN<<  "4. Volver al menú" << endl;
}

void OpcionesInsertar() {
	cout.fill('*');
	saltoLinea();
	cout<<"\t"<<BOLD_ON<<COLOR_CYAN<<setw(40)<<""<<endl;
	cout.fill(' ');
	saltoLinea();
	cout<<"\t"<<BOLD_ON<<COLOR_CYAN<<left<<setw(40)<<"|::INTRODUCIR ALUMNOS::|"<<RESET<<endl;
	saltoLinea();
	cout.fill('*');
	cout<<"\t"<<BOLD_ON<<COLOR_CYAN<<setw(40)<<""<<endl;
	saltoLinea();
	saltoLinea();
	cout <<"\t"<<COLOR_CYAN<< "1. Introducir Alumno" <<endl;
	cout <<"\t"<< "2. Volver al menu" << RESET<<endl;
}

void limpiarPantalla(){
	system("clear");
}

void saltoLinea(){
	cout<<endl;
}

void printAlumno(Alumno aux) {
	string dni = aux.getDNI();
	string nombre = aux.getNombre();
	string apellidos = aux.getApellidos();
	string fecha_nacimiento = aux.getFecha_nacimiento();
	string email_corporativo = aux.getEmail_corporativo();
	string domicilio = aux.getDomicilio();
	int telefono = aux.getTelefono();
	int curso = aux.getCurso();
	int nota = aux.getNota();
	int equipo = aux.getEquipo();
	bool lider = aux.getLider();

	cout << "DNI: " << dni << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Apellidos: " << apellidos << endl;
	cout << "Fecha Nacimiento: " << fecha_nacimiento << endl;
	cout << "Email: " << email_corporativo << endl;
	cout << "Domicilio: " << domicilio << endl;
	cout << "Telefono: " << telefono<< endl;
	cout << "Curso: " << curso << endl;
	cout << "Nota: " << nota << endl;
	cout << "Equipo: " << equipo<< endl;
	cout << "Lider: " << lider << endl;
}
