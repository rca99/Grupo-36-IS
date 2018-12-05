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

		inline  string getDNI() const {return dni_;};
		inline void setDNI(string dni) {dni_=dni;};

		inline  string getNombre() const {return nombre_;};
		inline void setNombre(string nombre){nombre_=nombre;};

		inline string getApellidos() const {return ape;};
		inline void setApellidos(string ape) {apellidos_=ape;};

		inline string getFecha_nacimiento() const {return fecha;};
		inline void setFecha_nacimiento(string fecha) {fecha_nacimiento_=fecha;};

		inline int getTelefono() const {return tlf;};
		inline void setTelefono(int tlf) {telefono_=tlf;};

		inline string getEmail_corporativo() const {return email;};
		inline void setEmail_corporativo(string email) {email_corporativo_=email;};

		inline string getDomicilio() const {return dom;};
		inline void setDomicilio(string dom) {domicilio_=dom;};

		inline int getCurso() const {return cur;};
		inline void setCurso(int cur) {curso_=cur;};

		inline int getNota() const {return calf;};
		inline void setNota(int calf) {nota_=calf;};

		inline int getEquipo() const {return eqp;};
		inline void setEquipo(int eqp) {equipo_=eqp;};

		inline bool getLider() const {return lid;};
		bool setLider(bool lid);
	};

#endif