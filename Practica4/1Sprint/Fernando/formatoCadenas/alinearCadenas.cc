 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <iostream>
#include <ostream>

#include <math.h>
#include <iomanip>//formato cout


#define MAX 1000


using namespace std;

void centrar_cadena();
/*ostream &operator<<(ostream &os, void *(centrar_cadena)(char *, int))  
{  
   
    char c[MAX];
    int a;
    os << centrar_cadena(c, a);  
    return os;  
} 
*/ 


void substring(char *cadena, char *subcadena, int inicio, int longitud)
{
    int i;
   
    for(i=0; i < longitud && inicio+i < strlen(cadena); i++)
       subcadena[ i ] = cadena[ inicio+i ];

    subcadena[ i ] = '\0';
}

void centrar_linea(char *linea, int ancho)
{
    int i, espacios;
    espacios = (ancho - strlen(linea)) / 2;
   
    for(i=0; i < espacios; i++)
       printf(" ");

    printf("%s", linea);
}

void derecha_linea(char *linea, int ancho)
{
    int i, espacios;
    espacios = ancho - strlen(linea);
   
    for(i=0; i < espacios; i++)
       printf(" ");

    printf("%s", linea);
}

void centrar_cadena(char *cadena, int ancho)
{
    char subcadena[MAX];
    int i, total;

    total = (int)ceil((float)strlen(cadena) / ancho);
   
    for(i=0; i < total; i++)
    {
       substring(cadena, subcadena, i*ancho, ancho);
       centrar_linea(subcadena, ancho);
    }
}

void derecha_cadena(char *cadena, int ancho)
{
    char subcadena[MAX];
    int i, total;

    total = (int)ceil((float)strlen(cadena) / ancho);
   
    for(i=0; i < total; i++)
    {
       substring(cadena, subcadena, i*ancho, ancho);
       derecha_linea(subcadena, ancho);
    }
}


int main()
{
    char cadena[MAX];
   
    printf("Ingrese cadena: ");
    fgets(cadena, 100, stdin);

    printf("\n\nCadena centrada 120:\n");
    centrar_cadena(cadena, 120);

    printf("\n\nCadena alineada a la derecha:\n");
    derecha_cadena(cadena, 80);   
    printf("\n");
       
    system("PAUSE");

    centrar_cadena(cadena,40);
    char titulo[]="Cadena Centrada-----40";
    

    cout<<endl;
    cout<<endl;
    centrar_cadena(titulo,40);
    ////********EJERCICIO PARA SOBRECARGA DE OPEARDORES********
    //cout<<left<<setw(40)<<centrar_cadena(titulo,40)<<endl;
    cout<<endl;
    cout<<left<<setw(40)<<cadena<<endl;
    
    return 0;
}
