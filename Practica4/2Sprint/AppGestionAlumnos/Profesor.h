#ifndef PROFESOR_H
#define PROFESOR_H
#include <string>
#include "Alumno.h"

using namespace std;

struct Credencialesprofesor{

	char usuario[30];
	char nombreCompleto[50];
	char contrasenya[5];
	char rol[20];
};


	class Profesor {

	private:
		
		string usuario_, rol_;
		int *ficheroBD_;// hay que modificarlo en el diagrama de clases. Al final no lo voy a necesitar

	public:

		Profesor(){};
		//int login(string usuario, string contrasenya);
		Credencialesprofesor registro(string usuario, string contrasenya);
		inline string getUsuario() const {return usuario_;}
		void setUsuario(string usuario){usuario_=usuario;}
		inline string getRol() const {return rol_;}
		void setRol(string rol){rol_=rol;}
		inline int *getFicheroBD() const {return ficheroBD_;}	// hay que modificarlo en el diagrama de clases
		void setFicheroBD(datosAlumno BD){ficheroBD_=(int*)&BD;} // hay que modificarlo en el diagrama de clases
		bool credencialesBin();
		//bool cargarCredenciales(string usuarioAcceso, string contrasenyaAcceso);
		
	};

#endif