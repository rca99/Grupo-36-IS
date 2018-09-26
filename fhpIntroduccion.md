

![logo de git+gitHub](http://blog.desafiolatam.com/wp-content/uploads/2016/05/git-github-logo.jpg)


# Manual de Git y GitHub

## Indice de contenidos

* Descripción de Git y GitHub.
	* Principales ventajas de Git y GitHub.
* Git
	* Instalación.
	* Configuración Básica.
	* Los tres estados de Git.
	* Comandos Básicos.
	* Ramas o Branches.

* GitHub

	* Creacion de repositorios.
	* Comandos gitHubI.

***
***

# **Descripción de Git y GitHub**

>Cualquier equipo de desarrollo de Software encontrará en *Git* una de sus principales herramientas para llevar a cabo sus proyectos de forma satisfactoria ya que se trata de un poderoso sistema de control de versiones distribuido.


*Git* nos permite realizar un seguimiento de los cambios de cualquier proyecto de software,  controlando todos los archivos que lo conforman. Veremos que hay una funcionalidad que nos permite excluir archivos o carpetas que, aunque forman parte de la información necesaria para el desarrollo del proyecto, no son necesarios para la implementación del mismo a través del código. *Git* nos permite conocer la evolución de los archivos a lo largo del tiempo y permite sincronizar los cambios que realizan los componentes del equipo sobre el proyecto.

***

*GitHub* es un sitio web que pone a disposición de programadores un repositorio remoto en el que subir una copia de nuestros proyectos de *Git*. Las ventajas principales de GitHub residen en que podemos documentar nuestro proyecto y realizar y seguimento del desarrollo del mismo.


## Principales ventajas de *Git* y *GitHub*

### Git

![logo de git](https://i2.wp.com/codecollege.co.za/wp-content/uploads/2016/09/git.jpg?resize=100%2C100&ssl=1)

* Habilidad para deshacer cambios.
* Historial y documentación de cambios.
* Múltiples versiones de código.
* Habilidad para resolver conflictos entre versiones de distintos programadores.
* Copias independientes


### GitHub

![logo de gitHub](https://img.stackshare.io/service/27/thumb_retina_sBsvBbjY.png)

* Documentación de requerimientos.
* Ver el alcance del desarrollo.


***
***


# **Git**

## Instalación

Para la instalación de Git en su ordenador se recomienda visitar la web del desarrollador, [Git](https://git-scm.com/downloads "Everything is local"), y seguir las indicaciones según su sistema operativo

## Configuración Básica

> A continuación se presentan los principales comandos de ejecución básica de *Git* que se ejecutarán desde el ***terminal de comandos*** de su sistema operativo. En windows existe la opción de instalar un terminal de comandos mejorado y adaptado a git.

**Nombre del administrador**

	git config --glogal user.name "Fernando Herrera Poch"


**Correo electrónico**

	git config --glogal user.mail a52hepof@uco.es

**Correo electrónico**

	git config --glogal user.mail a52hepof@uco.es

**Editor de texto**

	git config --glogal core.editor "gedit"

**Color de la interfaz**

	git config --glogal color.ui true

**Listado de la configuración**

	git config --list

El listado de la configuración informa además de los parámetros antes indicados, del repositorio remoto en caso de existir.

## Los tres estados de Git

![Los tres estados de Git](https://git-scm.com/figures/18333fig0106-tn.png)
















