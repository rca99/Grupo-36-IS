
## Insertar Alumno

**ID: 2**

**Breve descripcion: El profesor podra buscar los alumno introducidos en la base de datos por DNI y apellidos** 

**Actores principales: Profesor**

**Actores segundarios: Alumno**

### Precondiciones

* La aplicacion debe tener alumnos dados de alta.


### Flujo principal

1 El caso de uso comienza cuando el usuario necesita buscar un alumno.

2 El sistema comprueba si hay alumnos dados de alta en el sistema. 

3 El sistema recoge los datos del DNI y/o apellido que buscar

4 El sistema busca el alumno por DNI y/o apellido.

5 El sistema devuelve el alumno encontrado.


### Postcondiciones

**A** En caso de no existir el alumno muestra un mensaje indicando que el alumno no existe en la base de datos.
 
## Flujos alternativos

2.1 Si no hay alumnos en la base de datos, el sistema consulta al profesor si ha cargado la base de datos.

    2.1.1 Si ha cargado la base de datos, indicara que no hay alumnos y se le indicara que proceda a insertar alumnos antes de buscarlos.
    2.1.2 Si no ha cargado la base de datos, se le indica que la cargue.

3.1 Se comprueba que los datos introducidos son del tipo y formato correcto, Si no lo son se indica que se introduzcan adecuadamente.
