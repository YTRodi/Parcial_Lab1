#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    char sexo;
    char telefono[50];
    char domicilio[50];
    int isEmpty;
}eCliente;

#endif // CLIENTES_H_INCLUDED

int hardCodearClientes(eCliente vecCliente[],int tCli);

int menuClienteGeneralUno();
void inicializarCliente(eCliente vecCliente[], int tCli);
int buscarLibreCliente(eCliente vecCliente[], int tCli);
void mostrarUnCliente(eCliente vecCliente);
int imprimirClientes(eCliente vecCliente[],int tCli);
int altaClienteMaestra(eCliente vecCliente[],int tCli,int lastId);





int buscarClienteId(eCliente vecCliente[],int tCli,int idABuscar);
int menuModificacion();
int modificarCliente(eCliente vecCliente[],int tCli);


int bajaCliente(eCliente vecCliente[],int tCli);


void ordenarClientesPorApellidoYNombre(eCliente vecCliente[],int tCli);


void cargarDescripcionCliente(eCliente vecCliente[],int tCli,int id,char descripcion[]);





