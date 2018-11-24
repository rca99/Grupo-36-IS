Diagrama de secuencia 09 cargar copia de seguridad externa

Comienza cuando el coordinador de la asignatura solicita guardar una copia de seguridad externa. Para ello. la interfaz comprueba si existe un fichero local en la base de datos, iniciando un bucle **ALT**.
  * Si existe un fichero local, la base de datos conecta con el servidor externo y guarda en este la copia de seguridad. Devuelve un mensaje de confirmación y este lo muestra al coordinador.
  * Si no existe fichero local, devuelve un mensaje de error, y la interfaz lo muestra al usuario.
