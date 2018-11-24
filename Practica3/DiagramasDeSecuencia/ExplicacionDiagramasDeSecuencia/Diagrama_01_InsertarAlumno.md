## Diagrama de secuencia 01 insertar alumno

Comienza cuando el profesor solicita introducir un nuevo alumno. La interfaz le pide al sistema que le informe de cuantos alumnos existen en la base de datos, y lo muestra al usuario.
Se inicia un bucle **ALT** y, dependiendo del número de alumnos, se tomará uno de los caminos a seguir:
* Si el número de alumnos es inferior a 150, la base de datos permitirá la inserción. Para ello, solicita una serie de datos al profesor, quien proporciona nombre, apellidos y dni, iniciándose una búsqueda de alumnos.
  * Se inicia un nuevo bucle **ALT**. Si el alumno no existe, se exigirá al usuario introducir, al menos, los datos obligatorios del alumno.
    Aquí se abre un camino opcional. Si se introducen datos no obligatorios, entramos en un bucle **OPT**, donde tendríamos que tener en cuenta la gestión de líderes, abriéndose un nuevo bucle **ALT**.
      Si el grupo ya tiene líder, no habrá ninguna novedad; sin embargo, si no hay líder, devuelve un mensaje indicándolo y el profesor podrá introducir los datos opcionales.
    Aquí terminaría el bucle **OPT**, continuando tras la adición de los datos obligatorios incrementando el contador de alumnos existentes en la base de datos, y se devuelve un mensaje de confirmación.
  * La segunda opción en este bucle **ALT** es que el alumno ya exista, por lo que la interfaz devuelve un mensaje de error al usuario indicando que el alumno ya existe.
* Si el número de alumnos es 150, devuelve un mensaje de error indicando al usuario que no es posible insertar más alumnos.
