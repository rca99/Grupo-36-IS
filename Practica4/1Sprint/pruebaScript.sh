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



echo "Introduce la fecha de la Copia de seguridad:"
read TXT;
#git add gestionAlumnos.bin;
read NOMBREARCHIVO=gestionAlumnos+'$TXT'.bin;
mv  gestionAlumnos.bin  NOMBREARCHIVO;

git status;
cd ..
git add .;
clear;



git commit -m "Fecha última copia seguridad: $TXT"

git remote set-url origin https://a52hepof:vn9rn7rz@github.com/rca99/Grupo-36-IS.git

#cd 1Sprint
#git push -u origin master
#rm gestionAlumnos.bin
echo copia de seguridad realizada

 /usr/bin/firefox -new-window https://github.com/rca99/Grupo-36-IS/raw/master/Practica4/1Sprint/gestionAlumnos.bin

git remote set-url origin https://github.com/rca99/Grupo-36-IS.git


find -iname "*ges*"



##https://www.google.com/search?safe=active&client=ubuntu&hs=XGb&channel=fs&ei=FawGXK2ZJezEgAaqzLLQDg&q=shell+script+for+git+pull&oq=script+shell+para+git&gs_l=psy-ab.3.0.0i22i30l6.10585.18010..19905...5.0..0.314.3158.2j18j1j1......0....1..gws-wiz.......0j35i39j0i67j0i131j0i131i67j0i20i263j0i10j0i131i20i263j0i203j0i22i10i30.FEAJGkGnw3M