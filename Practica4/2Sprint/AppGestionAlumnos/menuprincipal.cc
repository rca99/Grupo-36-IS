// --------------
// MENU PRINCIPAL
// --------------

//g++ menuprincipal.cc Alumno.cc cargarBD.cc introducirAlumno.cc mostrarLista.cc buscarAlumno.cc guardarBD.cc Profesor.cc gestionLideres.cc BD.h Alumno.h Profesor.h guardarExterna.cc cargarExterna.cc guardarCredenciales.cc cargarCredenciales.cc modificarAlumno.cc

////*****FERNANDO
//Revisar todos los char que tengan el mismo tamaño
//errores al ittroducir en un int un char
//activar sleep acceso aplicación
//**CU**cargar base de datos. Si hay alumnos dados de alta, pedir confirmación porque se borrarán los datos que haya actualmente
//**CU** al cargar copia de seguridad hay que indicar los alumnos cargados en el sistema
// **CU** el sistema consulta al acceder si se desea cargar la base de datos en caso de existir 
//Configurar aplicación para que funcionen las copias de seguridad externas en cualquier equipo Añadir en scrip git init git remote add origin <repositorio git> user name, email, git set-url
//**CU** El sistema debe mostrar en blanco los datos del alumno no obligatorios que no hayan sido introducidos previamente.// no sé como se podría hacer. NO ME PREOCUPA
//Aspecto menús
//mostrar alumnos por interfaz o por html. Consultar de qué forma se desea


////*****CHARLII
//al introducir  alumno, que busque por apellidos y dni sin preguntar
//**CU** cuando se da de alta un alumno devuelve el número de alumnos el sistema
//**CU**cuando se introduce un alumno hay que indicar que ha sido correcto y mostrar su nombre y dni 
//**CU** En caso de devolver los alumnos del grupo, el sistema indicará si el grupo tiene líder o no lo tiene.// no sé si se puede hacer ahora. NO ME PREOCUPA
//en modificar alumnos cuando se introduce mal el código de si se desea modificar se vuelve inestable. Hacer esta comprobación en todas las peticiones de datos

////*****RAFA
//Interfaz Salir aplicación
//Interfaz Eliminar Alumnos



//Aspectos a mejorar
//FUNCIONES sin cout

//INSTRUCCIONES ACCESO Y USO APLICACIÓN
//insertar y modificar indicar tipo de dato y como meterlo (por ejemplo DNI si se introduce letra sin espacios)


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
#define INTENTOS_ACCESO_APLICACION 3


void saltoLinea();
void mostrarOpciones();
void OpcionesMostrar();
void OpcionesInsertar();
void OpcionesModificar();
void limpiarPantalla();
bool datosBusqueda(datosAlumno &datos);
void OpcionesOrden();
void printAlumno(Alumno aux);
void guardarBD();
void mostrarOpcionesAyudantes();
void generarhtml();

//void binarioAcceso();

int main(int argc, char const *argv[]) {

	limpiarPantalla();
	/*
	cout<<BLINK<<BOLD_ON<<"ACCEDIENDO A LA APLICACIÓN"<<RESET<<endl;
	
	//sleep(1);
	saltoLinea();
	cout<<"Se abrirá la carpeta donde se encuentran las instrucciones para acceder a la aplicación. "<<endl;
	cout<<" Abra el archivo acceso.html y vuelve a la terminal para acceder a la Aplicación "<<endl;
	//sleep(3);
	generarhtml();
	*/
	
	Profesor p;//para acceso a la aplicación.
	p.credencialesBin();// para guardar el fichero binario de las credenciales
	int intentosAcceso=0;//para controlar el número de intentos de acceso

	//introducir datos acceso

	do{
			limpiarPantalla();
			string user;
			string password;

			int intentosRestantes;
			intentosRestantes=INTENTOS_ACCESO_APLICACION-intentosAcceso;
			saltoLinea();
			cout<<"\tTiene "<<BOLD_ON<<COLOR_GREEN<<intentosRestantes<<RESET<<" intentos para acceder a la aplicación"<<endl;
			saltoLinea();
			cout<<"\tInserte su usuario: ";cout<<COLOR_BLUE;getline(cin, user);
			cout<<RESET;
			saltoLinea();
			cout<<"\tInserte su clave de acceso: ";cout<<COLOR_BLUE;getline(cin, password);
			
			//cout<<user<<"-"<<password<<endl;
			sleep(0.75);

			//comprobar credenciales

			Credencialesprofesor cprof=p.registro(user, password);// para recoger datos del usuario que accede y poder controlar el menú que se carga


			if(strcmp(cprof.usuario, user.c_str())==0 && strcmp(cprof.contrasenya, password.c_str())==0){

				cout<<COLOR_BRIGHTGREEN<<BLINK<<"ACCESO AUTORIZADO"<<RESET<<endl;

				cout<<cprof.contrasenya<<"-"<<cprof.usuario<<"-"<<cprof.rol<<endl;// la clase registro ha de devolver una estructura profesor

				limpiarPantalla();
				

				//Acceso al menú principal si credenciales son válidas

				int opc=0;
				int opcBusqueda=0;
				int opcMostrar=0;

				do {
					
					saltoLinea();

					
					limpiarPantalla();

					if (strcmp(cprof.rol, "coordinador")==0){
						saltoLinea();
						cout<<UNDERLINE_ON<<"\tBienvenido a la aplicación:  "<<RESET<<endl;
						saltoLinea();
						cout<<BOLD_ON<<"\t - "<<COLOR_CYAN<<cprof.nombreCompleto<<RESET<<BOLD_ON<<" - "<<RESET<<endl;
						mostrarOpciones();
						saltoLinea();	
						cout << "\t" << BOLD_ON << COLOR_LIGHTGREY <<"Introduzca una opción: " << COLOR_BRIGHTBLUE;
						cin >> opc;
						cout << RESET << endl;
						limpiarPantalla();
					}
					else{
						saltoLinea();
						cout<<UNDERLINE_ON<<"\tBienvenido a la aplicación:  "<<RESET<<endl;
						saltoLinea();
						cout<<BOLD_ON<<"\t - "<<COLOR_BRIGHTGREEN<<cprof.nombreCompleto<<RESET<<BOLD_ON<<" - "<<RESET<<endl;
						mostrarOpcionesAyudantes();
						saltoLinea();
						cout << "\t" << BOLD_ON << COLOR_LIGHTGREY <<"Introduzca una opción: " << COLOR_BRIGHTBLUE;
						cin >> opc;
						/*
						if (opc==7||opc==8){
							limpiarPantalla();
							mostrarOpcionesAyudantes();
						}
						*/
						
						cout << RESET << endl;
						limpiarPantalla();

					
					}

					
					switch(opc) {
						case 1: {	// INSERTAR ALUMNO

								// COMPRUEBA NºALUMNOS < 150 ···
								if(miBD.getNumeroAlumnos()==150) {
									cout << BOLD_RED << "\n\tERROR\n";
									cout << COLOR_BRIGHTGREEN << "\n\tNUMERO MAXIMO DE ALUMNOS (" << miBD.getNumeroAlumnos() << ") ALCANZADO\n";
									cout << COLOR_NORMAL << BOLD_ON  << "\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
									cin.ignore();
									cin.get();
									limpiarPantalla();
									break;
								} 

								// MENU INSERTAR ···
								OpcionesInsertar();
								cout << "\tNUMERO DE ALUMNOS: " << COLOR_GREEN << miBD.getNumeroAlumnos() << RESET;
								cout.fill('-');
								saltoLinea();
								saltoLinea();
											
								// PIDE DATOS OBLIGATORIOS ···
								datosAlumno datos;
								inicializardatos(datos);

								cout.fill(' ');
								cout << COLOR_CYAN << BOLD_ON << UNDERLINE_ON << setw(75) 
									 << "\tINTRODUZCA LOS DATOS OBLIGATORIOS DEL NUEVO ALUMNO"
									 << endl << endl << endl << RESET;

								cout << COLOR_GREEN << BOLD_ON << "\tDNI : " << COLOR_BRIGHTBLUE;
								cin.ignore();
								cin.getline(datos.dni, 10, '\n');
								cout << COLOR_GREEN << "\tNombre : " << COLOR_BRIGHTBLUE;
								cin.getline(datos.nombre, 40, '\n');
								cout << COLOR_GREEN << "\tApellidos : " << COLOR_BRIGHTBLUE;
								cin.getline(datos.apellidos, 40, '\n');
								cout << COLOR_GREEN << "\tFecha de nacimiento : " << COLOR_BRIGHTBLUE;
								cin.getline(datos.fecha_nacimiento, 20, '\n');
								cout << COLOR_GREEN << "\tTelefono : " << COLOR_BRIGHTBLUE;
								cin >> datos.telefono;
								cout << COLOR_GREEN << "\tEmail corporativo : " << COLOR_BRIGHTBLUE;
								cin.ignore();
								cin.getline(datos.email_corporativo, 50, '\n');
								cout << COLOR_GREEN << "\tDomicilio : " << COLOR_BRIGHTBLUE;
								cin.getline(datos.domicilio, 60, '\n');
								cout << COLOR_GREEN << "\tCurso : " << COLOR_BRIGHTBLUE;
								cin >> datos.curso;

								cout << RESET ;

								if( strlen(datos.dni)==0 || strlen(datos.nombre)==0 || strlen(datos.apellidos)==0 || strlen(datos.fecha_nacimiento)==0 || strlen(datos.email_corporativo)==0 || strlen(datos.domicilio)==0) {
									cout << BOLD_RED << "\n\tERROR" << endl;
									cout << COLOR_BRIGHTGREEN << "\n\tALGUN PARAMETRO NO SE HA INTRODUCIDO" << endl;
									cout << COLOR_NORMAL << BOLD_ON << "\n\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
									cin.ignore();
									cin.get();
									limpiarPantalla();
									break;
								}

								Alumno aux(datos); // Constructor con estructura
								
								cout << endl << "\t***" << endl << endl;
								// COMPRUEBA QUE EL ALUMNO NO HA SIDO INTRODUCIDO ANTERIORMENTE ···
								list <Alumno> alumnosencontrados;
								bool encontrado;


								cout << COLOR_CYAN << BOLD_ON << "\tComprobando que el alumno no esta dado de alta..." << endl;
								cout << "\tOPCIONES DE BUSQUEDA:" << endl;
								cout << "\t\t1. DNI\n\t\t2. Apellidos\n\n";
								cout << "\t¿Como desea buscar? : " << COLOR_BRIGHTBLUE;
								cin >> opcBusqueda;

								cout << RESET ;

								if(opcBusqueda==1) {
									encontrado=miBD.buscarAlumnoDNI(alumnosencontrados, aux);
								} else if (opcBusqueda == 2) {
									encontrado=(miBD.buscarAlumnoApellido(alumnosencontrados, aux)&&miBD.buscarAlumnoDNI(alumnosencontrados, aux));
								} else {
									cout << BOLD_RED << "\n\tERROR" << endl;
									cout << COLOR_BRIGHTGREEN << "\n\tOPCION DE BUSQUEDA NO VALIDA" << endl;
									cout << COLOR_NORMAL << BOLD_ON << "\n\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
									cin.ignore();
									cin.get();
									limpiarPantalla();
									break;
								}

								if(encontrado==true) {	// ALUMNO YA INTRODUCIDO
									cout << BOLD_RED << "\n\tERROR" << endl;
									cout << COLOR_BRIGHTGREEN << "\n\tEL ALUMNO YA SE ENCUENTRA EN LA BD" << endl;
									cout << COLOR_NORMAL << BOLD_ON << "\n\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
									cin.ignore();
									cin.get();
									limpiarPantalla();
									break;
								} 

								// ALUMNO NUEVO ···
								cout << COLOR_GREEN << "\n\tEl alumno no esta dado de alta" << endl;
								cout << RESET ;


								cout << endl << "\t***" << endl << endl;
								// DATOS ADICIONALES ···
								cout << COLOR_CYAN << BOLD_ON << "\t¿Desea introducir datos adicionales?" << endl;
								cout << "\tDATOS ADICIONALES:" << endl;
								cout << "\t\tNOTA\n\t\tEQUIPO\n\t\tLIDER\n";
								cout << "\tPulse 1 si desea introducir datos adicionales: " << COLOR_BRIGHTBLUE;	

								int datosAd;
								cin >> datosAd;
								cout << RESET ;

								if(datosAd == 1) {
									limpiarPantalla();
									OpcionesInsertar();
									cout.fill(' ');
									cout << COLOR_CYAN << BOLD_ON << UNDERLINE_ON << setw(75) 
									 	 << "\tINTRODUZCA LOS DATOS ADICIONALES DEL NUEVO ALUMNO"
									 	 << endl << endl << endl << RESET;
									cout << COLOR_DARKGREY << BOLD_ON << "\tNota : " << COLOR_BRIGHTBLUE;
									cin >> datos.nota;
									cout << COLOR_DARKGREY << "\tEquipo : " << COLOR_BRIGHTBLUE;
									cin >> datos.equipo;
									cout << COLOR_DARKGREY << "\tLider (1: Si; 0: No): " << COLOR_BRIGHTBLUE;
									cin >> datos.lider;

									if(cin.fail()) {
										cout << BOLD_RED << "\n\tERROR" << endl;
										cout << COLOR_BRIGHTGREEN << "\n\tINTRODUCCION DE LIDER INCORRECTA" << endl;
										cout << COLOR_NORMAL << BOLD_ON << "\n\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
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
								limpiarPantalla();
								OpcionesInsertar();
								saltoLinea();
								printAlumno(aux);
								
								cout << endl << "\t***" << endl << endl;
								cout << COLOR_LIGHTGREY << "\tINTRODUCIENDO :·:·:·:·:·:·:·:\n";
								cout << endl << "\t***" << endl << endl;
								// INTENTA INTRODUCIR EL ALUMNO ···
								if(!miBD.introducirAlumno(aux)) {
									cout << BOLD_RED  << "\n\tNO SE HA INTRODUCIDO EL ALUMNO" << endl;
								} else cout << COLOR_GREEN << "\tAlumno introducido correctamente" << endl;

								cout << COLOR_NORMAL << BOLD_ON << "\n\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
								cin.ignore();
								cin.get();
								limpiarPantalla();

							} break;
							case 2: {	// MODIFICAR ALUMNO
				
							// COMPRUEBA QUE HAYA ALUMNOS ···
							if(!miBD.buscarAlumnos()) {
								cout << BOLD_RED << "\n\tERROR" << endl;
								cout << COLOR_BRIGHTGREEN << "\n\tLA BD ESTA VACIA" << endl;
								cout << COLOR_NORMAL << BOLD_ON << "\n\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
								cin.ignore();
								cin.get();
								limpiarPantalla();
								break;
							}

							// VARIABLES ···
							vector <Alumno> alumnosencontrados;
							alumnosencontrados.clear();
							datosAlumno datos;
							int opcAlumno;
							Alumno myAlumno;
							string mydni;
							bool encontrado;

							// MENU MODIFICAR ···
							OpcionesModificar();

							// BUSCAR ALUMNO ···
							cout << "\tIntroduzca la opcion para buscar: " << endl << endl;
							cout << "\t1. DNI\n\t2. Apellidos\n\t3. Grupo\n\n\tOPCION: " << RESET << COLOR_BRIGHTRED;
							cin >> opcBusqueda;

							if(opcBusqueda==1) { // POR DNI ···
								cout << BOLD_ON << COLOR_BRIGHTBLUE << "\n\tDNI A BUSCAR: " << RESET << COLOR_BRIGHTRED;
								cin >> datos.dni ;

								Alumno aux(datos);
								encontrado=miBD.buscarAlumnoDNIv2(alumnosencontrados, aux);
							} else if (opcBusqueda==2) { // POR APELLIDO
								cout << BOLD_ON << COLOR_BRIGHTBLUE << "\n\tAPELLIDO A BUSCAR: " << RESET << COLOR_BRIGHTRED;
								cin >> datos.apellidos ;

								Alumno aux(datos);
								encontrado=miBD.buscarAlumnoApellidov2(alumnosencontrados, aux);
							} else if (opcBusqueda==3) { // POR GRUPO
								cout << BOLD_ON << COLOR_BRIGHTBLUE << "\n\tEQUIPO A BUSCAR: " << RESET << COLOR_BRIGHTRED;
								cin >> datos.equipo ;

								encontrado=miBD.buscarAlumnoEquipov2(alumnosencontrados, datos.equipo);
							} else { // OPCION DE BUSQUEDA NO VALIDA
								cout << BOLD_RED << "\n\tERROR" << endl;
								cout << COLOR_BRIGHTGREEN << "\n\tOPCION NO VALIDA" << endl;
								cout << COLOR_NORMAL << BOLD_ON << "\n\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
								cin.ignore();
								cin.get();
								limpiarPantalla();
								break;
							}

							if(encontrado==false) { // NO ENCUENTRA ALUMNOS
								cout << BOLD_RED << "\n\tERROR" << endl;
								cout << COLOR_BRIGHTGREEN << "\n\tEL ALUMNO NO SE ENCUENTRA EN LA BD" << endl;
								cout << COLOR_NORMAL << BOLD_ON << "\n\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
								cin.ignore();
								cin.get();
								limpiarPantalla();
								break;
							}

							if(alumnosencontrados.size()>1) { // ENCUENTRA MÁS DE UN ALUMNO
								int numAlumno=0;
								limpiarPantalla();
								OpcionesModificar();
								cout << BOLD_ON << COLOR_BRIGHTBLUE"\tCon los datos propuestos se han encontrado los siguiente alumnos: " << endl << endl;
								for(int i=0; i < alumnosencontrados.size(); i++) {
									printAlumno(alumnosencontrados[i]);
									cout << BOLD_ON << "\n\t--NUM ALUMNO ENCONTRADO--: " << COLOR_BRIGHTRED << numAlumno << endl << endl;
									numAlumno++;
								}					
								
								cout << BOLD_ON << COLOR_BRIGHTBLUE << "\tINTRODUZCA EL NUMERO DEL ALUMNO A MODIFICAR: " << RESET << COLOR_BRIGHTRED;
								cin >> opcAlumno;

								if(opcAlumno < 0 or opcAlumno >= alumnosencontrados.size()) {
									cout << BOLD_RED << "\n\tERROR" << endl;
									cout << COLOR_BRIGHTGREEN << "\n\tALUMNO INTRODUCIDO INCORRECTO" << endl;
									cout << COLOR_NORMAL << BOLD_ON << "\n\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
									cin.ignore();
									cin.get();
									limpiarPantalla();
									break;
								}

								myAlumno = alumnosencontrados[opcAlumno];
								mydni = myAlumno.getDNI();

							} else { // ENCUENTRA SOLO UN ALUMNO
								saltoLinea();
								myAlumno = alumnosencontrados.front();
								mydni = myAlumno.getDNI();
							}

							// CONFIRMA MODIFICAR ALUMNO
							limpiarPantalla();
							OpcionesModificar();
							printAlumno(myAlumno);
							cout << BOLD_ON << COLOR_BRIGHTBLUE << "\n\tPULSE 1 SI DESEA MODIFICAR ESTE ALUMNO: " << RESET << COLOR_BRIGHTRED;
							cin >> opcAlumno;

							if(opcAlumno!=1) { // NO CONFIRMA MODIFICAR ALUMNO
								cout << BOLD_ON << COLOR_BRIGHTGREEN << "\n\tNO SE MODIFICO NINGUN ALUMNO" << endl;
								cout << COLOR_NORMAL << BOLD_ON << "\n\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
								cin.ignore();
								cin.get();
								limpiarPantalla();
								break;
							}

							// PREGUNTA FORMA DE MODIFICAR ···
							cout << COLOR_BRIGHTBLUE << "\n\tCOMO QUIERE MODIFICAR?" << endl;
							cout <<"\n\t1. Un solo dato\n\t2. Todos los datos\n\tOPCION: " << COLOR_BRIGHTRED;
							cin >> opcAlumno;

							if(opcAlumno==1) { // MODIFICA UN SOLO DATO ···
								int opcDato, fallo=0;
								cout << BOLD_ON << "\n\tPULSE PARA MODIFICAR:\n";
								cout << "\n\t1. DNI\n\t2. Nombre\n\t3. Apellidos\n\t4. Fecha Nacimiento\n\t5. Email\n\t6. Domicilio\n\t7. Telefono\n\t8. Curso\n\t9. Nota\n\t10. Equipo\n\t11. Lider";
								cout << "\n\tOPC: " << COLOR_BRIGHTRED;
								cin >> opcDato;

								switch(opcDato) { // ELIGE DATO A MODIFICAR
									case 1: { // DNI
										list <Alumno> aux;
										cout << COLOR_GREEN << BOLD_ON << "\n\tDNI : " << COLOR_BRIGHTBLUE;
										cin.ignore();
										cin.getline(datos.dni, 10, '\n');
										myAlumno.setDNI(datos.dni);
										if(miBD.buscarAlumnoDNI(aux, myAlumno)) {
											fallo=1;
											cout << BOLD_RED << "\n\tERROR" << endl;
											cout << COLOR_BRIGHTGREEN << "\n\tYA HAY UN ALUMNO CON ESE DNI" << endl;
											cout << COLOR_NORMAL << BOLD_ON << "\n\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
											cin.ignore();
											cin.get();
											limpiarPantalla();
											break;
										}
									} break;
									case 2: { // NOMBRE
										cout << COLOR_GREEN << "\n\tNombre : " << COLOR_BRIGHTBLUE;
										cin.ignore();
										cin.getline(datos.nombre, 30, '\n');
										myAlumno.setNombre(datos.nombre);
									} break;
									case 3: { // APELLIDOS
										cout << COLOR_GREEN << "\n\tApellidos : " << COLOR_BRIGHTBLUE;
										cin.ignore();
										cin.getline(datos.apellidos, 30, '\n');
										myAlumno.setApellidos(datos.apellidos);

									} break;
									case 4: { // FECHA NACIMIENTO
										cout << COLOR_GREEN << "\n\tFecha de nacimiento : " << COLOR_BRIGHTBLUE;
										cin.ignore();
										cin.getline(datos.fecha_nacimiento, 10, '\n');
										myAlumno.setFecha_nacimiento(datos.fecha_nacimiento);

									} break;
									case 5: { // EMAIL CORPORATIVO
										cout << COLOR_GREEN << "\n\tEmail corporativo : " << COLOR_BRIGHTBLUE;
										cin.ignore();
										cin.getline(datos.email_corporativo, 30, '\n');
										myAlumno.setEmail_corporativo(datos.email_corporativo);
									} break;
									case 6: { // DOMICILIO
										cout << COLOR_GREEN << "\n\tDomicilio : " << COLOR_BRIGHTBLUE;
										cin.ignore();
										cin.getline(datos.domicilio, 30, '\n');
										myAlumno.setDomicilio(datos.domicilio);
									} break;
									case 7: { // TELEFONO
										cout << COLOR_GREEN << "\n\tTelefono : " << COLOR_BRIGHTBLUE;
										cin >> datos.telefono;
										myAlumno.setTelefono(datos.telefono);
									} break;
									case 8: { // CURSO
										cout << COLOR_GREEN << "\tCurso : " << COLOR_BRIGHTBLUE;
										cin >> datos.curso;
										myAlumno.setCurso(datos.curso);

									} break;
									case 9: { // NOTA
										cout << COLOR_DARKGREY << BOLD_ON << "\n\tNota : " << COLOR_BRIGHTBLUE;
										cin >> datos.nota;
										myAlumno.setNota(datos.nota);

										
										
									} break;
									case 10: { // EQUIPO
										cout << COLOR_DARKGREY << "\n\tEquipo : " << COLOR_BRIGHTBLUE;
										cin >> datos.equipo;
										myAlumno.setEquipo(datos.equipo);

									} break;
									case 11: { // LIDER
										if(myAlumno.getEquipo() == -1) { // SI MODIFICA EL LIDER, ALUMNO DEBE PERTENECER A UN EQUIPO
											cout << BOLD_RED << "\n\tERROR" << endl;
											cout << COLOR_BRIGHTGREEN << "\n\tEL ALUMNO NO TIENE EQUIPO, DESEA INTRODUCIRLO?" << endl;
											cin >> opcAlumno;
											if(opcAlumno!=1) {
												fallo=1;
												cout << COLOR_NORMAL << BOLD_ON << "\n\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
												cin.ignore();
												cin.get();
												limpiarPantalla();
												break;
											} else {
												cout << COLOR_DARKGREY << "\n\tEquipo : " << COLOR_BRIGHTBLUE;
												cin >> datos.equipo;
												myAlumno.setEquipo(datos.equipo);
											}
										}

										cout << COLOR_DARKGREY << "\n\tLider (1: Si; 0: No): " << COLOR_BRIGHTBLUE;
										cin >> datos.lider;

										if(cin.fail()) {	// CONTROL DE ERRORES AL INTRODUCIR LIDER
											cout << BOLD_RED << "\n\tERROR" << endl;
											cout << COLOR_BRIGHTGREEN << "\n\tINTRODUCCION DE LIDER INCORRECTA" << endl;
											cout << COLOR_NORMAL << BOLD_ON << "\n\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
				  							//cin.ignore(numeric_limits<int>::max());
				  							cin.clear();
				  							cin.ignore();
				  							cin.get();
				  							limpiarPantalla();
				  							break;
										}
										
										myAlumno.setLider(datos.lider);
									} break;
									default:  {	// OPCION DE DATO A MODIFICAR NO VALIDA
										fallo=1;
										cout << BOLD_RED << "\n\tERROR" << endl;
										cout << COLOR_BRIGHTGREEN << "\n\tOPCION NO VALIDA" << endl;
										cout << COLOR_NORMAL << BOLD_ON << "\n\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
										cin.ignore();
										cin.get();
										limpiarPantalla();
									}
								}

								if(fallo) break; // SI SE PRODUCE UN FALLO EN LOS DATOS SALE

							} else if (opcAlumno==2) { // MODIFICA TODO ···

								limpiarPantalla();
								OpcionesModificar();
								printAlumno(myAlumno);

								cout << COLOR_BRIGHTBLUE << "NUEVOS DATOS:" << endl;

								cout << COLOR_GREEN << BOLD_ON << "\tDNI : " << COLOR_BRIGHTBLUE;
								cin.ignore();
								cin.getline(datos.dni, 10, '\n');
								cout << COLOR_GREEN << "\tNombre : " << COLOR_BRIGHTBLUE;
								cin.getline(datos.nombre, 30, '\n');
								cout << COLOR_GREEN << "\tApellidos : " << COLOR_BRIGHTBLUE;
								cin.getline(datos.apellidos, 30, '\n');
								cout << COLOR_GREEN << "\tFecha de nacimiento : " << COLOR_BRIGHTBLUE;
								cin.getline(datos.fecha_nacimiento, 10, '\n');
								cout << COLOR_GREEN << "\tTelefono : " << COLOR_BRIGHTBLUE;
								cin >> datos.telefono;
								cout << COLOR_GREEN << "\tEmail corporativo : " << COLOR_BRIGHTBLUE;
								cin.ignore();
								cin.getline(datos.email_corporativo, 30, '\n');
								cout << COLOR_GREEN << "\tDomicilio : " << COLOR_BRIGHTBLUE;
								cin.getline(datos.domicilio, 30, '\n');
								cout << COLOR_GREEN << "\tCurso : " << COLOR_BRIGHTBLUE;
								cin >> datos.curso;

								cout << RESET ;

								if( strlen(datos.dni)==0 || strlen(datos.nombre)==0 || strlen(datos.apellidos)==0 || strlen(datos.fecha_nacimiento)==0 || strlen(datos.email_corporativo)==0 || strlen(datos.domicilio)==0) {
									cout << BOLD_RED << "\n\tERROR" << endl;
									cout << COLOR_BRIGHTGREEN << "\n\tALGUN PARAMETRO NO SE HA INTRODUCIDO" << endl;
									cout << COLOR_NORMAL << BOLD_ON << "\n\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
									cin.ignore();
									cin.get();
									limpiarPantalla();
									break;
								}

								myAlumno.setDNI(datos.dni);
								myAlumno.setNombre(datos.nombre);
								myAlumno.setApellidos(datos.apellidos);
								myAlumno.setFecha_nacimiento(datos.fecha_nacimiento);
								myAlumno.setEmail_corporativo(datos.email_corporativo);
								myAlumno.setDomicilio(datos.domicilio);
								myAlumno.setTelefono(datos.telefono);
								myAlumno.setCurso(datos.curso);

								cout << COLOR_BRIGHTBLUE << BOLD_ON << "\t¿Desea modificar llos datos adicionales?" << endl;
								cout << "\tPulse 1 si desea modificar datos adicionales: " << COLOR_BRIGHTRED;	

								int datosAd;
								cin >> datosAd;
								cout << RESET ;

								if(datosAd == 1) {
									limpiarPantalla();
									OpcionesInsertar();
									cout.fill(' ');
									cout << COLOR_BRIGHTBLUE << BOLD_ON << UNDERLINE_ON << setw(75) 
									 	 << "\tINTRODUZCA LOS DATOS ADICIONALES DEL ALUMNO"
									 	 << endl << endl << endl << RESET;
									cout << COLOR_DARKGREY << BOLD_ON << "\tNota : " << COLOR_BRIGHTBLUE;
									cin >> datos.nota;
									cout << COLOR_DARKGREY << "\tEquipo : " << COLOR_BRIGHTBLUE;
									cin >> datos.equipo;
									cout << COLOR_DARKGREY << "\tLider (1: Si; 0: No): " << COLOR_BRIGHTBLUE;
									cin >> datos.lider;

									if(cin.fail()) {
										cout << BOLD_RED << "\n\tERROR" << endl;
										cout << COLOR_BRIGHTGREEN << "\n\tINTRODUCCION DE LIDER INCORRECTA" << endl;
										cout << COLOR_NORMAL << BOLD_ON << "\n\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
			  							//cin.ignore(numeric_limits<int>::max());
			  							cin.clear();
			  							cin.ignore();
			  							cin.get();
			  							limpiarPantalla();
			  							break;
									}
									
									myAlumno.setNota(datos.nota);
									myAlumno.setEquipo(datos.equipo);
									myAlumno.setLider(datos.lider);
								}

							} else { // OPCION DE MODIFICAR NO VALIDA ···
								cout << BOLD_RED << "\n\tERROR" << endl;
								cout << COLOR_BRIGHTGREEN << "\n\tOPCION NO VALIDA" << endl;
								cout << COLOR_NORMAL << BOLD_ON << "\n\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
								cin.ignore();
								cin.get();
								limpiarPantalla();
								break;
							}

							// MODIFICA EL ALUMNO EN LA LISTA ···
							if(!miBD.modificarAlumno(myAlumno, mydni)) {
								cout << BOLD_RED  << "\n\tNO SE HA MODIFICADO EL ALUMNO" << endl;
							} else cout << COLOR_GREEN << "\n\tAlumno modificado correctamente" << endl;

							cout << COLOR_NORMAL << BOLD_ON << "\n\tPULSE UNA TECLA PARA VOLVER AL MENÚ";
							cin.ignore();
							cin.get();
							limpiarPantalla();

							} break;
						case 3: {	// ELIMINAR ALUMNO
								










							} break;
						case 4: {	// MOSTRAR ALUMNOS

								
							Alumno z;
							string DNI;
							string Apellidos;
							int equipo;

							if (miBD.getAlumnos().size()==0){
								cout<<"No hay datos que guardar"<<endl;
								char cargar;//opciones para cargar o salir al menú	

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
													cout<<COLOR_GREEN<<"Se han encontrado "<<RESET<<BOLD_ON<<listaBusqueda.size()<<RESET<<COLOR_GREEN<<" alumnos con el apellido: "<<z.getApellidos()<<RESET<<endl;	
													saltoLinea();
													cout<<"Indique cómo quiere mostrarlos"<<endl;
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
												saltoLinea();
												cout<<"Indique cómo quiere mostrarlos"<<endl;
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
							}
						}break;

							

						case 5: {	// GUARDAR BD

									
							if (miBD.getAlumnos().size()==0){
								cout<<"No hay datos que guardar"<<endl;
								char cargar;//opciones para cargar o salir al menú	

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
									break;
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

							if (strcmp(cprof.rol, "coordinador")==0){

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
							}
							else{
								cout <<"\t"<<"OPCIÓN NO VÁLIDA" << endl;
								cout<<"\t"<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
								limpiarPantalla();
							}



								} break;
						case 8: {	// CARGAR BACKUP
							
							if (strcmp(cprof.rol, "coordinador")==0){
								cout<<BOLD_ON<<BLINK<<"\tPreparando el sistema para cargar la copia externa"<<RESET<<endl;
								sleep(2);
								limpiarPantalla;
								miBD.cargarBackup();
								saltoLinea();
								saltoLinea();
								cout<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
								limpiarPantalla();
							}
							
							else{
								cout <<"\t"<<"OPCIÓN NO VÁLIDA" << endl;
								cout<<"\t"<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
								limpiarPantalla();
							}

							} break;	
						case 9: {	// GESTION PERFIL

							} break;
						case 10: {	// SALIR DE LA APLICACION
							cout<<"Hasta luego Lucas"<<endl;
							
							exit(-1);
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

			}
			else{
				
				limpiarPantalla();
				cout<<COLOR_RED<<"ACCESO DENEGADO"<<RESET<<endl;
				cout<<"Consulte sus credenciales de acceso y vuelva a entrar en la aplicación"<<endl;
				cout<<"Hasta luego Lucas"<<endl;
				intentosAcceso++;

			}
	

	}
	while(intentosAcceso<3);

	//salinda de aplicación 
	exit(-1);
	return 0;
}

void mostrarOpciones() {
	cout.fill('*');
	saltoLinea();
	cout<<"\t"<<BOLD_ON<<COLOR_LIGHTGREY<<setw(40)<<" "<<endl;
	cout.fill(' ');
	saltoLinea();
	cout<<"\t"<<BOLD_ON<<COLOR_LIGHTGREY<<left<<setw(40)<<"|::MENÚ APLICACIÓN::|"<<RESET<<endl;
	saltoLinea();
	cout.fill('*');
	cout<<"\t"<<BOLD_ON<<COLOR_LIGHTGREY<<setw(40)<<" "<<endl;
	saltoLinea();
	saltoLinea();
	cout <<"\t"<<COLOR_DARKGREY<< "1. Insertar Alumno" << endl;
	cout <<"\t"<<COLOR_LIGHTGREY<< "2. Modificar Alumno" << endl;
	cout <<"\t"<<COLOR_DARKGREY<< "3. Eliminar Alumno" << endl;
	cout <<"\t"<<COLOR_LIGHTGREY<< "4. Mostrar Alumnos" << endl;
	cout <<"\t"<<COLOR_DARKGREY<< "5. Guardar BD" << endl;
	cout <<"\t"<<COLOR_LIGHTGREY<< "6. Cargar BD" << endl;
	cout <<"\t"<<COLOR_DARKGREY<< "7. Guardar Backup"<< endl;
	cout <<"\t"<<COLOR_LIGHTGREY<< "8. Cargar Backup" << endl;
//	cout <<"\t"<<COLOR_DARKGREY<< "9. Gestion del Perfil" << endl;
	cout <<"\t"<<COLOR_DARKGREY<< "10. Salir de la aplicacion" << endl;
}

void mostrarOpcionesAyudantes() {
	cout.fill('*');
	saltoLinea();
	cout<<"\t"<<BOLD_ON<<COLOR_LIGHTGREY<<setw(40)<<" "<<endl;
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
	//cout <<"\t"<<COLOR_DARKGREY<< "9. Gestion del Perfil" << endl;
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
			cout<<RESET;

			if(opcOrden==5){

				break;
			}

			cout<<"\t"<<BOLD_ON<<COLOR_DARKGREY<<"Indique si desea mostrar la lista en orden Ascendente, introduzca <ASC>, o en orden Descendente, introduzca <DESC>: "<<COLOR_BRIGHTBLUE;getchar();getline(cin, orden);
			cout<<RESET<<endl;
			limpiarPantalla();


			if ((opcOrden==1||opcOrden==2||opcOrden==3||opcOrden==4)&&(orden=="ASC"||orden=="DESC")){
				
				miBD.mostrarAlumno(lista,opcOrden, orden);
				saltoLinea();
				cout<<"\t"<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
				limpiarPantalla();
			}

			
			

		}while((opcOrden!=1 ||opcOrden!=2||opcOrden!=3||opcOrden!=4||opcOrden!=5)&&(orden!="ASC"||orden!="DESC"));



}

void BD::ordenLista(){
	

		do{
			OpcionesOrden();
			saltoLinea();
			cout<<"\t"<<BOLD_ON<<COLOR_DARKGREY<<"Indique el orden en que quiere mostrar el alumno o alumnos: "<<COLOR_BRIGHTBLUE;cin>>opcOrden;
			cout<<RESET;
			
			if(opcOrden==5){

				break;
			}

			cout<<"\t"<<BOLD_ON<<COLOR_DARKGREY<<"Indique si desea mostrar la lista en orden Ascendente, introduzca <ASC>, o en orden Descendente, introduzca <DESC>: "<<COLOR_BRIGHTBLUE;getchar();getline(cin, orden);
			cout<<RESET<<endl;
			limpiarPantalla();

			


			if ((opcOrden==1||opcOrden==2||opcOrden==3||opcOrden==4)&&(orden=="ASC"||orden=="DESC")){
				
				miBD.mostrarAlumno(opcOrden, orden);
				saltoLinea();
				cout<<"\t"<<BOLD_ON<<"PULSE UNA TECLA PARA VOLVER AL MENÚ"<<endl;getchar();getchar();
				limpiarPantalla();
			}
			
		

		}while((opcOrden!=1 ||opcOrden!=2||opcOrden!=3||opcOrden!=4||opcOrden!=5)&&(orden!="ASC"||orden!="DESC"));



}



void OpcionesInsertar() {
	cout.fill('*');
	saltoLinea();
	cout<<"\t"<<BOLD_ON<<COLOR_CYAN<<setw(40)<<""<<endl;
	cout.fill(' ');
	saltoLinea();
	cout<<"\t"<<BOLD_ON<<COLOR_CYAN<<left<<setw(40)<<"|::INTRODUCIR ALUMNOS::|"<< RESET<<endl;
	saltoLinea();
	cout.fill('*');
	cout<<"\t"<<BOLD_ON<<COLOR_CYAN<<setw(40)<<""<<endl;
	saltoLinea();
}

void OpcionesModificar() {
	cout.fill('*');
	saltoLinea();
	cout<<"\t"<<BOLD_ON<<COLOR_BRIGHTBLUE<<setw(40)<<""<<endl;
	cout.fill(' ');
	saltoLinea();
	cout<<"\t"<<RESET<<COLOR_BRIGHTRED<<left<<setw(40)<<"|::MODIFICAR ALUMNOS::|"<< RESET<<endl;
	saltoLinea();
	cout.fill('*');
	cout<<"\t"<<BOLD_ON<<COLOR_BRIGHTBLUE<<setw(40)<<""<<endl;
	saltoLinea();
}

void printAlumno(Alumno aux) {
	cout.fill(' ');
	cout << COLOR_CYAN << BOLD_ON << UNDERLINE_ON << setw(75) 
	 	 << "\tDATOS DEL ALUMNO"
	 	 << endl << endl << endl << RESET;
	cout << COLOR_BRIGHTGREEN << BOLD_ON << "\tDNI: " << COLOR_BRIGHTBLUE << aux.getDNI() << endl;
	cout << COLOR_BRIGHTGREEN << "\tNombre: " << COLOR_BRIGHTBLUE << aux.getNombre() << endl;
	cout << COLOR_BRIGHTGREEN << "\tApellidos: " << COLOR_BRIGHTBLUE << aux.getApellidos() << endl;
	cout << COLOR_BRIGHTGREEN << "\tFecha Nacimiento: " << COLOR_BRIGHTBLUE << aux.getFecha_nacimiento() << endl;
	cout << COLOR_BRIGHTGREEN << "\tEmail: " << COLOR_BRIGHTBLUE << aux.getEmail_corporativo() << endl;
	cout << COLOR_BRIGHTGREEN << "\tDomicilio: " << COLOR_BRIGHTBLUE << aux.getDomicilio() << endl;
	cout << COLOR_BRIGHTGREEN << "\tTelefono: " << COLOR_BRIGHTBLUE << aux.getTelefono() << endl;
	cout << COLOR_BRIGHTGREEN << "\tCurso: " << COLOR_BRIGHTBLUE << aux.getCurso() << endl;
	cout << COLOR_DARKGREY << "\tNota: " << COLOR_BRIGHTBLUE << aux.getNota() << endl;
	cout << COLOR_DARKGREY << "\tEquipo: " << COLOR_BRIGHTBLUE << aux.getEquipo() << endl;
	cout << COLOR_DARKGREY << "\tLider: " << COLOR_BRIGHTBLUE << aux.getLider() << endl << RESET;
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

void generarhtml(){


	FILE *fp;

	BD b;
	Alumno a1, a2, a3, a4;
	char NombreFichero[50];
	string fichero="acceso";
	string nameBD="./Instrucciones/acceso.html";
	strcpy(NombreFichero, nameBD.c_str());

	/*a1.setNombre("Rodolfo Mateo");
	a2.setNombre("Rodolfo Inurria");
	a3.setNombre("Rodolfo Jaén");
	a4.setNombre("Rodolfo");
	
	b.introducirAlumno(a1);
	b.addNumeroAlumnos();
	b.introducirAlumno(a2);
	b.addNumeroAlumnos();
	b.introducirAlumno(a3);
	b.addNumeroAlumnos();
	b.introducirAlumno(a4);
	b.addNumeroAlumnos();
	cout<<BOLD_ON<<COLOR_YELLOW<<BLINK<<b.getNumeroAlumnos()<<RESET<<endl;
	*/

	/* Abrir archivo para escritura */
	fp = fopen(NombreFichero, "w");
	fprintf(fp, "<html> \n");
	fprintf(fp, "<head> \n");
	fprintf(fp, "<title>INSTRUCCIONES ACCESO</title>\n");
	fprintf(fp, "<head> \n");
	fprintf(fp, "<body> \n");
	fprintf(fp, "<p><a href='https://www.uco.es/eps/nodeorder/term/29' target='_blank'><img alt='' src='https://www.uco.es/eps/sites/default/files/info_general/logos/escudo_informatica.jpg' style='width: 150px; height: 150px;'' /></a></p>");
	fprintf(fp, "<p><span style='color:#003399;''><span style='font-family:comic sans ms,cursive;''><span style='font-size:24px;''><strong>GestionAlumnos&nbsp; - Grupo 36 IS</strong></span></span></span></p>");
	
	fprintf(fp, "<p><strong>Alumnos Integrantes Grupo 36</strong></p>");

	fprintf(fp, "<p style='margin-left: 40px;'><span style='font-size:16px;'><span style='color:#003399;''>Rafael Cantero Alen</span>- Representante</p>");
	fprintf(fp, "<p style='margin-left: 40px;'><span style='font-size:16px;'>Carlos Freire Caballero</span></p>");
	fprintf(fp, "<p style='margin-left: 40px;'><span style='font-size:16px;'>Fernando Herrera Poch</span></p>");
	fprintf(fp, "<p><a href='https://github.com/rca99/Grupo-36-IS' onclick='window.open(this.href, '', 'resizable=no,status=no,location=no,toolbar=no,menubar=no,fullscreen=yes,scrollbars=no,dependent=no'); return false;'><strong>Repositorio Git</strong></a></p>");
	fprintf(fp, "<p>&nbsp;</p>");

	fprintf(fp, "<p><strong>Instrucciones</strong></p>");

	fprintf(fp, "<p>A continuaci&oacute;n se presentan las instrucciones para ejecutar y usar la aplicaci&oacute;n</p>");

	fprintf(fp, "<ul>");
		fprintf(fp, "<li>El acceso a la aplicaci&oacute;n se realiza con sus credenciales de acceso normales a la Universidad</li>");
		fprintf(fp, "<li>Tiene <strong>tres</strong> intentos de acceso</li>");
		fprintf(fp, "<li>La contrase&ntilde;a distingue may&uacute;sculas y min&uacute;sculas</li>");
		fprintf(fp, "<li>A continuaci&oacute;n le recordamos los usuarios y una pista de la contrase&ntilde;a para acceder a la aplicaci&oacute;n</li><br />");
	fprintf(fp, "<ul>");

	fprintf(fp, "<table border='1' cellpadding='1' cellspacing='1' style='width:500px;'>");
		fprintf(fp, "<tbody>");
			fprintf(fp, "<tr>");
				fprintf(fp, "<td><strong>Profesor</strong></td>");
				fprintf(fp, "<td><strong>Usuario</strong></td>");
				fprintf(fp, "<td><strong>Rol</strong></td>");
				fprintf(fp, "<td><strong>Clave</strong></td>");
			fprintf(fp, "</tr>");

			fprintf(fp, "<tr>");
				fprintf(fp, "<td>David Guijo</td>");
				fprintf(fp, "<td>dguijo</td>");
				fprintf(fp, "<td>Ayudante</td>");
				fprintf(fp, "<td>1***</td>");
			fprintf(fp, "</tr>");

			fprintf(fp, "<tr>");
				fprintf(fp, "<td>Antonio Dur&aacute;n<</td>");
				fprintf(fp, "<td>aduran</td>");
				fprintf(fp, "<td>Ayudante</td>");
				fprintf(fp, "<td>2***</td>");
			fprintf(fp, "</tr>");

			fprintf(fp, "<tr>");
				fprintf(fp, "<td>Isabel</td>");
				fprintf(fp, "<td>isa</td>");
				fprintf(fp, "<td>Coordinador</td>");
				fprintf(fp, "<td>0***</td>");
			fprintf(fp, "</tr>");

		fprintf(fp, "</tbody>");
	fprintf(fp, "</table>\n");
	fprintf(fp, "<br />");
	
	/*list <Alumno> Auxiliar;

	Auxiliar=b.getAlumnos();
	
	fprintf(fp, "<p>A Lista de Alumnos del sistema</p>");
	list <Alumno>::iterator i;

	for ( i=Auxiliar.begin(); i !=Auxiliar.end(); ++i){
	
		fprintf(fp, i->getNombre().c_str());

	}
	*/



	fprintf(fp, "<body> \n");
	fprintf(fp, "<html> \n");

	/* Cerrar el archivo antes de terminar el programa */
	fclose(fp);
	printf("Se ha creado el archivo: acceso.html \n");
	
	system("chmod +x abrirWeb.sh");
	system("./abrirWeb.sh");
}

