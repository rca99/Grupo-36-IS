#! /bin/bash

#chmod +x guardarExterna.sh
git init
git config --global user.name "Fernando Herrera Poch"
git config --global user.mail a52hepof@uco.es

git remote add origin https://github.com/rca99/Grupo-36-IS.git

git status;


git add gestionAlumnos.bin;

clear;
echo "Introduce la fecha de la Copia de seguridad:"
read TXT;

git commit -m "Fecha última copia seguridad: $TXT"

git remote set-url origin https://a52hepof:vn9rn7rz@github.com/rca99/Grupo-36-IS.git


git push -u origin master
#rm gestionAlumnos.bin
echo -e "\e[34mCOPIA DE SEGURIDAD REALIZADA\e[0m"
