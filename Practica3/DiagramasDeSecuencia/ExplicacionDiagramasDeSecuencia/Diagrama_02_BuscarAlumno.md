## Diagrama de secuencia 02 buscar alumno

Comienza cuando se le pide al sistema que realice la búsqueda de un alumno. Primero comprueba que haya alumnos dados de alta. Aquí se inicia un bloque **ALT**.
* Si existen alumnos en la base de datos, se procede a la búsqueda del alumno, iniciándose un nuevo bloque **OPT**.

 * Búsqueda por DNI
 * Búsqueda por apellidos.
	Si encuentra varios alumnos con el mismo apellido se abre un nuevo bloque **ALT** en el que se iniciará una nueva búsqueda por DNI.
 * Búsqueda por Grupo 

  * Si se encuentra el alumno, lo devuelve.
  * Si no se encuentra, devuelve un error.

* Si la base de datos se encuentra vacía, devuelve un error.
