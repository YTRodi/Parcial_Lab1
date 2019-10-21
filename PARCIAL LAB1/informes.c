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
    printf("---ABM PARCIAL---\n\n");
    printf("1 - Mostrar juegos de categoria de mesa\n");
    printf("2 - Mostrar los alquileres efectuados por algun cliente seleccionado\n");
    printf("3 - Mostrar el total de todos los importes pagados por el cliente seleccionado\n");
    printf("4 - Listar los clientes que no alquilaron juegos\n");
    printf("5 - Listar los juegos que no han sido alquilados\n");
    printf("\nDE ACA PARA ABAJO SON LOS QUE ME PUEDEN LLEGAR A TOMAR\n\n");
    printf("6 - Clientes con mas alquiler\n");
    printf("7 - Listar clientes con X alquileres(CAMBIAR DEPENDIENDO DE CUANTOS QUIERO MOSTRAR EN LA FUNCION)\n");
    printf("8 - Listar mujeres que alquilaron\n");
    printf("9 - Listar mujeres que alquilaron JUEGOS DE AZAR\n");
    printf("11 - Listar Por fecha seleccionada\n");
    printf("10 - SALIR\n");

    getInt(&option,"\nIngrese opcion: ","Error. opcion no valida",1,15,2);
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
void imprimirClientesQueNoAlquilaron(eAlquiler vecAlquiler[],int tAlqui,eCliente vecCliente[],int tCli)
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
                mostrarUnCliente(vecCliente[i]);
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
                           eCategoria vecCategoria[],int tCate)
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
            mostrarUnCliente(vecCliente[i]);
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


void listarClientesConXAlquileres(eCliente vecCliente[],int tCli,eAlquiler vecAlquiler[],int tAlqui)
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
            mostrarUnCliente(vecCliente[i]);
        }
    }
}



void listarMujeresQueAlquilaron(eCliente vecCliete[],int tCli,eAlquiler vecAlquiler[],int tAlqui)
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
                        mostrarUnCliente(vecCliete[j]);
                    }
                }
            }
        }
    }
}

void listarMujeresQueAlquilaronJuegosDeXCategoria(eCliente vecCliete[],int tCli,
                                        eAlquiler vecAlquiler[],int tAlqui,
                                        eJuego vecJuego[],int tJue,
                                        eCategoria vecCategoria[],int tCate)
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
                                        mostrarUnCliente(vecCliete[j]);
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

void listarClientesPorFechaSeleccionada(eCliente vecCliente[],int tCli,eAlquiler vecAlquiler[],int tAlqui)
{
    eAlquiler fechaABuscarDia;
    eAlquiler fechaABuscarMes;
    eAlquiler fechaABuscarAnio;
    int index;
    int flag = 0;

    printf("\nBUSCAR CLIENTES POR FECHA\n\n");

    getInt(&fechaABuscarDia.fechaAlquiler.dia,"\nIngrese dia: ","Error.Reingrese",1,30,2);
    getInt(&fechaABuscarMes.fechaAlquiler.mes,"\nIngrese mes: ","Error.Reingrese",1,12,2);
    getInt(&fechaABuscarAnio.fechaAlquiler.anio,"\nIngrese anio: ","Error.Reingrese",1995,2019,2);


    index = buscarAlquilerPorFecha(vecAlquiler,tAlqui,fechaABuscarDia,fechaABuscarMes,fechaABuscarAnio);

    if(index == -1)
    {
        printf("\nNo hay un alquiler en esta fecha.\n\n");
    }
    else
    {

        for(int i = 0 ; i<tAlqui;i++)
        {
            if(vecAlquiler[i].isEmpty == 0)
            {
                for(int j = 0; j<tCli;j++)
                {
                    if(vecAlquiler[i].idCliente == vecCliente[j].id)
                    {
                        if(vecAlquiler[i].fechaAlquiler.dia == fechaABuscarDia.fechaAlquiler.dia &&
                           vecAlquiler[i].fechaAlquiler.mes == fechaABuscarMes.fechaAlquiler.mes &&
                           vecAlquiler[i].fechaAlquiler.anio == fechaABuscarAnio.fechaAlquiler.anio)
                           {
                               mostrarUnCliente(vecCliente[j]);
                               flag = 1;
                           }
                    }
                }
            }
        }
        if(flag == 0)
        {
            printf("\nCARAJOOOOO\n\n");
        }
    }
}

int buscarAlquilerPorFecha(eAlquiler vecAlquiler[],int tAlqui,int fechaDiaABuscar,int fechaMesABuscar,int fechaAnioABuscar)
{
    int index = -1;

    for(int i = 0; i<tAlqui;i++)
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


void listarClientesPorFecha(eCliente vecClinte[],int tCli,eAlquiler vecAlquiler[],int tAlqui)
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
        for(int i = 0; i<tCli;i++)
        {
            if(vecClinte[i].id == vecAlquiler[index].idCliente)
            {
                mostrarUnCliente(vecClinte[i]);
            }
        }
    }






}

int buscarPorFechaAlquiler(eAlquiler vecAlquiler[],eAlquiler auxAlqui,int tAlqui)
{
    int indice = -1;

    for(int i =0;i<tAlqui;i++)
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
