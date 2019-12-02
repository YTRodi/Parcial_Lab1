#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "Juego.h"


/** \brief Carga 11 Juegos con sus respectivos:
 *         -Id
 *         -Descripcion.
 *         -Importe.
 *         -IdCategoria.
 *
 * \param vecJuego[] Array del tipo estructura de Juegos.
 * \param tJue Longitud/tamaño del Array de Juegos.
 * \return void No retorna nada.
 *
 */
void hardCodearJuegos(eJuego vecJuego[],int tJue)
{
    //en caso que se necesite, agregar un campo isEmpty al final == 0.
    eJuego bJuego[]=
    {
        /**
        1 - Mesa
        2 - Azar
        3 - Estrategia
        4 - Salon
        5 - Magia
        **/

        //IDJUEGO, Descripcion,importe,idcategoria.
        {10,"Galera magica",1000,5},
        {11,"Metegol",5000,2},
        {12,"Pool",8000,4},
        {13,"Cubo Rubik",200,4},
        {14,"Ajedrez",6500,1},
        {15,"Conejo magico",125,4},
        {16,"Cartas",125,2},
        {17,"Monopoly",10000,1},
        {18,"Black Jack",225,2},
        {19,"Ping pong",7800,4},
        {20,"Jenga",200,1},
        {21,"Rompecabezas",150,1},
        {22,"Uno",400,2},
        {23,"Teg",6000,3},
        {24,"Cardistry",1100,5},
        {25,"Inflable",8400,4}
        //CON ESTO HAGO EL INFORME 5 (PARCIAL 2)

        /*{10,"Galera magica",1000,5},
        {11,"Metegol",5000,4},
        {12,"Pool",8000,4},
        {13,"Cubo Rubik",200,3},
        {14,"Ajedrez",6500,1},
        {15,"Conejo magico",125,5},
        {16,"Cartas",125,2},
        {17,"Monopoly",10000,1},
        {18,"Black Jack",225,2},
        {19,"Ping pong",7800,4},
        {20,"Jenga",200,1},
        {21,"Rompecabezas",150,1},
        {22,"Uno",400,2},
        {23,"Teg",6000,3},
        {24,"Cardistry",1100,5},
        {25,"Inflable",8400,4}*/
    };

    for(int i = 0; i<tJue;i++)
    {
        vecJuego[i] = bJuego[i];
    }
}


/** \brief Muestra por pantalla a un Juego pasado por parametro.
 *
 * \param vecJuego Juego a ser mostrado.
 * \param vecCategoria[] Array del tipo estructura de Categoria.
 * \param tCate Longitud/tamaño del Array de Categoria.
 * \return void No retorna nada.
 *
 */
void mostrarUnJuego(eJuego vecJuego,eCategoria vecCategoria[],int tCate)
{
    char nombre[20];

    cargarDescripcionCategoria(vecCategoria,tCate,vecJuego.idCategoria,nombre);

    printf("%4d %15s   $%.2f %15s\n\n",
           vecJuego.idJue,
           vecJuego.descripcion,
           vecJuego.importe,
           nombre);
}


/** \brief Imprime por pantalla todo el array de Clientes pasado por parametro.
 *
 * \param vecJuego[] Array del tipo estructura de Juegos.
 * \param tJue Longitud/tamaño del Array de Juegos.
 * \param vecCategoria[] Array del tipo estructura de Categoria.
 * \param tCate Longitud/tamaño del Array de Categoria.
 * \return void No retorna nada.
 *
 */
void imprimirJuegos(eJuego vecJuego[],int tJue,eCategoria vecCategoria[],int tCate)
{
    printf("  ID          NOMBRE    IMPORTE       CATEGORIA\n");
    printf("  --          ------    -------       ---------\n\n");

    for(int i=0;i<tJue;i++)
    {
        mostrarUnJuego(vecJuego[i],vecCategoria,tCate);
    }
}


/** \brief Cargar la descripcion del Juego.
 *
 * \param vecJuego[] Array del tipo estructura en el cual se va a cargar la descripcion.
 * \param tJue Longitud/tamaño del Array de Juegos.
 * \param id Id auxiliar en el cual se le iguala el Id del cliente.
 * \param descripcion[] Guarda la descripcion del juego.
 * \return void No retorna nada.
 *
 */
void cargarDescripcionJuego(eJuego vecJuego[],int tJue,int id,char descripcion[])
{
    for(int i = 0; i<tJue;i++)
    {
        if(vecJuego[i].idJue == id)
        {
            strcpy(descripcion,vecJuego[i].descripcion);
        }
    }
}
