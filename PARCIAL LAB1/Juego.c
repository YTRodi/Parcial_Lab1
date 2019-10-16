#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "Juego.h"

void hardCodearJuegos(eJuego vecJuego[],int tJue,int cant)
{
    //El ultimo cero es su estado isEmpty.
    eJuego bJuego[]=
    {
        //AGREGAR AL ULTIMO CAMPO EL ID DE CATEGORIA
        //IDJUEGO, Descripcion,importe,idcategoria.
        {10,"Galera magica",1000,5},
        {11,"Metegol",5000,4},
        {12,"Pool",8000,4},
        {13,"Cubo Rubik",200,3},
        {14,"Jenga",450,1},
        {15,"Cartas",125,2}
    };

    for(int i = 0; i<tJue;i++)
    {
        vecJuego[i] = bJuego[i];
    }
}

void mostrarUnJuego(eJuego vecJuego,eCategoria vecCategoria[],int tCate)
{
    char nombre[20];

    cargarDescripcionCategoria(vecCategoria,tCate,vecJuego.idCategoria,nombre);

    printf("%4d %15s   $%.2f %15s\n\n",
           vecJuego.idJue,
           vecJuego.descripcion,
           vecJuego.importe,
           nombre);
}

void imprimirJuegos(eJuego vecJuego[],int tJue,eCategoria vecCategoria[],int tCate)
{
    printf("  ID          NOMBRE    IMPORTE     DESCRIPCION\n");
    printf("  --          ------    -------     -----------\n\n");

    for(int i=0;i<tJue;i++)
    {
        mostrarUnJuego(vecJuego[i],vecCategoria,tCate);
    }
}

void cargarDescripcionJuego(eJuego vecJuego[],int tJue,int id,char descripcion[])
{
    for(int i = 0; i<tJue;i++)
    {
        if(vecJuego[i].idJue == id)
        {
            strcpy(descripcion,vecJuego[i].descripcion);
        }
    }
}
