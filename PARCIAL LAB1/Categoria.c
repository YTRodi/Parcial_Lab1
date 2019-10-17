#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "Categoria.h"

void hardCodearCategoria(eCategoria vecCategoria[],int tCate)//,int cant)
{
    eCategoria bCategoria[]=
    {
        //idCategoria y nombre (descripcion)
        {1,"Mesa"},
        {2,"Azar"},
        {3,"Estrategia"},
        {4,"Salon"},
        {5,"Magia"}
    };

    for(int i = 0; i<tCate;i++)
    {
        vecCategoria[i] = bCategoria[i];
    }

}

void mostrarCategoria(eCategoria vecCategoria)
{
    printf("%4d %15s\n\n",vecCategoria.idCate,vecCategoria.descripcion);
}

void imprimirCategorias(eCategoria vecCategoria[],int tCate)
{
    printf("  ID       CATEGORIA\n");
    printf("  --       ---------\n\n");

    for(int i=0; i<tCate; i++)
    {
        mostrarCategoria(vecCategoria[i]);
    }


}

int cargarDescripcionCategoria(eCategoria vecCategoria[],int tCate,int id,char descripcion[])
{
    int todoOk = 0;

    for(int i = 0;i<tCate;i++)
    {
        if(vecCategoria[i].idCate == id)
        {
            strcpy(descripcion,vecCategoria[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}
