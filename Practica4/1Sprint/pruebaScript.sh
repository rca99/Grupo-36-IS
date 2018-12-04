#! /bin/bash
#Le pasamos dos parametros e imprime el que esta en la posicion 1 y 2
#if [ ! -d '.git' ]; then
#	echo 'Esta carpeta no contiene un repositorio Git'
#	exit -1
#fi


echo "-" $1;
echo "-" $2;
echo "Nombre del fichero:" $0;
echo "Numero de parametros": $#;
echo "Todos los parametros menos el 0": $*;


git status;

#git add gestionAlumnos.bin;


cd ..
git add .;
clear;
echo "Introduce la fecha de la Copia de seguridad:"
read TXT;

git commit -m "Fecha última copia seguridad: $TXT"

git remote set-url origin https://a52hepof:vn9rn7rz@github.com/rca99/Grupo-36-IS.git

cd 1Sprint
git push -u origin master
rm gestionAlumnos.bin
echo copia de seguridad realizada



git remote set-url origin https://github.com/rca99/Grupo-36-IS.git


