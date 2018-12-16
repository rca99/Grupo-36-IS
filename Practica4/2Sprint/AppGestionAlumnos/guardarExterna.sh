#! /bin/bash

#chmod +x guardarExterna.sh


git status;


git add gestionAlumnos.bin;

clear;
echo "Introduce la fecha de la Copia de seguridad:"
read TXT;

git commit -m "Fecha última copia seguridad: $TXT"

git remote set-url origin https://a52hepof:vn9rn7rz@github.com/rca99/Grupo-36-IS.git

cd ..
git push -u origin master
#rm gestionAlumnos.bin
echo -e "\e[34mCOPIA DE SEGURIDAD REALIZADA\e[0m"
