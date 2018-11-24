##  Diagrama de secuencia 10 cargar copia de seguridad

Comienza cuando el coordinador solicita cargar una copia de seguridad externa. La interfaz se conecta con el repositorio remoto y comprueba que existan backups, iniciando un bloque **ALT**.
* Si existen backups, el servidor externo carga la backup en la base de datos, y esta devuelve un mensaje de confirmación que muestra la interfaz al usuario.
* Si no existen backups, se devuelve desde el servidor externo un mensaje de error que muestra la interfaz al usuario.
