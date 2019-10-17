#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

typedef struct
{
    int idCate;
    char descripcion[20];
}eCategoria;

#endif // CATEGORIA_H_INCLUDED

//void hardCodearCategoria(eCategoria vecCategoria[],int tCate,int cant);
void hardCodearCategoria(eCategoria vecCategoria[],int tCate);
void mostrarCategoria(eCategoria vecCategoria);
void imprimirCategorias(eCategoria vecCategoria[],int tCli);
int cargarDescripcionCategoria(eCategoria vecCategoria[],int tCate,int id,char descripcion[]);
