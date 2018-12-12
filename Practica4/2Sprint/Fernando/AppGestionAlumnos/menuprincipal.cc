// --------------
// MENU PRINCIPAL
// --------------

//g++ -g -Wall  menuprincipal.cc guardarBD.cc cargarBD.cc buscarAlumno.cc mostrarAlumno.cc Profesor.h Alumno.h consoleLinux.h BD.h Alumno.cc


//Revisar todos los char que tengan el mismo tamaño
//por defecto lider_=0;

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>//formato cout
#include <stdio.h>
#include "Alumno.h"
#include "Profesor.h"
#include "BD.h"
#include "consoleLinux.h"

using namespace std;
void saltoLinea();
void mostrarOpciones();
void OpcionesMostrar();
void limpiarPantalla();
bool datosBusqueda(datosAlumno &datos);

int main(int argc, char const *argv[]) {
	limpiarPantalla();
	BD miBD; //crea un objeto de base de datos con el nombre de fichero gestionAlumnos
	int opc=0;
	int opcMostrar=0;



	do {
		mostrarOpciones();
		saltoLinea();
		cout<<"\t"<<BOLD_ON<<COLOR_LIGHTGREY<<"Introduzca una opción: "<<COLOR_BRIGHTBLUE;cin>>opc;
		cout<<RESET<<endl;
		limpiarPantalla();
		
		switch(opc) {
			case 1: {	// INSERTAR ALUMNO
					

					Alumno a, b,c,d,e,f,g;
					a.setNombre("rodolfo");
					a.setCurso(2);
					a.setDNI("30");
					a.setLider(1);
					a.setEquipo(18);
					b.setNombre("Artura");
					b.setCurso(3);
					b.setDNI("30");
					b.setLider(0);


					c.setNombre("Jeremias");
					c.setCurso(2);
					c.setDNI("50");

					d.setNombre("M del Rosario");
					d.setApellidos("Alba Olivares");
					d.setCurso(1);
					d.setDNI("60");

					e.setNombre("M del Rosario");
					e.setApellidos("ruiz Olivares");
					e.setCurso(3);
					e.setDNI("70");

					f.setDNI("80");
					f.setApellidos("ruiz");
					f.setEquipo(18);
					f.setLider(true);

					g.setDNI("803");
					g.setApellidos("ruriz");
					g.setEquipo(18);
					g.setLider(true);

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
					saltoLinea();
					cout<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
					limpiarPantalla();

				} break;
			case 2: {	// MODIFICAR ALUMNO
					
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
								cout<<COLOR_DARKGREY<<"Indique ahora el apellido: "<<COLOR_BLUE;getline(cin,Apellidos);
								cout<<RESET<<endl;
								z.setApellidos(Apellidos);


								//fgets (Apellidos , 80 , stdin);
								//quitarEspacios(Apellidos);
								//fflush(stdin);
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
							
							if(miBD.buscarAlumno(listaBusqueda, equipo)){
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

void limpiarPantalla(){
	system("clear");


}

void saltoLinea(){
	cout<<endl;


}
