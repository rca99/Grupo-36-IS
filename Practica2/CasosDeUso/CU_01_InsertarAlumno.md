
## Insertar Alumno

**ID: XXX**
**Breve descripcion: El profesorpodra introducir los datos de un alumno** 

**Actores principales: Profesor**

**Actores segundarios: Alumno**

### Precondiciones

* El alumno a insertar no puede existir en el sistema.
* El alumno no es lider de otro grupo.
* El numero de alumnos del sistema sera menor a 150

### Flujo principal

1 El caso de uso comienza cuando el usuario necesita introducir un alumno.

2 El sistema comprueba el numero de alumnos que existen en el sistema. 

3 El sistema recoge los datos obligatorios de un alumno.

4 Se comprobara que el alumno no existe en el sistema.

5 El sistema comprueba que el grupo que ha elegido el alumno tiene ya lider.

### Postcondiciones

**A** El sistema se actualiza con la introduccion del alumno

**B** El sistema muestra un mensaje indicando que la insercion ha sido correcta mostrando el nombre y dni del alumno introducido
 

## Flujos alternativos

2.1 Si en el sistema hay 150 alumnos dados de alta, se muestra un error indicando que no se puede introducir el alumno.

3.1 Si no introduce los datos obligatorios muestra un mensaje de error, indicando los datos que faltan por introducir

4.1 El sistema no permite la insercion de un alumno que ya existe en el sistema y muestra un mensaje de error.

5.1 El sistema no permite indicar que un alumno es lider de un grupo que ya tenga lider.
