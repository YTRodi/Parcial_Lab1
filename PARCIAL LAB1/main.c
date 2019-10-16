#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "Clientes.h"
#include "Juego.h"
#include "Categoria.h"
#include "Alquiler.h"

#define TAMCLI 6
#define TAMJU 6
#define TAMCAT 5
#define TAMALQUI 6

int main()
{
    eCliente arrayCliente[TAMCLI];
    eJuego arrayJuego[TAMJU];
    eCategoria arrayCategoria[TAMCAT];
    eAlquiler arrayAlquiler[TAMALQUI];

    char exit = 'n';

    //CAMBIAR EL SUPERFLAGs A 0 PARA QUE FUNCIONE Y BORRAR EL HARDCODEO.
    int superFlag = 0;
    int superFlag2 = 0;

    int idCliente = 1000;
    int idAlquiler = 10000;

    inicializarCliente(arrayCliente,TAMCLI);
    inicializarAlquiler(arrayAlquiler,TAMALQUI);

    hardCodearJuegos(arrayJuego,TAMJU,6);
    hardCodearCategoria(arrayCategoria,TAMCAT,5);
    //idCliente = idCliente + hardCodearClientes(arrayCliente,TAMCLI,6);
    //idAlquiler = idAlquiler + hardCodearAlquileres(arrayAlquiler,TAMALQUI,6);

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
                ordenarClientesPorApellidoYNombre(arrayCliente,TAMCLI);
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
            printf("Confirma salir? <s/n>: ");
            fflush(stdin);
            exit = getche();
            printf("\n\n");
            break;

        default:
            printf("\n\n...Redireccionando al menu...\n\n");

        }
        system("pause");

    }
    while(exit == 'n');

    return 0;
}

