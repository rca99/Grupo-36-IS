#! /bin/bash

#chmod +x guardarExterna.sh


sleep 2;

git remote set-url origin https://a52hepof:vn9rn7rz@github.com/rca99/Grupo-36-IS.git

wget -N -P ../AppGestionAlumnos/CopiaSeguridad https://github.com/rca99/Grupo-36-IS/raw/master/Practica4/2Sprint/Fernando/AppGestionAlumnos/gestionAlumnos.bin

git remote set-url origin https://github.com/rca99/Grupo-36-IS.git

echo -e "\e[34mCOPIA DE SEGURIDAD EXTERNA GUARDADA EN \e[0mAppGestionAlumnos/CopiaSeguridad\e[0m"

sleep 2;
