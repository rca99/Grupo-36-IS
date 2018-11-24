## Cargar Copia de Seguridad

**ID: 8**

**Breve descripción: El profesor podrá cargar una copia de seguridad de los datos de los alumnos registrados.** 

**Actores principales: Profesor.**

**Actores segundarios: Alumno.**

### Precondiciones

* La copia de seguridad a cargar debe haber sido previamente guardada.

### Flujo principal

1 El caso de uso comienza cuando el usuario necesita cargar una copia de seguridad.

2 El sistema comprueba si existe el fichero de base de datos.

3 El sistema carga la base de datos.

4 El sistema comprueba que la base de datos se ha cargado correctamente. 

### Postcondiciones

**A** El sistema muestra un mensaje de confirmación de la carga y de cuál de las copias de seguridad existentes ha sido cargada.

**B** El sistema permite al usuario sobrescribir los datos de esa copia de seguridad.

## Flujos alternativos

2.1 Si no existe fichero de base de datos, el sistema pedirá al usuario que debe guardar antes la base de datos.

4.1 Si el sistema no es capaz de cargar la base de datos, dará un mensaje de error.
