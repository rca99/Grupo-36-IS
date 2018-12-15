// Carlos Freire Caballero
// Clase : Alumno
// Funcion : setLider (Gestion de Lideres)

#include "BD.h"
#include "Alumno.h"

#include <list>

bool BD::gestionLideres(Alumno alumnox, string dni) {

	int myteam=alumnox.getEquipo();
	list <Alumno> grupo;

	// buscarAlumnoporGrupos
	buscarAlumnoEquipo(grupo, myteam);


	// Comprueba que los alumnos del grupo no sean lideres 
	list <Alumno> :: iterator i ; 

	for(i=grupo.begin(); i!=grupo.end(); i++) {
		if(((*i).getLider()==1) && ((*i).getDNI() != dni)) {
			return false;
		} // Si alguno es lider, no se puede asignar un nuevo lider
	}

	// Si sale del for, significa que no hay lideres
	return true;
}