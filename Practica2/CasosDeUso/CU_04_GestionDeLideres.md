## Gestión de Líderes

**ID: 4**

**Breve descripción: El sistema verifica si un alumno puede ser o no líder del grupo.** 

**Actores principales: Profesor.**

**Actores segundarios: Alumno.**

### Precondiciones

* El alumno estará identificado en el sistema con su DNI, nombre, apellidos y grupo al que pertenece.

### Flujo principal

1 El caso de uso comienza cuando el profesor desea indicar si un alumno es líder de un grupo.

2 El sistema recibe el grupo con el que se quiere interactuar.

3 El sistema busca los alumnos que pertenecen a dicho grupo.

4 El sistema comprueba si algún alumno del grupo es líder.

4.1 Si tiene líder, el sistema no permitirá asignar como líder a dicho alumno.

4.2 Si no tiene líder, el sistema permitirá asignar como líder a dicho alumno.

### Postcondiciones

**A** El sistema se actualiza si el sistema permite indicar que el alumno es líder.

## Flujos alternativos

4.1.1 No se puede asignar al alumno como líder ya que el grupo tiene un líder y sale del caso de uso.
