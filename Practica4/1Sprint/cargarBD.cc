
#include "BD.h" //para incluir la lista de alumnos y funciones BD 
//#include "Profesor.h"//para incluir puntero a base de datos
#include "Alumno.h"
#include "Profesor.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void reservaMemoriaEstructura(datosAlumno **libreria, int registros);
void contarRegistros(char *nombreFicheroBin, int *registros);




bool BD::cargarBD(){

	char NombreFicheroBin[50];
	string nameBD=getNombreFichero()+".bin";
	strcpy(NombreFicheroBin, nameBD.c_str());
	
	datosAlumno *datosFicheroBinario;
	listaAlumnos_.clear();
	string nombref;
	Profesor p;

	FILE *fichero;

	fichero=fopen(NombreFicheroBin, "rb");

	if (fichero==NULL){
		fprintf(stderr, "\nError al abrir el fichero" );
	}



	int registros=0;
	contarRegistros(NombreFicheroBin, &registros);

	cout<<"registros fichero: "<<registros<<endl;
	reservaMemoriaEstructura(&datosFicheroBinario, registros);

	
	
	


	fread(datosFicheroBinario, sizeof(datosAlumno), 1, fichero);
	while(!feof(fichero)){
		
		fread(datosFicheroBinario, sizeof(datosAlumno), 1, fichero);
		
	}
	
	for (int i = 0; i < registros; ++i)
	{
		cout<<datosFicheroBinario[i].nombre;
	}

	fclose(fichero);
	
	list <Alumno> listaBD;
	//list <Alumno>::iterator i; 
	

	
 
      
  }




void reservaMemoriaEstructura(datosAlumno **libreria, int registros){

	*libreria=(datosAlumno*)malloc(registros*sizeof(datosAlumno));

	if (libreria==NULL){
		printf("error reserva memoria\n");
	}
}


void contarRegistros(char *nombreFicheroBin, int *registros){

	FILE *fichero;

	fichero=fopen(nombreFicheroBin, "rb");


	fseek(fichero, 0L, SEEK_END);

	*registros=ftell(fichero)/sizeof(datosAlumno);

	fclose(fichero);

}
















  /*


	ifstream ifile(nombreFichero_, ios::binary);


	
	if( ifile.is_open() ){
		ifile.read((char*)&datosFicheroBinario,sizeof(datosAlumno) );

		while(!ifile.eof() ){
			
			ifile.read((char*)&datosFicheroBinario,sizeof(datosAlumno) );
			
		}
	}

	
	for (i=listaBD.begin(); i!=listaBD.end();i++){
		
		cout<<"nombre: "<<i->getNombre()<<endl;
	}

	cout<<"Tamaño Base de Datos: "<<listaBD.size()<<endl;
	
	



	return 1;
	
	
	

}


*/
