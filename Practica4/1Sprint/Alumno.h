
#ifndef ALUMNO_H
#define ALUMNO_H



#include <string>

using namespace std;

	class Alumno {

	private:


		string dni_, nombre_, apellidos_, fecha_nacimiento_, email_corporativo_, domicilio_;
		int telefono_, curso_, nota_, equipo_;
		bool lider_;

	public:

		Alumno(string nif, string nom, string ape, string fecha, string email, string dom, int tlf, int cur, int calf, int eqp, bool lid);
		Alumno();
		
		inline  string getDNI() const {return dni_;}
		inline void setDNI(string dni) {dni_=dni;}

		inline  string getNombre() const {return nombre_;}
		inline void setNombre(string nombre){nombre_=nombre;}

		inline string getApellidos() const {return apellidos_;}
		inline void setApellidos(string ape) {apellidos_=ape;}



};

#endif