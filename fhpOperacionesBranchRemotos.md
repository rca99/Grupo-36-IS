### Operaciones con Branch remotos

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
