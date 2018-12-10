// --------------
// MENU PRINCIPAL
// --------------


#include "BD.h" //para incluir la lista de alumnos y funciones BD 
#include "Profesor.h"//para incluir puntero a base de datos
#include "Alumno.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include "consoleLinux.h"//colores menu
#include <iomanip>//formato cout



#include "Alumno.h"
//#include "Profesor.h"
#include "BD.h"





void mostrarOpciones();
bool datosBusqueda(datosAlumno &datos);

int main(int argc, char const *argv[]) {



	list <Alumno> listaAuxiliar;

	BD miBD; //crea un objeto de base de datos con el nombre de fichero gestionAlumnos

	int opc=0;

	do {
		mostrarOpciones();
		cout << "Introduzca una opcion: ";
		cin >> opc;
		switch(opc) {
			case 1: {	// INSERTAR ALUMNO
					
					Alumno a, b,c,d,e;
					a.setNombre("rodolfo");
					a.setCurso(2);
					b.setNombre("Artura");
					b.setCurso(3);
					c.setNombre("Jeremias");
					c.setCurso(2);
					d.setNombre("Pablo de las Casas");
					d.setCurso(1);
					e.setNombre("M del Rosario");
					e.setCurso(3);

				
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
					
					listaAuxiliar.push_back(aux);
					*/
					miBD.introducirAlumno(a);
					miBD.introducirAlumno(b);
					miBD.introducirAlumno(c);
					miBD.introducirAlumno(d);
					miBD.introducirAlumno(e);
					
			


				} break;
			case 2: {	// MODIFICAR ALUMNO
					
				} break;
			case 3: {	// ELIMINAR ALUMNO
					
				} break;
			case 4: {	// MOSTRAR ALUMNOS

				} break;
			case 5: {	// GUARDAR BD
				cout<<miBD.getAlumnos().size()<<endl;
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
				cout<<sizeof(datosAlumno)<<endl;
				miBD.cargarBD();

				




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
	cout <<COLOR_MAGENTA<<BOLD_ON<<UNDERLINE_ON<<BLINK<<ON_GREEN<<"\t::MENU APLICACION::" <<RESET<<endl; 
	cout<<endl;

	cout << COLOR_BRIGHTRED <<"1. Insertar Alumno" <<COLOR_NORMAL<<endl;
	cout << INVERTIDO<<"2. Modificar Alumno" << endl;
	cout <<  COLOR_BRIGHTRED <<"3. Eliminar Alumno" << COLOR_NORMAL<<endl;
	cout << "4. Mostrar Alumnos" << endl;
	cout <<COLOR_BRIGHTRED <<"5. Guardar BD" << COLOR_NORMAL<<endl;
	cout <<CONGELADO<<"6. Cargar BD" << endl;
	cout <<COLOR_BRIGHTRED <<"7. Guardar Backup (solo coordinador)"<< COLOR_NORMAL<<endl;
	cout <<ON_GREEN<<"8. Cargar Backup (solo coordinador)" << RESET<< endl;
	cout <<GRIS_OSCURO<<COLOR_BRIGHTRED <<"9. Gestion del Perfil" << COLOR_NORMAL<<endl;
	cout <<BLINK<< "10. Salir de la aplicacion" <<RESET<< endl;
}