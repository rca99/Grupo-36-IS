#include <iostream>
#include "Alumno.h"
#include "BD.h"
#include <string>

using namespace std;

	Alumno::Alumno(string nif, string nom, string ape, string fecha, string email, string dom, int tlf, int cur, int calf, int eqp, bool lid){
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
	};

	Alumno::Alumno(datosAlumno datos){

		nombre_=datos.nombre;
	};

	Alumno::Alumno(){

	};



