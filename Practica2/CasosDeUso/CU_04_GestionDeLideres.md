## Gestión de Líderes

**ID: 4**

**Breve descripción: El profesor podrá gestionar qué alumnos realizan la función de líder del grupo** 

**Actores principales: Profesor**

**Actores segundarios: Alumno**

### Precondiciones

* El alumno seleccionado deberá existir en el sistema

### Flujo principal

1 El caso de uso comienza cuando el usuario desea administrar los líderes de los grupos

2 El sistema recibe el grupo con el que se quiere interactuar

3 El sistema busca los alumnos que pertenecen a dicho grupo.

4 El sistema lista los alumnos del grupo.

5 El sistema indicara si el grupo tiene líder o no.

5.1 Si tiene líder, el sistema permitirá modificarlo y asignar al grupo un nuevo líder, dejarlo sin líder o no realizar ningún cambio.

5.2 Si no tiene líder, el sistema permitirá asignarlo o dejarlo sin líder.

6 El sistema muestra un mensaje indicando que el sistema ha sido o no actualizado según la opción indicada.

### Postcondiciones

A El sistema se actualiza conforme a los cambios aplicados en los líderes

## Flujos alternativos

3.1 Si el sistema no encuentra ningún alumno pertenciente al grupo recibido, muestra un mensaje de error
