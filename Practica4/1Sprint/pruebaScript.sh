#! /bin/bash
#Le pasamos dos parametros e imprime el que esta en la posicion 1 y 2
#if [ ! -d '.git' ]; then
#	echo 'Esta carpeta no contiene un repositorio Git'
#	exit -1
#fi


echo "Hola" $1;
echo "Hola" $2;
echo "Nombre del fichero:" $0;
echo "Numero de parametros": $#;
echo "Todos los parametros menos el 0": $*;

git status;
git add .;
read TXT;
git commit -am 'actualización'
git push -u https://a52hepof:vn9rn7rz@git@github.com:rca99/Grupo-36-IS.git --all
echo "a52hepof"
echo "vn9rn7rz"



