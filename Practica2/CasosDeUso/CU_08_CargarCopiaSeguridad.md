## Cargar Copia de Seguridad

**ID: 8**

**Breve descripcion: El profesor podra cargar una copia de seguridad de los datos de los alumnos registrados** 

**Actores principales: Profesor**

**Actores segundarios: Alumno**

### Precondiciones

* La copia de seguridad a cargar debe haber sido previamente guardada 

### Flujo principal

1 El caso de uso comienza cuando el usuario necesita cargar una copia de seguridad.

2 El sistema comprueba si hay copias de seguridad guardadas y da la opción al usuario de elegir cual quiere mostrar.

3 El sistema carga la copia de seguridad designada por el usuario.

4 El sistema comprueba que la base de datos se ha cargado correctamente. 

### Postcondiciones

A El sistema informa de cual de las copias de seguridad existentes ha sido cargada.

B El sistema permite al usuario sobrescribir los datos de esa copia de seguridad.

## Flujos alternativos

2.1 Si no hay copias de seguridad guardadas, el sistema pedirá al usuario que cree una copia de seguridad.

4.1 Si el sistema no es capaz de cargar la copia de seguridad da un mensaje de error, indicando que no ha sido posible cargar esa copia de seguridad.
