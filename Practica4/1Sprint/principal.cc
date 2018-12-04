

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

	system("git pull origin master");
	getchar();

	system("git status");
	system("git add .");
	system("git commit -am 'actualización'");
	system("git push -u origin master");

	

	return 0;
}