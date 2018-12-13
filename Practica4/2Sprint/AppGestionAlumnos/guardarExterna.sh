#! /bin/bash

#chmod +x guardarExterna.sh

git status;
cd ..
git add .;

##git add .;
clear;
echo "Introduce la fecha de la Copia de seguridad:"
read TXT;

git commit -m "Fecha última copia seguridad: $TXT"

git remote set-url origin https://a52hepof:vn9rn7rz@github.com/rca99/Grupo-36-IS.git

cd ..
git push -u origin Fernando
#rm gestionAlumnos.bin
echo copia de seguridad realizada