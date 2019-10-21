#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "Categoria.h"


/** \brief Carga 4 Categorias con sus respectivos:
 *         -Id
 *         -Descripcion.
 *
 * \param vecCategoria[] Array del tipo estructura de Categoria.
 * \param tCate Longitud/tamaño del Array de Categoria.
 * \return void No retorna nada.
 *
 */
void hardCodearCategoria(eCategoria vecCategoria[],int tCate)
{
    eCategoria bCategoria[]=
    {
        //idCategoria y nombre (descripcion)
        {1,"Mesa"},
        {2,"Azar"},
        {3,"Estrategia"},
        {4,"Salon"},
        {5,"Magia"}
    };

    for(int i = 0; i<tCate;i++)
    {
        vecCategoria[i] = bCategoria[i];
    }

}


/** \brief Muestra por pantalla a una categoria pasado por parametro.
 *
 * \param vecCategoria Categoria a ser mostrada.
 * \return void No retorna nada.
 *
 */
void mostrarCategoria(eCategoria vecCategoria)
{
    printf("%4d %15s\n\n",vecCategoria.idCate,vecCategoria.descripcion);
}


/** \brief Imprime por pantalla todo el array de Categoria pasado por parametro.
 *
 * \param vecCategoria[] Array del tipo estructura de Categoria.
 * \param tCate Longitud/tamaño del Array de Categoria.
 * \return void No retorna nada.
 *
 */
void imprimirCategorias(eCategoria vecCategoria[],int tCate)
{
    printf("  ID       CATEGORIA\n");
    printf("  --       ---------\n\n");

    for(int i=0; i<tCate; i++)
    {
        mostrarCategoria(vecCategoria[i]);
    }


}


/** \brief Cargar la descripcion de la categoria.
 *
 * \param vecCategoria[] Array del tipo estructura en el cual se va a cargar la descripcion.
 * \param tCate Longitud/tamaño del Array de Categoria.
 * \param id Id auxiliar en el cual se le iguala el Id del cliente.
 * \param descripcion[] Guarda la descripcion de la categoria.
 * \return int [0] si hubo un error - [1] TODO OK.
 *
 */
int cargarDescripcionCategoria(eCategoria vecCategoria[],int tCate,int id,char descripcion[])
{
    int todoOk = 0;

    for(int i = 0;i<tCate;i++)
    {
        if(vecCategoria[i].idCate == id)
        {
            strcpy(descripcion,vecCategoria[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}
