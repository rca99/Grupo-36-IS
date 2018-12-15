// funcion buscar alumno
// clase BD

#include "BD.h"
#include "Alumno.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <locale>//para función pasar a mayúscula

using namespace std;

string convertirMayuscula(string cadena);

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
	cout<<"Contador encontrados: "<<contador<<endl;
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
