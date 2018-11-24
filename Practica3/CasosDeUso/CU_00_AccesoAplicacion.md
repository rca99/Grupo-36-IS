
## Acceso a la aplicación

**ID: 00**

**Breve descripcion: Los profesores podrán acceder a la aplicación mediante sus credenciales de la Universidad.**

**Actores principales: Procesor coordinador y profesores ayundantes**

**Actores segundarios: -**

### Precondiciones

* Se dispone de acceso a las credenciales de los profesores (usuario, contraseña, asignaturas que cursan y papel que desempeñan en la misma, coordinador o ayudante).


### Flujo principal

1 El caso de uso comienza cuando el usuario necesita acceder a la aplicación.

2 El profesor introducirá su usuario y contraseña habitual de moodle.

3 El sistema comprobará si exite el usario y que la contraseña introducida es correcta.

4 Opcionalmente, el sistema consultará si se desea cargar la base de datos de alumnos en caso de existir.

4.1 Además, si es coordinador también dará la posibilidad de cargar la copia de seguridad externa en caso de existir.



### Postcondiciones

A Se accede al menú principal de la aplicación.

B Muestra un mensaje de bienvenida al profesor indicando su nombre por pantalla.

C En caso de cargar la base de datos o copia de seguridad muestra el número de alumnos actuales que se hayan registrados.



## Flujos alternativos

3.1 Si no se introducen las credenciales correctas el sistema informa al usuario y da tres oportunidades de acceso. En caso de no introducir las credenciales correctas en estas tres ocasiones, se sale de la aplicación.

4.1 En caso de no haber sido posible cargar la base de datos mostrará un mensaje informando de la causa.

4.1.1 No existe base de datos o copia de seguridad que cargar.

4.1.2 Ha habido un error a la hora de procesar el archivo de base de datos o copia de seguridad.
