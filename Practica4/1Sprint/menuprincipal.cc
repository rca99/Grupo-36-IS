// --------------
// MENU PRINCIPAL
// --------------

#include <iostream>
#include <string>
#include <cstdlib>
#include <list>


#include "Alumno.h"
#include "Profesor.h"
#include "BD.h"

using namespace std;



void mostrarOpciones();
bool datosBusqueda(datosAlumno &datos);

int main(int argc, char const *argv[]) {

	BD miBD;
	list <Alumno> listaAuxiliar;
	int opc=0;

	do {
		mostrarOpciones();
		cout << "Introduzca una opcion: ";
		cin >> opc;
		switch(opc) {
			case 1: {	// INSERTAR ALUMNO
					
					Alumno a, b;
					a.setNombre("rodolfo");
					b.setNombre("Fernando");
					listaAuxiliar.push_back(a);
					listaAuxiliar.push_back(b);

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
					//miBD.introducirAlumno(aux);
					*/
					miBD.setAlumnos(listaAuxiliar);


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
				cout<<sizeof(Alumno)<<endl;
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