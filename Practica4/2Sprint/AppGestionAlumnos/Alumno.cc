#include <iostream>
#include "Alumno.h"
#include "BD.h"
#include <string>
#include <cstring>

using namespace std;

void inicializardatos(datosAlumno &datos) {
	strcpy(datos.nombre, "");
	strcpy(datos.dni, "");
	strcpy(datos.apellidos, "");
	strcpy(datos.fecha_nacimiento, "");
	strcpy(datos.email_corporativo, "");
	strcpy(datos.domicilio, "");
	datos.curso=-1;
	datos.telefono=-1;
	datos.nota=-1;
	datos.equipo=-1;
}

Alumno::Alumno(string nif, string nom, string ape, string fecha, string email, string dom, int tlf, int cur, int calf, int eqp, bool lid=0){
	dni_=nif;
	nombre_=nom;
	apellidos_=ape;
	fecha_nacimiento_=fecha;
	email_corporativo_=email;
	domicilio_=dom;
	telefono_=tlf;
	curso_=cur;
	nota_=calf;
	equipo_=eqp;
	lider_=lid;
}

Alumno::Alumno(datosAlumno datos){

	dni_=datos.dni;
	nombre_=datos.nombre;
	apellidos_=datos.apellidos;
	fecha_nacimiento_=datos.fecha_nacimiento;
	email_corporativo_=datos.email_corporativo;
	domicilio_=datos.domicilio;
	telefono_=datos.telefono;
	curso_=datos.curso;
	nota_=datos.nota;
	equipo_=datos.equipo;
	lider_=0;
}

Alumno::Alumno(){
	lider_=false;
}
