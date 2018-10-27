
## Guardar Copia de Seguridad

**ID: 7**

**Breve descripcion: El profesor podrá realizar una copia de seguridad de los alumnos registrados en el sistema.**

**Actores principales: Profesor.**

**Actores segundarios: Alumno.**

### Precondiciones

* La aplicacion debe tener alumnos dados de alta.
* Los datos se guardaran en un archivo binario.


### Flujo principal

1 El caso de uso comienza cuando el usuario requiere realizar copia de seguidad.

2 El sistema comprueba si hay alumnos dados de alta.

3 El sistema actualiza los datos de los alumnos en el fichero binario que almacena la base de datos.

4 El sistema comprueba que la base de datos se ha guardado correctamente.


### Postcondiciones

**A** El sistema muestra un mensaje indicando que los datos se han guardado correctamente.

**B** En caso de no existir alumnos el sistema informa que no es necesaria la copia de seguridad.
 
## Flujos alternativos

1.1 En caso de que el profesor no haya indicado realizar copia de seguridad, al salir de la aplicación y si hay alumnos dados de alta en el sistema, se consultara al profesor si quiere realizar la copia de seguridad.

2.1 Si no hay alumnos en la base de datos, el sistema consulta al profesor si ha cargado la base de datos.

    2.1.1 Si ha cargado la base de datos, indicará que no hay alumnos y que proceda a insertar alumnos antes de realizar la copia de seguridad.
    2.1.2 Si no ha cargado la base de datos, se le indica que la cargue.

3.1 Si no existe el fichero binario se procederá a crearlo.

4.1. Si no se insertan correctamente los datos da un mensaje de error, indicando que vuelva a realizar la copia.
