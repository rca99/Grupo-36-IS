## Diagrama de secuencia 05 mostrar alumnos

Comienza cuando el profesor solicita mostrar un alumno, para lo cual la interfaz pregunta que opción de mostrado va a elegir, y el usuario selecciona la que desee entre mostrar un alumno, todos, o los de un grupo. Se abre un bloque **ALT** con estas tres opciones.
* Si se elige mostrar un alumno, se piden al usuario los datos del alumno, y estos se envian a la base de datos, que procede a buscarlo. Se inicia otro bloque **ALT**.
  * Si se encuentra el alumno, devuelve sus datos y lo muestra al profesor y, en caso de que sea un líder, se resalta en negrita.
  * Si no existe, se devuelve un mensaje de error de alumno no encontrado.
* Si se elige mostrar todos los alumnos de un grupo, se pide al usuario que indique que grupo quiere mostrar, y posteriormente como lo quiere ordenar a sus integrantes, Al disponer de esta información, se traslada a la base de datos que procede a la búsqueda. Se inicia un bloque **ALT**.
  * Si encuentra un grupo con alumnos, devuelve el grupo y lo muestra, resaltando en negrita al líder.
  * Si el grupo no tiene alumnos, devuelve un mensaje de no encontrado.
* Si se elige mostrar a todos los alumnos, la base de datos comprueba que existan alumnos, inicando un bloque **ALT**.
  * Si hay alumnos en la base de datos, devuelve los datos y se pregunta al usuario como los desea ordenar, este lo indica y la interfaz pide los datos necesarios a la base de datos, que se los devuelve, y por último son mostrados al usuario.
  * Si la base de datos está vacía, devuleve un mensaje de error indicando que la base de datos está vacía.
