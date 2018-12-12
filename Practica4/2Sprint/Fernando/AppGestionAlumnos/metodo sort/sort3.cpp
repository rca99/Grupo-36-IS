// Standard Template Library example using a class.
	 

	#include <iostream>

	#include <list>

	using namespace std;

	 

	// The List STL template requires overloading operators =, == and <.

	 

	class Alumno

	{

	   friend ostream &operator<<(ostream &, const Alumno &);

	 

	   public:

	      int x;

	      int y;

	      float z;

	      string nombre;
	      string apellido;


	 

	      Alumno();

	      Alumno(const Alumno &);

	      ~Alumno(){};

	      Alumno &operator=(const Alumno &rhs);

	      int operator==(const Alumno &rhs) const;

	      int operator<(const Alumno &rhs) const;

	};

	 

	Alumno::Alumno()   // Constructor

	{

	   x = 0;

	   y = 0;

	   z = 0;

	}

	 

	Alumno::Alumno(const Alumno &copyin)   // Copy constructor to handle pass by value.

	{                            

	   x = copyin.x;

	   y = copyin.y;

	   z = copyin.z;

	   nombre=copyin.nombre;

	   apellido=copyin.apellido;

	}

	 
	/*
	ostream &operator<<(ostream &output, const Alumno &Alumno)

	{

	   output << Alumno.x << ' ' << Alumno.y << ' ' << Alumno.z << Alumno.nombre<<endl;

	   return output;

	}
	*/

	 

	Alumno& Alumno::operator=(const Alumno &rhs)

	{

	   this->x = rhs.x;

	   this->y = rhs.y;

	   this->z = rhs.z;

	   return *this;

	}

	 

	int Alumno::operator==(const Alumno &rhs) const

	{

	   if( this->x != rhs.x) return 0;

	   if( this->y != rhs.y) return 0;

	   if( this->z != rhs.z) return 0;

	   return 1;

	}

	 

	// This function is required for built-in STL list functions like sort
	/*
	int Alumno::operator<(const Alumno &rhs) const

	{

	   if( this->x == rhs.x && this->y == rhs.y && this->z < rhs.z) return 1;

	   if( this->x == rhs.x && this->y < rhs.y) return 1;

	   if( this->x < rhs.x ) return 1;

	   return 0;

	}
	*/

	int Alumno::operator<(const Alumno &rhs) const

	{

	   if( this->nombre == rhs.nombre && this->apellido == rhs.apellido) return 1;

	   if( this->nombre == rhs.nombre && this->apellido < rhs.apellido) return 1;

	   if( this->nombre < rhs.nombre ) return 1;

	   return 0;

	}

	int main(int argc, char const *argv[])
	{
		/* code */
		return 0;
	}