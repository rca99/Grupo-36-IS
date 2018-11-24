## Diagrama de secuencia 11 salir de la aplicacion

Comienza cuando el profesor solicita salir de la aplicación. La interfaz muestra un mensaje de confirmación de salida, iniciando un bucle **ALT** que depende del resultado de esta.
* Si el profesor confirma la salida de la aplicación, la interfaz pide al profesor que guarde los cambios en la base de datos o en una copia de seguridad externa, empezando un nuevo bucle **ALT**.
  * Si se confirma la realización de la copia de seguridad, se solicita al sistema que realice el guardado en la base de datos o en el servidor externo. Devuelve un mensaje de confirmación que la interfaz muestra al usuario y el mensaje de salida de la aplicación, y sale de esta.
  * Si no se confirma la realización de copias de seguridad, se muestra al usuario un mensaje de salida y sale de esta.
* Si el usuario decide finalmente no salir de la aplicación, se le reconduce al menú de la aplicación.
