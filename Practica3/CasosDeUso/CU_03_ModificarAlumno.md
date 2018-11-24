## Modificar Alumno

**ID: 3**

**Breve descripción: El profesor podrá modificar los datos de un alumno.** 

**Actores principales: Profesor.**

**Actores segundarios: Alumno.**

### Precondiciones

* El alumno a modificar debe estar almacenado en el sistema.

### Flujo principal

1 El caso de uso da comienzo cuando el profesor necesita modificar un alumno.

2 El sistema pregunta si se desea buscar por DNI o por apellido.

3 El sistema busca al alumno en cuestión por DNI o por apellido.

4 El sistema muestra los datos del alumno, dando la opción de modificar aquellos que se deseen.

4.1 Si se mofica el campo de líder, el sistema comprobará que el grupo al que pertenece el alumno tenga líder o no.

### Postcondiciones

**A** El sistema se actualiza con la nueva información del alumno.

**B** El sistema muestra un mensaje indicando que la modificación ha sido correcta.
 

## Flujos alternativos

3.1 El sistema no permite la modificación de un alumno que no se encuentra almacenado en la aplicación.

4.1 Si se desean dejar en blanco alguno de los campos obligatorios, el sistema no permitirá guardar los cambios volviendo al punto 4 del proceso.

4.1.1 Si se desea modificar el campo líder, indicando que es líder de un grupo que ya lo tiene, muestra un  mensaje de error.
