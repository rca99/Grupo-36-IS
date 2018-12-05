// Alumno.cc
// Cuerpo de la clase alumno
#include "Alumno.h"
#include "BD.h"


bool Alumno::setLider(bool lider, BD basedatos) {

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





