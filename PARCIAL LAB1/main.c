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

#define TAMCLI 10
#define TAMJU 12
#define TAMCAT 5
#define TAMALQUI 15


/***
--HACER:
-DOXYGEN
-HARDCODEAR + ALQUILERES
-HARDCODEAR + CLIENTES
-HARDCODEAR + JUEGOS


**/




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
                        imprimirTotalDeImportes(arrayAlquiler,TAMALQUI,arrayCliente,TAMCLI,arrayJuego,TAMJU);
                        //printf("informe 3\n");
                        break;
                    case 4:
                        //printf("informe 4\n");
                        imprimirClientesQueNoAlquilaron(arrayAlquiler,TAMALQUI,arrayCliente,TAMCLI);
                        break;
                    case 5:
                        //printf("informe 5\n");
                        imprimirJuegosQueNoAlquilaron(arrayAlquiler,TAMALQUI,arrayJuego,TAMJU,arrayCategoria,TAMCAT);
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

