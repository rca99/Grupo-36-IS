// funcion buscar alumno
// clase BD

#include "BD.h"
#include "Alumno.h"
#include <iostream>
#include <string>
#include <cstring>
#include <locale>//para función pasar a mayúscula

using namespace std;

string convertirMayuscula(string cadena);

bool BD::buscarAlumno(list <Alumno> &lista, Alumno a) {
	// Comprueba que haya alumnos dados de alta
	
	int contador=0;
	if(getNumeroAlumnos()==0) {
		cout << "No hay alumnos dados de alta en la base de datos" << endl;
		return false;
	}

	list <Alumno> listaAuxiliar;



	listaAuxiliar=getAlumnos();
	list <Alumno> :: iterator i;

	for(i=listaAuxiliar.begin(); i!=listaAuxiliar.end(); i++) {
		if((*i).getDNI()==a.getDNI()) {
			(lista).push_back(*i);
			contador++;

		}

	
	}

	if (contador>0){

		return true;
	}
	else{return false;}

		


}


bool BD::buscarAlumnoDNI(list <Alumno> &lista, Alumno a){
	// Comprueba que haya alumnos dados de alta
	int contador=0;
	if(getNumeroAlumnos()==0) {
		cout << "No hay alumnos dados de alta en la base de datos" << endl;
		return false;
	}

	list <Alumno> listaAuxiliar;



	listaAuxiliar=getAlumnos();
	list <Alumno> :: iterator i;

	for(i=listaAuxiliar.begin(); i!=listaAuxiliar.end(); i++) {
		if((*i).getDNI()==a.getDNI()) {
			(lista).push_back(*i);
			contador++;

		}

	
	}

	if (contador>0){
		return true;
	}
	else{
		return false;
	}

	

}	

bool BD::buscarAlumnoApellido(list <Alumno> &lista, Alumno a){

	/*//Convertir string a mayúsculas
	string cadena;
	getline(cin, cadena);
	cout<<"Cadena introducida en mayusculas"<<cadena<<endl;
	cadena=convertirMayuscula(cadena);
	cout<<cadena<<endl;
	*/


	// Comprueba que haya alumnos dados de alta
	int contador=0;
	if(getNumeroAlumnos()==0) {
		cout << "No hay alumnos dados de alta en la base de datos" << endl;
		return false;
	}

	list <Alumno> listaAuxiliar;

	listaAuxiliar=getAlumnos();
	list <Alumno> :: iterator i;
	
	string apellidoAlumno=convertirMayuscula(a.getApellidos());
	cout<<"apellido que se busca: "<<apellidoAlumno<<endl;

	for(i=listaAuxiliar.begin(); i!=listaAuxiliar.end(); i++) {
		
		string apellidoLista=convertirMayuscula((*i).getApellidos());

		cout<<"apellido en lista: "<<apellidoLista<<endl;

		if(apellidoAlumno==apellidoLista) {
			(lista).push_back(*i);
			contador++;

		}

	
	}

	if (contador>0){
		return true;
	}
	else{

		return false;



	}

	

}

bool BD::buscarAlumno(list <Alumno> &lista,int equipo){

	int contador=0;
	if(getNumeroAlumnos()==0) {
		cout << "No hay alumnos dados de alta en la base de datos" << endl;
		return false;
	}

	list <Alumno> listaAuxiliar;



	listaAuxiliar=getAlumnos();
	list <Alumno> :: iterator i;

	for(i=listaAuxiliar.begin(); i!=listaAuxiliar.end(); i++) {
		

		if((*i).getEquipo()==equipo) {
			(lista).push_back(*i);
			contador++;

		}

	
	}

	if (contador>0){
		return true;
	}
	else{

		return false;



	}







}





string convertirMayuscula(string cadena){

  	locale loc;
 	string s=cadena;
 	
  	for (string::size_type i=0; i<s.length(); ++i){

  		 s[i]=toupper((s)[i],loc);
	
  	}


	return s;

}
