#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Clientes.h"
#include "utn.h"

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
    printf("7 - IMPRIMIR categorias\n");
    printf("8 - IMPRIMIR juegos\n");
    printf("9 - Informes\n");
    printf("10 - SALIR\n");
    getInt(&option,"\nIngrese opcion: ","Error. opcion no valida",1,10,2);
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
        if(getNombreOApellido(vecCliente[index].nombre,"\n<2-35 caract>\nIngrese nombre: ","\nError. Reingrese",2,35,2)!=-1)
        {
            if(getNombreOApellido(vecCliente[index].apellido,"\n<2-35 caract>\nIngrese apellido: ","\nError. Reingrese",2,35,2)!=-1)
            {
                if(getChar(&vecCliente[index].sexo,"\n<f/m>\nIngrese sexo: ","\nError. Reingrese",'f','m',2)!=-1)
                {
                    if(getStringTelefono(vecCliente[index].telefono,"\n<8-10 digitos>\nIngrese telefono: ","\nError. Reingrese",8,10,2)!=-1)
                    {
                        if(getString(vecCliente[index].domicilio,"\n<2-35 caract>\nIngrese domicilio: ","\nError. Reingrese",2,35,2)!=-1)
                        {
                            vecCliente[index].id = lastId;
                            vecCliente[index].isEmpty = 0;//Cambia su estado de libre a ocupado.
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

int hardCodearClientes(eCliente vecCliente[],int tCli)//,int cant)
{
    int contador = 0;

    //El ultimo cero es su estado isEmpty.
    eCliente bCliente[]=
    {
        {1000,"Yago","Rodi",'m',"42121743","Hudson 1515",0},
        {1001,"Camila","Roy",'f',"45128749","Solano 850",0},
        {1002,"Facundo","Tedesco",'m',"45678965","Doke 150",0},
        {1003,"Ban","Demon",'m',"45698735","Pedraza 888",0},
        {1004,"Joaquin","Escanor",'m',"1137103398","Lomas city 777",0},
        {1005,"Elisabeth","Angelita",'f',"66667894","Nanatsu 159",0},
        {1006,"Napoli","Eufrasia",'f',"65494875","Blancaflor 666",0},
        {1007,"Cespedes","Nahuel",'m',"42345678","Libertador 100",0},
        {1008,"Filipponi","Juana",'f',"45177539","Oddone 582",0},
        {1009,"Smith","Scott",'m',"45284582","Lelo 49",0}
    };

    //if(cant<=tCli && cant <=10)
    //{
        for(int i = 0; i<10;i++)
        {
            vecCliente[i] = bCliente[i];
            contador++;
        }
    //}

    return contador;
}


int buscarClienteId(eCliente vecCliente[],int tCli,int idABuscar)
{
    int index = -1;

    for(int i = 0; i<tCli;i++)
    {
        if(vecCliente[i].isEmpty==0 && vecCliente[i].id == idABuscar)
        {
            index = i;
            //Cuando encuentro el id, rompo el for.
            break;
        }
    }
    return index;
}

int menuModificacion()
{
    int option;
    printf("1 - Modificar nombre\n");
    printf("2 - Modificar domicilio\n");
    printf("3 - Modificar telefono\n");
    printf("4 - Salir\n");
    getInt(&option,"\nElija opcion: ","\nError. Ingrese un numero valido: ",1,4,2);
    return option;
}

int modificarCliente(eCliente vecCliente[],int tCli)
{
    int index;
    int idAMod;
    int todoOk = 0;


    system("cls");
    printf("\n--Modificar Cliente--\n");

    imprimirClientes(vecCliente,tCli);

    getInt(&idAMod,"\nIngrese ID a modificar: ","\nError. Reingrese un numero de id valido\n",1000,1999,2);

    index = buscarClienteId(vecCliente,tCli,idAMod);

    if(index == -1)
    {
        printf("\nNo existe un cliente con ese ID.\n\n");
    }
    else
    {
        printf("\n\n");
        printf("  ID       NOMBRE     APELLIDO     SEXO     TELEFONO     DIRECCION\n");
        printf("  --       ------     --------     ----     --------     ---------\n\n");
        mostrarUnCliente(vecCliente[index]);

        switch(menuModificacion())
        {
            case 1:
                if(getNombreOApellido(vecCliente[index].nombre,"\n<2-35 caract>\nIngrese nuevo nombre: ","\nError. Reingrese",2,35,2)!=-1)
                {
                    todoOk = 1;
                    printf("\n..Modificacion exitosa..\n\n");
                }
                break;

            case 2:
                if(getString(vecCliente[index].domicilio,"\n<2-35 caract>\nIngrese nuevo domicilio: ","\nError. Reingrese",2,35,2)!=-1)
                {
                    todoOk = 1;
                    printf("\n..Modificacion exitosa..\n\n");
                }
                break;

            case 3:
                if(getStringTelefono(vecCliente[index].telefono,"\n<8-10 digitos>\nIngrese nuevo telefono: ","\nError. Reingrese",8,10,2)!=-1)
                {
                    todoOk = 1;
                    printf("\n..Modificacion exitosa..\n\n");
                }
                break;

            case 4:
                printf("\n..Modificacion cancelada..\n\n...Redireccionando al menu...\n\n");
                break;
        }
    }
    return todoOk;
}

int bajaCliente(eCliente vecCliente[],int tCli)
{
    int index;
    int idABajar;
    int todoOk = 0;
    char confirma;

    system("cls");
    printf("\n--Baja Cliente--\n");

    imprimirClientes(vecCliente,tCli);

    getInt(&idABajar,"\nIngrese ID a dar de baja: ","\nError. Reingrese un numero de id valido\n",1000,1999,2);

    index = buscarClienteId(vecCliente,tCli,idABajar);

    if(index == -1)
    {
        printf("\nNo existe un cliente con ese ID.");
    }
    else
    {
        printf("\n\n");
        printf("  ID       NOMBRE     APELLIDO     SEXO     TELEFONO     DIRECCION\n");
        printf("  --       ------     --------     ----     --------     ---------\n\n");
        mostrarUnCliente(vecCliente[index]);

        printf("confirma baja? <s/n>: ");
        fflush(stdin);
        scanf("%c",&confirma);

        if(confirma == 's')
        {
            vecCliente[index].isEmpty = 1;
            printf("\n..Baja exitosa..\n\n");
            todoOk = 1;
        }
        else if(confirma == 'n')
        {
            printf("\nSe ha cancelado la operacion.\n\n");
        }
    }
    return todoOk;
}

void ordenarClientesPorApellidoYNombre(eCliente vecCliente[],int tCli)
{
    eCliente auxCliente;

    for(int i = 0; i<tCli-1;i++)
    {
        for(int j = i+1;j<tCli;j++)
        {
            if(strcmpi(vecCliente[i].apellido,vecCliente[j].apellido)>0)
            {
                auxCliente = vecCliente[i];
                vecCliente[i] = vecCliente[j];
                vecCliente[j] = auxCliente;
            }
            else
            {
                if(strcmpi(vecCliente[i].apellido,vecCliente[j].apellido)==0 && strcmpi(vecCliente[i].nombre,vecCliente[j].nombre)<0)
                {
                auxCliente = vecCliente[i];
                vecCliente[i] = vecCliente[j];
                vecCliente[j] = auxCliente;
                }
            }
        }
    }
}

void cargarDescripcionCliente(eCliente vecCliente[],int tCli,int id,char descripcion[])
{
    for(int i=0;i<tCli;i++)
    {
        if(vecCliente[i].id == id)
        {
            strcpy(descripcion,vecCliente[i].apellido);
            strcat(descripcion," ");
            strcat(descripcion,vecCliente[i].nombre);
            //strcpy(descripcion,vecCliente[i].nombre);
        }
    }

}


/*
void ordenarPorId(eCliente vecCliente[],int tCli)
{
    eCliente aux;

    for(int i = 0; i<tCli-1; i++)
    {
        for(int j = i +1 ; j<tCli; j++)
        {
            if(vecCliente[i].id > vecCliente[j].id)
            {
                aux = vecCliente[i];
                vecCliente[i] = vecCliente[j];
                vecCliente[j] = aux;
            }
        }
    }
}

void ordenarPorNombreDescendente(eCliente vecCliente[],int tCli)
{
    eCliente aux;

    for(int i = 0; i<tCli-1; i++)
    {
        for(int j = i +1; j<tCli; j++)
        {
            if(strcmpi(vecCliente[i].nombre,vecCliente[j].nombre)<0)
            {
                aux = vecCliente[i];
                vecCliente[i] = vecCliente[j];
                vecCliente[j] = aux;

            }
        }
    }

}


void obtenerNombreDelCliente(eCliente vecCliente[],int tCli,int id, char dondeAsignarCliente[])
{
    for(int i=0;i<tCli;i++)
    {
        if(vecCliente[i].id == id)
        {
            strcpy(dondeAsignarCliente,vecCliente[i].apellido);
            strcpy(dondeAsignarCliente,vecCliente[i].nombre);
        }
    }

}*/





