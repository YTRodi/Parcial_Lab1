#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
}eLocalidad;

typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    char sexo;
    char telefono[50];
    char domicilio[50];
    int idLocalidad;
    int isEmpty;
}eCliente;


#endif // CLIENTES_H_INCLUDED

int hardCodearClientes(eCliente vecCliente[],int tCli);

void hardCodearLocalidades(eLocalidad vecLocalidad[],int tLoca);


int menuClienteGeneralUno();
void inicializarCliente(eCliente vecCliente[], int tCli);
int buscarLibreCliente(eCliente vecCliente[], int tCli);
void mostrarUnCliente(eCliente vecCliente,eLocalidad vecLocalidad[],int tLoca);
int imprimirClientes(eCliente vecCliente[],int tCli,eLocalidad vecLocalidad[],int tLoca);

int altaClienteMaestra(eCliente vecCliente[],int tCli,int lastId,
                       eLocalidad vecLocalidad[],int tLoca);

int buscarClienteId(eCliente vecCliente[],int tCli,int idABuscar);
int menuModificacion();
int modificarCliente(eCliente vecCliente[],int tCli,eLocalidad vecLocalidad[],int tLoca);


int bajaCliente(eCliente vecCliente[],int tCli,eLocalidad vecLocalidad[],int tLoca);


void ordenarClientesPorApellidoYNombre(eCliente vecCliente[],int tCli);


void cargarDescripcionCliente(eCliente vecCliente[],int tCli,int id,char descripcion[]);


/***LOCALIDAD****/

void mostrarUnaLocalidad(eLocalidad vecLocalidad);
void imprimirLocalidad(eLocalidad vecLocalidad[],int tLoca);

void cargarDescripcionLocalidad(eLocalidad vecLocalidad[],int tLoca,int id,char descripcion[]);




