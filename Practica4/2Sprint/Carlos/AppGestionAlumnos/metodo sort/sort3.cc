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
	ostream &operator<<(ostream &output, const Alumno &Alumno)

	{

	   output << Alumno.x << ' ' << Alumno.y << ' ' << Alumno.z << Alumno.nombre<<Alumno.apellido<<endl;

	   return output;

	}
	
	 

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
		list<Alumno> L;

	   Alumno a1 ;

	 

	   a1.x=7;

	   a1.y=2;

	   a1.z=4.2355;

	   a1.nombre="Fernando";
	   a1.apellido="Herrera";



	   L.push_back(a1);  // Insert a new element at the end

	 
		 Alumno a2 ;

	 

	   a2.x=7;

	   a2.y=2;

	   a2.z=4.2355;

	   a2.nombre="Fernando";
	   a2.apellido="Ruiz";



	   L.push_back(a2);  // Object passed by value. Uses default member-wise

	                        // copy constructor

	 
	 

	   list<Alumno>::iterator i;

	 

	   cout << "Print x: " << endl;

	   for(i=L.begin(); i != L.end(); ++i) cout << (*i).nombre << " "; // print member

	   cout << endl << endl;     

	 

	   cout << "Print x, y, z: " << endl;

	   for(i=L.begin(); i != L.end(); ++i) cout << *i; // print with overloaded operator

	   cout << endl;

	 

	   cout << "Sorted: " << endl;

	   L.sort();

	   for(i=L.begin(); i != L.end(); ++i) cout << *i; // print with overloaded operator

	   cout << endl;

	 

	   cout << "Iterate in Reverse: " << endl;

	   list<Alumno>::reverse_iterator ri;

	   for(ri=L.rbegin(); ri != L.rend(); ++ri) cout << *ri; // print with overloaded operator

	   cout << endl;

	 

	   cout << "Remove where x=5: " << endl;

	   for(i=L.begin(); i != L.end(); )       // Don't increment iterator here

	       if( (*i).x == 5 ) i = L.erase(i);  // Returns iterator to the next item in the list

	       else ++i;                          // Increment iterator here

	   for(i=L.begin(); i != L.end(); ++i) cout << *i; // print with overloaded operator

	   cout << endl;

	 

	
		return 0;
	}