## Modificar Alumno

**ID: 3**
**Breve descripcion: El profesor podrá introducir los datos de un alumno** 

**Actores principales: Profesor**

**Actores segundarios: Alumno**

### Precondiciones

* El alumno a modificar debe estar almacenado en el sistema

### Flujo principal

1 El caso de uso da comienzo cuando el profesor necesita modificar un alumno

2 El sistema pregunta si se desea buscar por DNI o por apellido

3 El sistema busca al alumno en cuestión por DNI o por apellido

4 El sistema muestra campo a campo los datos del alumno, dando la opción de modificarlo si se desea

### Postcondiciones

A El sistema actualiza el sistema con la nueva información del alumno
B El sistema muestra un mensaje indicando que la modificación ha sido correcta
 

## Flujos alternativos

2.1 Si al buscar el alumno por apellido el sistema detecta más de un estudiante con dicho apellido se pedirá el DNI para filtrar la búsqueda

3.1 El sistema no permite la modificación de un alumno que no se encuentra almacenado en la aplicación

4.1 Se comprobará que el campo modificado cumple el formato asociado a su campo, mostrando un mensaje de error en caso de qué no sea así. 
