
## Insertar Alumno

**ID: XXX**
**Breve descripcion: El profesor podrá introducir los datos de un alumno** 

**Actores principales: Profesor**

**Actores segundarios: Alumno**

### Precondiciones

* El alumno a insertar no puede existir en el sistema.
* El alumno no es lider de otro grupo.

### Flujo principal

1 El caso de uso comienza cuando el usuario necesita introducir un alumno.
2 El sistema recoge los datos obligatorios de un alumno.
3 Se comprobara que el alumno no existe en el sistema.
4 El sistema comprueba que el alumno no pertenece a otro grupo

### Postcondiciones

A El sistema actualiza el sistema con la introduccion del alumno
B El sistema muestra un mensaje indicando que la insercion ha sido correcta mostrando el nombre y dni del alumno introducido
 

## Flujos alternativos

2.1 Si no introduce los datos obligatorios muestra un mensaje de error, indicando los datos que faltan por introducir
3.1 El sistema no permite la insercion de un alumno que ya existe en el sistema
