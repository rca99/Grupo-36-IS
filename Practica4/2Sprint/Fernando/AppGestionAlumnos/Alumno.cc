#include <iostream>
#include "Alumno.h"
#include "BD.h"
#include <string>

using namespace std;

	Alumno::Alumno(string nif="", string nom="", string ape="", string fecha="", string email="", string dom="", int tlf=0, int cur=0, int calf=0, int eqp=0, bool lid=0){
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
		lider_=false;
	
	};

	Alumno::Alumno(){
		dni_="";
		nombre_="";
		apellidos_="";
		fecha_nacimiento_="";
		email_corporativo_="";
		domicilio_="";
		telefono_=0;
		curso_=0;
		nota_=0;
		equipo_=0;
		lider_=false;
	};


	bool Alumno::alumnoLider(){

		BD miDataBase;

			/*
		// DEBE recibir la BD ??
		BD BDaux;
		// buscarAlumno -- Funcion aun sin definir
		BDaux.buscarAlumno(getEquipo());

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
		*/

		return 1;
	}
	


/*

int Alumno::operator<(const Alumno &rhs) const{

	   if( this->nombre_ <rhs.nombre_) return 1;


	   return 0;

}
*/

int Alumno::operator<(const Alumno &rhs) const	{

	   if( this->nombre_ == rhs.nombre_ && this->apellidos_ == rhs.apellidos_) return 1;

	   if( this->nombre_ == rhs.nombre_ && this->apellidos_ < rhs.apellidos_) return 1;

	   if( this->nombre_ < rhs.nombre_ ) return 1;

	   return 0;

}


