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
	}


	bool Alumno::setLider(bool lider) {

	// DEBE recibir la BD ??
	BD BDaux;
	// buscarAlumno -- Funcion aun sin definir
	BD.buscarAlumno(getEquipo());

	// Comprueba que los alumnos del grupo no sean lideres
	// Grupo de alumnos. ARRAY ??
	for(int i=0; i<3; i++) {
		if(alumnosdelgrupo[i].getLider()==1)
			return false; 
			// Si alguno es lider, no se puede asignar un nuevo lider
	}

	// Si sale del for, significa que no hay lideres
	lider_=true;
	return true; // Lider cambiado correctamente
}