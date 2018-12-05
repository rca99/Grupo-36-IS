// Alumno.h
// Cabecera de la clase Alumno


#ifndef ALUMNO_H
#define ALUMNO_H



#include <string>

using namespace std;

class Alumno{

private:

	string DNI_, nombre_, apellidos_;
	string f_nacimiento, mailcorporativo_, domicilio_;
	int edad_, telefono_, curso_, nota_, equipo_;
	bool lider_;


public:
	Alumno(string DNI="", string nombre="",int edad=0){

		DNI_=DNI;
		nombre_=nombre;
		edad_=edad;
	};

	//Nombre
	inline void setNombre(string nombre){

		nombre_=nombre;
	};
	inline  string getNombre() const {return nombre_;};


	//DNI
	inline void setDNI(string DNI){

		DNI_=DNI;
	};
	inline  string getDNI() const {return DNI_;};


	//Edad
	inline void setEdad(int edad){

		edad_=edad;
	};
	inline  int getEdad() const {return edad_;};

	//Líder. Gestion de líderes.
	inline bool getLider() const {return lider_;}
	bool setLider(bool lider);

};

#endif