#! /bin/bash

#chmod +x guardarExterna.sh


sleep 1;

rm -r ./CopiaSeguridad/*.bin


git remote set-url origin https://a52hepof:vn9rn7rz@github.com/a52hepof/APPGestionAlumnos.git

wget -N -P ../AppGestionAlumnos/CopiaSeguridad https://github.com/a52hepof/APPGestionAlumnos/raw/master/gestionAlumnos.bin

git remote set-url origin https://github.com/a52hepof/APPGestionAlumnos.git

echo -e "\e[34mCOPIA DE SEGURIDAD EXTERNA GUARDADA EN \e[0mAppGestionAlumnos/CopiaSeguridad\e[0m"

sleep 2;
github.com/a52hepof/APPGestionAlumnos.git