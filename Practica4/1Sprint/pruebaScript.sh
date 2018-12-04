#! /bin/bash
#Le pasamos dos parametros e imprime el que esta en la posicion 1 y 2
echo "Hola" $1;
echo "Hola" $2;
echo "Nombre del fichero:" $0;
echo "Numero de parametros": $#;
echo "Todos los parametros menos el 0": $*;

git status;
git add .;
git commit -am 'actualización'
git push -u origin master
echo "a52hepof"
echo "vn9rn7rz"