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


/** \brief Muestra un menu de opciones.
 *
 * \return int La opcion elegida.
 *
 */
int menuInformesClientes()
{
    int option;
    system("cls");

    printf("---INFORMES PARCIAL PARTE 2---\n\n");
    printf(" A partir de aca Parcial parte 2 \n");
    printf("1 - Listar clientes de una determindad localidad\n");
    printf("2 - listar el juego preferido en una localidad\n");
    printf("3 - Ingresar una localidad e informa el monto recaudado en alquileres a clientes de la misma\n");
    printf("4 - Elegir un juego e informar las fechas y nombres de los clientes que lo alquilaron\n");
    printf("5 - Informar la categoria de juegos menos alquilada\n");
    printf("6 - Listar telefonoes de los clientes que alquilaron juegos en una determinada fecha\n");
    printf("7 - Listar los juegos alquilados por mujeres\n");
    printf("8 - Mostrar el o los juegos mas alquilados por hombres\n");
    printf("9 - Listar los clientes que alquilaron un determinado juego\n");
    printf("10 - Mostrar recaudacion de una fecha en particular\n");



    /*printf("---INFORMES PARCIAL PARTE 1---\n\n");
    printf("10 - Mostrar juegos de categoria de mesa\n");
    printf("12 - Mostrar los alquileres efectuados por algun cliente seleccionado\n");
    printf("13 - Mostrar el total de todos los importes pagados por el cliente seleccionado\n");
    printf("14 - Listar los clientes que no alquilaron juegos\n");
    printf("15 - Listar los juegos que no han sido alquilados\n");





    printf("\n\n\nPRACTICA EN CASA\n\n");
    printf("16 - Clientes con mas alquiler\n");
    printf("17 - Listar clientes con X alquileres(CAMBIAR DEPENDIENDO DE CUANTOS QUIERO MOSTRAR EN LA FUNCION)\n");
    printf("18 - Listar mujeres que alquilaron\n");
    printf("19 - Listar mujeres que alquilaron JUEGOS DE AZAR\n");
    printf("20 - Listar Por fecha seleccionada\n");*/
    printf("21 - SALIR\n");

    getInt(&option,"\nIngrese opcion: ","Error. opcion no valida",1,21,2);
    //ACA LIMITAR LA OPCION, MUY IMPORTANTE!!!!!!!!!!!!!!!!!!!!!

    return option;
}


/** \brief Imprime los juegos de categoria mesa
 *
 * \param vecJuego[] Array del tipo estructura de Juegos.
 * \param tJue Longitud/tamaño del Array de Juegos.
 * \param vecCategoria[] Array del tipo estructura de Categoria.
 * \param tCate Longitud/tamaño del Array de Categoria.
 * \return void No retorna nada.
 *
 */
void imprimirJuegosMesa(eJuego vecJuego[],int tJue, eCategoria vecCategoria[],int tCate)
{
    char nombre[20];
    int flag = 0;

    printf("\n");
    printf("  ID          NOMBRE    IMPORTE     DESCRIPCION\n");
    printf("  --          ------    -------     -----------\n\n");

    for(int i = 0; i<tJue; i++)
    {

        for(int j = 0; j<tCate; j++)
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


/** \brief Imprime la lista de alquileres por un Id seleccionado manualmente.
 *
 * \param vecAlquiler[] Array del tipo estructura de alquileres.
 * \param tAlqui Longitud/tamaño del Array de estructura.
 * \param vecCliente[] Array del tipo estructura de Clientes.
 * \param tCli Longitud/tamaño del Array de estructura.
 * \param vecJuego[] Array del tipo estructura de Juegos.
 * \param tJue Longitud/tamaño del Array de Juegos.
 * \param vecCategoria[] Array del tipo estructura de Categoria.
 * \param tCate Longitud/tamaño del Array de Categoria.
 * \return void No retorna nada.
 *
 */
void imprimirAlquileresPorClienteSeleccionado(eAlquiler vecAlquiler[],int tAlqui,eCliente vecCliente[],int tCli,eJuego vecJuego[],int tJue,eCategoria vecCategoria[],int tCate,
        eLocalidad vecLocalidad[],int tLoca)
{

    int idClienteABuscar;
    int index;
    int flag = 0;

    printf("\n**ALQUILERES POR CLIENTES**\n\n");

    imprimirClientes(vecCliente,tCli,vecLocalidad,tLoca);
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
        for(int i = 0; i<tAlqui; i++)
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


/** \brief Imprime el total de importes por id de cliente seleccionado manualmente
 *
 * \param vecAlquiler[] Array del tipo estructura de alquileres.
 * \param tAlqui Longitud/tamaño del Array de estructura.
 * \param vecCliente[] Array del tipo estructura de Clientes.
 * \param tCli Longitud/tamaño del Array de estructura.
 * \param vecJuego[] Array del tipo estructura de Juegos.
 * \param tJue Longitud/tamaño del Array de Juegos.
 * \return void No retorna nada.
 *
 */
void imprimirTotalDeImportes(eAlquiler vecAlquiler[],int tAlqui,eCliente vecCliente[],int tCli, eJuego vecJuego[],int tJue,
                             eLocalidad vecLocalidad[],int tLoca)
{
    int idClienteABuscar;
    int index;
    float acumulador = 0;

    printf("\n**TOTAL DE IMPORTES POR CLIENTE**\n\n");

    imprimirClientes(vecCliente,tCli,vecLocalidad,tLoca);
    getInt(&idClienteABuscar,"\nIngrese ID del cliente: ","\nError. Reingrese un numero de id valido\n",1000,1999,2);


    index = buscarClienteId(vecCliente,tCli,idClienteABuscar);

    if(index == -1)
    {
        printf("\nNo existe un cliente con ese ID.\n\n");
    }
    else
    {
        //recorro los alquileres.
        for(int i = 0; i<tAlqui; i++)
        {
            if(vecAlquiler[i].idCliente == idClienteABuscar && vecAlquiler[i].isEmpty == 0)
            {
                //recorro los juegos.
                for(int j = 0; j<tJue; j++)
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


/** \brief Imprime los clientes que no alquilaron juegos.
 *
 * \param vecAlquiler[] Array del tipo estructura de alquileres.
 * \param tAlqui Longitud/tamaño del Array de estructura.
 * \param vecCliente[] Array del tipo estructura de Clientes.
 * \param tCli Longitud/tamaño del Array de estructura.
 * \return void No retorna nada.
 *
 */
void imprimirClientesQueNoAlquilaron(eAlquiler vecAlquiler[],int tAlqui,eCliente vecCliente[],int tCli,
                                     eLocalidad vecLocalidad[],int tLoca)
{
    printf("\n");
    printf("  ID       NOMBRE     APELLIDO     SEXO     TELEFONO     DIRECCION\n");
    printf("  --       ------     --------     ----     --------     ---------\n\n");

    for (int i=0; i<tCli; i++) //RECORRO LOS CLIENTES
    {

        if(vecCliente[i].isEmpty == 0)//SI EL CLIENTE ESTA DADO DE ALTA
        {
            //== 0(MUESTRA LOS QUE NO DIERON DE ALTA NINGUN ALQUILER), == 1(MUESTRA LOS QUE DIERON DE ALTA ALQUILER.)
            //NO HACE FALTA RECORRER NO ALQUILERES, PORQUE LO RECORRE EN LA FUNCION "tienePedidoAlquiler"

            if(tienePedidoAlquiler(vecCliente[i].id,vecAlquiler,tAlqui) == 0)
            {
                mostrarUnCliente(vecCliente[i],vecLocalidad,tLoca);
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


/** \brief Imprime juegos que no fueron alquilados.
 *
 * \param vecAlquiler[] Array del tipo estructura de alquileres.
 * \param tAlqui Longitud/tamaño del Array de estructura.
 * \param vecJuego[] Array del tipo estructura de Juegos.
 * \param tJue Longitud/tamaño del Array de Juegos.
 * \param vecCategoria[] Array del tipo estructura de Categoria.
 * \param tCate Longitud/tamaño del Array de Categoria.
 * \return void No retorna nada.
 *
 */
void imprimirJuegosQueNoAlquilaron(eAlquiler vecAlquiler[],int tAlqui,eJuego vecJuego[],int tJue,eCategoria vecCategoria[],int tCate)
{
    printf("\n");
    printf("  ID          NOMBRE    IMPORTE     DESCRIPCION\n");
    printf("  --          ------    -------     -----------\n\n");

    for(int i = 0 ; i<tJue; i++)
    {
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


/** \brief Verifica si coincide el idCliente de la lista de alquileres con el Id auxiliar.
 *
 * \param idAIgualar Variable Auxiliar.
 * \param vecAlquiler[] Array del tipo estructura de alquileres.
 * \param tAlqui Longitud/tamaño del Array de estructura.
 * \return int [0] ERROR - [1] - TODO OK.
 *
 */
int tienePedidoAlquiler(int idAIgualar,eAlquiler vecAlquiler[],int tAlqui)
{
    for(int i =0; i<tAlqui; i++)
    {
        if(vecAlquiler[i].idCliente == idAIgualar)
        {
            return 1;
        }
    }
    return 0;
}


/** \brief Verifica si coincide el idJuego de la lista de alquileres con el Id auxiliar.
 *
 * \param idAIgualar Variable Auxiliar.
 * \param vecAlquiler[] Array del tipo estructura de alquileres.
 * \param tAlqui Longitud/tamaño del Array de estructura.
 * \return int [0] ERROR - [1] - TODO OK.
 *
 */
int tienePedidoJuego(int idAIgualar,eAlquiler vecAlquiler[],int tAlqui)
{

    for(int i =0; i<tAlqui; i++)
    {
        if(vecAlquiler[i].idJuego == idAIgualar)
        {
            return 1;
        }

    }

    return 0;
}









/**LO QUE ME PUEDEN LLEGAR A TOMAR...****/

void clienteConMasAlquiler(eCliente vecCliente[],int tCli,
                           eAlquiler vecAlquiler[],int tAlqui,
                           eJuego vecJuego[],int tJue,
                           eCategoria vecCategoria[],int tCate,
                           eLocalidad vecLocalidad[],int tLoca)
{
    /**PUEDE USARSE PARA LISTAR JUEGOS MAS ALQUILADOS!!!***/

    int cantidades[tCli];
    int mayor = 0;
    int flag = 0;

    for(int i = 0; i<tCli; i++)
    {
        cantidades[i] = tieneMayorAlquiler(vecAlquiler,tAlqui,vecCliente[i].id);
        if(mayor<cantidades[i] || flag == 0)
        {
            mayor = cantidades[i];
            flag = 1;
        }
    }

    printf("\n");
    printf("   ..::EL CLIENTE QUE MAS ALQUILO ES::..\n\n");
    printf("  ID       NOMBRE     APELLIDO     SEXO     TELEFONO     DIRECCION\n");
    printf("  --       ------     --------     ----     --------     ---------\n\n");
    for(int i = 0; i<tCli; i++)
    {
        if(mayor == cantidades[i])
        {
            mostrarUnCliente(vecCliente[i],vecLocalidad,tLoca);
        }
    }

}


/*int cantidadAlquileresPorCliente(eAlquiler vecAlquiler[],int tAlqui,int idClienteAIgualar)
{
    int cantidad = 0;

    for(int i = 0; i<tAlqui; i++)
    {
        if(vecAlquiler[i].isEmpty == 0 && vecAlquiler[i].idCliente == idClienteAIgualar)
        {
            cantidad++;
        }
    }

    return cantidad;
}*/


int tieneMayorAlquiler(eAlquiler vecAlquiler[],int tAlqui,int idClienteAIgualar)
{
    int contador = 0;

    for(int i = 0; i<tAlqui; i++)
    {
        if(vecAlquiler[i].isEmpty == 0 && vecAlquiler[i].idCliente == idClienteAIgualar)
        {
            contador++;
        }
    }
    return contador;
}


void listarClientesConXAlquileres(eCliente vecCliente[],int tCli,eAlquiler vecAlquiler[],int tAlqui,
                                  eLocalidad vecLocalidad[],int tLoca)
{
    /**CAMBIAR EL 3 POR LA CANTIDAD QUE QUIERA MOSTRAR***/
    int contador = 0;

    printf("\n");
    printf("   ..::LISTAR CLIENTES CON X ALQUILERES::..\n\n");
    printf("  ID       NOMBRE     APELLIDO     SEXO     TELEFONO     DIRECCION\n");
    printf("  --       ------     --------     ----     --------     ---------\n\n");

    for(int i = 0; i<tCli; i++)
    {
        if(vecCliente[i].isEmpty == 0)
        {
            contador = tieneMayorAlquiler(vecAlquiler,tAlqui,vecCliente[i].id);
        }
        if(contador>2)
        {
            mostrarUnCliente(vecCliente[i],vecLocalidad,tLoca);
        }
    }
}



void listarMujeresQueAlquilaron(eCliente vecCliete[],int tCli,eAlquiler vecAlquiler[],int tAlqui,
                                eLocalidad vecLocalidad[],int tLoca)
{
    printf("\n");
    printf("   ..::LISTAR (F O M) QUE ALQUILARON::..\n\n");
    printf("  ID       NOMBRE     APELLIDO     SEXO     TELEFONO     DIRECCION\n");
    printf("  --       ------     --------     ----     --------     ---------\n\n");

    for(int i = 0; i<tAlqui; i++)
    {
        if(vecAlquiler[i].isEmpty == 0)
        {
            for(int j = 0; j<tCli; j++)
            {
                if(vecCliete[j].isEmpty == 0 && vecAlquiler[i].idCliente == vecCliete[j].id)
                {
                    if(vecCliete[j].sexo == 'f')
                    {
                        mostrarUnCliente(vecCliete[j],vecLocalidad,tLoca);
                    }
                }
            }
        }
    }
}

void listarMujeresQueAlquilaronJuegosDeXCategoria(eCliente vecCliete[],int tCli,
        eAlquiler vecAlquiler[],int tAlqui,
        eJuego vecJuego[],int tJue,
        eCategoria vecCategoria[],int tCate,
        eLocalidad vecLocalidad[],int tLoca)
{

    char nombreCategoria[50];

    for(int i = 0; i<tAlqui; i++)
    {
        if(vecAlquiler[i].isEmpty == 0)
        {
            for(int j = 0; j<tCli; j++)
            {
                if(vecCliete[j].isEmpty == 0 && vecAlquiler[i].idCliente == vecCliete[j].id && vecCliete[j].sexo == 'f')
                {
                    for(int k = 0; k<tJue; k++)
                    {
                        if(vecJuego[k].idJue == vecAlquiler[i].idJuego)
                        {
                            for(int y = 0; y<tCate; y++)
                            {
                                if(vecJuego[k].idCategoria == vecCategoria[y].idCate)
                                {
                                    cargarDescripcionCategoria(vecCategoria,tCate,vecJuego[k].idCategoria,nombreCategoria);

                                    if(strcmpi(nombreCategoria,"azar")==0)
                                    {
                                        mostrarUnCliente(vecCliete[j],vecLocalidad,tLoca);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

/*oid mostrarMujeresConJuego(eCliente vecCliente,eCategoria vecCate,eJuego vecJuego)
{
    printf("\n%s %s %s %s\n\n",vecCliente.nombre,vecCliente.apellido,vecJuego.descripcion,vecCate.descripcion);
}
POR SI LAS MOSCAS
*/



int buscarAlquilerPorFecha(eAlquiler vecAlquiler[],int tAlqui,int fechaDiaABuscar,int fechaMesABuscar,int fechaAnioABuscar)
{
    int index = -1;

    for(int i = 0; i<tAlqui; i++)
    {
        if(vecAlquiler[i].isEmpty == 0 &&
                vecAlquiler[i].fechaAlquiler.dia == fechaDiaABuscar &&
                vecAlquiler[i].fechaAlquiler.mes == fechaMesABuscar &&
                vecAlquiler[i].fechaAlquiler.anio == fechaAnioABuscar)
        {
            index = i;
            break;
        }
    }
    return index;
}

/*int buscarClientePorFecha(eCliente vecCliente[],int tCli,int idABuscar)
{
    int index = -1;

    for(int i = 0; i<tCli; i++)
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
*/


void listarClientesPorFecha(eCliente vecClinte[],int tCli,eAlquiler vecAlquiler[],int tAlqui,
                            eLocalidad vecLocalidad[],int tLoca)
{
    eAlquiler auxAlquiler;
    int index;


    getInt(&auxAlquiler.fechaAlquiler.dia,"\nIngrese dia: ","Error.Reingrese",1,30,2);
    getInt(&auxAlquiler.fechaAlquiler.mes,"\nIngrese mes: ","Error.Reingrese",1,12,2);
    getInt(&auxAlquiler.fechaAlquiler.anio,"\nIngrese anio: ","Error.Reingrese",1995,2019,2);

    index = buscarPorFechaAlquiler(vecAlquiler,auxAlquiler,tAlqui);

    if(index == -1)
    {
        printf("NO HAY ALQUIERES\n");
    }
    else
    {
        printf("ID APELLIDO NOMBRE\n");
        for(int i = 0; i<tCli; i++)
        {
            if(vecClinte[i].id == vecAlquiler[index].idCliente)
            {
                mostrarUnCliente(vecClinte[i],vecLocalidad,tLoca);
            }
        }
    }






}

int buscarPorFechaAlquiler(eAlquiler vecAlquiler[],eAlquiler auxAlqui,int tAlqui)
{
    int indice = -1;

    for(int i =0; i<tAlqui; i++)
    {
        if(vecAlquiler[i].fechaAlquiler.anio == auxAlqui.fechaAlquiler.dia &&
                vecAlquiler[i].fechaAlquiler.mes == auxAlqui.fechaAlquiler.mes &&
                vecAlquiler[i].fechaAlquiler.dia == auxAlqui.fechaAlquiler.dia
          )
        {
            indice = i;
            break;
        }
    }

    return indice;


}

/***INFORMES PARCIAL***/

//informe 1 (parcial 2);
void listarClientesPorLocalidadDeterminada(eAlquiler vecAlquiler[],int tAlqui,
        eCliente vecCliente[],int tCli,
        eJuego vecJuego[],int tJue,
        eCategoria vecCategoria[],int tCate,
        eLocalidad vecLocalidad[],int tLoca)
{

    int idLocalidadABuscar;
    //int idClienteABuscar;
    int index;
    int flag = 0;

    printf("\n**ALQUILERES POR CLIENTES**\n\n");

    imprimirLocalidad(vecLocalidad,tLoca);

    getInt(&idLocalidadABuscar,"\nIngrese ID de localidad a buscar: ","\nError. Reingrese un numero de id valido\n",101,106,2);


    index = buscarLocalidadId(vecLocalidad,tCli,idLocalidadABuscar);

    if(index == -1)
    {
        printf("\nNo existe un cliente con ese ID.\n\n");
    }
    else
    {
        printf("\n\n");
        printf("  ID       NOMBRE     APELLIDO     SEXO     TELEFONO     DIRECCION\n");
        printf("  --       ------     --------     ----     --------     ---------\n\n");

        //recorro todo el tamaño del vector de alquileres
        for(int j = 0; j<tCli; j++)
        {
            if(vecCliente[j].isEmpty == 0 && vecCliente[j].idLocalidad == idLocalidadABuscar)
            {
                mostrarUnCliente(vecCliente[j],vecLocalidad,tLoca);
                flag = 1;
            }
        }

    }

    if(flag == 0)
    {
        printf("\nLa localidad no dio de alta ningun alquiler\n\n");
    }

}

int buscarLocalidadId(eLocalidad vecLocalidad[],int tLoca,int idABuscar)
{
    int index = -1;

    for(int i = 0; i<tLoca; i++)
    {

        if(vecLocalidad[i].id == idABuscar)
        {
            index = i;
            //Cuando encuentro el id, rompo el for.
            break;
        }
    }
    return index;
}



//informe 2 (parcial 2);
void imprimirJuegosPreferidosDeUnaLocalidad(eCliente vecCliente[],int tCli,
        eAlquiler vecAlquiler[],int tAlqui,
        eJuego vecJuego[],int tJue,
        eCategoria vecCategoria[],int tCate,
        eLocalidad vecLocalidad[],int tLoca)
{
    int idLocalidadABuscar;
    int index;
    int flag = 0;
    char descripcionLocalidad[20];

    printf("\n**JUEGOS PREFERIDOS DE UNA LOCALIDAD DETERMINADA**\n\n");

    imprimirLocalidad(vecLocalidad,tLoca);

    getInt(&idLocalidadABuscar,"\nIngrese ID de localidad a buscar: ","\nError. Reingrese un numero de id valido\n",101,106,2);

    index = buscarLocalidadId(vecLocalidad,tCli,idLocalidadABuscar);

    cargarDescripcionLocalidad(vecLocalidad,tLoca,idLocalidadABuscar,descripcionLocalidad);

    printf("\nJuegos preferidos de la localidad de: %s \n",descripcionLocalidad);

    if(index == -1)
    {
        printf("\nNo existe un cliente con ese ID.\n\n");
    }
    else
    {
        printf("\n");
        printf("  ID          NOMBRE    IMPORTE       CATEGORIA\n");
        printf("  --          ------    -------       ---------\n\n");

        for(int i=0; i<tCli; i++)
        {
            if(vecCliente[i].idLocalidad == idLocalidadABuscar && vecCliente[i].isEmpty == 0)
            {
                for(int j=0; j<tAlqui; j++)
                {
                    if(vecCliente[i].id == vecAlquiler[j].idCliente)
                    {
                        for(int k=0; k<tJue; k++)
                        {
                            if(vecAlquiler[j].idJuego == vecJuego[k].idJue)
                            {
                                for(int x=0; x<tCate; x++)
                                {
                                    if(vecJuego[k].idCategoria == vecCategoria[x].idCate)
                                    {
                                        mostrarUnJuego(vecJuego[k],vecCategoria,tCate);
                                        flag = 1;
                                    }
                                }
                            }
                        }

                    }
                }
            }
        }

    }

    if(flag == 0)
    {
        printf("\nLa localidad no dio de alta ningun alquiler\n\n");
    }

}


//informe 3 (parcial 2)
void listarMontoRecaudadoPorDeAlquileresXLocalidadDeterminada(eCliente vecCliente[],int tCli,
        eAlquiler vecAlquiler[],int tAlqui,
        eJuego vecJuego[],int tJue,
        eCategoria vecCategoria[],int tCate,
        eLocalidad vecLocalidad[],int tLoca)
{
    float acumulador = 0;
    //int flag = 0;
    int index;
    int idLocalidadABuscar;
    char descripcionLocalidad[20];

    imprimirLocalidad(vecLocalidad,tLoca);

    getInt(&idLocalidadABuscar,"\nIngrese ID de localidad a buscar: ","\nError. Reingrese un numero de id valido\n",101,106,2);

    index = buscarLocalidadId(vecLocalidad,tLoca,idLocalidadABuscar);

    cargarDescripcionLocalidad(vecLocalidad,tLoca,idLocalidadABuscar,descripcionLocalidad);

    if(index == -1)
    {
        printf("\nNo existe un cliente con ese ID.\n\n");
    }
    else
    {
        for(int i=0; i<tCli; i++)
        {
            if(vecCliente[i].idLocalidad == idLocalidadABuscar && vecCliente[i].isEmpty == 0)
            {
                for(int j=0; j<tAlqui; j++)
                {
                    if(vecAlquiler[j].idCliente == vecCliente[i].id && vecAlquiler[j].isEmpty == 0)
                    {
                        for(int k=0; k<tJue; k++)
                        {
                            for(int x=0; x<tCate; x++)
                            {
                                if(vecAlquiler[j].idJuego == vecJuego[k].idJue)
                                {
                                    if(vecJuego[k].idCategoria == vecCategoria[x].idCate)
                                    {
                                        acumulador += vecJuego[k].importe;
                                        //acumulador = acumulador + vecJuego[k].importe;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        printf("\n\nEl monto recaudado de %s es de: $%.2f \n\n",descripcionLocalidad,acumulador);
    }
}





//informe 4 (parcial 2)
void imprimirClienteYFechaQueAlquiloXJuego(eCliente vecCliente[],int tCli,
                                            eAlquiler vecAlquiler[],int tAlqui,
                                            eJuego vecJuego[],int tJue,
                                            eCategoria vecCategoria[],int tCate,
                                            eLocalidad vecLocalidad[],int tLoca)
{
    int idJuegoABuscar;
    int index;
    char nombre[20];

    imprimirJuegos(vecJuego,tJue,vecCategoria,tCate);

    getInt(&idJuegoABuscar,"Ingrese id juego:","error.reingrese",10,25,2);

    index = buscarJuegoId(vecJuego,tJue,idJuegoABuscar);

    if(index == -1)
    {
        printf("\nEse juego nunca fue alquilado.\n\n");
    }
    else
    {
        for(int i=0; i<tAlqui; i++)
        {
            for(int j=0; j<tJue; j++)
            {
                if(vecJuego[j].idJue == idJuegoABuscar && vecAlquiler[i].idJuego == idJuegoABuscar)
                {
                    for(int k=0; k<tCli; k++)
                    {

                        cargarDescripcionCliente(vecCliente,tCli,vecAlquiler[i].idCliente,nombre);

                        if(vecAlquiler[i].idCliente == vecCliente[k].id)
                        {
                            //mostrarUnAlquiler(vecAlquiler[i],vecJuego,tJue,vecCliente,tCli);
                            printf("\nCliente: %s  FechaAlquiler: %d/%d/%d\n\n",
                                   nombre,
                                   vecAlquiler[i].fechaAlquiler.dia,
                                   vecAlquiler[i].fechaAlquiler.mes,
                                   vecAlquiler[i].fechaAlquiler.anio);
                        }
                    }
                }

            }
        }
    }
}


int buscarJuegoId(eJuego vecJuego[],int tJue,int idABuscar)
{
    int index = -1;

    for(int i = 0; i<tJue; i++)
    {

        if(vecJuego[i].idJue == idABuscar)
        {
            index = i;
            //Cuando encuentro el id, rompo el for.
            break;
        }
    }
    return index;
}


//informe 5 (parcial 2)
void InformarCategoriaDeJuegosMenosAlquilada(eCliente vecCliente[],int tCli,
                                            eAlquiler vecAlquiler[],int tAlqui,
                                            eJuego vecJuego[],int tJue,
                                            eCategoria vecCategoria[],int tCate,
                                            eLocalidad vecLocalidad[],int tLoca)
{

    /**  ARREGLARRRRRRRRRR   **/
    int cantidades[tCate];
    int menor = 0;
    int flag = 0;
    char nombreCate[50];


    for(int i = 0; i<tJue; i++)
    {
        cantidades[i] = tieneMayorAlquilerJuego(vecAlquiler,tAlqui,vecJuego[i].idJue);
        //if(menor>cantidades[i] || flag == 0)
        if(menor>cantidades[i] || flag == 0)
        {
            menor = cantidades[i];
            flag = 1;
        }
    }

    printf("\n");
    printf("   ..::LA CATEGORIA MENOS ALQUILADA ES::..\n\n");
    printf("  ID       CATEGORIA\n");
    printf("  --       ---------\n\n");

    for(int i=0; i<tAlqui; i++)
    {
        for(int j=0; j<tJue; j++)
        {
            for(int x=0;x<tCate;x++)
            {
                for(int k=0; k<tCli; k++)
                {
                    cargarDescripcionCategoria(vecCategoria,tCate,vecJuego[j].idCategoria,nombreCate);

                    if(vecAlquiler[i].idJuego == vecJuego[j].idJue && vecAlquiler[i].idCliente == vecCliente[k].id)
                    {
                        if(vecJuego[j].idCategoria == vecCategoria[x].idCate)
                        {
                            if(menor == cantidades[i])
                            {
                                printf("Categoria menos alquilada: %s\n",nombreCate);
                                printf("\n");
                            }
                        }
                    }
                }
            }
        }
    }




}



//informe 6 (parcial 2)
//Listar telefonoes de los clientes que alquilaron juegos en una determinada fecha;
void listarTelefonoesDeClientesXFechaDeterminada(eCliente vecCliente[],int tCli,
                                   eAlquiler vecAlquiler[],int tAlqui,
                                   eJuego vecJuego[],int tJue,
                                   eCategoria vecCategoria[],int tCate,
                                   eLocalidad vecLocalidad[],int tLoca)
{
    eFecha fecha;
    char nombreCliente[25];

    imprimirAlquileres(vecAlquiler,tAlqui,vecJuego,tJue,vecCliente,tCli);
    printf("\n<xx/xx/xxxx>Ingrese fecha:");
    scanf("%d/%d/%d",&fecha.dia,&fecha.mes,&fecha.anio);

    for(int i=0;i<tCli;i++)
    {
        if(vecCliente[i].isEmpty == 0)
        {
            for(int j=0;j<tAlqui;j++)
            {
                if(vecCliente[i].id == vecAlquiler[j].idCliente && vecAlquiler[j].isEmpty == 0)
                {
                    cargarDescripcionCliente(vecCliente,tCli,vecCliente[i].id,nombreCliente);

                    for(int k=0;k<tJue;k++)
                    {
                        for(int x=0;x<tCate;x++)
                        {
                            if(vecAlquiler[j].idJuego == vecJuego[k].idJue)
                            {
                                if(vecJuego[k].idCategoria == vecCategoria[x].idCate)
                                {
                                    if(vecAlquiler[j].fechaAlquiler.dia == fecha.dia &&
                                    vecAlquiler[j].fechaAlquiler.mes == fecha.mes &&
                                    vecAlquiler[j].fechaAlquiler.anio == fecha.anio)
                                    {
                                        printf("\n\nCliente: %s -- telefono: %s\n\n",nombreCliente,vecCliente[i].telefono);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}



//informe 8
//- Mostrar el o los juegos mas alquilados por hombres.
void listarJuegosMasAlquiladosXHombres(eCliente vecCliente[],int tCli,
                                       eAlquiler vecAlquiler[],int tAlqui,
                                       eJuego vecJuego[],int tJue,
                                       eCategoria vecCategoria[],int tCate,
                                       eLocalidad vecLocalidad[],int tLoca)
{

    int cantidades[tJue];
    int mayor = 0;
    int flag = 0;
    char nombre[50];

    for(int i = 0; i<tJue; i++)
    {
        cantidades[i] = tieneMayorAlquilerJuego(vecAlquiler,tAlqui,vecJuego[i].idJue);
        if(mayor<cantidades[i] || flag == 0)
        {
            mayor = cantidades[i];
            flag = 1;
        }
    }

    printf("\n");
    printf("   ..::EL JUEGO MAS ALQUILADO ES (FALTA PONER POR HOMBRES)::..\n\n");
    printf("  ID          NOMBRE    IMPORTE       CATEGORIA\n");
    printf("  --          ------    -------       ---------\n\n");

    for(int i=0; i<tAlqui; i++)
    {
        for(int j=0; j<tJue; j++)
        {
            for(int x=0;x<tCate;x++)
            {
                for(int k=0; k<tCli; k++)
                {
                    //cargarDescripcionCliente(vecCliente,tCli,vecAlquiler[i].idCliente,nombre);
                    cargarDescripcionJuego(vecJuego,tJue,vecAlquiler[i].idJuego,nombre);

                    if(vecAlquiler[i].idJuego == vecJuego[j].idJue && vecAlquiler[i].idCliente == vecCliente[k].id)
                    {
                        if(vecJuego[j].idCategoria == vecCategoria[x].idCate)
                        {
                            //if(vecCliente[k].sexo == 'm')
                            //{       VERIFICARRRRRRRRRRRRRRRRRRRRRR

                                if(mayor == cantidades[i])
                                {
                                    //mostrarUnCliente(vecCliente[i],vecLocalidad,tLoca);
                                    mostrarUnJuego(vecJuego[i],vecCategoria,tCate);
                                }
                           // }
                        }
                    }


                }
            }
        }
    }




}

int tieneMayorAlquilerJuego(eAlquiler vecAlquiler[],int tAlqui,int idJuegoAIgualar)
{
    int contador = 0;

    for(int i = 0; i<tAlqui; i++)
    {
        if(vecAlquiler[i].isEmpty == 0 && vecAlquiler[i].idJuego == idJuegoAIgualar)
        {
            contador++;
        }
    }
    return contador;
}


//informe 9
//Listar los clientes que alquilaron un determinado juego.
void listarClientesQueAlquilaronXJuego(eCliente vecCliente[],int tCli,
                                       eAlquiler vecAlquiler[],int tAlqui,
                                       eJuego vecJuego[],int tJue,
                                       eCategoria vecCategoria[],int tCate,
                                       eLocalidad vecLocalidad[],int tLoca)
{
    int idJuegoABuscar;
    int index;
    imprimirJuegos(vecJuego,tJue,vecCategoria,tCate);

    getInt(&idJuegoABuscar,"Ingrese ID Juego a buscar:","Error.Reingrese:",10,25,2);

    index = buscarJuegoId(vecJuego,tJue,idJuegoABuscar);

    if(index == -1)
    {
        printf("\n\nNo existe juego con ese id.\n\n");
    }
    else
    {
        printf("\n");
        printf("  ID       NOMBRE   APELLIDO     SEXO     TELEFONO         DIRECCION          LOCALIDAD\n");
        printf("  --       ------   --------     ----     --------         ---------         ----------\n\n");

        for(int i=0;i<tAlqui;i++)
        {
            for(int j=0;j<tCli;j++)
            {
                if(vecAlquiler[i].isEmpty == 0 &&
                   vecCliente[j].isEmpty == 0 &&
                   vecAlquiler[i].idCliente == vecCliente[j].id)
                {
                    for(int k=0;k<tJue;k++)
                    {
                        for(int x=0;x<tCate;x++)
                        {
                            if(vecAlquiler[i].idJuego == vecJuego[k].idJue)
                            {
                                if(vecJuego[k].idJue == idJuegoABuscar && vecJuego[k].idCategoria == vecCategoria[x].idCate)
                                {
                                    mostrarUnCliente(vecCliente[j],vecLocalidad,tLoca);
                                }
                            }
                        }
                    }
                }
            }
        }


    }






}


//informe 10 (parcial 2)
void mostrarRecaudacionDeUnaFechaDeterminada(eCliente vecCliente[],int tCli,
                                       eAlquiler vecAlquiler[],int tAlqui,
                                       eJuego vecJuego[],int tJue,
                                       eCategoria vecCategoria[],int tCate,
                                       eLocalidad vecLocalidad[],int tLoca)
{
    eFecha fechaRecaudacion;
    float recaudacionTotal = 0;

    imprimirAlquileres(vecAlquiler,tAlqui,vecJuego,tJue,vecCliente,tCli);
    printf("\nIngrese fecha:");
    scanf("%d/%d/%d",&fechaRecaudacion.dia,&fechaRecaudacion.mes,&fechaRecaudacion.anio);

    for(int i=0;i<tCli;i++)
    {
        if(vecCliente[i].isEmpty == 0)
        {
            for(int j=0;j<tAlqui;j++)
            {
                if(vecCliente[i].id == vecAlquiler[j].idCliente && vecAlquiler[j].isEmpty == 0)
                {
                    if(vecAlquiler[j].fechaAlquiler.dia == fechaRecaudacion.dia &&
                       vecAlquiler[j].fechaAlquiler.mes == fechaRecaudacion.mes &&
                       vecAlquiler[j].fechaAlquiler.anio == fechaRecaudacion.anio)
                    {
                        for(int k=0;k<tJue;k++)
                        {
                            for(int x=0;x<tCate;x++)
                            {
                                if(vecAlquiler[j].idJuego == vecJuego[k].idJue)
                                {
                                    if(vecJuego[k].idCategoria == vecCategoria[x].idCate)
                                    {
                                    recaudacionTotal = recaudacionTotal + vecJuego[k].importe;

                                    }
                                }
                            }
                        }
                    }
                }
            }

        }
    }


    printf("\n\nLa recaudacion total del %d/%d/%d es de %.2f\n\n",fechaRecaudacion.dia,fechaRecaudacion.mes,fechaRecaudacion.anio,recaudacionTotal);
}









