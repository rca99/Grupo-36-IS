## Guardar Copia de Seguridad Externa

**ID: 09**

**Breve descripción: El Coordinador podrá guardar la copia de seguridad externa en un servidor remoto.**

**Actores principales: Coordinador.**

**Actores segundarios: Alumno.**

### Precondiciones

* Debe existir previamente una base de datos de la cual crear la copia de seguridad externa.

### Flujo principal

1 El caso de uso comienza cuando el usuario requiere guardar la copia de seguridad externa

2 El sistema comprueba si existe el fichero de base de datos que guardar.

3 El sistema conecta con el repositorio remoto.

4 El sistema envía el fichero de base de datos al fichero remoto y guarda la copia de seguridad externa.

### Postcondiciones

**A** El sistema muestra un mensaje de confirmación de realización de la copia de seguridad externa.



## Flujos alternativos

2.1 Si no hay fichero de base de datos, el sistema indicará al usuario que cree una copia de seguridad antes de realizar la copia de  seguridad externa.

3.1 Si el sistema no es capaz de conectar con el repositorio remoto informa con un mensaje de error.

4.1 Si el sistema no realiza la copia de seguridad externa da un mensaje de error.
