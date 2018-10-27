
## Buscar Alumno

**ID: 2**

**Breve descripción: El profesor podrá buscar los alumnos introducidos en la base de datos por DNI, apellidos o grupo.** 

**Actores principales: Profesor**

**Actores segundarios: Alumno**

### Precondiciones

* La aplicacion debe tener alumnos dados de alta.

### Flujo principal

1 El caso de uso comienza cuando se necesita buscar un alumno.

2 El sistema comprueba si hay alumnos dados de alta en el sistema. 

3 El sistema recoge los datos necesarios (DNI, apellidos o grupo) para buscar.

3.1 El sistema convierte a mayúscula los datos (DNI o apellidos) que hay que buscar.

4 El sistema busca el alumno por DNI, apellidos o grupo.

### Postcondiciones

**A** El sistema devuelve el alumno o alumnos encontrados.

**B** En caso de devolver los alumnos del grupo, el sistema indicará si el grupo tiene líder o no lo tiene.
 
## Flujos alternativos

2.1 Si no hay alumnos en la base de datos, el sistema consultará al profesor si ha cargado la base de datos.

    2.1.1 Si ha cargado la base de datos, indicara que no hay alumnos y que proceda a insertar alumnos antes de buscarlos.
    2.1.2 Si no ha cargado la base de datos, se le indica que la cargue.

3.1 Se comprueba que los datos introducidos son del tipo y formato correcto, si no lo son se indica que se introduzcan adecuadamente.

4.1 En caso de no existir el alumno muestra un mensaje indicando que el alumno no existe en la base de datos y se regresa al paso 1.

4.2 En caso de que el grupo no tenga alumnos asociados, se muestra un mensaje indicando de que el grupo está vacío.

4.3 En caso de que exista más de un alumno con el mismo apellido, el sistema indica al profesor que introduzca el DNI para filtrar.
