#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "Clientes.h"
#include "Juego.h"
#include "Categoria.h"
#include "Alquiler.h"

int hardCodearAlquileres(eAlquiler vecAlquiler[],int tAlqui,int cantidad)
{
    int contador = 0;

    eAlquiler bAlquiler[]=
    {
        //idAlqui,idJuego,idCliente,fecha y estado isEmpty
        {10000,10,1002,{15,10,2019},0},
        {10001,12,1000,{5,11,2011},0},
        {10002,15,1005,{18,8,2018},0},
        {10003,11,1003,{24,6,2017},0},
        {10004,14,1004,{7,4,2013},0},
        {10005,10,1001,{27,9,2012},0},
    };

    if(cantidad<=tAlqui && cantidad <=10)
    {
        for(int i=0;i<tAlqui;i++)
        {
            /*Que recorra todas las posiciones del vector de alquiler
            y que vaya igualando secuencialmente todos los campos de la estructura*/

            vecAlquiler[i] = bAlquiler[i];
            contador++;
        }
    }

    return contador;
}


void inicializarAlquiler(eAlquiler vecAlquiler[], int tAlqui)
{
    for(int i = 0; i < tAlqui; i++)
    {
        vecAlquiler[i].isEmpty = 1;//LIBREEEEEE
    }
}


int buscarLibreAlquiler(eAlquiler vecAlquiler[], int tAlqui)
{
    int indice = -1;

    for(int i=0; i < tAlqui; i++)
    {
        if(vecAlquiler[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void mostrarUnAlquiler(eAlquiler vecAlquiler,eJuego vecJuego[],int tJue,eCliente vecCliente[],int tCli)
{
    char nombreCliente[20];
    char nombreJuego[20];

    cargarDescripcionCliente(vecCliente,tCli,vecAlquiler.idCliente,nombreCliente);
    cargarDescripcionJuego(vecJuego,tJue,vecAlquiler.idJuego,nombreJuego);

    //IdAlqui, idJuego, idCliente, eFecha(dia,mes,anio),
    printf("%4d  %15s       %19s    %02d/%02d/%d\n\n",
           vecAlquiler.idAlqui,
           nombreJuego,
           nombreCliente,
           vecAlquiler.fechaAlquiler.dia,
           vecAlquiler.fechaAlquiler.mes,
           vecAlquiler.fechaAlquiler.anio);
}

int imprimirAlquileres(eAlquiler vecAlquiler[],int tAlqui,eJuego vecJuego[],int tJue,eCliente vecCliente[],int tCli)
{
    int flag=0;

    printf("  ID             JUEGO        CLIENTE(APE Y NOM)         FECHA\n");
    printf("  --             -----        ------------------         -----\n\n");

    for(int i=0; i<tJue; i++)
    {
        if(vecAlquiler[i].isEmpty == 0)
        {
            mostrarUnAlquiler(vecAlquiler[i],vecJuego,tJue,vecCliente,tCli);
            flag=1;
        }
    }
    if (flag==0)
    {
        printf("\nNo hay --Alquileres-- que mostrar.\n\n");
    }
    return flag;
}


int altaAlquiler(eAlquiler vecAlquiler[],
                 int tAlqui,
                 int lastIdAlquiler,
                 eCliente vecCliente[],
                 int tCli,
                 eJuego vecJuego[],
                 int tJue,
                 eCategoria vecCategoria[],
                 int tCate)
{
    int todoOk= 0;
    int index;

    system("cls");
    printf("\n Alta --Alquiler--\n\n");

    index = buscarLibreAlquiler(vecAlquiler,tAlqui);

    if(index == -1)
    {
        printf("\n--Sistema completo.--\n\n");
    }
    else
    {
        imprimirJuegos(vecJuego,tJue,vecCategoria,tCate);

        if(getInt(&vecAlquiler[index].idJuego,"\n<10-15>\nIngrese ID de juego: ","Error.Reingrese\n",10,15,2)!=-1)
        {
            printf("\n\n");
            imprimirClientes(vecCliente,tCli);
            if(getInt(&vecAlquiler[index].idCliente,"\n\n<1000-1999>\nIngrese ID del cliente: ","Error.Reingrese\n",1000,1999,2)!=-1)
            {
                if(getInt(&vecAlquiler[index].fechaAlquiler.dia,"\n<1-31>\nIngrese dia: ","Error.Reingrese\n",1,31,2)!=-1)
                {
                    if(getInt(&vecAlquiler[index].fechaAlquiler.mes,"\n<1-12>\nIngrese mes: ","Error.Reingrese\n",1,12,2)!=-1)
                    {
                        if(getInt(&vecAlquiler[index].fechaAlquiler.anio,"\n<1995-2019>\nIngrese anio: ","Error.Reingrese\n",1995,2019,2)!=-1)
                        {
                            vecAlquiler[index].idAlqui = lastIdAlquiler;
                            vecAlquiler[index].isEmpty = 0;
                            todoOk = 1;
                            printf("\n--Alta de --Alquiler-- exitosa--\n\n");
                        }
                    }
                }
            }

        }

    }
    if(todoOk != 1)
    {
        printf("\nError en la carga de datos.\n");
    }

    return todoOk;
}
