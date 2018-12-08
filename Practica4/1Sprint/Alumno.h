


#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>

using namespace std;

	class Alumno {

	private:

		//string dni_, nombre_, apellidos_, fecha_nacimiento_, email_corporativo_, domicilio_;
		//int telefono_, curso_, nota_, equipo_;
		//bool lider_;
		string nombre_, apellidos_;
		int edad;

	public:

		//Alumno(string nif="", string nom="", string ape="", string fecha="", string email="", string dom="", int tlf, int cur, int calf, int eqp, bool lid);
		Alumno(string nombre="", string apellidos=""){
			nombre_=nombre;
			apellidos_=apellidos;
		};
		//inline  string getDNI() const {return dni_;}
		//inline void setDNI(string dni) {dni_=dni;}

		inline  string getNombre() const {return nombre_;}
		inline void setNombre(string nombre){nombre_=nombre;}

		inline string getApellidos() const {return apellidos_;}
		inline void setApellidos(string ape) {apellidos_=ape;}
		/*
		inline string getFecha_nacimiento() const {return fecha_nacimiento_;}
		inline void setFecha_nacimiento(string fecha) {fecha_nacimiento_=fecha;}

		inline int getTelefono() const {return telefono_;}
		inline void setTelefono(int tlf) {telefono_=tlf;}

		inline string getEmail_corporativo() const {return email_corporativo_;}
		inline void setEmail_corporativo(string email) {email_corporativo_=email;}

		inline string getDomicilio() const {return domicilio_;}
		inline void setDomicilio(string dom) {domicilio_=dom;}

		inline int getCurso() const {return curso_;}
		inline void setCurso(int cur) {curso_=cur;}

		inline int getNota() const {return nota_;}
		inline void setNota(int calf) {nota_=calf;}

		inline int getEquipo() const {return equipo_;}
		inline void setEquipo(int eqp) {equipo_=eqp;}

		inline bool getLider() const {return lider_;}
		bool setLider(bool lid);
		*/
	};

#endif