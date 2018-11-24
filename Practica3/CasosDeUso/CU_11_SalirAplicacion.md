## Guardar Copia de Seguridad Externa

**ID: 10**

**Breve descripción: El profesor podrá salir de la aplicación.**

**Actores principales: Profesor.**

**Actores segundarios: Alumno.**

### Precondiciones

* .

### Flujo principal

1 El caso de uso comienza cuando el usuario necesita salir de la aplicación.

2 El sistema solicita confirmación para salir de la aplicación

3 El sistema consulta si se quiere guardar la base de datos y/o de realizar la copia de seguridad externa en caso de ser el Coordinador.

3 La aplicación se cierra.

### Postcondiciones

**A** El sistema muestra un mensaje de salida al profesor y se cierra la aplicación.



## Flujos alternativos

2.1 Si se indica que no se quiere salir de la aplicación vuelve al menú principal de la aplicación.

3.1 Si no es posible cerrar la aplicación en ese momento se muestra un mensaje de error.


