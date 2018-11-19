
## Insertar Alumno

**ID: 1**

**Breve descripción: El profesor podrá introducir los datos de un alumno.** 

**Actores principales: Profesor.**

**Actores segundarios: Alumno.**

### Precondiciones

* El alumno a insertar no puede existir en el sistema.
* El número de alumnos del sistema será menor a 150.

### Flujo principal

1 El caso de uso comienza cuando el usuario necesita introducir un alumno.

2

3 El sistema comprueba el número de alumnos que existen en el sistema. 

4 El sistema recoge los datos obligatorios de un alumno y aquellos no obligatorios que el profesor desee introducir.

4.1 Los datos de nombre, apellidos y DNI serán convertidos a mayúsculas por el sistema.

5 Se comprobará que el alumno no existe ya en el sistema.

6 El sistema comprueba si el grupo que ha elegido el alumno tiene ya lider.

7 El sistema introduce el alumno.

8 El sistema comprueba la inserción del alumno en el sistema.

### Postcondiciones

**A** El sistema se actualiza con la introducción del alumno.

**B** El sistema muestra un mensaje indicando que la inserción ha sido correcta mostrando el nombre y dni del alumno introducido.
 
## Flujos alternativos

2.1 Si en el sistema hay 150 alumnos dados de alta, se muestra un error indicando que no se puede introducir el alumno.

4.1 Si no introduce los datos obligatorios muestra un mensaje de error, indicando los datos que faltan por introducir.

4.2 Por defecto, el campo líder valdrá NO.

4.3 Si el usuario introduce que un alumno es líder entonces deberá indicar obligatoriamente el grupo al que pertenece.

5.1 El sistema no permite la insercioón de un alumno que ya existe en el sistema y muestra un mensaje de error.

6.1 El sistema no permite indicar que un alumno es líder de un grupo que ya tenga líder.

7.1 Si el sistema no ha podido realizar la inserción del alumno indica que esta no ha podido ser realizada y que vuelva a intentarlo.
