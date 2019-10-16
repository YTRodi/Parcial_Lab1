#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"

#define TAMCLI 5

typedef struct
{
    char nombre[50];
    char apellido[50];
    char sexo;
    char telefono[50];
    int edad;
    char domicilio[50];
    int id;
    int isEmpty;
}eCliente;

int menuClienteGeneralUno();
void inicializarCliente(eCliente vecCliente[], int tCli);
int buscarLibreCliente(eCliente vecCliente[], int tCli);
void mostrarUnCliente(eCliente vecCliente);
int imprimirClientes(eCliente vecCliente[],int tCli);
int altaClienteMaestra(eCliente vecCliente[],int tCli,int lastId);


int hardCodearClientes(eCliente vecCliente[],int tCli,int cant);



int main()
{
    eCliente arrayCliente[TAMCLI];

    char exit = 'n';

    int idCliente = 100;

    inicializarCliente(arrayCliente,TAMCLI);

    idCliente = idCliente + hardCodearClientes(arrayCliente,TAMCLI);

    do
    {
        switch(menuClienteGeneralUno())
        {
            case 1:
                if(altaClienteMaestra(arrayCliente,TAMCLI,idCliente))
                {
                    idCliente++;
                }
                /*if(altaClienteMaestra(arrayCliente,TAMCLI) == 0)
                {
                    superFlag =1;
                */
                break;

            case 2://modificarCliente(arrayCliente,TAMCLI);
                /*if(superFlag == 1)
                {

                }
                else
                {
                    printf("\nDebe cargar clientes antes.\n\n");
                }*/
                break;

            case 3://bajaCliente(arrayCliente,TAMCLI);
                /*if(superFlag == 1)
                {

                }
                else
                {
                    printf("\nDebe cargar clientes antes.\n\n");
                }*/
                break;

            case 4:
               // ordenarPorNombreDescendente(arrayCliente,TAMCLI);
                //ordenarPorId(arrayCliente,TAMCLI);
                //ordenarAlfabeticamente(arrayCliente,TAMCLI);
                imprimirClientes(arrayCliente,TAMCLI);
                /*if(superFlag == 1)
                {

                }
                else
                {
                    printf("\nDebe cargar clientes antes.\n\n");
                }*/
                break;
            case 5:
                printf("alta alquiler\n");
                break;
            case 6:
                //imprimirAlquileres(arrayAlquiler,TAMAL,arrayCliente,TAMCLI);

                break;

            case 7:
            printf("Confirma salir? <s/n>: ");
            fflush(stdin);
            exit = getche();
            printf("\n\n");
            break;

            default:
                printf("\n...Redireccionando al menu...\n");

        }
    system("pause");

    }while(exit == 'n');

    return 0;



    return 0;




    return 0;
}

/** \brief Muestra un menu de opciones.
 *
 * \return int La opcion elegida.
 *
 */
int menuClienteGeneralUno()
{
    int option;
    system("cls");
    printf("---ABM PARCIAL---\n\n");
    printf("1 - ALTA cliente\n");
    printf("2 - MODIFICAR cliente\n");
    printf("3 - BAJA cliente\n");
    printf("4 - IMPRIMIR cliente\n");
    printf("5 - ALTA alquiler\n");
    printf("6 - IMPRIMIR alquiler\n");

    printf("7 - SALIR\n");
    getInt(&option,"\nIngrese opcion: ","Error. opcion no valida",1,6,2);
    //ACA LIMITAR LA OPCION, MUY IMPORTANTE!!!!!!!!!!!!!!!!!!!!!
    return option;
}

/** \brief Inicializa el array del tipo estructura de modo que el estado isEmpty
 *         de cada posicion del array sea 1 en todas sus posiciones.
 *
 * \param listFantasma[] Array de estructura a inicializar.
 * \param tFant Longitud/tamaño del Array de estructura.
 *
 */
void inicializarCliente(eCliente vecCliente[], int tCli)
{
    for(int i = 0; i < tCli; i++)
    {
        vecCliente[i].isEmpty = 1;//LIBREEEEEE
    }
}


/** \brief Encuentra la primera posicion disponible del
           array pasado por parametro o informa si esta lleno.
 *
 * \param listFantasma[] Array del tipo estructura en donde se buscara la posicion libre.
 * \param tFant Longitud/tamaño del Array de estructura.
 * \return int Retorna el índice de la primera posicion disponible que encuentra.
 *
 */
int buscarLibreCliente(eCliente vecCliente[], int tCli)
{
    int indice = -1;

    for(int i=0; i < tCli; i++)
    {
        if(vecCliente[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief Muestra por pantalla a un ITEM pasado por parametro.
 *
 * \param listFantasma ITEM a ser mostrado.
 * \return void No retorna nada.
 *
 */
void mostrarUnCliente(eCliente vecCliente)
{
    printf("%5d  %10s   %10s    %5c     %s     %10s\n\n",
           vecCliente.id,
           vecCliente.nombre,
           vecCliente.apellido,
           vecCliente.sexo,
           vecCliente.telefono,
           vecCliente.domicilio);
}

/** \brief Imprime por pantalla todo el array del ITEM pasado por parametro.
 *
 * \param listFantasma[] Array del tipo estructura a ser mostrado.
 * \param tFant Longitud/tamaño del Array de estructura.
 * \return int Retorna [0] si no hay ITEM que mostrar - [1] Todo OK
 *
 */
int imprimirClientes(eCliente vecCliente[],int tCli)
{
    int flag=0;
    printf("  ID       NOMBRE     APELLIDO     SEXO     TELEFONO     DIRECCION\n");
    printf("  --       ------     --------     ----     --------     ---------\n\n");
    for(int i=0; i<tCli; i++)
    {
        if(vecCliente[i].isEmpty == 0)
        {
            mostrarUnCliente(vecCliente[i]);
            flag=1;
        }
    }
    if (flag==0)
    {
        printf("\nNo hay --Clientes-- que mostrar.\n\n");
    }
    return flag;
}

//ALTA Cliente
/** \brief Da de alta al ITEM.
 *         Se fija si hay lugar libre.
 *         Se lo hay, pide los datos.
 *
 * \param listFantasma[] Array del tipo estructura a dar de alta.
 * \param tFant Longitud/tamaño del Array de estructura.
 * \return int Retorna [-1] si hubo un ERROR - [0] Todo OK.
 *
 */
int altaClienteMaestra(eCliente vecCliente[],int tCli,int lastId)
{


    int todoOk= 0;
    int index;

    system("cls");
    printf("\nAlta --Cliente--\n");

    index = buscarLibreCliente(vecCliente,tCli);

    if(index == -1)
    {
        printf("\n--Sistema completo.--\n\n");
    }
    else
    {
        if(getNombreOApellido(vecCliente[index].nombre,"\n<2-35 caract>\nIngrese nombre: ","\nError. Reingrese: ",2,35,2)!=-1)
        {
            if(getNombreOApellido(vecCliente[index].apellido,"\n<2-35 caract>\nIngrese apellido: ","\nError. Reingrese: ",2,35,2)!=-1)
            {
                if(getChar(&vecCliente[index].sexo,"\n<f/m>\nIngrese sexo: ","\nError. Reingrese: ",'f','m',2)!=-1)
                {
                    if(getStringTelefono(vecCliente[index].telefono,"\n<8-10 digitos>\nIngrese telefono: ","\nError. Reingrese: ",8,10,2)!=-1)
                    {
                        if(getString(vecCliente[index].domicilio,"\n<2-35 caract>\nIngrese domicilio: ","\nError. Reingrese: ",2,35,2)!=-1)
                        {
                            vecCliente[index].id = lastId;
                            vecCliente[index].isEmpty = 0;//Esta ocupado.
                            todoOk = 1;
                            printf("\n--Alta de --Cliente-- exitosa--\n\n");

                        }
                    }
                }
            }
        }    }
    if(todoOk != 1)
    {
        printf("\nError en la carga de datos.\n");
    }
    return todoOk;

}

int hardCodearClientes(eCliente vecCliente[],int tCli,int cant)
{
    int contador = 0;

    //El ultimo cero es su estado isEmpty.
    eCliente bCliente[] = {
        {100,"Yago","Rodi",'m',"42121743","Hudson 1515",0},
        {101,"Camila","Roy",'f',"45128749","Solano 850",0}
    };

    if(cant<=tCli && cant <=2)
    {
        for(int i = 0; i<tCli;i++)
        {
            vecCliente[i] = bCliente[i];
            contador++;
        }
    }


}
