## Diagrama de secuencia 02 buscar alumno

Comienza cuando se le pide al sistema que realice la búsqueda de un alumno. Primero comprueba que haya alumnos dados de alta. Aquí se inicia un bloque **ALT**.
* Si existen alumnos en la base de datos, se procede a la búsqueda del alumno, iniciándose un nuevo bloque **ALT**.
  * Si se encuentra el alumno, lo devuelve.
  * Si no se encuentra, devuelve un error.
* Si la base de datos se encuentra vacía, devuelve un error.
