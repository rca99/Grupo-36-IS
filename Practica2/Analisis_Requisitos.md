# Análisis de requisitos

* Partes interesadas
* Base de datos
* Requisitos

  * Funcionales
  * No funcionales


***

## Partes interesadas

**Profesor:** Gestiona y mantiene la base de datos de los alumnos

**Alumnos:** Cursan la asginatura impartida por el profesor


***

## Base de datos

El sistema almacenará los siguientes parámetros correspondientes a un alumno:
  * DNI
  * Nombre
  * Apellidos
  * Fecha de nacimiento
  * Teléfono
  * Email Corporativo
  * Domicilio
  * Curso más alto en el que se ha matriculado
  * Nota
  * Equipo al que pertenece
  * Líder (Sí/No)


***

## Requisitos

### <ins>Funcionales</ins>

  **1 Introducir un alumno:** El profesor podrá introducir un nuevo alumno
  
  **2 Buscar un alumno:** El sistema deberá buscar un alumno o varios de acuerdo a unas directrices
  
  **3 Modificar un alumno:** El profesor tendrá la opción de modificar los datos de un alumno
 
  **4 Gestion de líderes:** El sistema dará la posibilidad de gestionar los líderes de los grupos de acuerdo a las restricciones impuestas por el cliente (no pudiendo haber más de un líder por grupo)
  
  **5 Mostrar alumnos:** El sistema podrá mostrar uno, varios o todo los alumnos
  
  **6 Eliminar un alumno:** El sistema permitirá borrar un alumno de la base de datos
  
  **7 Guardar copia de seguridad:** El sistema dará la opción de realizar una copia de seguridad con los nuevos datos
  
  **8 Cargar copia de seguridad:** A su vez, el sistema también dará la opción de cargar copias anteriores
 
  
   Identificador | Requisito | Prioridad
   :--:|:--:|:--:
   001|Buscar alumno|1
   002|Gestión de líderes|1
   003|Introducir alumno|2
   004|Guardar copia de seguridad|2
   005|Cargar copia de seguridad|2
   006|Mostrar alumno|3
   007|Modificar alumno|4
   008|Eliminar alumno|5
 
 
### <ins>No Funcionales</ins>

  1 Sistema operativo Linux obligatorio, multiplataforma opcional
  
  2 Lenguaje de Programación C++
  
  3 Lenguaje de documentación Markdown
  
  4 Utilización de ficheros binarios para almancenar la información
  
  5 Máximo 150 alumnos
  
  6 Interfaz obligatoria línea de comandos, opcional gráfica
  
  7 Sólo sirve para el año actual
  
  8 Únicamente tendrá acceso el profesor de la asignatura
  

***
