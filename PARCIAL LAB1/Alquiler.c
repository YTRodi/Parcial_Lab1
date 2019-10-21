#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "Clientes.h"
#include "Juego.h"
#include "Categoria.h"
#include "Alquiler.h"

/** \brief Carga 20 Alquileres con sus respectivos:
 *         -Id
 *         -IdJuego.
 *         -IdCliente.
 *         -Fecha.
 *         -IsEmpty.
 *
 * \param vecAlquiler[] Array del tipo estructura de alquileres.
 * \param tAlqui Longitud/tamaño del Array de estructura.
 * \return int Contador.
 *
 */
int hardCodearAlquileres(eAlquiler vecAlquiler[],int tAlqui)//,int cantidad)
{
    int contador = 0;

    eAlquiler bAlquiler[]=
    {
        //idAlqui,idJuego,idCliente,fecha y estado isEmpty
        {10000,10,1002,{15,10,2019},0},
        {10001,12,1000,{5,11,2011},0},
        {10002,15,1005,{18,8,2018},0},
        {10003,14,1003,{24,6,2017},0},
        {10004,14,1004,{7,4,2013},0},
        {10005,17,1001,{27,9,2012},0},
        {10006,13,1005,{20,2,2010},0},
        {10007,12,1003,{30,9,2014},0},
        {10008,19,1001,{24,12,2012},0},
        {10009,21,1002,{8,9,2000},0},
        {10010,13,1000,{7,9,1998},0},
        {10011,21,1002,{21,10,2001},0},
        {10012,12,1009,{4,4,2008},0},
        {10013,25,1003,{5,8,1999},0},
        {10014,18,1001,{25,1,2010},0},
        {10015,24,1008,{26,12,2019},0},
        {10016,15,1003,{22,11,2013},0},
        {10017,13,1009,{15,2,2014},0},
        {10018,11,1005,{9,4,2016},0},
        {10019,23,1002,{10,10,2010},0}
    };

    for(int i = 0; i<20; i++)
    {
        vecAlquiler[i] = bAlquiler[i];
        contador++;
    }

    return contador;
}


/** \brief Inicializa el array del tipo estructura de modo que el estado isEmpty
 *         de cada posicion del array sea 1 en todas sus posiciones.
 *
 * \param vecAlquiler[] Array de estructura a inicializar.
 * \param tAlqui Longitud/tamaño del Array de estructura.
 * \return void No retorna nada.
 *
 */
void inicializarAlquiler(eAlquiler vecAlquiler[], int tAlqui)
{
    for(int i = 0; i < tAlqui; i++)
    {
        vecAlquiler[i].isEmpty = 1;//LIBREEEEEE
    }
}


/** \brief Encuentra la primera posicion disponible del
 *         array pasado por parametro o informa si esta lleno.
 *
 * \param vecAlquiler[] Array del tipo estructura en donde se buscara la posicion libre.
 * \param tAlqui Longitud/tamaño del Array de estructura.
 * \return int Retorna el índice de la primera posicion disponible que encuentra.
 *
 */
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


/** \brief  Muestra por pantalla a un Alquiler pasado por parametro.
 *
 * \param vecAlquiler Alquiler a ser mostrado.
 * \param vecJuego[] Array del tipo estructura de Juegos.
 * \param tJue Longitud/tamaño del Array de estructura.
 * \param vecCliente[] Array del tipo estructura de Clientes.
 * \param tCli Longitud/tamaño del Array de estructura.
 * \return void No retorna nada.
 *
 */
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


/** \brief Imprime por pantalla todo el array de Alquileres pasado por parametro.
 *
 * \param vecAlquiler[] Array del tipo estructura de alquileres.
 * \param tAlqui Array del tipo estructura de Alquileres.
 * \param vecJuego[] Array del tipo estructura de Juegos.
 * \param tJue Longitud/tamaño del Array de estructura.
 * \param vecCliente[] Array del tipo estructura de Clientes.
 * \param tCli Longitud/tamaño del Array de estructura.
 * \return int Retorna [0] si no hay Alquileres que mostrar - [1] Todo OK.
 *
 */
int imprimirAlquileres(eAlquiler vecAlquiler[],int tAlqui,eJuego vecJuego[],int tJue,eCliente vecCliente[],int tCli)
{
    int flag=0;

    printf("  ID             JUEGO        CLIENTE(APE Y NOM)         FECHA\n");
    printf("  --             -----        ------------------         -----\n\n");

    for(int i=0; i<tAlqui; i++)
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



/** \brief Da de alta al Alquiler.
 *         Se fija si hay lugar libre.
 *         Si lo hay, pide los datos.
 *
 * \param vecAlquiler[] Array del tipo estructura a dar de alta.
 * \param tAlqui Longitud/tamaño del Array de estructura.
 * \param lastIdAlquiler Ultimo Id que se va a igualar al Id de Alquiler.
 * \param vecCliente[] Array del tipo estructura de Clientes.
 * \param tCli Longitud/tamaño del Array de estructura.
 * \param vecJuego[] Array del tipo estructura de Juegos.
 * \param tJue Longitud/tamaño del Array de estructura.
 * \param vecCategoria[] eCategoria Array del tipo estructura de Categorias.
 * \param tCate Longitud/tamaño del Array de estructura.
 * \return int Retorna [0] si hubo un ERROR - [1] Todo OK.
 *
 */
int altaAlquilerMaestra(eAlquiler vecAlquiler[],
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

        if(getInt(&vecAlquiler[index].idJuego,"\n<10-15>\nIngrese ID de juego: ","Error.Reingrese\n",10,25,2)!=-1)
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
        if(todoOk != 1)
        {
            printf("\nError en la carga de datos.\n");
        }


    }

    return todoOk;
}
