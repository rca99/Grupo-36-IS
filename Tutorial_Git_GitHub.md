![logo de git+gitHub](http://blog.desafiolatam.com/wp-content/uploads/2016/05/git-github-logo.jpg)


# **Manual de Git y GitHub**

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

	* GitHub no es Git
	* Creacion de repositorios.
	* Comandos GitHub.

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

## Uso básico de Git

### Comandos básicos I

**Iniciar repositorio en un directorio**

	git init

**Agregar cambios al area de staging**

	git add

**Validar cambios en el repositorio**

	git commit -m "Mensaje"

**Hacer los dos pasos anteriores en uno**

	git commit -m "Mensaje"

Historial de commits

	git log

### Comandos básicos II

**Ayuda del listado anterior**

	git help log

**Listar los 5 commits más recientes**

	git log -n 5

**Listar los commits desde una fecha**

	git log --since=2018-09-26

**Listar los commits por autor**

	git log --author="Antonio"	

**Ver cambios en el directorio**

	git status

### Comandos básicos III

**Ver diferencia entre ficheros en el directorio y el repositorio git**

	git diff

**Ver diferencia entre ficheros en el *staging* y el repositorio**

	git diff --staged

**Eliminar archivos**

	git rm archivo
	git commit -m "Mensaje"

**Mover o renombrar archivos**

	git mv antiguo nuevo
	git commit -m "Mensaje"

### Comandos básicos IV

**Deshacer cambios con git**

	git checkout -- nombre_fichero

**Retirar archivos del staging**

	git reset HEAD nombre_fichero

**Complementar último commit**

	git commit amend -m "Mensaje"

**Recuperar versión de un fichero commit antiguo**

	git checkout <id_commit> -- nombre archivo

**Revertir un commit**

	git revert <id_commit>

### Comandos básicos V

**Deshacer multiples cambios en el repositorio**

	git reset -- soft < id_commit >
	git reset -- mixed < id_commit >
	git reset -- hard < id_commit >

**Listar archivos que git no controla**

	git clean -n

**Eliminar archivos que git no controla**

	git clean -f

**Ignorar archivos en el repositorio:**

.gitignore

### Comandos básicos VI

**Listar el contenido del repositorio de git**

	git ls - tree master
	git ls - tree master ^^^
	git ls - tree master ~3

**Log en una línea**

	git log -- oneline

**Log con los tres  últimos commits en una línea**

	git log -- oneline -3

Para mas opciones consultar documentación de git.

### Comandos básicos VII

**Examinar el contenido de un commit**

	git show <id >

**Comparar un commit con el actual**

	git diff < id > nombre_archivo

**Comparar dos commits**

	git diff id .. id nombre_archivo
	
***

## Ramas

Es la forma para separar la linea actual de desarrollo con respecto a la principal. Normalmente representan versiones del software que posteriormente son integradas a la linea principal.

![Imagen explicativa del funcionamiento de las ramas](https://uialberto.files.wordpress.com/2016/11/gitflowui.png?w=616&h=381)

### Comandos ramas I

**Para ver el listado de ramas**

	git branch

**Para crear una nueva rama**

	git branch nombre_rama

**Para cambiarnos a otra rama**

	git checkout nombre_rama

**Para crear una rama y moverse en un solo paso**

	git checkout -b nombre_rama

**Para comparar ramas**

	git diff nombre_rama .. nombre_rama

### Comandos ramas II

**Para ver ramas identicas a la actual**

	git branch --merged

**Para renombrar ramas**

	git branch -m nombre_antiguo nombre_nuevo

**Para eliminar ramas**

	git branch -d nombre_rama
	git branch -D nombre_rama

Para integrar ramas a la actual

	git merge nombre_rama

Para resolver conflictos

	git merge --abort

### Comandos ramas III

**Para almacenar cambios temporales**

	git stash save "Mensaje"

**Para listar cambios**

	git stash list

**Para ver el contenido de un cambio temporal**

	git stash show -p nombre_stash

**Para eliminar un cambio temporal**

	git stash drop nombre_stash

**Para aplicar el cambio del stash**

	git stash apply nombre_stash
	git stash pop nombre_stash'
	
***
***

# **GitHub**

## GitHub no es Git

Github y git no son lo mismo. Mientras que git es un sistema de control de versiones, github es la plataforma remota que aloja y sustenta dichos repositorios git.

![gitHub no es git](https://www.appcoda.com/wp-content/uploads/2018/04/git-notequal-github.png)


## Creación de respositorios

Lo primero que hay que hacer es acceder a gitHub y si no tienes cuenta, crear una.

> Debes saber que la opción gratuita **no incluye la posibilidad de repositorios privados**

![Alta gitHub](https://www.wikihow.com/images/thumb/2/2c/Join-github-1.jpg/728px-Join-github-1.jpg)

El proceso de creación de repositorios remotos es sencillo.

![Nuevos repositorio](http://www.malgreve.net/wp-content/uploads/2014/02/GitHub-Create-New-Repository.png)

La **información del repositorio** aparece una vez se crea el mismo.

![Información repositorio](https://d186loudes4jlv.cloudfront.net/git/images/github_new_repo3.png)

Para acceder al link del respositorio remoto una vez este contenga algún fichero se hace a través de la opción **clonar o descargar el repositorio**

![Clone or download](https://services.github.com/on-demand/images/gifs/github-cli/git-clone.gif)

***

## Comandos GitHub

### Comandos GitHub I

**Para añadir un repositorio remoto**

	git remote add origin url

**Para ver los repositorios remotos**

	git remote -v

**Para eliminar un repositorio remoto**

	git remote rm origin

**Para añadir cambios del repositorio local al remoto**

	git push -u origin master

**Para añadir cambios del repositorio remoto al local**

	git pull

### Comandos GitHub II

**Para ver branches remotos**

	git branch -r

**Para ver todos los branches**

	git branch -a

**Para clonar un repositorio remoto**

	git clone url

### Dar seguimiento a branches remotos

**LOCAL → REMOTO**

* Cambios en el repositorio local
* Commit de los cambios
* Añadir cambios a repositorio remoto:

		git push
	
**REMOTO → LOCAL**

* Sincronización unión:

		git fetch origin
		git merge origin/master

* En un solo paso:

		git pull

### Operaciones con Branches remotos

**Creación**

	git push -u origin branch_remoto

El proceso se hace como sigue a continuación:

* Crear branch local
* Hacer cambios en dicho branch
* Hacer commit
* Copiar el branch al repositorio remoto


**Copia**

	git checkout -b local remoto

**Eliminación**

	git push origin --delete branch_remoto
