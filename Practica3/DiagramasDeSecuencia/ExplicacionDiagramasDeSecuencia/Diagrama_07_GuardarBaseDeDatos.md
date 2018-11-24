## Diagrama de secuencia 07 guardar base de datos

Comienza cuando el profesor solicita guardar los datos en la base de datos. Para ello, la interfaz se pregunta si hay alumnos guardados en la base de datos, iniciando un bucle **ALT**.
* Si en la base de datos ya hay alumnos almacenados, guarda los cambios que han sido realizados, y devuelve un mensaje de confirmación a la interfaz que muestra al usuario que esta operación ha sido realizada satisfactoriamente. Además, estos cambios producidos se guardan en un fichero binario.
* Si la base de datos se encuentra vacía, la base de datos devuelve un error y la interfaz se lo muestra al usuario.
