#ifndef PROFESOR_H
#define PROFESOR_H
#include <string>

using namespace std;

	class Profesor {

	private:
		
		string usuario_, rol_;
		int *ficheroBD_;			// hay que modificarlo en el diagrama de clases

	public:

		Profesor();
		int login(string usuario, string contrasenya);
		void registro(string usuario, string contrasenya);
		inline string getUsuario() const {return usuario_;}
		void setUsuario();
		inline string getRol() const {return rol_;}
		void setRol();
		inline int *getFicheroBD() const {return ficheroBD_;}	// hay que modificarlo en el diagrama de clases
		void setFicheroBD(int *nuevofichero);		// hay que modificarlo en el diagrama de clases
	};

#endif