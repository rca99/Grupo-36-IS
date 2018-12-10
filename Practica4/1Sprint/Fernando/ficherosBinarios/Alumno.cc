#include <iostream>
#include "Alumno.h"
#include "BD.h"
#include <string>

using namespace std;

	Alumno::Alumno(string nif, string nom, string ape, string fecha, string email, string dom, int tlf, int cur, int calf, int eqp, bool lid){
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
		lider_=datos.lider;
	};

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
		lider_=datos.lider;
	
	};

	Alumno::Alumno(){

	};



