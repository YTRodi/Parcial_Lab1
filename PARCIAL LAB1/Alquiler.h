#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int idAlqui;
    int idJuego;
    int idCliente;
    eFecha fechaAlquiler;
    int isEmpty;
}eAlquiler;

#endif // ALQUILER_H_INCLUDED

/*
#include "Clientes.h"
#include "Juego.h"
#include "Categoria.h"
*/

//int hardCodearAlquileres(eAlquiler vecAlquiler[],int tAlqui,int cantidad);
int hardCodearAlquileres(eAlquiler vecAlquiler[],int tAlqui);


void inicializarAlquiler(eAlquiler vecAlquiler[], int tAlqui);
int buscarLibreAlquiler(eAlquiler vecAlquiler[], int tAlqui);

void mostrarUnAlquiler(eAlquiler vecAlquiler,eJuego vecJuego[],int tJue,eCliente vecCliente[],int tCli);

int imprimirAlquileres(eAlquiler vecAlquiler[],int tAlqui,eJuego vecJuego[],int tJue,eCliente vecCliente[],int tCli);

int altaAlquilerMaestra(eAlquiler vecAlquiler[],
                        int tAlqui,
                        int lastIdAlquiler,
                        eCliente vecCliente[],
                        int tCli,
                        eJuego vecJuego[],
                        int tJue,
                        eCategoria vecCategoria[],
                        int tCate,
                        eLocalidad vecLocalidad[],
                        int tLoca);









