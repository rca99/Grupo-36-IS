
## Acceso a la aplicación

**ID: 0**

**Breve descripcion: Los profesores podrán acceder a la aplicación mediante sus credenciales de la Universidad.**

**Actores principales: Procesor coordinador y profesores ayundantes**

**Actores segundarios: -**

### Precondiciones

* Se dispone de acceso a las credenciales de los profesores (usuario, contraseña, asignaturas que cursan y papel que desempeñan en la misma, coordinador o ayudante).


### Flujo principal

1 El caso de uso comienza cuando el usuario necesita acceder a la aplicación.

2 El profesor introducirá su usuario y contraseña habitual de moodle.

3 El sistema comprobará si exite el usario y que la contraseña introducida es correcta.



### Postcondiciones

A Se accede al menú principal de la aplicación.

B Muestra un mensaje de bienvenida al profesor indicando su nombre por pantalla.



## Flujos alternativos

3.1 Si no se introducen las credenciales correctas el sistema informa al usuario y da tres oportunidades de acceso. En caso de no introducir las credenciales correctas en estas tres ocasiones, se sale de la aplicación.

