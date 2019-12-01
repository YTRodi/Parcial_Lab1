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

#define TAMCLI 12
#define TAMJU 16
#define TAMCAT 5
#define TAMALQUI 21
#define TAMLOCA 6


/** A LO ULTIMO CAMBIAR EL SUPERFLAG A 0 ***/


int main()
{
    eCliente arrayCliente[TAMCLI];
    eJuego arrayJuego[TAMJU];
    eCategoria arrayCategoria[TAMCAT];
    eAlquiler arrayAlquiler[TAMALQUI];

    /**NUEVO ARRAY DE LOCALIDAD***/
    eLocalidad arrayLocalidad[TAMLOCA];

    char exit = 'n';
    char exitInforme = 'n';

    //CAMBIAR EL SUPERFLAGs A 0 PARA QUE FUNCIONE Y BORRAR EL HARDCODEO.
    int superFlag = 1;
    int superFlag2 = 1;

    int idCliente = 1000;
    int idAlquiler = 10000;
   // int idLocalidad = 100;

    inicializarCliente(arrayCliente,TAMCLI);
    inicializarAlquiler(arrayAlquiler,TAMALQUI);

    hardCodearJuegos(arrayJuego,TAMJU);
    hardCodearCategoria(arrayCategoria,TAMCAT);
    idCliente = idCliente + hardCodearClientes(arrayCliente,TAMCLI);
    idAlquiler = idAlquiler + hardCodearAlquileres(arrayAlquiler,TAMALQUI);

    hardCodearLocalidades(arrayLocalidad,TAMLOCA);

    do
    {
        switch(menuClienteGeneralUno())
        {
        case 1:
            if(altaClienteMaestra(arrayCliente,TAMCLI,idCliente,arrayLocalidad,TAMLOCA))
            {
                idCliente++;
                //idLocalidad++;
                superFlag = 1;
            }
            break;

        case 2:
            if(superFlag == 1)
            {
                modificarCliente(arrayCliente,TAMCLI,arrayLocalidad,TAMLOCA);
            }
            else
            {
                printf("\nDebe cargar clientes antes.\n\n");
            }
            break;

        case 3:
            if(superFlag == 1)
            {
                bajaCliente(arrayCliente,TAMCLI,arrayLocalidad,TAMLOCA);
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
                imprimirClientes(arrayCliente,TAMCLI,arrayLocalidad,TAMLOCA);
            }
            else
            {
                printf("\nDebe cargar clientes antes.\n\n");
            }
            break;

        case 5:
            if(altaAlquilerMaestra(arrayAlquiler,TAMALQUI,idAlquiler,arrayCliente,TAMCLI,arrayJuego,TAMJU,arrayCategoria,TAMCAT,arrayLocalidad,TAMLOCA))
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
                        listarClientesPorLocalidadDeterminada(arrayAlquiler,TAMALQUI,arrayCliente,TAMCLI,arrayJuego,TAMJU,arrayCategoria,TAMCAT,arrayLocalidad,TAMLOCA);
                        break;

                    case 2:
                        imprimirJuegosPreferidosDeUnaLocalidad(arrayCliente,TAMCLI,arrayAlquiler,TAMALQUI,arrayJuego,TAMJU,arrayCategoria,TAMCAT,arrayLocalidad,TAMLOCA);
                        break;

                    case 3:
                        listarMontoRecaudadoPorDeAlquileresXLocalidadDeterminada(arrayCliente,TAMCLI,arrayAlquiler,TAMALQUI,arrayJuego,TAMJU,arrayCategoria,TAMCAT,arrayLocalidad,TAMLOCA);
                        break;

                    case 4:
                        imprimirClienteYFechaQueAlquiloXJuego(arrayCliente,TAMCLI,arrayAlquiler,TAMALQUI,arrayJuego,TAMJU,arrayCategoria,TAMCAT,arrayLocalidad,TAMLOCA);
                        break;

                    case 5:
                        InformarCategoriaDeJuegosMenosAlquilada(arrayCliente,TAMCLI,arrayAlquiler,TAMALQUI,arrayJuego,TAMJU,arrayCategoria,TAMCAT,arrayLocalidad,TAMLOCA);
                        break;

                    case 6:
                        listarTelefonoesDeClientesXFechaDeterminada(arrayCliente,TAMCLI,arrayAlquiler,TAMALQUI,arrayJuego,TAMJU,arrayCategoria,TAMCAT,arrayLocalidad,TAMLOCA);
                        break;

                    case 7:
                        listarMujeresQueAlquilaron(arrayCliente,TAMCLI,arrayAlquiler,TAMALQUI,arrayLocalidad,TAMLOCA);
                        break;

                    case 8:
                        listarJuegosMasAlquiladosXHombres(arrayCliente,TAMCLI,arrayAlquiler,TAMALQUI,arrayJuego,TAMJU,arrayCategoria,TAMCAT,arrayLocalidad,TAMLOCA);
                        break;

                    case 9:
                        listarClientesQueAlquilaronXJuego(arrayCliente,TAMCLI,arrayAlquiler,TAMALQUI,arrayJuego,TAMJU,arrayCategoria,TAMCAT,arrayLocalidad,TAMLOCA);
                        break;

                    case 10:
                        mostrarRecaudacionDeUnaFechaDeterminada(arrayCliente,TAMCLI,arrayAlquiler,TAMALQUI,arrayJuego,TAMJU,arrayCategoria,TAMCAT,arrayLocalidad,TAMLOCA);
                        break;













                    case 99:
                        imprimirJuegosMesa(arrayJuego,TAMJU,arrayCategoria,TAMCAT);
                        //printf("informe 1\n");
                        break;
                    case 12:
                        imprimirAlquileresPorClienteSeleccionado(arrayAlquiler,TAMALQUI,arrayCliente,TAMCLI,arrayJuego,TAMJU,arrayCategoria,TAMCAT,arrayLocalidad,TAMLOCA);
                        //printf("informe 2\n");
                        break;
                    case 13:
                        imprimirTotalDeImportes(arrayAlquiler,TAMALQUI,arrayCliente,TAMCLI,arrayJuego,TAMJU,arrayLocalidad,TAMLOCA);
                        //printf("informe 3\n");
                        break;
                    case 14:
                        //printf("informe 4\n");
                        imprimirClientesQueNoAlquilaron(arrayAlquiler,TAMALQUI,arrayCliente,TAMCLI,arrayLocalidad,TAMLOCA);
                        break;
                    case 15:
                        //printf("informe 5\n");
                        imprimirJuegosQueNoAlquilaron(arrayAlquiler,TAMALQUI,arrayJuego,TAMJU,arrayCategoria,TAMCAT);
                        break;




                    /**---LOS QUE PRACTIQUE EN CASA?--***/


                    case 16:
                        clienteConMasAlquiler(arrayCliente,TAMCLI,arrayAlquiler,TAMALQUI,arrayJuego,TAMJU,arrayCategoria,TAMCAT,arrayLocalidad,TAMLOCA);
                        break;

                    case 17:
                        listarClientesConXAlquileres(arrayCliente,TAMCLI,arrayAlquiler,TAMALQUI,arrayLocalidad,TAMLOCA);
                        break;

                    case 18:
                        //listarMujeresQueAlquilaron(arrayCliente,TAMCLI,arrayAlquiler,TAMALQUI,arrayLocalidad,TAMLOCA);
                        break;

                    case 19:
                        listarMujeresQueAlquilaronJuegosDeXCategoria(arrayCliente,TAMCLI,arrayAlquiler,TAMALQUI,arrayJuego,TAMJU,arrayCategoria,TAMCAT,arrayLocalidad,TAMLOCA);
                        break;

                    case 20:
                        listarClientesPorFecha(arrayCliente,TAMCLI,arrayAlquiler,TAMALQUI,arrayLocalidad,TAMLOCA);
                        break;

                    case 21:
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

        case 11:
            printf("\n");
            imprimirLocalidad(arrayLocalidad,TAMLOCA);
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

