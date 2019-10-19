#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "Clientes.h"
#include "Juego.h"
#include "Categoria.h"
#include "Alquiler.h"
#include "informes.h"

int menuInformesClientes()
{
    int option;
    system("cls");
    printf("---ABM PARCIAL---\n\n");
    printf("1 - Mostrar juegos de categoria de mesa\n");
    printf("2 - Mostrar los alquileres efectuados por algun cliente seleccionado\n");
    printf("3 - Mostrar el total de todos los importes pagados por el cliente seleccionado\n");
    printf("4 - Listar los clientes que no alquilaron juegos\n");
    printf("5 - Listar los juegos que no han sido alquilados\n");
    printf("10 - SALIR\n");
    getInt(&option,"\nIngrese opcion: ","Error. opcion no valida",1,10,2);
    //ACA LIMITAR LA OPCION, MUY IMPORTANTE!!!!!!!!!!!!!!!!!!!!!
    return option;
}


void imprimirJuegosMesa(eJuego vecJuego[],int tJue, eCategoria vecCategoria[],int tCate)
{
    char nombre[20];
    int flag = 0;

    printf("\n");
    printf("  ID          NOMBRE    IMPORTE     DESCRIPCION\n");
    printf("  --          ------    -------     -----------\n\n");

    for(int i = 0; i<tJue;i++)
    {

        for(int j = 0; j<tCate;j++)
        {
            if(vecJuego[i].idCategoria == vecCategoria[j].idCate)
            {
                //cargo todas las descripciones de las categorias.

                cargarDescripcionCategoria(vecCategoria,tCate,vecJuego[i].idCategoria,nombre);

                if(strcmpi(nombre,"mesa")==0)
                {
                    //vecJuego[i] == estamos hablando de UN juego solamente adentro del array.
                    mostrarUnJuego(vecJuego[i],vecCategoria,tCate);
                    flag = 1;
                }
            }
        }
    }
    if(flag == 0)
    {
        printf("\n--No hay juegos de mesa--\n\n");
    }
}

void imprimirAlquileresPorClienteSeleccionado(eAlquiler vecAlquiler[],int tAlqui,eCliente vecCliente[],int tCli,eJuego vecJuego[],int tJue,eCategoria vecCategoria[],int tCate)
{

    int idClienteABuscar;
    int index;
    int flag = 0;

    printf("\n**ALQUILERES POR CLIENTES**\n\n");

    imprimirClientes(vecCliente,tCli);
    getInt(&idClienteABuscar,"\nIngrese ID del cliente: ","\nError. Reingrese un numero de id valido\n",1000,1999,2);


    index = buscarClienteId(vecCliente,tCli,idClienteABuscar);

    if(index == -1)
    {
        printf("\nNo existe un cliente con ese ID.\n\n");
    }
    else
    {
        printf("\n");
        printf("  ID             JUEGO        CLIENTE(APE Y NOM)         FECHA\n");
        printf("  --             -----        ------------------         -----\n\n");

        //recorro todo el tama�o del vector de alquileres
        for(int i = 0; i<tAlqui;i++)
        {
            if(vecAlquiler[i].idCliente == idClienteABuscar && vecAlquiler[i].isEmpty == 0)
            {
                //vecAlquiler[i] == estamos hablando de UN alquiler solamente adentro de todo el array.

                mostrarUnAlquiler(vecAlquiler[i],vecJuego,tJue,vecCliente,tCli);
                flag = 1;
            }

        }
    }

    if(flag == 0)
    {
        printf("\nEl Cliente no dio de alta ningun alquiler\n\n");
    }

}

void imprimirTotalDeImportes(eAlquiler vecAlquiler[],int tAlqui,eCliente vecCliente[],int tCli, eJuego vecJuego[],int tJue)
{
    int idClienteABuscar;
    int index;
    float acumulador = 0;

    printf("\n**TOTAL DE IMPORTES POR CLIENTE**\n\n");

    imprimirClientes(vecCliente,tCli);
    getInt(&idClienteABuscar,"\nIngrese ID del cliente: ","\nError. Reingrese un numero de id valido\n",1000,1999,2);


    index = buscarClienteId(vecCliente,tCli,idClienteABuscar);

    if(index == -1)
    {
        printf("\nNo existe un cliente con ese ID.\n\n");
    }
    else
    {
        //recorro los alquileres.
        for(int i = 0;i<tAlqui;i++)
        {
            if(vecAlquiler[i].idCliente == idClienteABuscar && vecAlquiler[i].isEmpty == 0)
            {
                //recorro los juegos.
                for(int j = 0; j<tJue;j++)
                {
                    if(vecJuego[j].idJue == vecAlquiler[i].idJuego)
                    {
                        acumulador = acumulador + vecJuego[j].importe;
                    }
                }
            }
        }
    }

    printf("\n\nLa suma acumulada del cliente es: $%.2f\n\n",acumulador);
}

void imprimirClientesQueNoAlquilaron(eAlquiler vecAlquiler[],int tAlqui,eCliente vecCliente[],int tCli)
{
    int contador;

    printf("\n");
    printf("  ID       NOMBRE     APELLIDO     SEXO     TELEFONO     DIRECCION\n");
    printf("  --       ------     --------     ----     --------     ---------\n\n");

    for (int i=0;i<tCli;i++)
    {
        contador = 0;

        if(vecCliente[i].isEmpty == 0)
        {
            if(tienePedidoAlquiler(vecCliente[i].id,vecAlquiler,tAlqui) == 0)//si cambio el == 1 me muestralos que alquilaron
            {
                mostrarUnCliente(vecCliente[i]);
                //printf("%d %s %s\n\n",vecCliente[i].id,vecCliente[i].nombre,vecCliente[i].apellido);//los que no alquilaron
            }
        }

        /*for(int j=0;j<tAlqui;j++)
        {
            if(vecCliente[i].id == vecAlquiler[j].idCliente && vecCliente[i].isEmpty == 0)
            {
                //cuento los clientes que alquilaron.

                contador++;
            }
        }

        //si no entra al if del segundo for quiere decir que no alquilo.(osea el contador == 0);
        if(contador == 0 && vecCliente[i].isEmpty == 0)
        {
            mostrarUnCliente(vecCliente[i]);
        }*/
    }

}

void imprimirJuegosQueNoAlquilaron(eAlquiler vecAlquiler[],int tAlqui,eJuego vecJuego[],int tJue,eCategoria vecCategoria[],int tCate)
{
    int contador;

    printf("\n");
    printf("  ID          NOMBRE    IMPORTE     DESCRIPCION\n");
    printf("  --          ------    -------     -----------\n\n");

    for(int i = 0 ; i<tJue; i++)
    {
        contador = 0;

       // for(int j = 0; j<tAlqui;j++)
        //{
            if(tienePedidoJuego(vecJuego[i].idJue,vecAlquiler,tAlqui)==0)
            {

                mostrarUnJuego(vecJuego[i],vecCategoria,tCate);
            }




      //  }
            /*if(vecJuego[i].idJue == vecAlquiler[j].idJuego)
            {
                contador++;
            }
        }

        if(contador == 0)
        {
            mostrarUnJuego(vecJuego[i],vecCategoria,tCate);
        }*/

    }
}


int tienePedidoAlquiler(int idCliente,eAlquiler listAlquiler[],int tamAl)
{

    for(int i =0;i<tamAl;i++)
    {
        if(listAlquiler[i].idCliente == idCliente)
        {
            return 1;
        }

    }

    return 0;

}

int tienePedidoJuego(int id,eAlquiler vecAlquiler[],int tam)
{

    for(int i =0;i<tam;i++)
    {
        if(vecAlquiler[i].idJuego == id)
        {
            return 1;
        }

    }

    return 0;
}


