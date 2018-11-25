## Cargar Copia de Seguridad Externa

**ID: 10**

**Breve descripción: El Coordinador de la asignatura podrá cargar una copia de seguridad externa de los datos de los alumnos registrados.**

**Actores principales: Coordinador de la asignatura.**

**Actores segundarios: Alumno.**

### Precondiciones

* La copia de seguridad externa a cargar debe haber sido previamente guardada.
* Debe haber una conexión a internet activa para acceder al repositorio remoto.

### Flujo principal

1 El caso de uso comienza cuando el usuario necesita cargar una copia de seguridad externa

2 El sistema carga la copia de seguridad externa.

3 El sistema comprueba que la base de datos se ha cargado correctamente.

### Postcondiciones

**A** El sistema muestra un mensaje de confirmación de la carga y de cuál de las copias de seguridad existentes ha sido cargada.

**B** El sistema permite al usuario sobrescribir los datos de esa copia de seguridad.

## Flujos alternativos

2.1 Si no hay copias de seguridad externas guardadas, el sistema pedirá al usuario que cree una copia de seguridad.

3.1 Si el sistema no es capaz de cargar la copia de seguridad da un mensaje de error, indicando que no ha sido posible cargar esa copia de seguridad.
