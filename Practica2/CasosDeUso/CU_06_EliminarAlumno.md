## Eliminar Alumno

**ID: 6**

**Breve descripcion: El profesor podrá eliminar un alumno de la base de datos** 

**Actores principales: Profesor**

**Actores segundarios: Alumno**

### Precondiciones

* El alumno que será eliminado debe existir en el sistema.

### Flujo principal

1 El caso de uso se iniciará en el momento que el profesor desee eliminar un alumno.

2 El sistema pregunta si se desea eliminar por DNI o por apellido.

3 El sistema busca al alumno en cuestión por DNI o por apellido.

4 Se elimina al alumno del sistema.

### Postcondiciones

**A** El sistema actualiza la base de datos eliminando al alumno.

**B** Se muestra un mensaje de éxito, indicando la correcta eliminación del alumno.
 

## Flujos alternativos

3.1 El sistema no permite la eliminación de un alumno que no existe en la aplicación.
