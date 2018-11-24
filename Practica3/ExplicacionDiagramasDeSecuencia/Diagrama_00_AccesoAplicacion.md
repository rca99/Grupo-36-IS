## Diagrama de secuencia 00 acceso a la aplicación

Comienza cuando un usuario no registrado solicita acceder a la aplicación, para lo que se le requieren unos datos de acceso, iniciándose un bucle **LOOP** de tres iteraciones que sirven como contador de los intentos de acceso.
El profesor introduce sus datos, y se manda comprobar sus credenciales, iniciando un bucle **ALT**.
* Si las credenciales son correctas, se devuleve el usuario y su rol al sistema, que crea una instancia profesor con esos datos. Se origina un bucle **OPT** con un bucle **ALT** anidado, donde se establece que si es profesor, solo se le permite cargar la base de datos, mientras que si es coordinador se le permite cargar una copia de seguridad externa. Tras esto, se procede al acceso al menú de la aplicación.
* Si las credenciales son incorrectas, se incrementa el contador de intentos de acceso, cuyo número devuelve el sistema, y es mostrado al usuario por la interfaz.

Finalmente, si se introducen incorrectamente las credenciales el número máximo de intentos permitidos, se expulsará al usuario del sistema.
