
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

// firefox ../AppGestionAlumnos/acceso.html


int main(){

	FILE *fp;

	BD b;
	Alumno a1, a2, a3, a4;

	/*a1.setNombre("Rodolfo Mateo");
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
	*/

	/* Abrir archivo para escritura */
	fp = fopen("acceso.html", "w");
	fprintf(fp, "<html> \n");
	fprintf(fp, "<head> \n");
	fprintf(fp, "<title>INSTRUCCIONES ACCESO</title>\n");
	fprintf(fp, "<head> \n");
	fprintf(fp, "<body> \n");
	fprintf(fp, "<p><a href='https://www.uco.es/eps/nodeorder/term/29' target='_blank'><img alt='' src='https://www.uco.es/eps/sites/default/files/info_general/logos/escudo_informatica.jpg' style='width: 150px; height: 150px;'' /></a></p>");
	fprintf(fp, "<p><span style='color:#003399;''><span style='font-family:comic sans ms,cursive;''><span style='font-size:24px;''><strong>GestionAlumnos&nbsp; - Grupo 36 IS</strong></span></span></span></p>");
	
	fprintf(fp, "<p><strong>Alumnos Integrantes Grupo 36</strong></p>");

	fprintf(fp, "<p style='margin-left: 40px;'><span style='font-size:16px;'><span style='color:#003399;''>Rafael Cantero Alen</span>- Representante</p>");
	fprintf(fp, "<p style='margin-left: 40px;'><span style='font-size:16px;'>Carlos Freire Caballero</span></p>");
	fprintf(fp, "<p style='margin-left: 40px;'><span style='font-size:16px;'>Fernando Herrera Poch</span></p>");
	fprintf(fp, "<p><a href='https://github.com/rca99/Grupo-36-IS' onclick='window.open(this.href, '', 'resizable=no,status=no,location=no,toolbar=no,menubar=no,fullscreen=yes,scrollbars=no,dependent=no'); return false;'><strong>Repositorio Git</strong></a></p>");
	fprintf(fp, "<p>&nbsp;</p>");

	fprintf(fp, "<p><strong>Instrucciones</strong></p>");

	fprintf(fp, "<p>A continuaci&oacute;n se presentan las instrucciones para ejecutar y usar la aplicaci&oacute;n</p>");

	fprintf(fp, "<ul>");
		fprintf(fp, "<li>El acceso a la aplicaci&oacute;n se realiza con sus credenciales de acceso normales a la Universidad</li>");
		fprintf(fp, "<li>Tiene <strong>tres</strong> intentos de acceso</li>");
		fprintf(fp, "<li>A continuaci&oacute;n le recordamos los usuarios y una pista de la contrase&ntilde;a para acceder a la aplicaci&oacute;n</li><br />");
	fprintf(fp, "<ul>");

	fprintf(fp, "<table border='1' cellpadding='1' cellspacing='1' style='width:500px;'>");
		fprintf(fp, "<tbody>");
			fprintf(fp, "<tr>");
				fprintf(fp, "<td><strong>AProfesor</strong></td>");
				fprintf(fp, "<td><strong>AUsuario</strong></td>");
				fprintf(fp, "<td><strong>ARol</strong></td>");
				fprintf(fp, "<td><strong>AClave</strong></td>");
			fprintf(fp, "</tr>");

			fprintf(fp, "<tr>");
				fprintf(fp, "<td>David Guijo</td>");
				fprintf(fp, "<td>dguijo</td>");
				fprintf(fp, "<td>Ayudante</td>");
				fprintf(fp, "<td>1***</td>");
			fprintf(fp, "</tr>");

			fprintf(fp, "<tr>");
				fprintf(fp, "<td>Antonio Dur&aacute;n<</td>");
				fprintf(fp, "<td>aduran</td>");
				fprintf(fp, "<td>Ayudante</td>");
				fprintf(fp, "<td>2***</td>");
			fprintf(fp, "</tr>");

			fprintf(fp, "<tr>");
				fprintf(fp, "<td>Isabel</td>");
				fprintf(fp, "<td>isa</td>");
				fprintf(fp, "<td>Coordinador</td>");
				fprintf(fp, "<td>0***</td>");
			fprintf(fp, "</tr>");

		fprintf(fp, "</tbody>");
	fprintf(fp, "</table>\n");
	fprintf(fp, "<br />");
	
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
	printf("Se ha creado el archivo: acceso.html \n");
	system("chmod +x abrirWeb.sh");
	system("./abrirWeb.sh");

	
	
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