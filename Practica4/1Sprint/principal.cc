

#include "BD.h"
#include <stdio.h>//para system
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{

	BD b;
	b.guardarBD();	/* code */
	b.cargarBD();
	getchar();
	system ("git status");

	b.cargarBD();

	system("sudo ScriptCopiaExterna.sh");

	
	

	return 0;
}