# Análisis de Requisitos

* Partes interesadas.
* Datos almacenados por la aplicación.
* Requisitos.

  * Funcionales.
  * No funcionales.


***

## Partes interesadas

**Profesores:** Gestionan y mantienen la base de datos de los alumnos. Formado por el coordinador y los ayudantes. Las funciones que realizan son las mismas, salvo que el coordinador puede realizar copias de seguridad externas.

**Alumnos:** Cursan la asginatura impartida por el profesor.


***

## Datos almacenados por la aplicación

El sistema almacenará los siguientes parámetros correspondientes a un alumno:
  * DNI.
  * Nombre.
  * Apellidos.
  * Fecha de nacimiento.
  * Teléfono.
  * Email Corporativo.
  * Domicilio.
  * Curso más alto en el que se ha matriculado.
  * Nota.
  * Equipo al que pertenece.
  * Líder (Sí/No).


***

## Requisitos

### <ins>Funcionales</ins>

  **0 Acceso a la aplicación:** Los profesores podrán acceder a la aplicación mediante sus credenciales de la Universidad.

  **1 Introducir un alumno:** Los profesores podrá introducir un nuevo alumno.

  **2 Buscar un alumno:** El sistema deberá buscar un alumno o varios de acuerdo a unas directrices.

  **3 Modificar un alumno:** Los profesores tendrá la opción de modificar los datos de un alumno.

  **4 Gestión de líderes:** El sistema dará la posibilidad de gestionar los líderes de los grupos de acuerdo a las restricciones impuestas por el cliente (no pudiendo haber más de un líder por grupo).

  **5 Mostrar alumnos:** El sistema podrá mostrar uno, varios o todos los alumnos.

  **6 Eliminar un alumno:** El sistema permitirá borrar un alumno de la base de datos.

  **7 Guardar base de datos:** El sistema dará la opción de guardar los datos introducidos en la aplicación en un fichero binario.

  **8 Cargar base de datos:** El sistema permite cargar el fichero binario con los datos introducidos.

  **9 Guardar copia de seguridad externa:** El sistema dará la opción de realizar una copia de seguridad en un servidor externo con los datos de la aplicación.

  **10 Cargar copia de seguridad externa:** El sistema también dará la opción de cargar la copia de seguridad externa.

  **11 Salir de la aplicación:** El sistema dará consultará si se desea guardar la base de datos o bien realizar la copia de seguridad externa, sólo para el caso del Coordinador.


   Identificador | Requisito | Prioridad
   :--:|:--:|:--:
   000|Acceso a la aplicación|1
   001|Introducir alumno|1
   002|Buscar alumno|1
   007|Guardar copia de seguridad|2
   008|Cargar copia de seguridad|2
   009|Guardar copia de seguridad externa|2
   010|Cargar copia de seguridad externa|2
   004|Gestión de líderes|2
   005|Mostrar alumno|3
   003|Modificar alumno|4
   006|Eliminar alumno|4
   007|Salir de la aplicación|5


### <ins>No Funcionales</ins>

  **1.** Sistema operativo Linux obligatorio, multiplataforma opcional.

  **2.** Lenguaje de Programación C++.

  **3.** Lenguaje de documentación Markdown.

  **4.** Utilización de ficheros binarios para almancenar la información, tanto la de los alumnos como las credenciales de los profesores.

  **5.** Utilización de Drive para almacenar la información en un servidor externo.

  **6.** Máximo 150 alumnos.

  **7.** Interfaz obligatoria línea de comandos, opcional gráfica.

  **8.** Únicamente sirve para el año actual.

  **9.** Tendrán acceso solo aquellos profesores que figuren en las credenciales cedidas por la Universidad que incluyen usuario, contraseña y rol.


***
