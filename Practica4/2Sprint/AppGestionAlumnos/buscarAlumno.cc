// funcion buscar alumno
// clase BD

#include "BD.h"
#include "Alumno.h"
#include <iostream>
#include <string>
#include <cstring>
#include <locale>//para función pasar a mayúscula

using namespace std;

<<<<<<< HEAD
bool BD::buscarAlumnos() { // Comprueba que haya alumnos dados de alta
	if(numeroAlumnos_ == 0) 
		return false;
	else return true;
=======
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

		


>>>>>>> 19544f3ea35e1dbf900de3518ace8437620fa429
}


bool BD::buscarAlumnoDNI(list <Alumno> &lista, Alumno a){
	int contador=0;
<<<<<<< HEAD

=======
	if(getNumeroAlumnos()==0) {
		cout << "No hay alumnos dados de alta en la base de datos" << endl;
		return false;
	}

	list <Alumno> listaAuxiliar;



	listaAuxiliar=getAlumnos();
>>>>>>> 19544f3ea35e1dbf900de3518ace8437620fa429
	list <Alumno> :: iterator i;

	for(i=listaAlumnos_.begin(); i!=listaAlumnos_.end(); i++) {
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
<<<<<<< HEAD
	int contador=0;
=======

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
>>>>>>> 19544f3ea35e1dbf900de3518ace8437620fa429

	list <Alumno> :: iterator i;
	
	string apellidoAlumno=convertirMayuscula(a.getApellidos());
	cout<<"apellido que se busca: "<<apellidoAlumno<<endl;

<<<<<<< HEAD
	for(i=listaAlumnos_.begin(); i!=listaAlumnos_.end(); i++) {
		if((*i).getApellidos()==a.getApellidos()) {
=======
	for(i=listaAuxiliar.begin(); i!=listaAuxiliar.end(); i++) {
		
		string apellidoLista=convertirMayuscula((*i).getApellidos());

		cout<<"apellido en lista: "<<apellidoLista<<endl;

		if(apellidoAlumno==apellidoLista) {
>>>>>>> 19544f3ea35e1dbf900de3518ace8437620fa429
			(lista).push_back(*i);
			contador++;

		}

	
	}

	if (contador>0) {
		return true;
<<<<<<< HEAD
	} else return false;
=======
	}
	else{

		return false;



	}

	

>>>>>>> 19544f3ea35e1dbf900de3518ace8437620fa429
}

bool BD::buscarAlumno(list <Alumno> &lista,int equipo){

	int contador=0;
<<<<<<< HEAD
=======
	if(getNumeroAlumnos()==0) {
		cout << "No hay alumnos dados de alta en la base de datos" << endl;
		return false;
	}

	list <Alumno> listaAuxiliar;
>>>>>>> 19544f3ea35e1dbf900de3518ace8437620fa429



	listaAuxiliar=getAlumnos();
	list <Alumno> :: iterator i;

<<<<<<< HEAD
	for(i=listaAlumnos_.begin(); i!=listaAlumnos_.end(); i++) {
=======
	for(i=listaAuxiliar.begin(); i!=listaAuxiliar.end(); i++) {
		

>>>>>>> 19544f3ea35e1dbf900de3518ace8437620fa429
		if((*i).getEquipo()==equipo) {
			(lista).push_back(*i);
			contador++;

		}

<<<<<<< HEAD
	if (contador>0)
=======
	
	}

	if (contador>0){
>>>>>>> 19544f3ea35e1dbf900de3518ace8437620fa429
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
