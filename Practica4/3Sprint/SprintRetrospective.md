# Proyecto:: **Gestión de Alumnos IS 2018-2019**
 
## Sprint:

### Reunión: Retrospective meeting

**Fecha reunión:23/12/2018 23:30**

ASPECTOS A DESTACAR DEL TRABAJO DESARROLLADO

* Uno de los aspectos que más han incidido en el desarrollo del trabajo ha sido pensar que el Código se implementaría en tres sesiones de Sprint. Con esa base desarrollamos una planificación 
de la implantación del código que tuvimos que comprimir en dos semanas. Como fuimos informados en la segunda semana tuvimos que desarrollar las funciones previstas en dos semanas en una sóla. 
Tuvimos poco tiempo para ir analizando los problemas y los tuvimos que ir resolviendo sobre la marcha y no como estaba previsto en las reuniones del Sprint. Estas reuniones se basaron en poner en común el trabajo que habíamos realizado, analizar los problemas de desarrollo, proponer soluciones  y ver qué teníamos pendiente.

* Ha habido ocasiones en que hemos tenido que desarrollar funciones que no nos eran propias para poder evolucionar en nuestras funcionalidadades. Después las poníamos en común y las acababa de
desarrollar quién tuviera esa funcioanalidad. El hecho de no estar trabajando en el mismo horario ni estar disponibles cuando el compañero lo necesitase ha hecho que tengamos que utilizar funciones tipo STUB no completamente definidas de acuerdo a las 

* La metodología, bien llevada a cabo, es muy efectiva, pues nos permite a los integrantes del equipo ver como avanzan o no los progresos de nuestros compañeros, así como una comunicación fluida y rápida acerca de lo que se está trabajando.

ASPECTOS A MEJORAR

* El primer Sprint no fue muy productivo ya que quedaron funciones sin desarrollar plenamente, ya que no tuvieron ningún proceso de validación, simplemente se codificaron sin probarlas de ninguna manera. Después de este primer Sprint, se empezó a crear una interfaz con la que poder probar las funciones que se iban codificando. Esta interfaz finalmente se convirtió en el menú de la aplicación.

* Respecto al código se han cometido algunos errores debidos fundamentalmente al tiempo de desarrollo y a la inexperiencia programando c++. Entre ellas se encuentran:

1 Interfaz demasiado compleja. Se podría haber trabajado en un patrón de diseño tipo Composite para la definición del menú.
2 Hay partes de la interfaz repetidas que se podrían haber integrado en funciones propias de la interfaz, como las de guardar/cargar copia de seguridad.

* Confirmación de los tiempos de entrega antes de comenzar el trabajo.

* En la planificación del trabajo fuimos muy optimismas con el tiempo de desarrollo pensando que lo desarrollaríamos en menos tiempo del que finalmente hemos necesitado. 
Este hecho fundamentalmente se ha debido a nuestra poca experiencia programando, a no haber previsto que el código hay que ir probándolo conforme lo  vamos desarrollando. Es decir, no planteamos, que las funciones había que desarrollarlas, sino también probarlas mínimamente.

* Es preciso mejorar en el diseño de las clases, ya que de lo inicialmente previsto, han habido datos privados no usados (puntero a la base de datos en la clase profesor) o funciones que hemos tenido que crear que no estaban inicialmente previstas, como la de insertar alumno, que podía recibir un objeto alumno o bien una estructura de alumnos.

* Durante el desarrollo del código nos ha ocurrido, sobre todo al final, que la modificación de una función, ha afectado a otras partes del código. Ha sido el caso de la función de insertarAlumno(Alumno nuevoAlumno);. Si hay una función definida de una forma, es mejor preguntar si alguien la está usando en otra parte del código, antes de modificarla. En caso de duda, es mejor crear otra nueva para la funcionalidad que se esté desarrollando ya que no sabemos si la modificación puede afectar a otra parte del código.

* Debido a que es la primera vez que trabajamos con ramas en git, nos ha costado, sobre todo al inicio del desarrollo del código, adaptarnos a esta nueva forma de trabajo, provocando que trabajasemos un poco más lentos e inseguros, hasta que nos hemos acostumbrado plenamente a esta dinámica.

* La comunicación no ha sido tan buena como cabría esperar, dando lugar a errores del tipo: modificar parte de una funcionalidad que está realizando un compañero, o tener trabajo adelantado en la rama individual que debería estar en la rama master. Entendemos que se necesita más práctica y más trabajo. Pese a todo, el trabajo en general ha dado buenos frutos, pues en un tiempo relativamente corto se ha llevado a cabo la realización de un "software" capaz de gestionar los alumnos de una asignatura.
