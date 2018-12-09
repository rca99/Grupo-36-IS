
#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>



using namespace std;

typedef struct  {
	string dni, apellidos, fecha_nacimiento, email_corporativo, domicilio;
	char nombre[40];
	int telefono, curso, nota, equipo;
	bool lider;
}datosAlumno;

	class Alumno {

	private:


		string dni_, nombre_, apellidos_, fecha_nacimiento_, email_corporativo_, domicilio_;
		int telefono_, curso_, nota_, equipo_;
		bool lider_;

	public:

		Alumno(string nif, string nom, string ape, string fecha, string email, string dom, int tlf, int cur, int calf, int eqp, bool lid);
		Alumno(datosAlumno datos);
		Alumno();
		
		inline  string getDNI() const {return dni_;}
		inline void setDNI(string dni) {dni_=dni;}

		inline  string getNombre() const {return nombre_;}
		inline void setNombre(string nombre){nombre_=nombre;}

		inline string getApellidos() const {return apellidos_;}
		inline void setApellidos(string ape) {apellidos_=ape;}


		inline  int getCurso() const {return curso_;}
		inline void setCurso(int curso) {curso_=curso;}


};

#endif