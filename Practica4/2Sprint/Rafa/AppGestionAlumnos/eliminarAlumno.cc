// funcion eliminar alumno
// clase BD

#include "BD.h"
#include "Alumno.h"
#include <iostream>
#include <string>

using namespace std;

/* Primero un switch para elegir si buscar por dni o apellidos
Luego busco y recorro la lista en el propio buscarAlumno
Si encontrado=1, habré encontrado al alumno y lo elimino haciendo popback

