
int menuInformesClientes();
void imprimirJuegosMesa(eJuego vecJuego[],int tJue, eCategoria vecCategoria[],int tCate);

void imprimirAlquileresPorClienteSeleccionado(eAlquiler vecAlquiler[],int tAlqui,eCliente vecCliente[],int tCli,eJuego vecJuego[],int tJue,eCategoria vecCategoria[],int tCate,
                                              eLocalidad vecLocalidad[],int tLoca);

void imprimirTotalDeImportes(eAlquiler vecAlquiler[],int tAlqui,eCliente vecCliente[],int tCli, eJuego vecJuego[],int tJue,
                             eLocalidad vecLocalidad[],int tLoca);

void imprimirClientesQueNoAlquilaron(eAlquiler vecAlquiler[],int tAlqui,eCliente vecCliente[],int tCli,
                                     eLocalidad vecLocalidad[],int tLoca);

void imprimirJuegosQueNoAlquilaron(eAlquiler vecAlquiler[],int tAlqui,eJuego vecJuego[],int tJue,eCategoria vecCategoria[],int tCate);


int tienePedidoAlquiler(int idAIgualar,eAlquiler vecAlquiler[],int tAlqui);
int tienePedidoJuego(int idAIgualar,eAlquiler vecAlquiler[],int tAlqui);




/***LOS QUE ME PUEDEN LLEGAR A TOMAR***/

void clienteConMasAlquiler(eCliente vecCliente[],int tCli,
                           eAlquiler vecAlquiler[],int tAlqui,
                           eJuego vecJuego[],int tJue,
                           eCategoria vecCategoria[],int tCate,
                           eLocalidad vecLocalidad[],int tLoca);

int tieneMayorAlquiler(eAlquiler vecAlquiler[],int tAlqui,int idClienteAIgualar);

void listarClientesConXAlquileres(eCliente vecCliente[],int tCli,eAlquiler vecAlquiler[],int tAlqui,
                                  eLocalidad vecLocalidad[],int tLoca);

void listarMujeresQueAlquilaron(eCliente vecCliete[],int tCli,eAlquiler vecAlquiler[],int tAlqui,
                                eLocalidad vecLocalidad[],int tLoca);

void listarMujeresQueAlquilaronJuegosDeXCategoria(eCliente vecCliete[],int tCli,
                                        eAlquiler vecAlquiler[],int tAlqui,
                                        eJuego vecJuego[],int tJue,
                                        eCategoria vecCategoria[],int tCate,
                                        eLocalidad vecLocalidad[],int tLoca);



void listarClientesPorFecha(eCliente vecClinte[],int tCli,eAlquiler vecAlquiler[],int tAlqui,
                            eLocalidad vecLocalidad[],int tLoca);

int buscarPorFechaAlquiler(eAlquiler vecAlquiler[],eAlquiler auxAlqui,int tAlqui);







//informe 1 (parcial 2);
void listarClientesPorLocalidadDeterminada(eAlquiler vecAlquiler[],int tAlqui,
                                           eCliente vecCliente[],int tCli,
                                           eJuego vecJuego[],int tJue,
                                           eCategoria vecCategoria[],int tCate,
                                            eLocalidad vecLocalidad[],int tLoca);

int buscarLocalidadId(eLocalidad vecLocalidad[],int tLoca,int idABuscar);


//informe 2 (parcial 2);
void imprimirJuegosPreferidosDeUnaLocalidad(eCliente vecCliente[],int tCli,
                                            eAlquiler vecAlquiler[],int tAlqui,
                                            eJuego vecJuego[],int tJue,
                                            eCategoria vecCategoria[],int tCate,
                                            eLocalidad vecLocalidad[],int tLoca);

//informe 3 (parcial 2)
void listarMontoRecaudadoPorDeAlquileresXLocalidadDeterminada(eCliente vecCliente[],int tCli,
                                                              eAlquiler vecAlquiler[],int tAlqui,
                                                              eJuego vecJuego[],int tJue,
                                                              eCategoria vecCategoria[],int tCate,
                                                              eLocalidad vecLocalidad[],int tLoca);

int buscarJuegoId(eJuego vecJuego[],int tJue,int idABuscar);


//informe 4 (parcial 2)
void imprimirClienteYFechaQueAlquiloXJuego(eCliente vecCliente[],int tCli,
                                            eAlquiler vecAlquiler[],int tAlqui,
                                            eJuego vecJuego[],int tJue,
                                            eCategoria vecCategoria[],int tCate,
                                            eLocalidad vecLocalidad[],int tLoca);




//informe 5 (parcial 2)
void InformarCategoriaDeJuegosMenosAlquilada(eCliente vecCliente[],int tCli,
                                            eAlquiler vecAlquiler[],int tAlqui,
                                            eJuego vecJuego[],int tJue,
                                            eCategoria vecCategoria[],int tCate,
                                            eLocalidad vecLocalidad[],int tLoca);

//informe 6 (parcial 2)
//Listar telefonoes de los clientes que alquilaron juegos en una determinada fecha;
void listarTelefonoesDeClientesXFechaDeterminada(eCliente vecCliente[],int tCli,
                                   eAlquiler vecAlquiler[],int tAlqui,
                                   eJuego vecJuego[],int tJue,
                                   eCategoria vecCategoria[],int tCate,
                                   eLocalidad vecLocalidad[],int tLoca);

//informe 8
//- Mostrar el o los juegos mas alquilados por hombres.
void listarJuegosMasAlquiladosXHombres(eCliente vecCliente[],int tCli,
                                        eAlquiler vecAlquiler[],int tAlqui,
                                        eJuego vecJuego[],int tJue,
                                        eCategoria vecCategoria[],int tCate,
                                        eLocalidad vecLocalidad[],int tLoca);

int tieneMayorAlquilerJuego(eAlquiler vecAlquiler[],int tAlqui,int idJuegoAIgualar);


//informe 9
//Listar los clientes que alquilaron un determinado juego.
void listarClientesQueAlquilaronXJuego(eCliente vecCliente[],int tCli,
                                       eAlquiler vecAlquiler[],int tAlqui,
                                       eJuego vecJuego[],int tJue,
                                       eCategoria vecCategoria[],int tCate,
                                       eLocalidad vecLocalidad[],int tLoca);


//informe 10 (parcial 2)
void mostrarRecaudacionDeUnaFechaDeterminada(eCliente vecCliente[],int tCli,
                                       eAlquiler vecAlquiler[],int tAlqui,
                                       eJuego vecJuego[],int tJue,
                                       eCategoria vecCategoria[],int tCate,
                                       eLocalidad vecLocalidad[],int tLoca);


