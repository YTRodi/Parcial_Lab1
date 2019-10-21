#include "Categoria.h"
#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

typedef struct
{
    int idJue;
    char descripcion[20];
    float importe;
    int idCategoria;
}eJuego;
#endif // JUEGO_H_INCLUDED

//ACA HACER EL INCLUDE CATEGORIA.H

void hardCodearJuegos(eJuego vecJuego[],int tJue);
void mostrarUnJuego(eJuego vecJuego,eCategoria vecCategoria[],int tCate);
void imprimirJuegos(eJuego vecJuego[],int tJue,eCategoria vecCategoria[],int tCate);
void cargarDescripcionJuego(eJuego vecJuego[],int tJue,int id,char descripcion[]);
