

#include <iostream>
#include <string>

#include <iomanip>//formato cout
#include <stdio.h>
#include "Alumno.h"
//#include "Profesor.h"
//#include "BD.h"
#include "consoleLinux.h"
#include "Alumno.h"
#include "BD.h"

int main(){

	FILE *fp;

	BD b;
	Alumno a1, a2, a3, a4;

	a1.setNombre("Rodolfo Mateo");
	a2.setNombre("Rodolfo Inurria");
	a3.setNombre("Rodolfo Jaén");
	a4.setNombre("Rodolfo");
	
	b.introducirAlumno(a1);
	b.addNumeroAlumnos();
	b.introducirAlumno(a2);
	b.addNumeroAlumnos();
	b.introducirAlumno(a3);
	b.addNumeroAlumnos();
	b.introducirAlumno(a4);
	b.addNumeroAlumnos();
	cout<<BOLD_ON<<COLOR_YELLOW<<BLINK<<b.getNumeroAlumnos()<<RESET<<endl;


	/* Abrir archivo para escritura */
	fp = fopen("prueba.html", "w");
	fprintf(fp, "<html> \n");
	fprintf(fp, "<head> \n");
	fprintf(fp, "<title>LISTA DE ALUMNOS DE LA ASIGNATURA</title>\n");
	fprintf(fp, "<head> \n");
	fprintf(fp, "<body> \n");
	fprintf(fp, "<FONT FACE='Courier'><FONT COLOR='red'>Esta es la primera linea de texto. </FONT>\n");
	fprintf(fp, "<CENTER>Esta es la segunda"
	"linea</CENTER> \n");
	fprintf(fp, "Y esta es la <B>tercera linea de texto.</B> \n");

	list <Alumno> Auxiliar;

	Auxiliar=b.getAlumnos();
	/*
	list <Alumno>::iterator i;

	for ( i=Auxiliar.begin(); i !=Auxiliar.end(); ++i){
	
		fprintf(fp, i->getNombre());

	}
	*/


	fprintf(fp, "<body> \n");
	fprintf(fp, "<html> \n");

	/* Cerrar el archivo antes de terminar el programa */
	fclose(fp);
	printf("Se ha creado el archivo: prueba.html \n");
	return 0;

}
/*
<html> 
<head>
<title>El primer documento HTML</title>
</head> 
<body>
<p>El lenguaje HTML es <strong>tan sencillo</strong> que
practicamente se entiende sin estudiar el significado
de sus etiquetas principales.</p>
</body> 
</html>
*/