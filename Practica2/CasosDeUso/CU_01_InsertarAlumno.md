
## Insertar Alumno

**ID: 1**

**Breve descripcion: El profesor podra introducir los datos de un alumno** 

**Actores principales: Profesor**

**Actores segundarios: Alumno**

### Precondiciones

* El alumno a insertar no puede existir en el sistema.
* El alumno no es lider de otro grupo.
* El numero de alumnos del sistema sera menor a 150.

### Flujo principal

1 El caso de uso comienza cuando el usuario necesita introducir un alumno.

2 El sistema comprueba el numero de alumnos que existen en el sistema. 

3 El sistema recoge los datos obligatorios de un alumno y aquellos no obligatorios que el profesor desee introducir.

3.1 Los datos de nombre, apellidos, grupo y DNI serán convertidos a mayúscula por el sistema.

4 Se comprobara que el alumno no existe en el sistema.

5 El sistema comprueba que el grupo que ha elegido el alumno tiene ya lider.

6 El sistema introduce el alumno.

7 El sistema comprueba la insercion del alumno en el sistema.

### Postcondiciones

**A** El sistema se actualiza con la introduccion del alumno

**B** El sistema muestra un mensaje indicando que la insercion ha sido correcta mostrando el nombre y dni del alumno introducido

**C** El nombre del grupo, nombre del alumno, DNI del alumno, 
 

## Flujos alternativos

2.1 Si en el sistema hay 150 alumnos dados de alta, se muestra un error indicando que no se puede introducir el alumno.

3.1 Si no introduce los datos obligatorios muestra un mensaje de error, indicando los datos que faltan por introducir.

3.2 Si el usuario introduce que un alumno es líder entonces deberá indicar obligatoriamente el grupo al que pertenece.

4.1 El sistema no permite la insercion de un alumno que ya existe en el sistema y muestra un mensaje de error.

5.1 El sistema no permite indicar que un alumno es lider de un grupo que ya tenga lider.

6.1 Si el sistema no ha podido realizar la insercion del alumno indica que esta no ha podido ser realizada e indicando que vuelva a realizarla.
