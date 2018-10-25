## Mostrar Alumno

**ID: 5**

**Breve descripcion: El profesor podra mostrar los datos de un alumno** 

**Actores principales: Profesor**

**Actores segundarios: Alumno**

### Precondiciones

* El alumno a mostrar debe existir en el sistema.

### Flujo principal

1 El caso de uso comienza cuando el usuario necesita mostrar un alumno.

2 El sistema da la opcion de mostrar a todos los alumnos dados de alta en el sistema, a uno en particular, o a los pertenecientes a un grupo.

3 El sistema dara la opcion de mostrar a los alumnos por orden alfabetico, por su numero de dni, o por el curso mas alto en el que esten matriculados; tanto de forma ascendente como descendente.

4 El sistema muestra los datos del alumno o alumnos que se haya pedido mostrar segun los criterios seleccionados.

### Postcondiciones

A El sistema debe mostrar en blanco los datos del alumno no obligatorios que no hayan sido introducidos previamente.

## Flujos alternativos

2.1 Si el sistema no encuentra a un alumno al que se ha pedido mostrar al buscarlo en el sistema, dará un mensaje de error.

3.1 Si hay dos alumnos que posean la misma información en el campo según el que mostrar a los alumnos ordenados(por ejemplo, el curso mas alto en el que se este matriculado), se mostraran ordenados segun otro de los criterios disponibles.

4.1 Si el sistema no es capaz de mostrar ningun alumno con los criterios establecidos dara un mensaje de error y pedira al usuario que cambie los criterios escogidos.
