### *Dar seguimiento a branches remotos*

* LOCAL → REMOTO
	* Cambios en el repositorio local
	* Commit de los cambios
	* Añadir cambios a repositorio remoto:
	`git push`
* REMOTO → LOCAL
	* Sincronización unión:
	~~~
	git fetch origin
	git merge origin/master
	~~~
	* En un solo paso:
	`git pull`

