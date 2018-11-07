
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

2 El sistema comprueba el número de alumnos que existen en el sistema. 

3 El sistema recoge los datos obligatorios de un alumno y aquellos no obligatorios que el profesor desee introducir.

4 Se comprobará que el alumno no existe ya en el sistema.

5 El sistema comprueba si el grupo que ha elegido el alumno tiene ya lider.

6 El sistema introduce el alumno.

7 El sistema comprueba la inserción del alumno en el sistema.

### Postcondiciones

**A** El sistema se actualiza con la introducción del alumno.

**B** El sistema muestra un mensaje indicando que la inserción ha sido correcta mostrando el nombre y dni del alumno introducido.
 
## Flujos alternativos

2.1 Si en el sistema hay 150 alumnos dados de alta, se muestra un error indicando que no se puede introducir el alumno.

3.1 Si no introduce los datos obligatorios muestra un mensaje de error, indicando los datos que faltan por introducir.

3.2 Por defecto, el campo líder valdrá NO.

3.3 Si el usuario introduce que un alumno es líder entonces deberá indicar obligatoriamente el grupo al que pertenece.

4.1 El sistema no permite la insercioón de un alumno que ya existe en el sistema y muestra un mensaje de error.

5.1 El sistema no permite indicar que un alumno es líder de un grupo que ya tenga líder.

6.1 Si el sistema no ha podido realizar la inserción del alumno indica que esta no ha podido ser realizada y que vuelva a intentarlo.
