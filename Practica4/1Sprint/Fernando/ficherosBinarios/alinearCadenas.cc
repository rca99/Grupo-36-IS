 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000

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
    fgets(cadena);

    printf("\n\nCadena centrada:\n");
    centrar_cadena(cadena, 80);

    printf("\n\nCadena alineada a la derecha:\n");
    derecha_cadena(cadena, 80);   
    printf("\n");
       
    system("PAUSE");
    return 0;
}
