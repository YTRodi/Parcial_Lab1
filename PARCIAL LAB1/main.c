#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "Clientes.h"
#include "Juego.h"
#include "Categoria.h"
#include "Alquiler.h"

#define TAMCLI 15
#define TAMJU 12
#define TAMCAT 5
#define TAMALQUI 15


int menuInformesClientes();
void imprimirJuegosMesa(eJuego vecJuego[],int tJue, eCategoria vecCategoria[],int tCate);
void imprimirAlquileresPorClienteSeleccionado(eAlquiler vecAlquiler[],int tAlqui,eCliente vecCliente[],int tCli,eJuego vecJuego[],int tJue,eCategoria vecCategoria[],int tCate);



int main()
{
    eCliente arrayCliente[TAMCLI];
    eJuego arrayJuego[TAMJU];
    eCategoria arrayCategoria[TAMCAT];
    eAlquiler arrayAlquiler[TAMALQUI];

    char exit = 'n';
    char exitInforme = 'n';

    //CAMBIAR EL SUPERFLAGs A 0 PARA QUE FUNCIONE Y BORRAR EL HARDCODEO.
    int superFlag = 1;
    int superFlag2 = 1;

    int idCliente = 1000;
    int idAlquiler = 10000;

    inicializarCliente(arrayCliente,TAMCLI);
    inicializarAlquiler(arrayAlquiler,TAMALQUI);

    hardCodearJuegos(arrayJuego,TAMJU);
    hardCodearCategoria(arrayCategoria,TAMCAT);
    idCliente = idCliente + hardCodearClientes(arrayCliente,TAMCLI);
    idAlquiler = idAlquiler + hardCodearAlquileres(arrayAlquiler,TAMALQUI);


    do
    {
        switch(menuClienteGeneralUno())
        {
        case 1:
            if(altaClienteMaestra(arrayCliente,TAMCLI,idCliente))
            {
                idCliente++;
                superFlag = 1;
            }
            break;

        case 2:
            if(superFlag == 1)
            {
                modificarCliente(arrayCliente,TAMCLI);
            }
            else
            {
                printf("\nDebe cargar clientes antes.\n\n");
            }
            break;

        case 3:
            if(superFlag == 1)
            {
                bajaCliente(arrayCliente,TAMCLI);
            }
            else
            {
                printf("\nDebe cargar clientes antes.\n\n");
            }
            break;

        case 4:
            if(superFlag == 1)
            {
                //ordenarClientesPorApellidoYNombre(arrayCliente,TAMCLI);
                imprimirClientes(arrayCliente,TAMCLI);
            }
            else
            {
                printf("\nDebe cargar clientes antes.\n\n");
            }
            break;

        case 5:
            if(altaAlquiler(arrayAlquiler,TAMALQUI,idAlquiler,arrayCliente,TAMCLI,arrayJuego,TAMJU,arrayCategoria,TAMCAT))
            {
                idAlquiler++;
                superFlag2 = 1;
            }
            break;

        case 6:
            if(superFlag2 == 1)
            {
                imprimirAlquileres(arrayAlquiler,TAMALQUI,arrayJuego,TAMJU,arrayCliente,TAMCLI);
            }
            else
            {
                printf("\nDebe cargar Alquileres antes.\n\n");
            }
            break;

        case 7:
            //SOLO HARDCODEADO.
            imprimirCategorias(arrayCategoria,TAMCAT);
            break;

        case 8:
            //SOLO HARDCODEADO.
            imprimirJuegos(arrayJuego,TAMJU,arrayCategoria,TAMCAT);
            break;
        case 9:
            do
            {
                switch(menuInformesClientes())
                {
                    case 1:
                        imprimirJuegosMesa(arrayJuego,TAMJU,arrayCategoria,TAMCAT);
                        //printf("informe 1\n");
                        break;
                    case 2:
                        imprimirAlquileresPorClienteSeleccionado(arrayAlquiler,TAMALQUI,arrayCliente,TAMCLI,arrayJuego,TAMJU,arrayCategoria,TAMCAT);
                        //printf("informe 2\n");
                        break;
                    case 3:
                        printf("informe 3\n");
                        break;
                    case 4:
                        printf("informe 4\n");
                        break;
                    case 5:
                        printf("informe 5\n");
                        break;
                    case 10:
                        printf("Confirma salir? <s/n>: ");
                        fflush(stdin);
                        exitInforme = getche();
                        printf("\n\n");
                        break;
                    default:
                        printf("\n\n...Usted no ingreso una opcion valida...");
                        printf("\n\n...--Redireccionando al menu--...\n\n");
                }
                system("pause");

            }while(exitInforme == 'n');
            break;

        case 10:
            printf("Confirma salir? <s/n>: ");
            fflush(stdin);
            exit = getche();
            printf("\n\n");
            break;

        default:
            printf("\n\n...Usted no ingreso una opcion valida...");
            printf("\n\n...--Redireccionando al menu--...\n\n");

        }
        system("pause");

    }
    while(exit == 'n');

    return 0;
}

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

        //recorro todo el tamaño del vector de alquileres
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
