

#include "BD.h"
#include <stdio.h>//para system
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[])
{

	BD b;
	b.guardarBD();	/* code */
	b.cargarBD();

	system("./pruebaScript.sh");



	

	return 0;
}