// --------------
// MENU PRINCIPAL
// --------------

//g++ menuprincipal.cc Alumno.cc cargarBD.cc introducirAlumno.cc mostrarLista.cc buscarAlumno.cc guardarBD.cc Profesor.cc gestionLideres.cc BD.h Alumno.h Profesor.h guardarExterna.cc cargarExterna.cc




//Revisar todos los char que tengan el mismo tamaño
//por defecto lider_=0;
//valores que no se cumplimentan deben aparecer en blanco
//errores al ittroducir en un int un char
//instrucciones en html para compilar y ejecutar programa

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>//formato cout
#include <stdio.h>
#include <cstdlib>
#include <limits>
#include "Alumno.h"
#include "Profesor.h"
#include "BD.h"
#include "consoleLinux.h"
#include <unistd.h>//sleep

using namespace std;

int opcOrden=0;
string orden="AAA";//para orden ascendente o descendente ASC, DESC
BD miBD; //crea un objeto de base de datos con el nombre de fichero gestionAlumnos
int contadorBackUp=0;//para controlar si se han introducido nuevos alumnos. sE DECLARA GLOBAL PARA QUE ESTÉ SIEMPRE DISPONIBLE



void saltoLinea();
void mostrarOpciones();
void OpcionesMostrar();
void OpcionesInsertar();
void limpiarPantalla();
bool datosBusqueda(datosAlumno &datos);
void OpcionesOrden();
void printAlumno(Alumno aux);
void guardarBD();

//void binarioAcceso();

int main(int argc, char const *argv[]) {
	
	Profesor p;//para acceso a la aplicación.
	//string clave;
	//string usuario;








	limpiarPantalla();
	int opc=0;
	int opcBusqueda=0;
	int opcMostrar=0;

	//miBD.setNumeroAlumnos(150);

	do {
		mostrarOpciones();
		saltoLinea();

		cout << "\t" << BOLD_ON << COLOR_LIGHTGREY <<"Introduzca una opción: " << COLOR_BRIGHTBLUE;
		cin >> opc;
		cout << RESET << endl;

		limpiarPantalla();
		
		switch(opc) {
			case 1: {	// INSERTAR ALUMNO

					// COMPRUEBA NºALUMNOS < 150 ···
					if(miBD.getNumeroAlumnos()==150) {
						cout << BOLD_RED << "\n\tERROR\n" << RESET;
						cout << COLOR_BRIGHTGREEN << "\n\tNUMERO MAXIMO DE ALUMNOS (" << miBD.getNumeroAlumnos() << ") ALCANZADO\n";
						cout << RESET << endl;
						cout << BOLD_ON  << "\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
						cin.ignore();
						cin.get();
						limpiarPantalla();
						break;
					} else { // Muestra el numero de alumnos
						OpcionesInsertar();
						cout<< "\n\tNUMERO DE ALUMNOS: " << miBD.getNumeroAlumnos();
						saltoLinea();
						saltoLinea();
					}
					
					// PIDE DATOS OBLIGATORIOS ···
					datosAlumno datos;
					inicializardatos(datos);

					cout << "Introduzca los datos obligatorios del nuevo alumno" << endl;

					cout << "DNI : ";
					cin.ignore();
					cin.getline(datos.dni, 10, '\n');
					cout << "Nombre : ";
					cin.getline(datos.nombre, 30, '\n');
					cout << "Apellidos : ";
					cin.getline(datos.apellidos, 30, '\n');
					cout << "Fecha de nacimiento : ";
					cin.getline(datos.fecha_nacimiento, 15, '\n');
					cout << "Telefono : ";
					cin >> datos.telefono;
					cout << "Email corporativo : ";
					cin.ignore();
					cin.getline(datos.email_corporativo, 30, '\n');
					cout << "Domicilio : ";
					cin.getline(datos.domicilio, 30, '\n');
					cout << "Curso : ";
					cin >> datos.curso;

					Alumno aux(datos); // Constructor con estructura
					
					// COMPRUEBA QUE EL ALUMNO NO HA SIDO INTRODUCIDO ANTERIORMENTE ···
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
						cout << "\nOpcion de busqueda no valida" << endl;
						cout << BOLD_ON << "\nPULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;
						cin.ignore();
						cin.get();
						limpiarPantalla();
						break;
					}

					if(encontrado==true) {	// ALUMNO YA INTRODUCIDO
						cout << "\nEl alumno ya se encuentra en la BD" << endl;
						cout << BOLD_ON << "\nPULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;
						cin.ignore();
						cin.get();
						limpiarPantalla();
						break;
					} 

					// ALUMNO NUEVO
					cout << "\nEl alumno no se encuentra en la BD" << endl;


					// DATOS ADICIONALES ···
					cout << "\n¿Desea introducir datos adicionales?" << endl;
					cout << "DATOS ADICIONALES:" << endl;
					cout << "\tNOTA\n\tEQUIPO\n\tLIDER\n";
					cout << "Pulse 1 si desea introducir datos adicionales: ";	

					int datosAd;
					cin >> datosAd;
					
					if(datosAd == 1) {
						cout << "Nota : ";
						cin >> datos.nota;
						cout << "Equipo : ";
						cin >> datos.equipo;
						cout << "Lider (1: Si; 0: No): ";
						cin >> datos.lider;

						if(cin.fail()) {
							cout << "Introduccion de lider incorrecta" << endl;
							cout << BOLD_ON << "PULSE UNA TECLA PARA VOLVER AL MENÚ";
  							//cin.ignore(numeric_limits<int>::max());
  							cin.clear();
  							cin.ignore();
  							cin.get();
  							limpiarPantalla();
  							break;
						}
						
						aux.setNota(datos.nota);
						aux.setEquipo(datos.equipo);
						aux.setLider(datos.lider);
					}

					// MUESTRA LOS DATOS DEL ALUMNO A INTRODUCIR ···
					printAlumno(aux);

					// INTENTA INTRODUCIR EL ALUMNO ···
					if(!miBD.introducirAlumno(aux)) {
						cout << "Error al introducir el alumno" << endl;
					} else cout << "Alumno introducido correctamente" << endl;

					cout<<BOLD_ON<<"\nPULSE UNA TECLA PARA VOLVER AL MENÚ";
					cin.ignore();
					cin.get();
					limpiarPantalla();

				} break;
			case 2: {	// MODIFICAR ALUMNO
					list <Alumno> alumnosencontrados;
					datosAlumno a;
					bool encontrado; 

					cout << "Introduzca la opcion para buscar: " << endl;
					cout << "1. DNI\n2. Apellidos\n3. Grupo" << endl;
					cin >> opcBusqueda;

					if(opcBusqueda==1) {
						cout << "DNI: ";
						cin >> a.dni ;

						Alumno aux(a);
						encontrado=miBD.buscarAlumnoDNI(alumnosencontrados, aux);
					} else if (opcBusqueda==2) {
						cout << "Apellido: ";
						cin >> a.apellidos ;

						Alumno aux(a);
						encontrado=miBD.buscarAlumnoApellido(alumnosencontrados, aux);
					} else if (opcBusqueda==3) {
						cout << "EQUIPO: ";
						cin >> a.equipo ;
						encontrado=miBD.buscarAlumnoEquipo(alumnosencontrados, a.equipo);

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

								if(listaBusqueda.size()>1){

									cout<<COLOR_RED<<"**ATENCIÓN: PUEDE HABER ALUMNOS DUPLICADOS- hay más de un alumno con DNI: "<<z.getDNI()<<RESET<<endl;

								}
								else{
									saltoLinea();
									cout<<COLOR_GREEN<<"El alumno con DNI: "<<z.getDNI()<<" ha sido encontrado."<<RESET<<endl;
									

								}

								saltoLinea();
								miBD.ordenLista(listaBusqueda);
								
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
									miBD.ordenLista(listaBusqueda);

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
								miBD.ordenLista(listaBusqueda);

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
							miBD.ordenLista();
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

				
				guardarBD();
			

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

				if (miBD.getAlumnos().size()==contadorBackUp){

					cout<<COLOR_RED<<"ANTES DE GUARDAR LA COPIA DE SEGURIDAD EXTERNA INTRODUZCA NUEVOS ALUMNOS EN LA BASE DE DATOS"<<RESET<<endl;
					saltoLinea();
					cout<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
					limpiarPantalla();
					break;
				}
				cout<<BOLD_ON<<BLINK<<"\tPreparando el sistema para realizar la copia externa"<<RESET<<endl;
				sleep(4);

				miBD.guardarBD();
				getchar();
				cout<<BOLD_ON<<"Pulse una tecla para continuar"<<endl;getchar();getchar();
				miBD.guardarBackup();
				saltoLinea();
				saltoLinea();
				cout<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
				contadorBackUp++;
				limpiarPantalla();




				} break;
			case 8: {	// CARGAR BACKUP

				miBD.cargarBackup();
				saltoLinea();
				saltoLinea();
				cout<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
				limpiarPantalla();


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
	cout<<"\t"<<BOLD_ON<<COLOR_LIGHTGREY<<setw(40)<<RESET<<""<<endl;
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


void OpcionesMostrar() {
	cout.fill('*');
	saltoLinea();
	cout<<"\t"<<BOLD_ON<<COLOR_GREEN<<setw(40)<<""<<endl;
	cout.fill(' ');
	saltoLinea();
	cout<<"\t"<<BOLD_ON<<COLOR_GREEN<<left<<setw(40)<<"|::MOSTRAR ALUMNOS::|"<<RESET<<endl;
	saltoLinea();
	cout.fill('*');
	cout<<"\t"<<BOLD_ON<<COLOR_GREEN<<setw(40)<<""<<RESET<<endl;
	saltoLinea();
	saltoLinea();
	cout <<"\t"<<COLOR_GREEN<< "1. Mostrar Alumno" <<endl;
	cout <<"\t"<<COLOR_BRIGHTGREEN<<  "2. Mostrar Alumnos de un grupo" << endl;
	cout <<"\t"<<COLOR_GREEN<< "3. Mostrar todos los alumnos" << endl;
	cout <<"\t"<<COLOR_BRIGHTGREEN<<  "4. Volver al menú principal" << endl;


}

void limpiarPantalla(){
	system("clear");


}

void saltoLinea(){
	cout<<endl;


}


void OpcionesOrden(){
	
	cout.fill('*');
	saltoLinea();
	cout<<"\t"<<BOLD_ON<<COLOR_CYAN<<UNDERLINE_ON<<left<<setw(40)<<"Opciones Orden"<<RESET<<endl;
	saltoLinea();
	saltoLinea();
	cout <<"\t"<<COLOR_CYAN<< "1. Ordenar por DNI" << RESET<<endl;
	cout <<"\t"<<COLOR_LIGTHCYAN<<  "2. Ordenar por apellido" << endl;
	cout <<"\t"<<COLOR_CYAN<< "3. Ordenar por Grupo" << endl;
	cout <<"\t"<<COLOR_LIGTHCYAN<<  "4. Ordenar por Curso más alto matriculado" << endl;
	cout <<"\t"<<COLOR_CYAN<<  "5. Volver al menú de Mostrar Alumnos" << endl;


}




void BD::ordenLista(list <Alumno> &lista){
	

		do{
			/*OpcionesOrden();
			saltoLinea();
			cout<<"\t"<<BOLD_ON<<COLOR_DARKGREY<<"Indique la opción elegida: "<<COLOR_BRIGHTBLUE;cin>>opcOrden;
			cout<<RESET<<endl;
			limpiarPantalla();
	
			if(opcOrden==5){

				break;
			}
			*/
			OpcionesOrden();
			saltoLinea();
			cout<<"\t"<<BOLD_ON<<COLOR_DARKGREY<<"Indique el orden en que quiere mostrar el alumno o alumnos: "<<COLOR_BRIGHTBLUE;cin>>opcOrden;
			cout<<"\t"<<BOLD_ON<<COLOR_DARKGREY<<"Indique si desea mostrar la lista en orden Ascendente, introduzca <ASC>, o en orden Descendente, introduzca <DESC>: "<<COLOR_BRIGHTBLUE;getchar();getline(cin, orden);
			cout<<RESET<<endl;
			limpiarPantalla();


			if ((opcOrden==1||opcOrden==2||opcOrden==3||opcOrden==4)&&(orden=="ASC"||orden=="DESC")){
				
				miBD.mostrarAlumno(lista,opcOrden, orden);
				saltoLinea();
				cout<<"\t"<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
				limpiarPantalla();
			}

			if(opcOrden==5){

				break;
			}
			
			

		}while((opcOrden!=1 ||opcOrden!=2||opcOrden!=3||opcOrden!=4||opcOrden!=5)&&(orden!="ASC"||orden!="DESC"));



}

void BD::ordenLista(){
	

		do{
			OpcionesOrden();
			saltoLinea();
			cout<<"\t"<<BOLD_ON<<COLOR_DARKGREY<<"Indique el orden en que quiere mostrar el alumno o alumnos: "<<COLOR_BRIGHTBLUE;cin>>opcOrden;
			cout<<"\t"<<BOLD_ON<<COLOR_DARKGREY<<"Indique si desea mostrar la lista en orden Ascendente, introduzca <ASC>, o en orden Descendente, introduzca <DESC>: "<<COLOR_BRIGHTBLUE;getchar();getline(cin, orden);
			cout<<RESET<<endl;
			limpiarPantalla();



			if ((opcOrden==1||opcOrden==2||opcOrden==3||opcOrden==4)&&(orden=="ASC"||orden=="DESC")){
				
				miBD.mostrarAlumno(opcOrden, orden);
				saltoLinea();
				cout<<"\t"<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
				limpiarPantalla();
			}
			
			if(opcOrden==5){

				break;
			}

		}while((opcOrden!=1 ||opcOrden!=2||opcOrden!=3||opcOrden!=4||opcOrden!=5)&&(orden!="ASC"||orden!="DESC"));



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

void printAlumno(Alumno aux) {
	cout << "DNI: " << aux.getDNI() << endl;
	cout << "Nombre: " << aux.getNombre() << endl;
	cout << "Apellidos: " << aux.getApellidos() << endl;
	cout << "Fecha Nacimiento: " << aux.getFecha_nacimiento() << endl;
	cout << "Email: " << aux.getEmail_corporativo() << endl;
	cout << "Domicilio: " << aux.getDomicilio() << endl;
	cout << "Telefono: " << aux.getTelefono() << endl;
	cout << "Curso: " << aux.getCurso() << endl;
	cout << "Nota: " << aux.getNota() << endl;
	cout << "Equipo: " << aux.getNota() << endl;
	cout << "Lider: " << aux.getLider() << endl;
}


void guardarBD(){

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



}


